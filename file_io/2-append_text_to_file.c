#include "main.h"

/**
 * append_text_to_file - append text to the end of the file
 * @filename: name of the file
 * @text_content: content of the file
 *
 * Return: 1 on success, -1 of failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int sz;

	if (filename == NULL || *filename == '\0')
	{
		return (-1);
	}

	fd = open(filename, O_WRONLY | O_APPEND);

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
