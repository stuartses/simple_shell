/**
 * _strcpy -  copies the string pointed to by src
 * @dest: destination char
 * @src: origin char
 *
 * Description:  function that copies the string pointed to by src
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup -  copies the string pointed to by src to a new pointer
 * @src: origin char
 *
 * Description:  function that copies the string pointed to by src
 * Return: dest ponter
 */

char *_strdup(const char *src)
{
	int i = 0, len;
	char *dest;

	len = _strlen(src);
	dest = malloc((sizeof(char) * len) + 1);

	if (dest == NULL)
		return (NULL);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}


/**
 * _strlen - Function that return the length of a string
 *
 * @str: Pointer type char
 *
 * Return: The length of a string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return (i);
}
