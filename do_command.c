#include "main.h"

/**
 * do_command - Exucte the command using execve
 *
 * Description: 'excute the command'
 * @command: Command
 * Return: Always 0.
 */

void do_command(const char *command)
{
	pid_t first_process = fork();

	if (first_process == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (first_process == 0)
	{
		char **args = malloc(sizeof(char *) * 2);
		args[0] = (char *)command;
		args[1] = NULL;

		execve(command, args);
		perror("execv");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
