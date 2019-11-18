#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before execve\n");
	printf("%s\n", argv[1]);
	execve(argv[0], argv, NULL);
/*
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
*/
	printf("After execve\n");
	return (0);
}
