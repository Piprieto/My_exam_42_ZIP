/*			02_ft_strlen.txt
			
Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions: 
--------------------------------------------------------------------------------
Write a function that returns the length of a string.
Your function must be declared as follows:
int	ft_strlen(char *str);
--------------------------------------------------------------------------------
Escribe una función que devuelva la longitud de una cadena.
Su función debe declararse de la siguiente manera:
int ft_strlen(char *str);
*/

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	
	while(str[i] != '\0')
		i++;
	return(i);		
}

/* 
//Para probarlo:

int main (void)
{
	int i;
	char str[] = "Hola mundo";
	
	i = ft_strlen(str);
	printf("len = %d \n", i);
	return(0);
}
*/

// El main anterior es equivalente a este:
/*
int main(void)
{
    printf("%d", ft_strlen("Hola Mundo"));
    return (0);
}
*/
