/*			01_aff_a.txt

Assignment name  : aff_a
Expected files   : aff_a.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays the first 'a' 
character it encounters in it, followed by a newline. If there are no 
'a' characters in the string, the program just writes a newline. 
If the number of parameters is not 1, the program displays 'a' 
followed by a newline.
--------------------------------------------------------------------------------
Escribe un programa que tome una cadena y muestre la primera 'a'
carácter que encuentra en él, seguido de una nueva línea. si no hay
caracteres 'a' en la cadena, el programa simplemente escribe una nueva línea.
Si el número de parámetros no es 1, el programa muestra 'a'
seguido de una nueva línea.

Example:
$> ./aff_a "abc" | cat -e
a$
$> ./aff_a "dubO a POIL" | cat -e
a$
$> ./aff_a "zz sent le poney" | cat -e
$
$> ./aff_a | cat -e
a$
*/


#include <unistd.h>
	
int	main(int argc, char **argv)
{
	int i;
	
	i = 0;
	if (argc != 2)			//si el número de parámetros introducido no es 1
		write(1, "a", 1);	// muestra una a
	else
	{
		while (argv[1][i] != '\0') 		// recorremos la cadena 
		{
			if (argv[1][i] == 'a')		// si encuentra una a 
			{
			 	write(1, "a", 1);	// la escribe y hacemos que salga
			 	break;			// del while porque con que haya una es suf
			}
			i++;				// aumentamos el contador para evaluar la siguiente posición y buscar la a
		}
	}
	write(1, "\n", 1);				// escribimos salto de linea y termina
	return(0);
}
