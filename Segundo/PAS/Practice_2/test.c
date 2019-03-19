#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE *etc_group;
	char line[50];
	char group_name[20];
	etc_group = fopen("/etc/group", "r");
	while((fgets(line, 50, etc_group)) != NULL){
		for(int i = 0; line[i] != ':'; i++) {
			group_name[i] = line[i];
		}
		printf("%s\n", group_name);
	}
	fclose(etc_group);
	return 0;
}
