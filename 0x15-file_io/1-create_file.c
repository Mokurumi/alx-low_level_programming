#include "main.h"

/**
 * create_file - create a file and add content
 *
 * @filename: name of file to be created
 * @text_content: content to insert in new file
 *
 * Return: 1 on success and -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	FILE *filepointer;

	if (filename == NULL)
		return (-1);

	filepointer = fopen(filename, "w");
	if (filepointer == NULL)
		return (-1);

	if (text_content != NULL)
		fprintf(filepointer, "%s", text_content);

	fclose(filepointer);
	return (1);
}
