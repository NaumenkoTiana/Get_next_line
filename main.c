#include "get_next_line.h"
#include <stdio.h>

//bonus tests

int main()
{
	int fd1;
	int fd2;
	int x;
	int y;
	char *line = "Hello";
	x = 1;
	y = 1;
	fd1 = open("test.txt", O_RDONLY);
  printf("%s\n", ">> test 1 << ");
  while ((x = get_next_line(fd1, &line)) && y < 3)
  {
      printf("%s\n", line);
//	  free(line);
      y++;
  }
	printf("%s\n", line);
//	free(line);
    fd2 = open("test3.txt", O_RDONLY);
    printf("%s\n", ">> test 3 << ");
    while ((x = get_next_line(fd2, &line)) && y < 6)
    {
        printf("%s\n", line);
//		free(line);
        y++;
    }
//	free(line);
    printf("%s\n", ">> test 1 << ");
    while ((x = get_next_line(fd1, &line)) && y < 9)
    {
        printf("%s\n", line);
//        free(line);
        y++;
    }
//	free(line);
	return (0);
}

//war&peace test

//int main()
//{
//	int fd;
//	int x;
//	char *line;
//
//	fd = open("war&peace.txt", O_RDONLY);
//	while((x = get_next_line(fd, &line)))
//	{
//		printf("%s\n\n", line);
//		free(line);
//	}
//	return (0);
//}