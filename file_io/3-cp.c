#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * error_file - helps print and exit
 * @msg: message to print
 * @file: file that errored
 * @code: exit code
 */
void error_file(char *msg, char *file, int code)
{
	dprintf(STDERR_FILENO, msg, file);
	exit(code);
}

/**
 * close_fd - helper to close fd
 * @fd: fd to be closed
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies a file to another
 * @argc: number of arguments
 * @argv: array of args
 *
 * Return: 0 success, otherwise exit codes
 */
int main(int argc, char *argv[])
{
	int origin, destination, origin_read, write_status;
	char origin_content[1024];

	if (argc != 3)
		error_file("Usage: cp file_from file_to\n", "", 97);
	origin = open(argv[1], O_RDONLY);
	if (origin == -1)
		error_file("Error: Can't read from file %s\n", argv[1], 98);
	destination = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (destination == -1)
	{
		close(origin);
		error_file("Error: Can't write to %s\n", argv[2], 99);
	}
	while ((origin_read = read(origin, origin_content, 1024)) > 0)
	{
		write_status = write(destination, origin_content, origin_read);
		if (write_status == -1)
		{
			close(origin);
			close(destination);
			error_file("Error: Can't write to %s\n", argv[2], 99);
		}
	}
	if (origin_read == -1)
	{
		close(origin);
		close(destination);
		error_file("Error: Can't read from file %s\n", argv[1], 98);
	}

	close_fd(origin);
	close_fd(destination);

	return (0);
}
