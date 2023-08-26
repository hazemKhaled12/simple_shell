#include "main.h"
#define ARGS_BUFFER 130
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
		char *args[ARGS_BUFFER];
		int arg_counter = 0;
		char *token;

		token = strtok((char *)command, " ");
		while (token != NULL)
		{
			args[arg_counter++] = token;
			token = strtok(NULL, " ");
		}

		args[arg_counter] = NULL;

		if (command[0] == 0)
		{
			return;
		}

		execv(args[0], args);

		print_to_std_out("Error excuting command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
