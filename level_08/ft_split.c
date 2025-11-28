/*		08_ft_split.txt

Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.
A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.
Your function must be declared as follows:
char    **ft_split(char *str);
--------------------------------------------------------------------------------
Escribe una función que tome una cadena, la divida en palabras y las devuelva como
una matriz de cadenas terminada en NULL.
Una "palabra" se define como parte de una cadena delimitada por espacios/tabulaciones/nueva
líneas, o por el inicio/final de la cadena.
Su función debe declararse de la siguiente manera:
char **ft_split(char *str);*/



#include <stdlib.h>
#include <stdio.h>

int	ft_type_char(char c)					//funcion para diferenciar mediante sus valores ASCII caracteres imprimibles o espacios
{
	if (((c >= 9) && (c <= 13)) || c == 32)			//si es algún tabulador o SPACE devuelve 0
		return (0);
	else if ((c >= 33) && (c <= 126))			//si es un carácter imprimible devuelve 1
		return(1);
	else
		return(2);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)	//desde man strncpy
{								//func para copiar n caracteres de scr en dest
	size_t	i = 0;
	
	while(i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

int	ft_nwords(char *str)
{
	int 	i = 0;					//contador para recorrer str
	int	n = 0;					//en n el número de ppalabras
	
	while (str[i] != '\0')  			//recorremos todo el str
	{
		while (ft_type_char(str[i]) == 0)	//pasamos los espacios que pueda haber al principio
			i++;
		if(ft_type_char(str[i]) == 1)		//cuando encuentra el primer carácter printable aumenta el contador n
			n++;
		while (ft_type_char(str[i]) == 1)	//llegamos al final de la primera palabra y repetimos el ciclo
			i++;
	}
	return(n);
}

char	**ft_split(char *str)
{
	char	**split;
	int 	i = 0;								//contador para recorrer str y buscar las diferentes palabras
	int	j = 0;								//contador para recorrer split
	int	word;
	
	split = (char**)malloc(sizeof(char*) * (ft_nwords(str) + 1));		//reservamos memoria, un array en el que cada elemento el una palabra, es decir, otro array
	if (!split)								//protejemos el malloc
		return(NULL);
	while(str[i] != '\0')							//recorremos str para buscar cada palabra
	{
		while((str[i] != '\0') && ft_type_char(str[i]) == 0)		//por si hay espacios al principio
			i++;
		word = i;							//en word guardamos el índice donde comienza la palabra
		while((str[i] != '\0') && ft_type_char(str[i]) == 1)		//buscamos el índice donde termina la palabra, en i
			i++;
		if(word != i)							//si inicio de palabra es dif al comienzo
		{
			split[j] = (char*)malloc(sizeof(char) * ((i - word) + 1));		//reservo memoria en cada elemento de split del tamaño de la palabra que voy a guardar: tamaño de la palabra (i - wor) y hacemos +1 para incluir el fin de cadena '\0'
			if (!split[j])                                                      	// Verifico si malloc falló
            		{
                		while (j > 0)                                                   // Libero la memoria en caso de fallo
                	    		free(split[--j]);
                		free(split);
                		return (NULL);
            		}
			ft_strncpy(split[j], &str[word], (i - word));
			split[j][i - word] = '\0';					//nos aseguramos que se incluye el fin de linea
			j++; 
		}
	}
	split[j] = NULL;				//split es un array de punteros a char* así que termina en NULL, no un array de char que terminaría en '\0' 
	return (split);
}

int main(void)
{	
	int	i = 0;
	char	**split;

	split = ft_split("   Cada palabra una linea   ");
	if (!split)
	{
	        printf("Error en la asignación de memoria\n");
	        return (1);
	}
	while (split[i])
	{
        	printf("Palabra [%d]: %s\n", i, split[i]);
        	free(split[i]);  // Liberar memoria de cada palabra
        	i++;
        }
	free(split);  // Liberar el array principal
	return (0);
}
