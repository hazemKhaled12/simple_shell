#include "main.h"
#define BUFFER_SIZE 1024

/**
 * main - entry point
 *
 * Description: simple shell
 *
 *
 * Return: always 0
 */


int main(void)
{
	char *line;
	char prompt[] = "simple_shell$ ";

	while (1)
	{
		pid_t pid = fork();
		printf("%s", prompt);

		line = malloc(BUFFER_SIZE);
		if (line == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		if (fgets(line, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			free(line);
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		if (strcmp(line, "") == 0)
		{
			free(line);
			continue;
		}

		if (pid == -1)
		{
			perror("fork");
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

	return 0;
}
