#include "main.h"
#define BUFFER_SIZE 1024

/**
 * main - entry point
 *
 * Description: 'this is the description'
 *
 * Return: Always 0.
 */

int main(void)
{
	char *line;
	pid_t pid;
	int result;

	while (1)
	{
		line = malloc(BUFFER_SIZE);
		result = create_and_validate(line);
		if (result == -1)
			break;
		if (result == 1)
			continue;
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (execlp(line, line, NULL) == -1)
			{
				perror("execlp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			waitpid(pid, &status, 0);
		}
		free(line);
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
	char prompt[] = "simple_shell$ ";

	printf("%s", prompt);

	if (line == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	if (fgets(line, BUFFER_SIZE, stdin) == NULL)
	{
		printf("\n");
		free(line);
		return (-1);
	}

	line[strcspn(line, "\n")] = '\0';

	if (strcmp(line, "") == 0)
	{
		free(line);
		return (1);
	}

	return (0);
}
