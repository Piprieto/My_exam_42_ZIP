/*			07_ft_range.txt
			
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int     *ft_range(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.
--------------------------------------------------------------------------------
Escribe la siguiente función:
int *ft_range(int start, int end);
Debe asignar (con malloc()) una matriz de números enteros, llenarla con números consecutivos
valores que comienzan al principio y terminan al final (¡incluidos el inicio y el final!), luego
devuelve un puntero al primer valor de la matriz.

Examples:
- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/


#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int *arr;								//puntero al array de enteros que vamos a devolver
	int sign = 1;							//con sign determinamos si la secuencia es ascendente (+1) o descendente (-1) dependiendo de qué valores se han dado a start y a end: (-1, 5) o (5, -1)
	size_t size;							//variable que contendrá el tamaño del array que vamos a crear
	size_t i = 0;							// i es un contador para recorrer el array según size, como habrá que compararlos tiene que ser del mismo tipo;
	
	if(start > end)							//si la secuencia es descendente (-1)
		sign = -1;
	size = (end - start) * sign  + 1;		//calculamos el tamaño del array. Multiplicando por sign hacemos que siempre sea un valor positivo.
	
	arr = (int*)malloc(sizeof(int) * size);	//Calcula la cantidad total de memoria necesaria para size elementos de tipo int.
	if (! arr)
		return (NULL);						//si malloc no puede asignar memoria devuelve NULL
	while(i < size)							//asignamos cada valor en el arr 
	{
		arr[i] = start + i * sign;
		i++;
	}
	return(arr);
}

int	main(int argc, char **argv)
{
	int start;
	int end;
	int i = 0;
	int size_arr;
	int *arr;
	
	if(argc != 3)							//los valores inicial y final para rellenar el array se pasan como argumentos al programa, así que comprobamos que se hayan indicado correctamente
		return(0);
	start = atoi (argv[1]);					//atoi convierte cadenas de caracteres pasadas como argumento, argv[1] y argv[2], en enteros
	end = atoi (argv[2]);
	arr = ft_range(start, end);				//llamamos a la funcion para rellenar arr
	if (end < start)						//calculamos el tamaño del array
		size_arr = start - end + 1;
	else
		size_arr = end - start + 1;
	while (i < size_arr)					//hacemos un ciclo para mostrar el array
	{
		printf ("%d   ", arr[i]);
		i++;
	}
	free (arr);
	printf("\n");
	return (0);
}
