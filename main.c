// for test purposes

#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);

int main()
{
    const char *test_strings[] = {
        "Hello World!",
        "",
        "1234567890",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "b",
        NULL
    };

    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);

    printf("Testing asm ft_strlen function:\n\n");

    for (int i = 0; i < num_tests; ++i)
    {
        size_t expected = test_strings[i] == NULL ? 0 : strlen(test_strings[i]);
        size_t result = ft_strlen(test_strings[i]);
        
        printf("Test #%d: \"%s\"\n", i + 1, test_strings[i]);
        printf("  strlen():     %zu\n", expected);
        printf("  ft_strlen():  %zu\n", result);
        printf("  %s\n\n", (expected == result) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
    }
}


