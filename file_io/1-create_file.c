#include "main.h"

/**
 * create_file - create file with text content
 * @filename: name of the file
 * @text_content: content of the file
 *
 * Return: actual numbers that you read and print
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int sz;

	if (filename == NULL || *filename == '\0')
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (fd == -1)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		text_content = "";
	}

	sz = write(fd, text_content, strlen(text_content));
	if (sz == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
