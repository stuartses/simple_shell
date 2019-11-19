#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
	char *buffer, *parse ;
	size_t buffer_size = 50;
	int com_len = 0, i = 0;
	size_t getline_out, new_pid, new_exec;
        char **parse_com, **argv;

	buffer = malloc(sizeof(char) * buffer_size);
	parse_com = malloc(sizeof(char*) * buffer_size);

	printf("$ ");
	getline_out = getline(&buffer, &buffer_size, stdin);

	while (buffer[i] != '\n')
		i++;
	buffer[i] = '\0';

	parse = strtok(buffer, " ");
	while (parse != NULL)
	{
		parse_com[com_len] = parse;
		parse = strtok(NULL, " ");
		com_len++;
	}
	argv = parse_com;
	new_pid = fork();

	if (new_pid == 0)
	{
		new_exec = execve(argv[0], argv, NULL);
		if (new_exec == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);

	free(buffer);
	free(parse_com);

	return (0);
}
