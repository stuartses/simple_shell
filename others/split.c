#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (void)
{
	char str[20] = "Hello,how,are,you";
	char *_split;

	_split = strtok(str, ",");
	while (_split != NULL)
	{
		printf("%s\n", _split);
		_split = strtok(NULL, ",");

	}
	return (0);
}
