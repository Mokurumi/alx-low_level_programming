#include "main.h"

/**
 * print_usage_and_exit - Prints usage message and exits with error code 97.
 */
void print_usage_and_exit(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * print_error_and_exit - Prints error message with filename and exits
 *
 * @message: The error message to print.
 * @filename: The name of the file associated with the error.
 * @err: The error code
 */
void print_error_and_exit(const char *message, const char *filename, int err)
{
	dprintf(STDERR_FILENO, "Error: %s %s\n", message, filename);
	exit(err);
}

/**
 * copy_file - Copies the content of a file to another file.
 *
 * @file_from: The name of the source file.
 * @file_to: The name of the destination file.
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, read_chars, write_chars;
	char buf[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit("Can't read from file ", file_from, 98);

	if (access(file_to, F_OK) == 0 && access(file_to, W_OK) != 0)
		print_error_and_exit("Can't write to ", file_to, 99);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
		print_error_and_exit("Can't write to ", file_to, 99);

	while ((read_chars = read(fd_from, buf, 1024)) > 0)
	{
		write_chars = write(fd_to, buf, read_chars);
		if (write_chars != read_chars)
			print_error_and_exit("Can't write to ", file_to, 99);
	}

	if (read_chars == -1)
		print_error_and_exit("Can't read from file ", file_from, 98);

	if (close(fd_from) == -1)
		print_error_and_exit("Can't close fd ", file_from, 100);

	if (close(fd_to) == -1)
		print_error_and_exit("Can't close fd ", file_to, 100);
}

/**
 * main - check the code
 *
 * @argc: args length
 * @argv: args array
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_usage_and_exit();

	if (access(argv[1], F_OK | R_OK) == -1)
		print_error_and_exit("Can't read from file ", argv[1], 98);

	copy_file(argv[1], argv[2]);

	return (0);
}
