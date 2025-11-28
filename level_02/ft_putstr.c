#include <unistd.h>

void ft_putstr(char *str)  
{
	int i;
	
	i = 0;
	while(str[i] != '\0')		//recorremos el string hasta encontrasr el indicador de final '\0'
		write(1, &str[i++], 1); //escribimos en pantalla cada elemento y aumentamos el contador para pasar al siguiente
}

int main (void)
{
	char str[] = "Hola mundo\n";
	
	ft_putstr(str);
	return (0);
}
