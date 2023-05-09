#include "main.h"

/**
 * append_text_to_file - add textual content to end of file
 *
 * @filename: name of file to be created
 * @text_content: content to append
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *filepointer;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	filepointer = fopen(filename, "a");
	if (filepointer == NULL)
		return (-1);

	if (text_content != NULL)
		if (fputs(text_content, filepointer) == EOF)
		{
			fclose(filepointer);
			return (-1);
		}

	fclose(filepointer);
	return (1);
}
