#include <stdio.h>

/**
 * factorial - Calculates factorial of a number
 * @num: number to compute the factorial of
 *
 * Description: takes an integer and computes its factorial
 * recursively
 * Return: The factorial of the number.
 */
int factorial(int num)
{
	if (num <= 1)
		return (1);
	else
		return (num * factorial(num - 1));
}

/**
 * main - Entry point of the program.
 *
 * Description: This function calls the factorial function and displays the
 * result. It serves as the starting point for program execution.
 * Return: Always 0 (Success).
 */
int main(void)
{
	int num = 5;

	printf("Factorial of %d is %d\n", num, factorial(num));

	return (0);
}
