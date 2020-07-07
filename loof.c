#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;

	while (i < 5)
	{
			while (j < 5)
			{
				if (j >= i)
					printf("*");
				else
					printf(" ");
				j++;
			}
	printf("\n");
	i++;
	j = 0;
	}
return 0;
}
