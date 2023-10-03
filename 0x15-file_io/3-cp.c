#include "main.h"
#define BUF_LMT 1024
#define FAILURE (-1)
/**
 * main - copies the content of one file to another
 * @as: the string aguments passed tot he program
 * @argc: count of rguments passed
 *
 * Return: 0 if success, if the number of argument is not the correct one,
 * exit with code 97
 * if file_from does not exist, or if you can not read it, exit with code 98
 * if you can not create or if write to file_to fails, exit with code 99
 * if you can not close a file descriptor , exit with code 100
 */
int main(int argc, char **as)
{
	int fd_from, fd_to, cnt_rd;
	char buf[BUF_LMT] = {'\0'};

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	}
	fd_from = open(as[1], O_RDONLY);
	if (fd_from == FAILURE)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", as[1]), exit(98);
	}
	fd_to = open(as[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == FAILURE)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", as[2]), exit(99);
	}
	do {
		cnt_rd = read(fd_from, buf, BUF_LMT);
		if (cnt_rd == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", as[1]), exit(98);
		if (write(fd_to, buf, cnt_rd) == -1)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", as[2]), exit(99);
	} while (cnt_rd == BUF_LMT);

	if (close(fd_from) == FAILURE)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd_from), exit(100);
	}
	if (close(fd_to) == FAILURE)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd_to), exit(100);
	}
	return (0);
}
