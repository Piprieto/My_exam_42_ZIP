#include <unistd.h>

int	main (int argc, char **argv)						//según la tabla ASCII entre la A(65) y la Z(90) hay 25 posiciones así que 13 es el punto medio, que corresponde a la M(77)
{										//en la primera mitad de A a M sumamos 13 posiciones para cambiar la letra y en la segunda mitad restamos 13 para cambiarla
	int i = 0;
	
	if(argc == 2)								//comprobamos que se pasa un solo argumento
	{
		while (argv[1][i] != '\0')					//recorremos la cadena hasta el indicador de final
		{
			if ((argv[1][i] >= 'A' && argv[1][i] <= 'M') || 	//Si el carácter está en la primera mitad, mayus o minusc
			(argv[1][i] >= 'a' && argv[1][i] <= 'm'))
				argv[1][i] = argv[1][i] + 13;			// sumamos 13 posiciones para escribir el nuevo carácter
			else if((argv[1][i] >= 'N' && argv[1][i] <= 'Z') || 	//Si el carácter está en la segunda mitad, mayus o minusc
			(argv[1][i] >= 'n' && argv[1][i] <= 'z'))
				argv[1][i] = argv[1][i] - 13;			//restamos 13
			write (1, &argv[1][i], 1);				//si no es una letra (números, comas, espacios,...) escribimos el carácter tal cual
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
