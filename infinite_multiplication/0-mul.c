#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * print_error - Prints error message
 */
void print_error(void)
{
	char *error = "Error\n";
	while (*error)
		_putchar(*error++);
	exit(98);
}

/**
 * is_digit - Checks if the character is a digit
 * @c: The character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;
	while (*s++)
		len++;
	return (len);
}

/**
 * multiply - numbers
 * @num1: number
 * @num2: number
 */
void multiply(char *num1, char *num2)
{
    int len1 = _strlen(num1);
    int len2 = _strlen(num2);
    int *result = calloc(len1 + len2, sizeof(int));
    int i, j, carry, n1, n2, sum;

    if (!result)
        exit(98);

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i + j + 1] += carry;
    }

    // Skip leading zeros
    i = 0;
    while (i < len1 + len2 && result[i] == 0)
        i++;

    if (i == len1 + len2)
        _putchar('0');
    else
    {
        for (; i < len1 + len2; i++)
            _putchar(result[i] + '0');
    }
    _putchar('\n');
    free(result);
}


/**
 * main - Entry point numbers
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int i;

	if (argc != 3)
		print_error();

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; num1[i]; i++)
	{
		if (!is_digit(num1[i]))
			print_error();
	}

	for (i = 0; num2[i]; i++)
	{
		if (!is_digit(num2[i]))
			print_error();
	}

	multiply(num1, num2);

	return (0);
}
