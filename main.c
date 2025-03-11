// for test purposes

#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern size_t ft_strlen(const char *s);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);

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

    int num_of_tests = sizeof(str1) / sizeof(str1[0]);

    int i = 0;
    for (; i < num_of_tests; ++i)
    {
        printf("Test #%i, \"%s\" and \"%s\"\n", i + 1, str1[i], str2[i]);
        int expected = strcmp(str1[i], str2[i]);
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
    const char *src[] = {"Hello world", "1", "", "1234567890", NULL};

    int num_of_tests = sizeof(src) / sizeof(src[0]);

    for (int i = 0; i < num_of_tests; ++i)
    {
        ft_write(1, src[i], ft_strlen(src[i]));
    }

}


int main()
{
    // ft_strlen_test();
    // ft_strcpy_test();
    // ft_strcmp_test();
    ft_write_test();

}


