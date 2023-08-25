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
		execlp(command, command, (char *)(NULL));
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
