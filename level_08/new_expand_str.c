/*				08_expand_str.txt
				
Escribe un programa que tome una cadena y la muestre exactamente con tres espacios.
entre cada palabra, sin espacios ni tabulaciones ni al principio ni al final,
seguido de una nueva línea.
Una palabra es una sección de cadena delimitada por espacios/tabulaciones o por el
inicio/final de la cadena.
Si el número de parámetros no es 1, o si no hay palabras, simplemente muestre
una nueva línea.

Examples:
$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>*/

#include<unistd.h>
#include<stdio.h>

int	ft_type_char(char c)
{
	if((c >= 9 && c <= 13) || c == 32)
		return(0);
	if(c >= 33 && c <= 126)
		return(1);
	else
	return(2);		
}

int	main(int argc, char **argv)
{
	int	i = 0;
	int	n = 0;
	
	if(argc == 2)
	{
		while(argv[1][i] != '\0')
		{
			while(argv[1][i] != '\0' && ft_type_char(argv[1][i]) == 0)
				i++;
			printf("Primer caracter en: %d \n", i);
			if((ft_type_char(argv[1][i]) == 1) && n > 0)
				write(1, "   ", 3);
			while(argv[1][i] != '\0' && ft_type_char(argv[1][i]) == 1)
			{
				write(1, &argv[1][i], 1);
				i++;
				n++;
			}
		}
	
	}
	write(1, "\n", 1);
	return(0);
}
