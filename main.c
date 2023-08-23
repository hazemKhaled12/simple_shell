#include "main.h"
#define MAX_COMMAND_LENGTH 100

/**
 * main - entry point
 *
 * Description: simple shell
 *
 * @ac: input count
 *
 * @av: input array
 *
 * Return: always 0
 */

int main(int ac, char **av)
{
	char command[MAX_COMMAND_LENGTH];
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[] = {command, NULL};
			char *envp[] = {NULL};

			if (execve(command, args, envp) == -1)
			{
				perror("Command execution failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
