#include "main.h"

/**
 * read_textfile - read a text file
 * @filename: name of the file
 * @letters: number of letters in file
 *
 * Return: actual numbers that you read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	int sz;
	char *c;

	c = malloc(sizeof(char) * letters);
	if (c ==  NULL)
	{
		return (0);
	}

	if (filename == NULL)
	{
		return (0);
	}

	fd = open(filename, O_RDONLY);

	if (fd == 0)
	{
		return (0);
	}

	sz = read(fd, c, letters);

	write(STDOUT_FILENO, c, letters);

	close(fd);

	return (sz);
}
