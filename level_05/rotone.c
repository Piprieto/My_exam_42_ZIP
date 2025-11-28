#include <unistd.h>

int	main (int argc, char **argv)
{
	int i = 0;
	
	if (argc == 2)								//comprobamos que hay un solo argumento
	{
		while (argv[1][i] != '\0')					//recorremos la cadena hasta el indicador de final de cadena
		{
			if((argv[1][i] >= 'A' && argv[1][i] < 'Z') || 		//si el caráter es una letra 
			(argv[1][i] >= 'a' && argv[1][i] < 'z'))
				argv[1][i] = argv[1][i] + 1;			//situamos el índice en la siguiente en orden alfabético
			else if (argv[1][i] == 'Z')				// la z y la Z son casos especiales y da sig en orden alfabético no es la sig en la tabla ascii
				argv[1][i] = 'A';
			else if (argv[1][i] == 'z')
				argv[1][i] = 'a';
			write(1, &argv[1][i++], 1);				//escribimos el carácter correspondiente y pasamos a la siguiente
		}
	}
	write(1, "\n", 1);
	return (0);
}
