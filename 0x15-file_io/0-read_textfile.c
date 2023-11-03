#include "main.h"

/**
 * read_textfile -  a function that reads a text file
 * and prints it to the POSIX standard output.
 * @filename: a string pointer to a file.
 * @letters: number of letters to be read and printed.
 *
 * Return: actual number of letters read and printed.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	/*the file descriptor*/
	int fd;
	/*number of letters to be read from the file*/
	ssize_t num_letters_read;
	/*actual number of letters read and printed on the stdout*/
	ssize_t num_letters_written;
	/*a buffer that holds the letters to be printed on the stdout*/
	char *buf;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);
	num_letters_read = read(fd, buf, letters);
	num_letters_written = write(STDOUT_FILENO, buf, num_letters_read);
	close(fd);
	free(buf);
	return (num_letters_written);
}
