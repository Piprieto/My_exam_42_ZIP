/*05_first_word.txt
		
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays its first word, followed by a
newline.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or if there are no words, simply display
a newline.
--------------------------------------------------------------------------------
Escribe un programa que tome una cadena y muestre su primera palabra, seguida 
de una nueva línea.
Una palabra es una sección de cadena delimitada por espacios/tabulaciones o 
por el inicio/final de la cuerda.
Si el número de parámetros no es 1, o si no hay palabras, simplemente muestre
una nueva línea.

Examples:
$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/

#include <unistd.h>

int	ft_type_char(char c)				//función para seleccionar el tipo de cada carácter de una cadena
{
	if ((c >= 9 && c <=13) || c == 32)	//espacios (0)
		return(0);
	else if (c >= 33 && c <= 126)		//letras o caracteres imprimibles (1)
		return (1);
	else 
		return (2);						//resto (2)
}

int	main(int argc, char **argv)
{
	int i = 0;
	
	if (argc == 2)													//comprobamos que se ha pasado 1 argumento
	{
		while (argv[1][i] != '\0' && ft_type_char(argv[1][i]) == 0)	//mientras no llegue al final de la cadena y si son espacios o tabulaciones aumentamos el contador para comprobar el siguiente carácter
			i ++;
		while (argv[1][i] != '\0' && ft_type_char(argv[1][i]) == 1)	//si es un carácter imprimible lo escribimos en pantalla hasta que llegue a un hueco o final de la cadena
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return(0);
}
