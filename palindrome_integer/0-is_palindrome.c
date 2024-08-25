#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - Check if an unsigned long integer is a palindrome.
 * @n: The unsigned long integer to be checked.
 *
 * Return: 1 if n is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
    unsigned long reverse = 0;
    unsigned long original = n;

    while (n != 0)
    {
        reverse = reverse * 10 + n % 10;
        n = n / 10;
    }

    return (original == reverse) ? 1 : 0;
}
