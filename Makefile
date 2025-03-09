NAME = libasm.a
SRCS = ft_strlen.s
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

bonus: 

re: fclean all

.PHONY: all clean fclean bonus re

# no relinling, 
# bonus in different file *_bonus.c/h