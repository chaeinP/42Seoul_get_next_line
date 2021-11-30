#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd1, fd2, fd3;
	int i = 0;
	int j = 0;
	char *line;

	fd1 = open("tests/multiple_line_with_nl", O_RDONLY);
	fd2 = open("tests/43_no_nl", O_RDONLY);
	fd3 = open("tests/multiple_nlx5", O_RDONLY);

	int fds[3] = {fd1, fd2, fd3};
	while (i < 5){

		j = 0;
		while(j < 3){
			line = get_next_line(fds[j]);
			printf("[files %d ] %s\n", fds[j], line);
			free(line);
			j++;
		}
		//system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
