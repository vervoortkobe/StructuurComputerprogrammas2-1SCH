#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************************
 *                                                Oefening 1                                                *
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

/************************************************************************************************************
 *                                                Oefening 3                                                *
 ************************************************************************************************************/

Person *make_person(uint8_t age, Marital_Status marital_status,
                    Highest_Education_Level highest_education,
                    uint8_t employment_status, Region region) {
	Person *person = malloc(sizeof(Person));
	person->age = age;
	person->marital_status = marital_status;
	person->highest_education = highest_education;
	person->employment_status = employment_status;
	person->region = region;
	return person;
}

#define MAX_LINE_LENGTH 10
uint8_t read_number(FILE *file) {
	char buffer[MAX_LINE_LENGTH];
	fgets(buffer, MAX_LINE_LENGTH, file);
	return atoi(buffer);
}

Person *read_person(FILE *file) {
	uint8_t age = read_number(file);
	Marital_Status marital_status = read_number(file);
	Highest_Education_Level highest_education = read_number(file);
	uint8_t employment_status = read_number(file);
	Region region = read_number(file);
	return make_person(age, marital_status, highest_education, employment_status, region);
}

Person **read_n_people(int n, FILE *file) {
	Person **array = calloc(n, sizeof(Person*));
	for (int i = 0; i < n; i++) {
		array[i] = read_person(file);
	}
	return array;
}





int main(void) {
	return 0;
}
