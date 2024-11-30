#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void func1(char *src)
{
	char dst[(strlen(src) + 1) * sizeof(char)];
	
	strncpy(dst, src, strlen(src) + sizeof(char));
	dst[strlen(dst)] = '\0';
}

void func2(int fd)
{
	char	*buf;
	size_t	len;

	if (read(fd, &len, sizeof(len)) != sizeof(len))
		return ;
	if (len > 1024)
		return ;
	buf = malloc(len+1); 
	len = read(fd, buf, len);
	buf[len] = '\0';
}

char *func3()
{
	char buffer[1024];

	printf("Please enter your user id :");
	fgets(buffer, 1024, stdin);
	if (!isalpha(buffer[0]))
	{
		char *errormsg;

		errormsg = (char *)malloc(1044 * sizeof(char));
		if (errormsg == NULL)
		{
			fprintf(stderr, "malloc failed\n");
			return NULL;
		}
		strncpy(errormsg, buffer, 1024);   
		strcat(errormsg, " is not  a valid ID");
	}
	return NULL;
}

void func4(char *foo)
{
	char *buffer = (char *)malloc(10 * sizeof(char));
	if (buffer == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		return ;
	}
	strncpy(buffer, foo, 10);
}

int main()
{
	int y = 9;
	int a[10];

	func4("fooooooooooooooooooooooooooooooooooooooooooooooooooo");

	char *err = func3();
	if (err != NULL)
	{
		printf("%s\n", err);
		free(err);
	}
	printf("%s", "hello world");

	while (y >= 0) 
	{
		a[y] = y;
		y = y - 1;
	}
	return 0;
}