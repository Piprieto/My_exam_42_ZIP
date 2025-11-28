# include <unistd.h>

int ft_strlen (char *str)		//función para calcular la longitud de una cadena
{
	int i = 0;
	
	while (str[i] != '\0')		//recorremos la cadena hasta llegar al indicador de final
		i++;			//incrementamos el contador con cada posición
	return (i - 1);			//devolvemos el contador sin el cierre
}

int main (int argc, char **argv)	
{
	int i = 0;
	
	if (argc == 2)					//si el núm de argumentos es 2
	{
		i = ft_strlen (argv[1]);		//calculamos la long de la cadena
		while (i >= 0)				//recorremos la cadena desde el final
			write(1, &argv[1][i--], 1);	//escribimos cada elemento
	}
	write(1, "\n", 1);				//escribimos final salto de linea
	return(0);
}
