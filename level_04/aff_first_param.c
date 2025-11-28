#include <unistd.h>

int	main(int argc, char **argv)			
{
	int i = 0;
	
	if (argc > 1)					//comprobamos que hay, al menos un argumento
	{
		while(argv[1][i] != '\0')		// recorremos el primer argumento hasta encontrar el indicador de final de cadena
			write(1, &argv[1][i++], 1);	//escribimos en pantalla caracter a caracter
							// aumentamos el contador
	}
	write(1, "\n", 1);				//mostramos cambio de linea
	return(0);
}
