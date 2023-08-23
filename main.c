#include "main.h"

/**
 * main - Entry point
 *
 * @argc: arg count
 * @argv: arg vector
 * Return: Always 0.
 */

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Give a filename\n");
		return (1);
	}
	if (access(argv[1], F_OK) == -1)
	{
		printf("File does not exist");
		return (2);
	}
	printf("Hello world %i,  %s , %s\n", argc, argv[0], argv[1]);
	return (0);
}
