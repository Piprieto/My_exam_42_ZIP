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

			01_aff_z.txt

Assignment name  : aff_z
Expected files   : aff_z.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays the first 'z'
character it encounters in it, followed by a newline. If there are no
'z' characters in the string, the program writes 'z' followed
by a newline. If the number of parameters is not 1, the program displays
'z' followed by a newline.
--------------------------------------------------------------------------------
Escribe un programa que tome una cadena y muestre la primera 'z'
carácter que encuentra en él, seguido de una nueva línea. si no hay
caracteres 'z' en la cadena, el programa escribe 'z' seguido
por una nueva línea. Si el número de parámetros no es 1, el programa muestra
'z' seguida de una nueva línea.

Example:
$> ./aff_z "abc" | cat -e
z$
$> ./aff_z "dubO a POIL" | cat -e
z$
$> ./aff_z "zaz sent le poney" | cat -e
z$
$> ./aff_z | cat -e
z$
*/

#include <unistd.h>

int	main(void)
{
	write (1, "z\n", 2);
	return (0);
} 
