#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char *av[]){
	int fd = 0;
	int i = 0;
	char *line;
	while (i < 3){
		line = get_next_line(fd);
		printf("[std] : %s", line);
		free(line);
		//system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
		i++;
	}
	return (0);
}
