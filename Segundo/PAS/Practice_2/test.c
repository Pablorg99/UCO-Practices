#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *etc_group;
	int character;
	char *group_name;
	etc_group = fopen("/etc/group", "r");
	if(etc_group == NULL) perror("Can not open file");
	while(!feof(etc_group)) {
		printf("Im in while\n");	
		fgetc(etc_group, "%s", line);
		printf("%s\n", line);
	}
	
	return 0;
}
