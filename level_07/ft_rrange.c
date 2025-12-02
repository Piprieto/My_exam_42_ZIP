/*			07_ft_rrange.txt
			
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int     *ft_rrange(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.
--------------------------------------------------------------------------------
Escribe la siguiente función:
int *ft_rrange(int start, int end);
Debe asignar (con malloc()) una matriz de números enteros, llenarla con números consecutivos
valores que comienzan al final y terminan al inicio (¡incluidos el inicio y el final!), luego
devuelve un puntero al primer valor de la matriz.

Examples:
- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.      */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int *arr;
	size_t size;
	size_t i;
	int sign = 1;
	
	if (end < start)
		sign = -1;
	size = (end - start) * sign + 1;
	arr = (int *)malloc(sizeof(int) * size);
	if(!arr)
		return(NULL);
	i = 0;
	while(i < size)
	{
		arr[i] = end - i * sign;
		i++;
	}
	return(arr);
}

int	main(int argc, char **argv)
{
	int start;
	int end;
	int *arr;
	int arr_size;
	int i = 0;
	
	if (argc != 3)
		return(0);
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	arr = ft_rrange(start, end);
	if (end < start)
		arr_size = start - end + 1;
	else
		arr_size = end - start +  1;
	while(i < arr_size)
	{
		printf("%d   ", arr[i]);
		i++;
	}
	free(arr);
	printf("\n");
	return(0);
}
