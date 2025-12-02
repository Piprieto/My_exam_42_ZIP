/*03_fizzbuzz.txt

Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that prints the numbers from 1 to 100, each separated by a
newline.
If the number is a multiple of 4, it prints 'fizz' instead.
If the number is a multiple of 7, it prints 'buzz' instead.
If the number is both a multiple of 4 and a multiple of 7, it prints 'fizzbuzz' instead.
--------------------------------------------------------------------------------
Escribe un programa que imprima los números del 1 al 100, cada uno separado por un
nueva línea.
Si el número es múltiplo de 4, en su lugar imprime 'fizz'.
Si el número es múltiplo de 7, en su lugar imprime 'buzz'.
Si el número es múltiplo de 4 y múltiplo de 7, en su lugar imprime 'fizzbuzz'.

Example:
$>./fizzbuzz
1
2
3
buzz
5
6
fizz
buzz
9
10
11
buzz
13
fizz
15
buzz
17
18
19
buzz
fizz
22
23
buzz
25
26
27
fizzbuzz
29
30
[...]
97
fizz
99
buzz
$> */

#include <unistd.h>

int ft_print_num(int n)
{
	char dig[] = "0123456789";
	
	if (n > 9)
		ft_print_num(n / 10);
	write (1, &dig[n % 10], 1);
	return(0);
}


int main (void)
{
	int i = 1;
	
	while (i <= 100)
	{
		if ((i % 28) == 0)
			write (1, "fizzbuzz", 8);
		else if ((i % 4) == 0)
			write (1, "fizz", 4);
		else if ((i % 7) == 0)
			write (1, "buzz", 4);
		else
			ft_print_num(i);
		i++;
		write(1, "\n", 1);
	}
	return(0);
}
