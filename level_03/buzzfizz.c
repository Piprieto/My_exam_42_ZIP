#include <unistd.h>

int ft_print_num (int n)		//función recursiva que pasa un int a un char para poder escribirlo en pantalla
{
	char dig[] = "0123456789";
	
	if (n > 9)			//si el número tiene más de un dígito
		ft_print_num (n / 10);	//lo divido y llamo recursivamente a la función para quedarme con el díg de la izda. Ejem: 36/10 = 3,6 me quedo con el 3 y ya es < 9
	write (1, &dig[n % 10], 1);	//cuando ya es sólo un número al hacer n%10 obtengo el resto, es decir el num de la decha 3%10=0,3 así que escibo en pantalla 3 
	return(0);
}

/*Ejemplo de la func anterior par aun número de tres dígitos: ft_print_num(123)

Paso 01 123 mayor de 9 lo divido entre 10 --> 12,3 y llamo de nuevo a la función luego continuara con n = 123.
Paso 02 12 (12,3 en int es 12) mayor de 9 lo divido entre 10 --> 1,2 y llamo de nuevo a la función luego continuara con n = 12.
Paso 03 1 (1,2 en int es 1) menor de 9 -- > write(1, &dig[1 % 10], 1) el resto de la división es "1".

La función regresa a la llamada anterior (con n = 12) --> write(1, &dig[12 % 10], 1) el resto de la división es "2".

La función regresa a la llamada anterior (con n = 123) --> write(1, &dig[123 % 10], 1) el resto de la división es "3".
*/

int main (void)
{
	int i = 1;
	
	while (i <= 100)				//para escribir números del 1 al 100
	{
		if ((i % 15) == 0)			//si es múltiplo de 15
			write (1, "buzzfizz", 8);	//escribo buzzfizz
		else if ((i % 5) == 0)			//si múltiplo de 5
			write (1, "buzz", 4);		//escribo buzz
		else if ((i % 3) == 0)			//si múltiplo de 3
			write (1 ,"fizz", 4);		//escribo fizz
		else					//si no, lla mo a la función que pasa de un int a un char para escribir dígito a dígito el número correspondiente.
			ft_print_num (i);
		i++;
		write (1, "\n", 1);
	}
	return(0);
}
