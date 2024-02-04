#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
	int fd;
	char *cmd;

	cmd = NULL;
	fd = fork();
	if(fd == 0)
	{
		if(execve(cmd, NULL, NULL) == -1)
		{
			printf("%d\n", errno);
			printf("%s: %s\n", cmd, strerror(errno));
		}
	}
}