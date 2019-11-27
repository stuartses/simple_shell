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
 * get_value_enviroment - Function that get the value of env
 *
 * @env: Pointer to pointer type char
 * @path_line: Pointer type char
 * @name_var: Pointer type char
 *
 * Return: void
 */
void get_value_enviroment(char **env, char *path_line, char *name_var)
{
	int i = 0;

	while (env[i] != NULL)
	{
		if (_strncmp(name_var, env[i], 4) == 0)
		{
			path_line = _strcpy(path_line, env[i]);
			break;
		}
		i++;
	}
}

/**
 * check_path - Cheks if program exists in path
 * @args: arguments
 * @path_dir: string with all paths
 *
 * Description: parse paths and check if program exist
 * Return: 1 sucess, 0 fails, -1 error
 */
int check_path(char **args, char *path_dir)
{
	char *tmp_path;
	struct stat stat_var;

	path_dir = strtok(NULL, ":");

	while (path_dir != NULL)
	{
		tmp_path = malloc(sizeof(char) *
				  (_strlen(path_dir) + _strlen(args[0])) + 2);

		if (tmp_path == NULL)
		{
			write(STDERR_FILENO, "Error assign memory\n", 50);
			free(tmp_path);
			return (-1);
		}

		tmp_path = _strcpy(tmp_path, path_dir);
		insert_path(tmp_path, args[0]);

		if (stat(tmp_path, &stat_var) == 0)
		{
			args[0] = _strdup(tmp_path);
			free(tmp_path);
			return (1);
		}

		free(tmp_path);

		path_dir = strtok(NULL, ":");
	}

	return (0);
}

/**
 * process_path - Look for program in enviroment PATH directories
 *
 * @args: input argument from stdin
 * @env: enviroment variables
 *
 * Description: Look for the program in system and complete with full Path
 *
 * Return: int with the status of the process
 */
int process_path(char **args, char **env)
{
	int path_chk;
	char *path_line, *path_dir;

	path_line = malloc((sizeof(char) * BUFFERSIZE));

	if (path_line == NULL)
	{
		write(STDERR_FILENO, "Error assign memory\n", 50);
		free(path_line);
		return (-1);
	}

	get_value_enviroment(env, path_line, "PATH");

	path_dir = strtok(path_line, "=");
	path_chk = check_path(args, path_dir);

	free(path_line);

	if (path_chk != 0)
		return (path_chk);

	return (0);
}
