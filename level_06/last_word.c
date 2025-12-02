/* 06_last_word.txt		
			

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays its last word followed by a \n.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or there are no words, display a newline.
--------------------------------------------------------------------------------
Escribe un programa que tome una cadena y muestre su última palabra seguida 
de \n.
Una palabra es una sección de cadena delimitada por espacios/tabulaciones o 
por el inicio/final de la cadena.
Si el número de parámetros no es 1 o no hay palabras, muestre una nueva línea.

Example:
$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>
#include<stdio.h>

		int	ft_strlen(char *str) 			//función para obtener la longitud de un string
{
	int i = 0;
	
	while(str[i] != '\0') 					//recorremos caracter a caracter y aumentamos el contador 
		i++;
	return (i - 1); 						//devolvemos la longitud sin el final de string.El número de posiciones totales
}

int ft_type_char(char c)  					//funcion que nos da de qué tipo es un caracter
{
	if ((c >= 9 && c <= 13) || (c == 32))   //Si "c" es igual a cualquier espacio ascii: (9) '\t',
											// (10) '\n', (11) '\v,  (12) '\f', (13) '\r'
											// O si "c" es un espacio (32)  ' '
		return (0);
	else if (c >= 33 && c <= 126)
		return (1);
	else
		return(2);
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	
	if (argc == 2)												// si el número de argumentos es 2
	{
		i = ft_strlen(argv[1]);									// calculamos la longitud total para situarnos al final del string
		while (i >= 0 && (ft_type_char(argv[1][i]) == 0))		// recorremos hacia atrás el string para ver dónde termina la úlima palabra, evitando espacios, tabuladores...
			i--;							
		j = i;													// así tendremos en j el índice donde termina la última palabra.
		while (i >= 0 && (ft_type_char(argv[1][i]) == 1))		// recorremos hacia atrás la palabra para obtener dónde comienza.	
				i--;											//Cuando evalua la primera letra de la palabra entra en el while y también resta uno a i
		i++;													//así que hay que hacer esta corrección para que i sea el índice donde comienza la palabra
		while (i <= j)											// empezando en i y hasta j escribimos la palabra
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
