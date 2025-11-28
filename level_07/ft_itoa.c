#include <stdlib.h>
#include <stdio.h>

/*			07_ft_itoa.txt		
			
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.
Your function must be declared as follows:
char	*ft_itoa(int nbr);
--------------------------------------------------------------------------------
Escribe una función que tome un int y lo convierta en una cadena terminada en nulo.
La función devuelve el resultado en una matriz de caracteres que debes asignar.
Su función debe declararse de la siguiente manera:
char *ft_itoa(int nbr);
*/

/* 
Queremos convertir un int en una cadena de char. Un int son 64 bytes (32 bits) así que permite almacenar valores entre -2147483648 y 2147483647. Si le damos a la func como argumento un número mayor dará error y los dos números límites tampoco saldrán correctamente pq hay que tratarlos diferente. Así que aunque el arg de la función que nos piden es int, lo cambiaremos a long int permitiendo almacenar valores mucho mayores.
Para obtener el número max INT en la terminal:
un "int" esta formado por 32 bits
Positivos y negativos (enteros con signo): del -2147483648 al 2147483647

En un terminal ejecuta "bc"  (Basic Calculator)
pones 2 ^ 31 y obtienes 2147483648
para salir "quit"
*/

int ft_nbrlen(long int nbr)      // Función para contar los digitos del número y el signo en caso de negativo
{
	int i = 0;
	
	if (nbr == 0)
		i = 1;
	if (nbr < 0)			// Si el número es menor de 0 (negativo)
	{
		i++;			// Cuento uno por el signo negativo
		nbr = nbr * (-1);	// convierto el número en positivo
	}
	while (nbr > 0)			// Recorro el número mientras sea mayor que 0
	{
		i++;			// Cuento el digito
		nbr = nbr / 10;		// Divido el número entre 10 (me muevo entre unidades, decenas, centenas...)
	}
	return(i);			// Devuelvo el número de digitos incluyendo el signo en caso de negativo
}

char	*ft_itoa(int nbr)			
{
	char	*str;					//string donde guardaremos los caracteres de nbr
	int	len;	
	char	*digits = "0123456789";
	long int n;
	
	n = (long int)nbr;				//pasamos nbr de int a long int 
	len = ft_nbrlen(n);				//calculamos el número de dígitos de nbr
	str = (char*)malloc(sizeof(char) * (len + 1));	//asignamos espacio para cada carácter y también para el cierre de string '/0'
	if(!str)					//protejo el malloc
		return(NULL);	
	str[len] = '\0';				//colocamos el cierre del string
	if(n == 0)
		str[--len] = '0';
	if (n < 0)					//si el número es negativo 
	{
		str[0] = '-';				//colocamos el signo
		n = n * (-1);			//hacemos que sea positivo
	}
	while (n > 0)
	{
		len --;				//nos colocamos en la posición anterior
		str[len] = digits[n % 10];	//asigno el digito obtenido del resto de la división entre 10.
        	n = n / 10;			// Divido el número entre 10 (me muevo entre unidades, decenas, centenas...)
	}
	return(str);
	
}

int	main(int argc, char **argv)
{	
	char	*str;

	if (argc != 2)
		return (0);
	str = ft_itoa(atoi(argv[1]));
	printf ("%s\n", str);
	free (str);
	return (0);
}
