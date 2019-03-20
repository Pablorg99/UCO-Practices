/**
 * @file ejercicio1.c
 * @author Pablo Rodríguez Guillén (i72rogup@uco.es)
 * @brief File with the implementation of the first exercise of the second practice of PAS
 * @version 0.1
 * @date 2019-03-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
/* Libraries for structs passwd and group */
#include <pwd.h>
#include <grp.h>
/* Librarie to use strtok */
#include <string.h>

/*Function headers*/
void printUser(struct passwd *passwd_struct);
void printGroup(struct group *group_struct);
void showAllGroups(struct group *group_struct);

int main (int argc, char **argv)
{
    int option_character;

    /* Struct for getopt_long() */
    static struct option long_options[] = {
		/* Command line options */
		{"username", required_argument, 0, 'u'},
		{"useruid", required_argument, 0, 'i'},
		{"groupname", required_argument, 0, 'g'},
		{"groupuid", required_argument, 0, 'd'},
		{"allgroups", no_argument, 0, 's'},
		{"allinfo", no_argument, 0, 'a'},
		{"bactive", no_argument, 0, 'b'},
		/* This indicates that the last possibility is 0,0,0,0. So that there are not more options */
		{0, 0, 0, 0}
	};

	/* Structs for passwd and group format */
	struct passwd *passwd_struct;
	struct group *group_struct;

    /* These variables will store the result of processing the command line */
    /* In char * will be stored the argument (passed from getopt_long with extern char * optarg) */
    /* Flags for each option will pass to be 1 when the option is detected in the iteration of getopt_long returns */
    char *uvalue = NULL;
    char *ivalue = NULL;
    char *gvalue = NULL;
    char *dvalue = NULL;
	
    /* getopt_long() will use this variable to save the option */
    int option_index = 0;

    /* Disable default error prints */
    /* opterr = 0; */

    /* 'u:' means that the option u need an argument */
    while ((option_character = getopt_long(argc, argv, "u:i:g:d:sab", long_options, &option_index)) != -1)
    {
        /* All command options has been parsed */
        if (option_character == -1)
            break;
        switch (option_character)
        {
        case 'u':
            uvalue = optarg;
			passwd_struct = getpwnam(uvalue);
			printUser(passwd_struct);
            break;

        case 'i':
            ivalue = optarg;
			passwd_struct = getpwuid(atoi(ivalue));
			printUser(passwd_struct);
            break;

        case 'g':
            gvalue = optarg;
			group_struct = getgrnam(gvalue);
			printGroup(group_struct);
            break;

		case 'd':
            dvalue = optarg;
			group_struct = getgrgid(atoi(dvalue));
			printGroup(group_struct);
            break;

        case 's':
            showAllGroups(group_struct);
            break;

        case 'a':
            break;

        case 'b':
            break;

        case '?':
            /* getopt_long() has his default error message to print */
            /* If you want to create your own ones, assign 0 to opterr */
            break;

        default:
            abort ();
        }
        printf("optind: %d, optarg: %s, optopt: %c\n", optind, optarg, optopt);
    }
    return 0;
}


void printUser(struct passwd *passwd_struct) {
	printf("Nombre: %s\n", passwd_struct->pw_gecos);
	printf("Login: %s\n", passwd_struct->pw_name);
	printf("Password: %s\n", passwd_struct->pw_passwd);
	printf("UID: %d\n", passwd_struct->pw_uid);
	printf("Home: %s\n", passwd_struct->pw_dir);
	printf("Número de grupo principal: %d\n", passwd_struct->pw_gid);
}

void printGroup(struct group *group_struct) {
	printf("Nombre: %s\n", group_struct->gr_name);
	printf("Password: %s\n", group_struct->gr_passwd);
	printf("GID: %d\n", group_struct->gr_gid);
	printf("Member List: %s\n", *(group_struct->gr_mem)); 
}

void showAllGroups(struct group *group_struct) {
	char line[50];
	char *group_name;
   	
	FILE *etc_group;
	etc_group = fopen("/etc/group", "r");
	/* Read one line per iteration */
	while((fgets(line, 50, etc_group)) != NULL) {
		/* Save in group_name the line chars until ":" */
		group_name = strtok(line, ":");
		group_struct = getgrnam(group_name);
		printGroup(group_struct);
		printf("------------------------\n");
	}
	fclose(etc_group);
}
