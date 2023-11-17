#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: String to evaluate
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
