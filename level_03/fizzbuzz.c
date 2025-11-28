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
