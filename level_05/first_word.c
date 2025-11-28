#include <unistd.h>

int	ft_type_char(char c)			//función para seleccionar el tipo de cada carácter de una cadena
{
	if ((c >= 9 && c <=13) || c == 32)	//espacios (0)
		return(0);
	else if (c >= 33 && c <= 126)		//letras o caracteres imprimibles (1)
		return (1);
	else 
		return (2);			//resto (2)
}

int	main(int argc, char **argv)
{
	int i = 0;
	
	if (argc == 2)								//comprobamos que se ha pasado 1 argumento
	{
		while (argv[1][i] != '\0' && ft_type_char(argv[1][i]) == 0)	//mientras no llegue al final de la cadena y si son espacios o tabulaciones aumentamos el contador para comprobar el siguiente carácter
			i ++;
		while (argv[1][i] != '\0' && ft_type_char(argv[1][i]) == 1)	//si es un carácter imprimible lo escribimos en pantalla hasta que llegue a un hueco o final de la cadena
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return(0);
}
