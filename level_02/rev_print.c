/*02_rev_print.txt			
			
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays the string in reverse
followed by a newline.
If the number of parameters is not 1, the program displays a newline.
-------------------------------------------------- ------------------------------
Escribe un programa que tome una cadena y la muestre al revés
seguido de una nueva línea.
Si el número de parámetros no es 1, el programa muestra una nueva línea.

Examples:
$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$*/


# include <unistd.h>

int ft_strlen (char *str)		//función para calcular la longitud de una cadena
{
	int i = 0;
	
	while (str[i] != '\0')		//recorremos la cadena hasta llegar al indicador de final
		i++;					//incrementamos el contador con cada posición
	return (i - 1);				//devolvemos el contador sin el cierre
}

int main (int argc, char **argv)	
{
	int i = 0;
	
	if (argc == 2)						//si el núm de argumentos es 2
	{
		i = ft_strlen (argv[1]);		//calculamos la long de la cadena
		while (i >= 0)					//recorremos la cadena desde el final
			write(1, &argv[1][i--], 1);	//escribimos cada elemento
	}
	write(1, "\n", 1);					//escribimos final salto de linea
	return(0);
}
