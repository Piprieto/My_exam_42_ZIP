#include <unistd.h>

int	main(void)	// un programa que siempre escriba una z seguida de salto de linea
{
	write (1, "z\n", 2);
	return (0);
} 
