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

void printUser(struct passwd *pw);
void printGroup(struct group *gr);
void showAllGroups(int sflaf);

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
	struct passwd *pw;
	struct group *gr;

    /* These variables will store the result of processing the command line */
    /* In char * will be stored the argument (passed from getopt_long with extern char * optarg) */
    /* Flags for each option will pass to be 1 when the option is detected in the iteration of getopt_long returns */
    char *uvalue = NULL;
    char *ivalue = NULL;
    char *gvalue = NULL;
    char *dvalue = NULL;
	
	int sflag = 0;
    /*int aflag = 0;
    int bflag = 0;*/

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
			pw = getpwnam(uvalue);
			printUser(pw);
            break;

        case 'i':
            ivalue = optarg;
			pw = getpwuid(atoi(ivalue));
			printUser(pw);
            break;

        case 'g':
            gvalue = optarg;
			gr = getgrnam(gvalue);
			printGroup(gr);
            break;

		case 'd':
            dvalue = optarg;
			gr = getgrgid(atoi(dvalue));
			printGroup(gr);
            break;

        case 's':
            sflag = 1;
            showAllGroups(sflag);
            break;
/*
        case 'a':
            aflag = 1;
            break;

        case 'b':
            bflag = 1;
            break;
*/
        case '?':
            /* getopt_long() has his default error message to print */
            /* If you want to create your own ones, assign 0 to opterr */
            break;

        default:
            abort ();
        }
        printf("optind: %d, optarg: %s, optopt: %c\n", optind, optarg, optopt);
    }

    /* Imprimir el resto de argumentos de la línea de comandos que no son opciones con "-" */
    if (optind < argc)
    {
        printf("Argumentos ARGV que no son opciones: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        putchar ('\n');
    }
    /* printf ("aflag = %d, bflag = %d, cvalue = %s, dvalue = %s, fvalue = %s\n",aflag, bflag, cvalue, dvalue, fvalue); */

    exit (0);
}


void printUser(struct passwd *pw) {
	printf("Nombre: %s\n", pw->pw_gecos); //No es lo mismo el nombre de usuario asociado a un login que el propio login
	printf("Login: %s\n", pw->pw_name);
	printf("Password: %s\n", pw->pw_passwd);
	printf("UID: %d\n", pw->pw_uid);
	printf("Home: %s\n", pw->pw_dir);
	printf("Número de grupo principal: %d\n", pw->pw_gid);
}

void printGroup(struct group *gr) {
	printf("Nombre: %s\n", gr->gr_name);
	printf("Password: %s\n", gr->gr_passwd);
	printf("GID: %d\n", gr->gr_gid);
	printf("Member List: %s\n", *(gr->gr_mem)); 
}

void showAllGroups(int sflag) {
    printf("%d\n", sflag);
    FILE *etc_group;
    char *group_name;
    struct group *gr;
    etc_group = fopen("/etc/group", "r");
    while(!feof(etc_group)) {
        fscanf(etc_group, "%s:%*[^\n]", group_name);
        printf("%s\n", group_name);
        gr = getgrnam(group_name);
		printGroup(gr);
    }
    fclose(etc_group);
}
