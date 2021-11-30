#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(){
	int fd = open("gnl-tester/files/nl", O_RDONLY);
	int i = 0;
	char *line;
	while (i < 1){
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		//system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
		i++;
	}
	return (0);
}
