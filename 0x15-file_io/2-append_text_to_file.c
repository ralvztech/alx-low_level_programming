#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file and text_content is the NULL terminated string,
 * to add at the end of the file
 * @text_content: text to append
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int w_out, count;

	if (filename == NULL)
	return (-1);

	int fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
	{
		return (-1);
	}
	if (text_content)
	{

		count = 0;
		while (*(text_content + count) != '\0')
		count++;

		w_out = write(fd, text_content, count);
		if (w_out == -1)
		{
			return (-1);
		}
	}
	close(fd);
	return (1);
}
