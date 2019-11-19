#include <stdlib.h>
#include <stdio.h>
int main (void)
{
	char *buffer;
	size_t buffer_size = 50;
	char getline_out = '0';
	int i = 0;

	buffer = malloc(sizeof(char) * buffer_size);
	printf("$ ");

	while (getline_out != '\n' && getline_out != EOF)
	{
		getline_out = getchar();
		buffer[i] = getline_out;
		i++;
	}
	if (getline_out == EOF)
		printf("\n");
	else
		printf("%s", buffer);
	free(buffer);

	return (0);
}
