#include <stddef.h>
#include "slide_line.h"

void slide_left(int *line, size_t size)
{
	size_t i, pos = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (pos > 0 && line[pos - 1] == line[i])
			{
				line[pos - 1] *= 2;
				line[i] = 0;
			}
			else
			{
				if (i != pos)
				{
					line[pos] = line[i];
					line[i] = 0;
				}
				pos++;
			}
		}
	}
}

void slide_right(int *line, size_t size)
{
	int i, pos = (int)size - 1;

	for (i = (int)size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (pos < (int)size - 1 && line[pos + 1] == line[i])
			{
				line[pos + 1] *= 2;
				line[i] = 0;
			}
			else
			{
				if (i != pos)
				{
					line[pos] = line[i];
					line[i] = 0;
				}
				pos--;
			}
		}
	}
}

int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
	}
	else if
	(direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
	}
	else
	{
		return (0);
	}
	return (1);
}
