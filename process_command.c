#include "holberton.h"
/**
 * insert_path - concat string with path
 * @in_path: input path
 * @arg: command to concat
 *
 * Description: Concatenates command with input path
 * Return: void
 */

void insert_path(char *in_path, char *arg)
{
	char *long_path;

	long_path = _strcat(in_path, "/");
	long_path = _strcat(in_path, arg);
}

/**
 * process_path - Look for program in enviroment PATH directories
 * @args: input argument from stdin
 * @env: enviroment variables
 *
 * Descriptio: Look for the program in system and complete with full Path
 * Return: void
 */
void process_path(char **args, char **env)
{
	int proc_i = 0, found_path;
	char *path_line, *path_dir, *temp_path;

	path_line = malloc((sizeof(char) * BUFFERSIZE));

	while (env[proc_i] != NULL)
	{
		if (strncmp("PATH", env[proc_i], 4) == 0)
		{
			path_line = strcpy(path_line, env[proc_i]);
		}
		proc_i++;
	}

	found_path = access(args[0], F_OK);
	path_dir = strtok(path_line, "=");
	path_dir = strtok(NULL, ":");

	while (found_path != 0 && path_dir != NULL)
	{
		temp_path = malloc((sizeof(char) * strlen(path_dir)) + 1);
		temp_path = strcpy(temp_path, path_dir);
		insert_path(temp_path, args[0]);
		found_path = access(temp_path, F_OK);
		if (found_path == 0)
			args[0] = temp_path;
		else
			free(temp_path);

		path_dir = strtok(NULL, ":");
	}
	/* se debe liberar temp_path cuando se ejecuta el comando!! ¿Como? */
	free(path_line);
}
