#include "holberton.h"
/**
 * insert_path - concat string with path
 *
 * @in_path: input path
 * @arg: command to concat
 *
 * Description: Concatenates command with input path
 *
 * Return: void
 */
void insert_path(char *in_path, char *arg)
{
	_strcat(in_path, "/");
	_strcat(in_path, arg);
}

/**
 * process_path - Look for program in enviroment PATH directories
 *
 * @args: input argument from stdin
 * @env: enviroment variables
 * @new_path: new_path for execution
 *
 * Description: Look for the program in system and complete with full Path
 *
 * Return: int with the status of the process
 */
int process_path(char **args, char **env)
{
	int proc_i = 0, found_path;
	char *path_line, *path_dir, *tmp_path;

	path_line = malloc((sizeof(char) * BUFFERSIZE));

	if (path_line == NULL)
	{
		write(STDERR_FILENO, "Error assign memory\n", 50);
		free(path_line);
		return (-1);
	}

	while (env[proc_i] != NULL)
	{
		if (strncmp("PATH", env[proc_i], 4) == 0)
		{
			path_line = _strcpy(path_line, env[proc_i]);
		}
		proc_i++;
	}

	found_path = access(args[0], F_OK);
	path_dir = strtok(path_line, "=");
	path_dir = strtok(NULL, ":");

	while (found_path != 0 && path_dir != NULL)
	{
		tmp_path = malloc(sizeof(char) *
				   (_strlen(path_dir) + _strlen(args[0])) + 2);

		if (tmp_path == NULL)
		{
			write(STDERR_FILENO, "Error assign memory\n", 50);
			free(path_line);
			free(tmp_path);
			return (-1);
		}

		tmp_path = _strcpy(tmp_path, path_dir);
		insert_path(tmp_path, args[0]);
		found_path = access(tmp_path, F_OK);

		if (found_path == 0)
		{
			args[0] = strdup(tmp_path);
			free(path_line);
			free(tmp_path);
			return (1);
		}

		free(tmp_path);

		path_dir = strtok(NULL, ":");
	}
	free(path_line);
	return (0);
}
