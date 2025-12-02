
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
