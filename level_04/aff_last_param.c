#include <unistd.h>

int	main(int argc, char **argv)
{
	int i = 0;
	
	if (argc > 1)						//comprobamos que hay, al menos un argumento
	{
		while (argv[argc - 1][i] != '\0')		// argc es el número total de argumentos pasados, así que el índice del último correstonde a (argc - 1)
			write(1, &argv[argc - 1][i++], 1);	//recorremos uno a uno cada elemento de la última cadena pasada como argumento
	}							//escribimos en pantalla carácter a carácter de la última cadena
	write(1, "\n", 1);					//incluímos el d¡salto de línea
	return(0);
}
