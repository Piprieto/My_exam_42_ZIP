#include<stdlib.h>
#include<stdio.h>

int	ft_type_char(char c)
{
	if (((c >= 9) && (c <= 13)) || c == 32)			
		return (0);
	else if ((c >= 33) && (c <= 126))
		return(1);
	else
		return(2);
}

int	ft_num_words(char *str)
{
	int	i = 0;
	int	n = 0;
	
	while(str[i] != '\0')
	{
		while(ft_type_char(str[i]) == 0)
			i++;
		if(ft_type_char(str[i]) == 1)
			n++;
		while(ft_type_char(str[i]) == 1)
			i++;
	}
	return(n);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i = 0;
	
	while(i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

char	**ft_split(char *str)
{
	char	**split;
	int	i = 0;
	int	j = 0;
	int	word;
	int	size;
	
	size=ft_num_words(str);
	split=(char**)malloc(sizeof(char*) * (size + 1));
	if(!split)
		return(NULL);
	while(str[i] != '\0')
	{
		while(str[i] != '\0' && ft_type_char(str[i]) == 0)
			i++;
		word = i;
		while(str[i] != '\0' && ft_type_char(str[i]) == 1)
			i++;
		if(word != i)
		{
			split[j]=(char*)malloc(sizeof(char) * (i - word +1));
			if(!split[j])
			{
				while (j > 0)
				{
					free(split[j]);
					j--;
				}
				free(split);
				return(NULL);
			}
			ft_strncpy(split[j], &str[word], (i - word));
			split[j][i - word] = '\0';
			j++;
		}
		
	}
	split[j] = NULL;
	return(split);	
}

int main()
{
	char	**split;
	int	i = 0;
	
	split = ft_split("  Una palabra en cada linea   .");
	if(!split)
	{
		printf("Error\n");
		return(1);
	}
	while(split[i])
	{
		printf("Linea [%d]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return(0);
}
