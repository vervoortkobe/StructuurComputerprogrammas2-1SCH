#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************************
*                                                Oefening 1                                                 *
************************************************************************************************************/

void oef1() {
	int a = 10;
	int array[10];
	printf("%i\n", a);
}

/************************************************************************************************************
*                                                Oefening 2                                                 *
************************************************************************************************************/

void read_password(char *password) {
	int i = 0;
	char c;
	while ((c = getchar()) != '\n') {
		password[i] = c;
		i++;
	}
	password[i] = '\0';
}

int login() {
	char password[] = "hello";
	char input[6];
	read_password(input);
	printf("%s\n%s\n", input, password);
	int passwords_equal = strncmp(password, input, 5);
	return ! passwords_equal;
}

void oef2() {
	printf("Geef je paswoord in:\n");
	while (1) {
		if (login()) {
			printf("Paswoord correct!\n");
			break;
		} else {
			printf("Paswoord incorrect!\nProbeer opnieuw:\n");
		}
	}
}

/************************************************************************************************************
*                                                Oefening 3                                                 *
************************************************************************************************************/

// Zie new_stackmachine
// ./print_to_input 1 2 3 0xxxxxxxxxx
// vul 3 random getallen in en dan het teruggegeven address

/************************************************************************************************************
 *                                                Oefening 4                                                *
 ************************************************************************************************************/

int fac(int n) {
	int result = 1;
	while (n > 1) {
		result *= n;
		n--;
	}
	return result;
}

/************************************************************************************************************
 *                                               Oefening 5                                                *
 ************************************************************************************************************/

//
//  Created by Elisa Gonzalez Boix on 08/12/2020.
//

typedef struct thunk_struct {
	struct thunk_struct *(*fun)(int, int);
	int arg1;
	int arg2;
} thunk;

thunk* make_thunk(thunk* (*f)(int, int), int, int);
void trampoline(thunk*);
thunk* printAndStop(int n, int acc);

thunk* make_thunk(thunk* (*f)(int, int), int a, int b)
{
	thunk* t = (thunk*) malloc(sizeof(thunk));
	if (t != NULL) {
		t->fun = f;
		t->arg1 = a;
		t->arg2 = b;
	}
	return t;
}

void trampoline(thunk* t)
{
  while (t != NULL) {
		thunk *temp = t->fun(t->arg1, t->arg2);
		free(t);
		t = temp;
	}
}

thunk* printAndStop(int n, int acc)
{
	printf("answer is %d\n", acc);
	return NULL;
}

/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/

typedef enum {
	SINGLE, COHABITATING, MARRIED, WIDOW
} Marital_Status;
typedef enum {
	PRIMARY, SECONDARY, ACADEMIC_BACHELOR, PROFESSIONAL_BACHELOR, MASTER
} Highest_Education_Level;
typedef enum {
	BRUSSELS, FLANDERS, WALLONIA
} Region;

typedef struct {
	uint8_t age;
	Marital_Status marital_status;
	Highest_Education_Level highest_education;
	uint8_t employment_status;
	Region region;
} Person;

Person **read_n_people(int n, FILE *file);

/************************************************************************************************************
*                                                Oefening 7                                                 *
************************************************************************************************************/

/*
 * Zie https://dhavalkapil.com/blogs/Buffer-Overflow-Exploit/
 */
void secretFunction()
{
	printf("Congratulations!\n");
	printf("You have entered in the secret function!\n");
}

void echo()
{
	char buffer[20];
	printf("Enter some text:\n");
	scanf("%s", buffer);
	printf("You entered: %s\n", buffer);
}




int main(int argc, char *argv[]) {
	/* Oef 1 */
	printf("Oef 1\n");
	oef1();
	
	/* Oef 2 */
	printf("\n\nOef 2\n");
	oef2();
	
	/* Oef 7 */
//	printf("\n\nOef 7\n");
//	echo();

	return EXIT_SUCCESS;
}
