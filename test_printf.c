#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "ft_printf.h" // あなたのft_printf.hをインクルード

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"

void test_basic(int *total_tests, int *passed_tests) {
    int ft_len, printf_len;
    
    // Basic string tests
    printf_len = printf("Test 1: Basic string: %s\n", "Hello World");
    ft_len = ft_printf("Test 1: Basic string: %s\n", "Hello World");
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Basic string test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Basic string test failed (printf: %d, ft_printf: %d)\n" RESET, printf_len, ft_len);
    }

    // Character tests
    printf_len = printf("Test 2: Characters: %c %c %c\n", 'a', '\t', 127);
    ft_len = ft_printf("Test 2: Characters: %c %c %c\n", 'a', '\t', 127);
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Character test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Character test failed\n" RESET);
    }

    // Integer tests
    printf_len = printf("Test 3: Integers: %d %i %d\n", INT_MAX, INT_MIN, 0);
    ft_len = ft_printf("Test 3: Integers: %d %i %d\n", INT_MAX, INT_MIN, 0);
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Integer test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Integer test failed\n" RESET);
    }
}

void test_hex_pointer(int *total_tests, int *passed_tests) {
    int ft_len, printf_len;
    void *ptr = (void *)0x12345678;
    
    // Hexadecimal tests
    printf_len = printf("Test 4: Hex: %x %X %x\n", 0xdead, 0xBEEF, 0);
    ft_len = ft_printf("Test 4: Hex: %x %X %x\n", 0xdead, 0xBEEF, 0);
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Hexadecimal test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Hexadecimal test failed\n" RESET);
    }

    // Pointer tests
    printf_len = printf("Test 5: Pointers: %p %p\n", ptr, NULL);
    ft_len = ft_printf("Test 5: Pointers: %p %p\n", ptr, NULL);
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Pointer test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Pointer test failed\n" RESET);
    }
}

void test_edge_cases(int *total_tests, int *passed_tests) {
    int ft_len, printf_len;
    char *null_str = NULL;
    
    // Edge cases
    printf_len = printf("Test 6: NULL string: %s\n", null_str);
    ft_len = ft_printf("Test 6: NULL string: %s\n", null_str);
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ NULL string test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ NULL string test failed\n" RESET);
    }

    // Empty string
    printf_len = printf("Test 7: Empty string: '%s'\n", "");
    ft_len = ft_printf("Test 7: Empty string: '%s'\n", "");
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Empty string test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Empty string test failed\n" RESET);
    }

    // Multiple percent signs
    printf_len = printf("Test 8: Multiple %%: 100%% %%d\n");
    ft_len = ft_printf("Test 8: Multiple %%: 100%% %%d\n");
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Multiple percent test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Multiple percent test failed\n" RESET);
    }
}

void test_unsigned(int *total_tests, int *passed_tests) {
    int ft_len, printf_len;
    
    // Unsigned tests
    printf_len = printf("Test 9: Unsigned: %u %u %u\n", UINT_MAX, 0, 42);
    ft_len = ft_printf("Test 9: Unsigned: %u %u %u\n", UINT_MAX, 0, 42);
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Unsigned test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Unsigned test failed\n" RESET);
    }
}

void test_mixed(int *total_tests, int *passed_tests) {
    int ft_len, printf_len;
    
    // Mixed format test
    printf_len = printf("Test 10: Mixed: %d %s %c %x %p %%\n", 42, "test", 'Z', 0xABCD, (void *)0x123);
    ft_len = ft_printf("Test 10: Mixed: %d %s %c %x %p %%\n", 42, "test", 'Z', 0xABCD, (void *)0x123);
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Mixed format test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Mixed format test failed\n" RESET);
    }

    // Long string test
    char long_str[1000];
    memset(long_str, 'A', 999);
    long_str[999] = '\0';
    
    printf_len = printf("Test 11: Long string: %s\n", long_str);
    ft_len = ft_printf("Test 11: Long string: %s\n", long_str);
    (*total_tests)++;
    if (printf_len == ft_len) {
        printf(GREEN "✓ Long string test passed\n" RESET);
        (*passed_tests)++;
    } else {
        printf(RED "✗ Long string test failed\n" RESET);
    }
}

int main(void) {
    int total_tests = 0;
    int passed_tests = 0;

    printf(BLUE "\n=== Starting ft_printf tests ===\n\n" RESET);

    test_basic(&total_tests, &passed_tests);
    test_hex_pointer(&total_tests, &passed_tests);
    test_edge_cases(&total_tests, &passed_tests);
    test_unsigned(&total_tests, &passed_tests);
    test_mixed(&total_tests, &passed_tests);

    printf(BLUE "\n=== Test Summary ===\n" RESET);
    printf("Total tests: %d\n", total_tests);
    printf("Passed tests: %d\n", passed_tests);
    printf("Failed tests: %d\n", total_tests - passed_tests);
    printf("Success rate: %.2f%%\n", (float)passed_tests / total_tests * 100);

    return (0);
}
