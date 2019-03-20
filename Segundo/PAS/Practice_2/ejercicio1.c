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
/* Library to use strtok */
#include <string.h>
/* Library for getlogin() */
#include <unistd.h>

/*Function headers*/
void printUser(struct passwd *passwd_struct);
void printGroup(struct group *group_struct);
void showAllGroups(struct group *group_struct);
void showUserAndGroup(char *login, struct passwd *passwd_struct, struct group *group_struct);
void showHelp();

int main (int argc, char **argv)
{

    /* Struct for getopt_long() */
    static struct option long_options[] = {
		/* Command line options */
		{"username", required_argument, 0, 'u'},
		{"useruid", required_argument, 0, 'i'},
		{"groupname", required_argument, 0, 'g'},
		{"groupuid", required_argument, 0, 'd'},
		{"allgroups", no_argument, 0, 's'},
		{"allinfo", required_argument, 0, 'a'},
		{"bactive", no_argument, 0, 'b'},
		{"help", no_argument, 0, 'h'},
		/* This indicates that the last possibility is 0,0,0,0. So that there are not more options */
		{0, 0, 0, 0}
	};

	/* Structs for passwd and group format */
	struct passwd *passwd_struct = NULL;
	struct group *group_struct = NULL;

    /* Variables for each option with */
    char *uvalue = NULL;
    char *ivalue = NULL;
    char *gvalue = NULL;
    char *dvalue = NULL;
	char *avalue = NULL;

	
	int option_character;
    int option_index = 0;

    /* Disable default error prints */
    /* opterr = 0; */

	/* Variable to store the login name when getlogin() is called */
	char *login = NULL;

	/* In case of no arguments */
	if(argc == 1) {
		printf("You can give me some arguments, take a look at --help or -h\n\n");
		login = getlogin();
		if(login == NULL) {
			perror("Could not get login");
			exit(-1);
		}
		showUserAndGroup(login, passwd_struct, group_struct);
	}
    
	/* 'u:' means that the option u need an argument */
    while ((option_character = getopt_long(argc, argv, "u:i:g:d:sa:bh", long_options, &option_index)) != -1)
    {
        /* All command options has been parsed */
        if (option_character == -1)
            break;
        switch (option_character)
        {
        case 'u':
            uvalue = optarg;
			passwd_struct = getpwnam(uvalue);
			if(passwd_struct == NULL) {
				fprintf(stderr, "The user login specified does not exists");
				exit(-1);
			} 
			printUser(passwd_struct);
            break;

        case 'i':
            ivalue = optarg;
			passwd_struct = getpwuid(atoi(ivalue));
			if(passwd_struct == NULL) {
				fprintf(stderr, "The user id specified does not exists");
				exit(-1);
			} 
			printUser(passwd_struct);
            break;

        case 'g':
            gvalue = optarg;
			group_struct = getgrnam(gvalue);
			if(group_struct == NULL) {
				fprintf(stderr, "The group name specified does not exists");
				exit(-1);
			} 
			printGroup(group_struct);
            break;

		case 'd':
            dvalue = optarg;
			group_struct = getgrgid(atoi(dvalue));
			if(group_struct == NULL) {
				fprintf(stderr, "The group id specified does not exists");
				exit(-1);
			} 
			printGroup(group_struct);
            break;

        case 's':
            showAllGroups(group_struct);
            break;

        case 'a':
			avalue = optarg;
			showUserAndGroup(avalue, passwd_struct, group_struct);
            break;

        case 'b':
			login = getlogin();
			if(login == NULL) {
				perror("Could not get login");
				exit(-1);
			}
			showUserAndGroup(login, passwd_struct, group_struct);
            break;
		case 'h':
			showHelp();
			break;

        case '?':
            /* getopt_long() has his default error message to print */
            /* If you want to create your own ones, assign 0 to opterr */
			showHelp();
            break;

        default:
            abort ();
        }
    }
    return 0;
}


void printUser(struct passwd *passwd_struct) {
	printf("Nombre: %s\n", passwd_struct->pw_gecos);
	printf("Login: %s\n", passwd_struct->pw_name);
	printf("Password: %s\n", passwd_struct->pw_passwd);
	printf("UID: %d\n", passwd_struct->pw_uid);
	printf("Home: %s\n", passwd_struct->pw_dir);
	printf("ID de grupo principal: %d\n", passwd_struct->pw_gid);
}

void printGroup(struct group *group_struct) {
	printf("Nombre: %s\n", group_struct->gr_name);
	printf("Password: %s\n", group_struct->gr_passwd);
	printf("GID: %d\n", group_struct->gr_gid);
	printf("Members List: %s\n", *(group_struct->gr_mem)); 
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

void showUserAndGroup(char *login, struct passwd *passwd_struct, struct group *group_struct) {
	passwd_struct = getpwnam(login);
	if(passwd_struct == NULL) {
		fprintf(stderr, "The user login specified does not exists");
		exit(-1);
	}
	group_struct = getgrgid(passwd_struct->pw_gid);
	printUser(passwd_struct);
	printf("-----------------------------\n");
	printGroup(group_struct);
}

void showHelp() {
	printf("-h, --help 						Show this help\n");
	printf("-u, --username <user_login>		Show user specified info\n");
	printf("-i, --useruid <user_id>			Show user specified info\n");
	printf("-g, --groupname <group_name>	Show group specified info\n");
	printf("-d, --groupuid <group_id>		Show group specified info\n");
	printf("-s, --allgroups					Show info of all groups on the system\n");
	printf("-a, --allinfo <user_login>		Show all info (group and user) of specified user\n");
	printf("-b, --bactive					Show all info (group and user) of current user\n");
}