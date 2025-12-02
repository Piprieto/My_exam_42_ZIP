/*05_rotone.txt
			
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.
'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
The output will be followed by a \n.
If the number of arguments is not 1, the program displays \n.
-------------------------------------------------- ------------------------------
Escribe un programa que tome una cadena y la muestre, reemplazando cada uno de sus
letras por la siguiente en orden alfabético.
'z' se convierte en 'a' y 'Z' se convierte en 'A'. El caso no se ve afectado.
La salida irá seguida de un \n.
Si el número de argumentos no es 1, el programa muestra \n.

Example:
$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>*/

#include <unistd.h>

int	main (int argc, char **argv)
{
	int i = 0;
	
	if (argc == 2)											//comprobamos que hay un solo argumento
	{
		while (argv[1][i] != '\0')							//recorremos la cadena hasta el indicador de final de cadena
		{
			if((argv[1][i] >= 'A' && argv[1][i] < 'Z') || 	//si el caráter es una letra 
			(argv[1][i] >= 'a' && argv[1][i] < 'z'))
				argv[1][i] = argv[1][i] + 1;				//situamos el índice en la siguiente en orden alfabético
			else if (argv[1][i] == 'Z')						// la z y la Z son casos especiales y da sig en orden alfabético no es la sig en la tabla ascii
				argv[1][i] = 'A';
			else if (argv[1][i] == 'z')
				argv[1][i] = 'a';
			write(1, &argv[1][i++], 1);						//escribimos el carácter correspondiente y pasamos a la siguiente
		}
	}
	write(1, "\n", 1);
	return (0);
}
