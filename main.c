#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	main (int argc, char **argv)
{
	int fd;
	int ret;
	char *buf;
	int	index;

	buf = malloc(sizeof(char) * (10000+ 1));
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, 10000);
	buf[ret] = '\0';
	index = 0;
	while (buf[index] != '\0')
	{
		if (buf[index] == '\n')
			buf[index] = ' ';
		index++;
	}
	printf("%s",buf);
}