/*			06_inter.txt										
			
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
Escribe un programa que tome dos cadenas y muestre, sin dobles, los
caracteres que aparecen en ambas cadenas, en el orden en que aparecen en la primera.
La pantalla será seguida por un \n.
Si el número de argumentos no es 2, el programa muestra \n.

Examples:
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$*/


#include <unistd.h>

int ft_iter(char *str, int i)			//función para comprobar que un carácter está repetido en una cadena
{			
	int j = 0;
	
	while(j < i) 						//bucle para recorrer la cadena desde la posición 0 hasta la i
	{
		if(str[i] == str[j]) 			//si el carácter se repite devuelve 1
			return(1);
		j++;
	}
	return(0); 							//si el carácter no aparecía antes, devuelve 0
}

int	main(int argc, char **argv)
{	
	int j;
	int i = 0;
	
	if (argc == 3) 													//verificamos que se han pasado dos cadenas para comparar
	{
		while(argv[1][i] != '\0') 									// analizaremos cada carácter de la primera cadena con cada uno de la segunda 
		{			  												//y a su vez con los anteriores de la primera, para que no se repitan.
			j = 0; 													//j recorre la segunda cadena tantas veces como caracteres tenga la primera
			while(argv[2][j] != '\0' && ft_iter(argv[1], i) == 0) 	//si no hemos llegado al final de la segunda cadena
			{														//y si el carácter a comparar de la primera no se ha comparado ya anteriormente
				if (argv[1][i] == argv[2][j])						// si aparece en las dos cadenas lo escribo una vez y salgo
				{
					write(1, &argv[1][i], 1);
					break; 
				}
				else
					j++; 					//aumento el contador de la segunda cadena para comparar con el siguiente carácter 
			}
			i++; 							//aumento el contador en de la primera cadena para comparar el siquiente carácter
		}
	}
	write (1, "\n", 1);
	return(0);
}
