#include "palindrome.h"

/**
 * getbeg - finds number number needed to index first digit of n
 * @n: number to check
 *
 * Return: beginning index
 */
unsigned long getbeg(unsigned long n)
{
	unsigned long beg = 1;

	do
		beg *= 10;
	while (n /= 10);
	return (beg / 10);
}
