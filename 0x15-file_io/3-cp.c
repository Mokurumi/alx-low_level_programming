#include "main.h"

#define _POSIX_C_SOURCE 200809L
#define BUFFER_SIZE 1024

/**
 * print_usage_error - prints usage error message to stderr
 */
void print_usage_error(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * print_read_error - prints read error message to stderr
 *
 * @filename: The name of the source file.
 */
void print_read_error(char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	exit(98);
}

/**
 * print_write_error - prints write error message to stderr
 *
 * @filename: The name of the source file.
 */
void print_write_error(char *filename)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	exit(99);
}

/**
 * print_close_error - prints close error message to stderr
 *
 * @fd: the file descriptor that couldn't be closed
 */
void print_close_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * main - copy text from one file to the other
 *
 * @argc: args length
 * @argv: args array
 *
 * Return: Always 0 or error code
 */
int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;
	int input_fd, output_fd;

	if (argc != 3)
		print_usage_error();

	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		print_read_error(argv[1]);

	output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		print_write_error(argv[2]);

	while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(output_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
			print_write_error(argv[2]);
	}

	if (bytes_read == -1)
		print_read_error(argv[1]);

	if (close(input_fd) == -1)
		print_close_error(input_fd);

	if (close(output_fd) == -1)
		print_close_error(output_fd);

	return (0);
}
