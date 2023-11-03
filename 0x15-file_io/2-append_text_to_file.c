#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: file to append.
 * @text_content: NULL terminated string to append at the end file.
 *
 * Return: 1 on success and -1 on failure.
 *
 * Do not create the file if it does not exist.
 * If text_content is NULL, do not add anything to the file.
 * Return 1 if the file exists and -1 if the file does not exist or
 * if you do not have the required permissions to write the file.
*/

int append_text_to_file(const char *filename, char *text_content)
{
	/*the file descriptor*/
	int fd;
	/*number of letters in text_content i.e its length*/
	int num_letters;
	/*number of letters to be printed on the stdout*/
	int num_letters_written;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		num_letters = strlen(text_content);
		num_letters_written = write(fd, text_content, num_letters);
		if (num_letters_written == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
