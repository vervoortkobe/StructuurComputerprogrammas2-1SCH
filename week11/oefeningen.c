#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************************
 *                                                Oefening 4                                                *
 ************************************************************************************************************/

typedef struct info {
  char *name, *location, *year_of_birth;
} Info;

/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/

#include <unistd.h> //for read and write and lseek system calls
#include <fcntl.h> // for open & creat system calls
#include <stdlib.h> // for malloc & NULL

#define SEEK_END 2 // this should be defined in unistd.h!!

#define PERMS 0666 /* RW for owner, group, others */
#define BUFSIZ 1024
#define OPEN_MAX 20
#define EOF (-1)

typedef struct _iobuf {
  int  cnt;       // characters left
  char *ptr;      // next character position
  char *base;     // location of the buffer
  int  flag;      // mode of the file access
  int  fd;        // file descriptor (number)
} FILE2;

extern FILE2 _iob[OPEN_MAX];

#define STDIN (&_iob[0])
#define STDOUT (&_iob[1])
#define STDERR (&_iob[2])

enum _flags {
  _READ   = 01,  // file open for reading
  _WRITE  = 02,  // file open for writing
  _UNBUF  = 04,  // file is unbuffered
  _EOF    = 010, // EOF has occurred on this file
  _ERR    = 020  // error occurred on this file
};








int main(int argc, char *argv[]) {
  return 0;
}
