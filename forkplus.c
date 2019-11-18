#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main (void)
{
	pid_t child_pid;
	int child_exec, i = 0, j = 0;

	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			printf("process %d\n", i);

			child_exec = execve(argv[0], argv, NULL);

			if (child_exec == -1)
				perror("Error");
			/*exit(0);*/
			/* no es necesario el exit, ya que execve cierra el proceso */
		}
		sleep(2);
		i++;
	}

	for (j = 0; j < 5; j++)
	{
		wait(NULL);
	}

	return (0);
}
