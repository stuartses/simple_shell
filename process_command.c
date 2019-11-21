#include "holberton.h"
/**
 *
 *
 */

void insert_path(char *in_path, char *arg)
{
	char *long_path;

	long_path = _strcat(in_path, "/");
	long_path = _strcat(in_path, arg);
}

/**
 *
 *
 */
void process_path(char **args, char **env)
{
	int proc_i = 0, found_path, proc_j = 0;
	char *path_line, *path_dir, *new_path;
	struct stat *stat_buf;

	while(env[proc_i] != NULL)
	{
		if (strncmp("PATH", env[proc_i], 4) == 0)
			path_line = env[proc_i];
		proc_i++;
	}

	path_dir = strtok(path_line, "=");
	path_dir = strtok(NULL, ":");

	stat_buf = malloc(sizeof(stat_buf));

	found_path = stat(args[0], stat_buf);

	while (path_dir != NULL && found_path != 0)
	{
		printf("...%s, len: %zu\n", path_dir, strlen(path_dir));
		new_path = malloc((sizeof(char) * strlen(path_dir)) + 1);
		strcpy(new_path, path_dir);
		insert_path(new_path, args[0]);
		found_path = stat(new_path, stat_buf);
		path_dir = strtok(NULL, ":");

		if (found_path == 0)
			args[0] = new_path;
		else
			free(new_path);

	}
	free(stat_buf);
}
