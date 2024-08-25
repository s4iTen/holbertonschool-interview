#include "menger.h"
#include <stdio.h>
#include <math.h>

void print_char(char c)
{
	putchar(c);
}

void print_level(int level, int i, int j)
{
	while (level > 0)
	{
		if (i % 3 == 1 && j % 3 == 1)
		{
			print_char(' ');
		}
		else
		{
			print_level(level - 1, i / 3, j / 3);
		}
		i /= 3;
		j /= 3;
		level--;
	}
	print_char('#');
}

void menger(int level)
{
	if (level < 0)
	{
		return;
	}

	int size = (int)pow(3, level);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			print_level(level, i, j);
		}
		print_char('\n');
	}
}
