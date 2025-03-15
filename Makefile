NAME = libasm.a
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SRCS:.s=.o)

NASM = nasm
NASM_FLAGS = -f elf64
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

all: $(NAME)

%.o: %.s # For any .s (assembly source file), produce a corresponding .o (object file).
	$(NASM) $(NASM_FLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c $(NAME)
	./a.out

re: fclean all

.PHONY: all clean fclean test re