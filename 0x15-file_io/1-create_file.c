#include "main.h"

/**
 * create_file -  a function that creates a file.
 * @filename: the file to be cretad.
 * @text_content: a NULL terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
*/

int create_file(const char *filename, char *text_content)
{
	/*the file descriptor*/
	int fd;
	/*number of letters in text_content i.e its length*/
	int num_letters;
	/*number of letters to be printed on the stdout*/
	int num_letters_written;

	/* create file filename in a write-only mode, if it exist truncate*/
	/* its contents and assign 0600 (i.e rw-------) file permision*/
	/* to the created file*/
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content == NULL)
		text_content = "";
	num_letters = strlen(text_content);
	num_letters_written = write(fd, text_content, num_letters);
	if (num_letters_written == -1)
		return (-1);
	close(fd);
	return (1);
}
