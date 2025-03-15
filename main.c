// for test purposes

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

void ft_strlen_test()
{
    const char *test_strings[] = {"Hello world", "1", "", "1234567890", NULL};

    int num_of_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    printf("--------------Testing asm ft_strlen function:-------------------\n\n");

    for (int i = 0; i < num_of_tests; ++i)
    {
        size_t expected = (test_strings[i] == NULL) ? 0 : strlen(test_strings[i]);
        size_t result = ft_strlen(test_strings[i]);
        
        printf("Test #%d: \"%s\"\n", i + 1, test_strings[i]);
        printf("  strlen():     %zu\n", expected);
        printf("  ft_strlen():  %zu\n", result);
        printf("  %s\n\n", (expected == result) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
    }
}

void ft_strcpy_test()
{
    char dest[10000];
    const char *src[] = {"Hello world", "1", "", "1234567890", NULL};

    int num_of_tests = sizeof(src) / sizeof(src[0]);

    printf("-----------------Testing asm ft_strcpy() function---------------\n\n");

    
    for (int i = 0; i < num_of_tests; ++i)
    {
        ft_strcpy(dest, src[i]);
        printf("Test #%d: \"%s\"\n", i + 1, src[i]);
        printf("  dest: \"%s\"\n", dest);
        int pass = 1;
        if (/* dest && */ src[i])
            pass = !strcmp(dest, src[i]);
        printf("  %s\n\n", (pass) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
    }
}

void ft_strcmp_test()
{
    printf("-----------------Testing asm ft_strcmp() function---------------\n\n");

    const char *str1[] = {"Hello World",  "", " ", "sdfs"};
    const char *str2[] = {"Hello World2", "", "",  "sdf" };

    int expectetation[] = {-50, 0, 32, 115, 0};
    int num_of_tests = sizeof(str1) / sizeof(str1[0]);

    int i = 0;
    for (; i < num_of_tests; ++i)
    {
        printf("Test #%i, \"%s\" and \"%s\"\n", i + 1, str1[i], str2[i]);
        int expected = expectetation[i];
        int result = ft_strcmp(str1[i], str2[i]);
        printf("  strcmp() %d and ft_strcmp() %d\n", expected, result);
        printf("  %s\n\n", (expected == result) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
    }

    char *str = NULL;
    printf("Test #%i, \"%s\" and \"%s\"\n", i + 1, str, "1");
    int expected = 0;
    int result = ft_strcmp(NULL, str2[i]);
    printf("  strcmp() %d and ft_strcmp() %d\n", expected, result);
    printf("  %s\n\n", (expected == result) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
}

void ft_write_test()
{
    const char *src[] = {"Hello world", "~", "", "1234567890", NULL};
    int num_of_tests = sizeof(src) / sizeof(src[0]);

    printf("-----------------Testing asm ft_write() function----------------\n\n");

    for (int i = 0; i < num_of_tests; ++i)
    {
        int printed;
        int expected;
        printf("Test #%i, \"%s\"\n", i + 1, src[i]);
        write(1, "  ", 2); expected =   write(1, src[i], ft_strlen(src[i])); write(1, "\n", 1);
        write(1, "  ", 2); printed = ft_write(1, src[i], ft_strlen(src[i])); write(1, "\n", 1);
        printf("  %s\n\n", (printed == expected) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
    }

    printf("Test #6, Invalid fd\n");
    int invalid_fd = 99999;
    
    errno = 0;
    int sys_result = write(invalid_fd, "test", 4);
    int sys_errno = errno;
    errno = 0;
    int ft_result = ft_write(invalid_fd, "test", 4);
    int ft_errno = errno;
    
    printf("  write:    result=%d, errno=%d (%s)\n", sys_result, sys_errno, strerror(sys_errno));
    printf("  ft_write: result=%d, errno=%d (%s)\n", ft_result, ft_errno, strerror(ft_errno));
    printf("  %s\n\n", (sys_result == ft_result && sys_errno == ft_errno) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");

    printf("Test #7, Negative fd\n");
    invalid_fd = -1;
    
    errno = 0;
    sys_result = write(invalid_fd, "test", 4);
    sys_errno = errno;
    errno = 0;
    ft_result = ft_write(invalid_fd, "test", 4);
    ft_errno = errno;
    
    printf("  write:    result=%d, errno=%d (%s)\n", sys_result, sys_errno, strerror(sys_errno));
    printf("  ft_write: result=%d, errno=%d (%s)\n", ft_result, ft_errno, strerror(ft_errno));
    printf("  %s\n\n", (sys_result == ft_result && sys_errno == ft_errno) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
}

void ft_read_test()
{
    char buffer[100];
    char ft_buffer[100];
    int file_fd;
    
    printf("-----------------Testing asm ft_read() function-----------------\n\n");
    
    printf("Test #1, Reading from file\n");
    file_fd = open("test.txt", O_RDWR | O_CREAT, 0644);
    if (file_fd == -1) {
        printf("  Error creating test file\n");
        return;
    }
    write(file_fd, "Hello from test file!", 21);
    close(file_fd);
    
    file_fd = open("test.txt", O_RDONLY);
    bzero(buffer, sizeof(buffer));
    bzero(ft_buffer, sizeof(ft_buffer));
    
    errno = 0;
    int original = read(file_fd, buffer, 50);
    int original_errno = errno;
    close(file_fd);
    
    file_fd = open("test.txt", O_RDONLY);
    errno = 0;
    int mine = ft_read(file_fd, ft_buffer, 50);
    int mine_errno = errno;
    close(file_fd);
    
    printf("  read:    \"%s\", result=%d, errno=%d\n", buffer, original, original_errno);
    printf("  ft_read: \"%s\", result=%d, errno=%d\n", ft_buffer, mine, mine_errno);
    printf("  %s\n\n", (original == mine && !strcmp(buffer, ft_buffer)) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
    
    printf("Test #2, Invalid fd\n");
    int invalid_fd = 99999;
    
    errno = 0;
    int sys_result = read(invalid_fd, buffer, 10);
    int sys_errno = errno;
    
    errno = 0;
    int ft_result = ft_read(invalid_fd, ft_buffer, 10);
    int ft_errno = errno;
    
    printf("  read:    result=%d, errno=%d (%s)\n", sys_result, sys_errno, strerror(sys_errno));
    printf("  ft_read: result=%d, errno=%d (%s)\n", ft_result, ft_errno, strerror(ft_errno));
    printf("  %s\n\n", (sys_result == ft_result && sys_errno == ft_errno) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
    
    printf("Test #3, NULL buffer\n");
    file_fd = open("test.txt", O_RDONLY);
    
    errno = 0;
    char *null = NULL;
    sys_result = -1;
    sys_errno = 14;
    
    errno = 0;
    ft_result = ft_read(file_fd, null, 10);
    ft_errno = errno;
    close(file_fd);
    
    printf("  read:    result=%d, errno=%d (%s)\n", sys_result, sys_errno, strerror(sys_errno));
    printf("  ft_read: result=%d, errno=%d (%s)\n", ft_result, ft_errno, strerror(ft_errno));
    printf("  %s\n\n", (sys_result == ft_result && sys_errno == ft_errno) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
    
    unlink("test.txt"); // to delete this file
}

void ft_strdup_test()
{
    const char *src[] = {"Hello world", "~", "", "1234567890", NULL};
    int num_of_tests = sizeof(src) / sizeof(src[0]);

    printf("---------------Testing asm ft_strdup() function----------------\n\n");

    for (int i = 0; i < num_of_tests; ++i)
    {
        char *expected;
        char *result;
        printf("Test #%i, \"%s\"\n", i + 1, src[i]);
        
        expected =  src[i] ? strdup(src[i]) : 0;
        result = ft_strdup(src[i]);
        printf("  %s\n\n", (!ft_strcmp(expected, result)) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
        free(expected);
        free(result);
    }
}


int main()
{
    ft_strlen_test();
    ft_strcpy_test();
    ft_strcmp_test();
    ft_write_test();
    ft_read_test();
    ft_strdup_test();
}


