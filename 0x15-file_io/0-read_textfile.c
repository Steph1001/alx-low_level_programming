#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the standard output
 * @filename: name of the file to be read
 * @letters: number of letters to read and print
 *
 * Return: the number of letters printed, or 0 if it failed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	int amount, tot;
	char *bufferc;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	bufferc = malloc(sizeof(char) * letters);
	if (!bufferc)
		return (0);

	amount = read(fd, bufferc, letters);
	if (amount < 0)
	{
		free(bufferc);
		return (0);
	}
	bufferc[amount] = '\0';

	close(fd);

	tot = write(STDERR_FILENO, bufferc, amount);
	if (tot < 0)
	{
		free(bufferc);
		return (0);
	}

	free(bufferc);
	return (tot);
}
