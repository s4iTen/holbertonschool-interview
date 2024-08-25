#include <stdio.h>
#include <math.h>

void menger(int level)
{
	if (level < 0)
		return;

	int size = pow(3, level);

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			int draw = 1;

			int x_temp = x;
			int y_temp = y;


			while (x_temp > 0 || y_temp > 0)
			{
				if (x_temp % 3 == 1 && y_temp % 3 == 1)
				{
					draw = 0;
					break;
				}
				x_temp /= 3;
				y_temp /= 3;
			}

			if (draw)
				printf("#");
			else
				printf(" ");
		}
		printf("\n");
	}
}
