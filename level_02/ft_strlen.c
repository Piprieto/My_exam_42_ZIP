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
int main (void)
{
	int i;
	char str[] = "Hola mundo";
	
	i = ft_strlen(str);
	printf("len = %d \n", i);
	return(0);
}
*/
/* El main anterior es equivalente a este:
int main(void)
{
    printf("%d", ft_strlen("Hola Mundo"));
    return (0);
} */
