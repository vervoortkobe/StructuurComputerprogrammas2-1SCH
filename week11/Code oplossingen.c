#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************************
 *                                                Oefening 1                                                *
 ************************************************************************************************************/

int count_c(char *path) {
	FILE *file = fopen(path, "r");
	if (file == NULL) {
		printf("File %s could not be opened\n", path);
		return 0;
	}
	char c;
	int counter = 0;
	while ((c = fgetc(file)) != EOF) {
		if (c == 'c') {
			++counter;
		}
	}
	fclose(file);
	return counter;
}

/************************************************************************************************************
 *                                                Oefening 2                                                *
 ************************************************************************************************************/

#define MAX_LINE_SIZE 1000

void head(char *file_path) {
	FILE *file = fopen(file_path, "r");
	if (file == NULL) {
		printf("File %s could not be opened\n", file_path);
		return;
	}
	for (int i = 0; i < 10; i++) {
		char buffer[MAX_LINE_SIZE];
		if (fgets(buffer, MAX_LINE_SIZE, file) != NULL) {
			printf("%s", buffer);
		} else {
			break;
		}
	}
	fclose(file);
}

/************************************************************************************************************
 *                                                Oefening 3                                                *
 ************************************************************************************************************/

void search_file(char *string, char *path) {
	FILE *file = fopen(path, "r");
	if (file == NULL) {
		printf("File %s kon niet geopend worden.\n", path);
		return;
	}
	char buffer[MAX_LINE_SIZE];
	while (fgets(buffer, MAX_LINE_SIZE, file) != NULL) {
		if (strstr(buffer, string) != NULL) {
			printf("%s", buffer);
		}
	}
	fclose(file);
}

void grep(char *string, char **paths_array, int nr_of_paths) {
	int i;
	for (i = 0; i < nr_of_paths; i++) {
		search_file(string, paths_array[i + 2]);
	}
}


/************************************************************************************************************
 *                                                Oefening 4                                                *
 ************************************************************************************************************/

typedef struct info {
  char *name, *location, *year_of_birth;
} Info;

void insert_person(char *database_path, Info *info) {
  FILE *db = fopen(database_path, "a");
  fprintf(db, "%s\n%s\n%s\n", info->name, info->location, info->year_of_birth);
  fclose(db);
}

void cut_off_last_char(char *string) {
	int string_length = strlen(string);
	string[string_length - 1] = '\0';
}

Info *find_person(char *database_path, char *name) {
  FILE *db = fopen(database_path, "r");
  char *name_read = calloc(1000, sizeof(char));
  char *location_read = calloc(1000, sizeof(char));
  char *year_of_birth_read = calloc(1000, sizeof(char));
  while (fgets(name_read, 1000, db) != NULL) {
    fgets(location_read, 1000, db);
    fgets(year_of_birth_read, 1000, db);
    cut_off_last_char(name_read);
    cut_off_last_char(location_read);
    cut_off_last_char(year_of_birth_read);
    if (strcmp(name, name_read) == 0) {
      Info *info_found = malloc(sizeof(Info));
      info_found->name = name_read;
      info_found->location = location_read;
      info_found->year_of_birth = year_of_birth_read;
      fclose(db);
      return info_found;
    }
  }
  free(name_read); free(location_read); free(year_of_birth_read);
  fclose(db);
  return NULL;
}

/************************************************************************************************************
 *                                                Oefening 5                                                *
 ************************************************************************************************************/

// Niet gemaakt tijdens het WPO

/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/



//
//  Created by Elisa Gonzalez Boix on 29/11/16.
//  Copyright © 2016 Elisa Gonzalez Boix. All rights reserved.
//  Example based on K&R Section 8.5

#include <unistd.h> //for read and write and lseek system calls
#include <fcntl.h> // for open & creat system calls
#include <stdlib.h> // for malloc & NULL

#define PERMS 0666 /* RW for owner, group, others */


typedef struct _iobuf {
	int  cnt;       // allocated bytes for the file
	char *ptr;      // next character position
	char *base;     // location of the buffer
	int  flag;      // mode of the file access
	int  fd;        // file descriptor (number)
} FILE2;

#define OPEN_MAX 10

extern FILE2 _iob[OPEN_MAX];

#define stdin2 (&_iob[0])
#define stdout2 (&_iob[1])
#define stderr2 (&_iob[2])

enum _flags {
	_READ   = 01,  // file open for reading
	_WRITE  = 02,  // file open for writing
	_UNBUF  = 04,  // file is unbuffered
	_EOF    = 010, // EOF has occurred on this file
	_ERR    = 020  // error occurred on this file
};

#define feof(p) ((p)->flag & _EOF) != 0)
#define ferror(p) ((p)->flag & _ERR) != 0)

FILE2 _iob[OPEN_MAX] = { /* stdin, stdout, stderr */
		{ 0, (char *) 0, (char *) 0, _READ, 0 },
		{ 0, (char *) 0, (char *) 0, _WRITE, 1 },
		{ 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};

FILE2 *fopen2(char *name, char *mode);

FILE2 *fopen2(char *name, char *mode)
{
	int fd;
	FILE2 *fp;
	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp->flag & (_READ | _WRITE)) == 0)
			break; /* found free slot */
	if (fp >= _iob + OPEN_MAX)
		/* no free slots */
		return NULL;
	if (*mode == 'w')
		fd = creat(name, PERMS);
	else
		if (*mode == 'a') {
			if ((fd = open(name, O_WRONLY, 0)) == -1)
				fd = creat(name, PERMS);
			// file positioning system call; takes a file descriptor for a file,
			// and positions the offset of the open file to the given offset (in this case O)
			// according to integer determining origin:
			//0  SEEK_SET => beginning
			//1  SEEK_CUR => from current position
			//2  SEEK_END => end of the file
			lseek(fd, 0L, SEEK_END);
		}
		else
			fd = open(name, O_RDONLY, 0);
	if (fd == -1) /* couldn't access name */
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;
	return fp;
}


int fillbuf2(FILE2 *fp);
int fgetc2(FILE2 *fp);

#define BUFFER_SIZE 5

int fillbuf2(FILE2 *fp) {
  if ((fp->flag & (_READ | _EOF | _ERR)) != _READ) {
    return EOF;
  }
  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, BUFSIZ);
  if ((--(fp->cnt)) < 0) {
    if (fp->cnt == -1) {
      fp->flag = fp->flag | _EOF;
    } else {
      fp->flag = fp->flag | _ERR;
    }
    fp->cnt = 0;
    return EOF;
  }
  char result = *(fp->ptr);
  fp->ptr++;
  return result;
}

int fgetc2(FILE2 *fp) {
  if ((fp->flag & (_READ | _EOF | _ERR)) != _READ) {
    return EOF;
  }
  if (fp->flag & _UNBUF) {
    char c;
    return (read(fp->fd, &c, 1) == 1) ? c : EOF;
  }
  if (fp->base == NULL) {
    fp->base = (char *) malloc(BUFSIZ);
    fp->ptr = fp->base;
  }
  if (fp->base == NULL) {
    fp->flag = _ERR;
    return EOF;
  }
  if (fp->cnt == 0) {
    return fillbuf2(fp);
  } else {
    char c = *(fp->ptr);
    fp->ptr++;
    fp->cnt--;
    return c;
  }
}




// Geen deel van de oefeningen: maak een nieuw bestand aan met file_content als inhoud.
void initialise_file(char *file_name, const char *file_content) {
	FILE *file = fopen(file_name, "w");
	if (file == NULL) { exit(1); }
	fputs(file_content, file);
	fclose(file);
}

int main(int argc, char **argv) {
	// Initialiseer bestanden die gebruikt gaan worden in de oefeningen
	initialise_file("file.txt", "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	initialise_file("db", ""); // Wis het bestand "db", als dat bestand zou bestaan.
	initialise_file("new_file.txt", "Line 1\nLine 2\nLine 3\n");
	initialise_file("file_met_counter.txt", "een string van 28 karakters\n13 karakters\n");



	/* Oef 1 */
	printf("Oef 1\n");
	printf("%i\n", count_c("file.txt"));

	/* Oef 2 */
	printf("\n\nOef 2\n");
	head("file.txt");

	/* Oef 3 */
	printf("\n\nOef 3\n");
	if (argc <= 1) {
		printf("Niet genoeg argumenten meegegeven om grep uit te voeren.\n");
	} else {
		grep(argv[1], argv, argc - 2);
	}


	/* Oef 4 */
	printf("\n\nOef 4\n");
	Info info = {"Janssens", "Brussel", "2000"};
	insert_person("db", &info);
	Info *person_found = find_person("db", "Janssens");
	if (person_found != NULL) {
		printf("Found name: %s, location: %s, year of birth: %s\n", person_found->name, person_found->location, person_found->year_of_birth);
		free(person_found->name);
		free(person_found->location);
		free(person_found->year_of_birth);
		free(person_found);
	} else {
		printf("Person not found\n");
	}

	/* Oef 5 */
	printf("\n\nOef 5\n");
	printf("Niet gemaakt tijdens het WPO\n");

	/* Oef 6 */
	printf("\n\nOef 6\n");
	FILE2 *fp = fopen2("file.txt", "r");
	printf("First 15 characters of file.txt:\n");
	for (int i = 0; i < 15; i++) {
		int result = fgetc2(fp);
		printf("%c", result);
	}

	return EXIT_SUCCESS;
}
