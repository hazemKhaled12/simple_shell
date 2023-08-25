#include "main.h"

/**
 * tokanizer - Tokanize the command
 *
 * Description: 'this is the description'
 * @argc: arg count
 * @argv: args array
 * @envp: array of env
 * Return: Always 0.
 */

int tokanizer(char *command)
{
	char command[] = "ls -l /home/user";

	char *token;
	char *delim = " ";

	token = strtok(command, delim);

	while (token != NULL)
	{
		printf("TOKEN: %s\n", token);
		token = strtok(NULL, delim);
	}

	return (0);
}
