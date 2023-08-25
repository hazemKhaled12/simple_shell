#include "main.h"
#define BUFFER_SIZE 1024

/**
 * main - entry point
 *
 * Description: 'this is the description'
 * @argc: arg count
 * @argv: args array
 * @envp: array of env
 * Return: Always 0.
 */

int main(int __attribute__((__unused__)) argc,
		char *argv[], char __attribute__((__unused__)) *envp[])
{
	char line[BUFFER_SIZE];
	pid_t pid;
	int result;

	while (1)
	{
		result = create_and_validate(line);
		if (result == -1)
			break;
		if (result == 1)
			continue;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execl(line, line, NULL) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
	}

	return (0);
}

/**
 * create_and_validate - something else
 *
 * @line: "string"
 *
 * Return: Always 0.
 */

int create_and_validate(char *line)
{
	char prompt[] = "#cisfun$ ";

	printf("%s", prompt);

	if (fgets(line, BUFFER_SIZE, stdin) == NULL)
	{
		printf("\n");
		return (-1);
	}

	line[strcspn(line, "\n")] = '\0';

	if (strcmp(line, "") == 0)
	{
		return (1);
	}

	return (0);
}
