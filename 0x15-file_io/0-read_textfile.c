#include "main.h"

/**
 * read_textfile - read file content
 *
 * @filename: name of the file to read
 * @letters: maximum number of letters to read and print
 *
 * Return: number of letters read and printed || 0 for failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *filepointer;
	char *buffer;
	ssize_t bytes_read;

	if (filename == NULL)
		return (0);

	filepointer = fopen(filename, "r");
	if (filepointer == NULL)
		return (0);

	buffer = malloc(letters + 1);
	if (buffer == NULL)
	{
		fclose(filepointer);
		return (0);
	}

	bytes_read = fread(buffer, 1, letters, filepointer);
	fclose(filepointer);

	if (bytes_read == 0 ||
			fwrite(buffer, 1, bytes_read, stdout) != (size_t) bytes_read)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	return (bytes_read);
}
