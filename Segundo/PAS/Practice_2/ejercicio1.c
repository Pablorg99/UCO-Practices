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

int main (int argc, char **argv)
{
	int option_character;
	
	/* Struct for getoptlong */
	static struct option long_options[] =
	{
		/* Command line options */
		{"username", required_argument, 0, 'u'},
		{"useruid", required_argument, 0, 'i'},
		{"groupname", required_argument, 0, 'g'},
		{"groupuid", required_argument, 0, 'd'},
		{"allgroups", no_argument, 0, 's'},
		{"allinfo", no_argument, 0, 'a'},
		{"bactive", no_argument, 0, 'b'},
		/* This indicates the end of the options */
		{0, 0, 0, 0}
	};

	/* These variables will store the result of processing the command line */
	/* In char * will be stored the argument (passed from getopt_long with extern char * optarg) */
	/* Flags for each option will pass to be 1 when the option is detected in the iteration of getopt_long returns */
	char *uvalue = NULL;
	char *ivalue = NULL;
	char *gvalue = NULL;
	char *dvalue = NULL;
	int sflag = 0;
	int aflag = 0;
	int bflag = 0;

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
				break;

			case 'i':
				ivalue = optarg;
				break;

			case 'g':
				gvalue = optarg;
				break;

			case 's':
				sflag = 1;
				break;

			case 'a':
				aflag = 1;
				break;

			case 'b':
				bflag = 1;
				break;

			case '?':
				/* getopt_long has his default error message to print */
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

