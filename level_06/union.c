/*			06_union.txt
			
			
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
--------------------------------------------------------------------------------
Escribe un programa que tome dos cadenas y muestre, sin dobles, el
caracteres que aparecen en cualquiera de las cadenas.
La pantalla se mostrará en el orden en que aparecen los caracteres en la línea 
de comando y irá seguido de un \n.
Si el número de argumentos no es 2, el programa muestra \n.

Example:
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>*/

#include <unistd.h>

int	ft_iter(char *str, int i)		//función para comprobar si un carácter se repite previamente en una cadena
{
	int j = 0;
	
	while(j < i) 					//bucle para recorrer la cadena desde la posición 0 hasta la i
	{
		if(str[i] == str[j]) 		//si el carácter se repite devuelve 1
			return(1);
		j++;
	}
	return(0); 						//si el carácter no aparecía antes, devuelve 0
}

int	ft_strchr(char *str, char c) 	//func para comprobar si un carácter c aparece en una cadena
{
	int i = 0;
	
	while(str[i] != '\0')
	{
		if(str[i] == c)
			return (1);				// si aparece devuelve 1
		else
			i++;
	}
	return (0); 					//si c no aparece en la cadena devuelve 0
}

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	
	if(argc == 3)							//verificamos que se han pasado dos cadenas para comparar
	{
		while(argv[1][i] != '\0')			//analizaremos cada caracter de la primera
		{
			if(ft_iter(argv[1], i) == 0)	//escribimos todos los caracteres de la primera cad eliminando los repetidos.
				write(1, &argv[1][i], 1); 
			i++;
		}
		while(argv[2][j] != '\0')			//recorremos la segunda cadena
		{
			if(ft_strchr(argv[1], argv[2][j]) == 1 || (ft_iter(argv[2], j) == 1))		//si el caracter a comparar estaba ya en la primera 
				j++;																	//o se repite en la segunda, seguimos con el siguiente
			else																		//si no, lo escribimos y pasamos al siguiente	
			{
				write(1, &argv[2][j], 1);
				j++;
			}
		}
	}
	write(1, "\n", 1);
	return(0);
}


