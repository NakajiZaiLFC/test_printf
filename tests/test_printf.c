#include "../include/ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

typedef struct s_test_result
{
	int		total;
	int		passed;
	char	*category;
}			t_test_result;

void	print_test_header(char *category)
{
	printf(BLUE "\n=== Testing %s ===\n" RESET, category);
}

void	check_result(t_test_result *result, int printf_len, int ft_len,
		char *test_name)
{
	result->total++;
	if (printf_len == ft_len)
	{
		printf(GREEN "✓ %s (len: %d)\n" RESET, test_name, ft_len);
		result->passed++;
	}
	else
	{
		printf(RED "✗ %s (printf: %d, ft_printf: %d)\n" RESET, test_name,
			printf_len, ft_len);
	}
}

void	test_strings(t_test_result *result)
{
	char	*null_str;
	char	long_str[1000];

	int p_len, ft_len;
	null_str = NULL;
	print_test_header("String Tests");
	// Basic string
	p_len = printf("Basic string: %s\n", "Hello World");
	ft_len = ft_printf("Basic string: %s\n", "Hello World");
	check_result(result, p_len, ft_len, "Basic string test");
	// Empty string
	p_len = printf("Empty string: '%s'\n", "");
	ft_len = ft_printf("Empty string: '%s'\n", "");
	check_result(result, p_len, ft_len, "Empty string test");
	// NULL string
	p_len = printf("NULL string: %s\n", null_str);
	ft_len = ft_printf("NULL string: %s\n", null_str);
	check_result(result, p_len, ft_len, "NULL string test");
	// Long string
	memset(long_str, 'A', 998);
	long_str[998] = '\n';
	long_str[999] = '\0';
	p_len = printf("Long string: %s", long_str);
	ft_len = ft_printf("Long string: %s", long_str);
	check_result(result, p_len, ft_len, "Long string test");
}

void	test_characters(t_test_result *result)
{
	int p_len, ft_len;
	print_test_header("Character Tests");
	// Basic character
	p_len = printf("Basic char: %c\n", 'a');
	ft_len = ft_printf("Basic char: %c\n", 'a');
	check_result(result, p_len, ft_len, "Basic character test");
	// Special characters
	p_len = printf("Special chars: %c %c %c %c\n", '\n', '\t', ' ', '\0');
	ft_len = ft_printf("Special chars: %c %c %c %c\n", '\n', '\t', ' ', '\0');
	check_result(result, p_len, ft_len, "Special characters test");
	// ASCII limits
	p_len = printf("ASCII limits: %c %c\n", 0, 127);
	ft_len = ft_printf("ASCII limits: %c %c\n", 0, 127);
	check_result(result, p_len, ft_len, "ASCII limits test");
}

void	test_integers(t_test_result *result)
{
	int p_len, ft_len;
	print_test_header("Integer Tests");
	// Basic integers
	p_len = printf("Basic integers: %d %i\n", 42, -42);
	ft_len = ft_printf("Basic integers: %d %i\n", 42, -42);
	check_result(result, p_len, ft_len, "Basic integer test");
	// Zero
	p_len = printf("Zero: %d\n", 0);
	ft_len = ft_printf("Zero: %d\n", 0);
	check_result(result, p_len, ft_len, "Zero test");
	// Limits
	p_len = printf("Integer limits: %d %d\n", INT_MAX, INT_MIN);
	ft_len = ft_printf("Integer limits: %d %d\n", INT_MAX, INT_MIN);
	check_result(result, p_len, ft_len, "Integer limits test");
}

void	test_unsigned(t_test_result *result)
{
	int p_len, ft_len;
	print_test_header("Unsigned Tests");
	// Basic unsigned
	p_len = printf("Basic unsigned: %u\n", 42);
	ft_len = ft_printf("Basic unsigned: %u\n", 42);
	check_result(result, p_len, ft_len, "Basic unsigned test");
	// Zero
	p_len = printf("Unsigned zero: %u\n", 0);
	ft_len = ft_printf("Unsigned zero: %u\n", 0);
	check_result(result, p_len, ft_len, "Unsigned zero test");
	// Maximum
	p_len = printf("Unsigned max: %u\n", UINT_MAX);
	ft_len = ft_printf("Unsigned max: %u\n", UINT_MAX);
	check_result(result, p_len, ft_len, "Unsigned maximum test");
}

void	test_hex(t_test_result *result)
{
	int p_len, ft_len;
	print_test_header("Hexadecimal Tests");
	// Basic hex
	p_len = printf("Basic hex: %x %X\n", 0xabc, 0xABC);
	ft_len = ft_printf("Basic hex: %x %X\n", 0xabc, 0xABC);
	check_result(result, p_len, ft_len, "Basic hexadecimal test");
	// Zero
	p_len = printf("Hex zero: %x %X\n", 0, 0);
	ft_len = ft_printf("Hex zero: %x %X\n", 0, 0);
	check_result(result, p_len, ft_len, "Hexadecimal zero test");
	// Maximum
	p_len = printf("Hex max: %x %X\n", UINT_MAX, UINT_MAX);
	ft_len = ft_printf("Hex max: %x %X\n", UINT_MAX, UINT_MAX);
	check_result(result, p_len, ft_len, "Hexadecimal maximum test");
}

void	test_pointers(t_test_result *result)
{
	void	*ptr;
	int		stack_var;

	int p_len, ft_len;
	ptr = (void *)0x12345678;
	print_test_header("Pointer Tests");
	// Basic pointer
	p_len = printf("Basic pointer: %p\n", ptr);
	ft_len = ft_printf("Basic pointer: %p\n", ptr);
	check_result(result, p_len, ft_len, "Basic pointer test");
	// NULL pointer
	p_len = printf("NULL pointer: %p\n", NULL);
	ft_len = ft_printf("NULL pointer: %p\n", NULL);
	check_result(result, p_len, ft_len, "NULL pointer test");
	// Stack address
	stack_var = 42;
	p_len = printf("Stack pointer: %p\n", (void *)&stack_var);
	ft_len = ft_printf("Stack pointer: %p\n", (void *)&stack_var);
	check_result(result, p_len, ft_len, "Stack pointer test");
}

void	test_percent(t_test_result *result)
{
	int p_len, ft_len;
	print_test_header("Percent Sign Tests");
	// Single percent
	p_len = printf("Single percent: %%\n");
	ft_len = ft_printf("Single percent: %%\n");
	check_result(result, p_len, ft_len, "Single percent test");
	// Multiple percent
	p_len = printf("Multiple percent: %% %% %%\n");
	ft_len = ft_printf("Multiple percent: %% %% %%\n");
	check_result(result, p_len, ft_len, "Multiple percent test");
	// Percent with other specifiers
	p_len = printf("Mixed percent: %% %d %%\n", 42);
	ft_len = ft_printf("Mixed percent: %% %d %%\n", 42);
	check_result(result, p_len, ft_len, "Mixed percent test");
}

void	test_mixed(t_test_result *result)
{
	int p_len, ft_len;
	print_test_header("Mixed Format Tests");
	// Complex format string
	p_len = printf("Mixed 1: %d %s %c %x %p %%\n", 42, "test", 'Z', 0xABCD,
			(void *)0x123);
	ft_len = ft_printf("Mixed 1: %d %s %c %x %p %%\n", 42, "test", 'Z', 0xABCD,
			(void *)0x123);
	check_result(result, p_len, ft_len, "Complex format test");
	// Multiple same specifier
	p_len = printf("Mixed 2: %d %d %d\n", INT_MIN, 0, INT_MAX);
	ft_len = ft_printf("Mixed 2: %d %d %d\n", INT_MIN, 0, INT_MAX);
	check_result(result, p_len, ft_len, "Multiple same specifier test");
	// All types
	p_len = printf("Mixed 3: %c %s %p %d %i %u %x %X %%\n", 'A', "str",
			(void *)0x123, -42, 42, 42, 42, 42);
	ft_len = ft_printf("Mixed 3: %c %s %p %d %i %u %x %X %%\n", 'A', "str",
			(void *)0x123, -42, 42, 42, 42, 42);
	check_result(result, p_len, ft_len, "All types test");
}

void	print_summary(t_test_result *results, int count)
{
	int		total_tests;
	int		total_passed;
	float	success_rate;

	total_tests = 0;
	total_passed = 0;
	printf(BLUE "\n=== Test Summary ===\n" RESET);
	for (int i = 0; i < count; i++)
	{
		printf("%s: %d/%d (%.1f%%)\n", results[i].category, results[i].passed,
			results[i].total, (float)results[i].passed / results[i].total
			* 100);
		total_tests += results[i].total;
		total_passed += results[i].passed;
	}
	printf(BLUE "\n=== Final Results ===\n" RESET);
	printf("Total tests: %d\n", total_tests);
	printf("Passed tests: %d\n", total_passed);
	printf("Failed tests: %d\n", total_tests - total_passed);
	success_rate = (float)total_passed / total_tests * 100;
	if (success_rate == 100.0)
	{
		printf(GREEN "Success rate: %.1f%%\n" RESET, success_rate);
	}
	else if (success_rate >= 80.0)
	{
		printf(YELLOW "Success rate: %.1f%%\n" RESET, success_rate);
	}
	else
	{
		printf(RED "Success rate: %.1f%%\n" RESET, success_rate);
	}
}

int	main(void)
{
	t_test_result results[] = {{0, 0, "Strings"}, {0, 0, "Characters"}, {0, 0,
		"Integers"}, {0, 0, "Unsigned"}, {0, 0, "Hexadecimal"}, {0, 0,
		"Pointers"}, {0, 0, "Percent Signs"}, {0, 0, "Mixed Formats"}};

	printf(BLUE "\n=== Starting ft_printf tests ===\n" RESET);

	test_strings(&results[0]);
	test_characters(&results[1]);
	test_integers(&results[2]);
	test_unsigned(&results[3]);
	test_hex(&results[4]);
	test_pointers(&results[5]);
	test_percent(&results[6]);
	test_mixed(&results[7]);

	print_summary(results, sizeof(results) / sizeof(results[0]));

	return (0);
}
