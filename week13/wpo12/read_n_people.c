// https://dodona.be/en/courses/5451/series/63969/activities/917738736
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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

Person *make_person(uint8_t age, Marital_Status marital_status,
                    Highest_Education_Level highest_education,
                    uint8_t employment_status, Region region) {
  Person *p = malloc(sizeof(Person));
  if (p == NULL) return NULL;
  p->age = age;
  p->marital_status = marital_status;
  p->highest_education = highest_education;
  p->employment_status = employment_status;
  p->region = region;
  return p;
}

#define MAX_LINE_LENGTH 10
uint8_t read_number(FILE *file) {
  char buffer[MAX_LINE_LENGTH];
  if (fgets(buffer, MAX_LINE_LENGTH, file) == NULL) {
    return 0;
  }
  return (uint8_t)atoi(buffer);
}

Person *read_person(FILE *file) {
  uint8_t age = read_number(file);
  Marital_Status marital_status = (Marital_Status)read_number(file);
  Highest_Education_Level highest_education = (Highest_Education_Level)read_number(file);
  uint8_t employment_status = read_number(file);
  Region region = (Region)read_number(file);
  return make_person(age, marital_status, highest_education, employment_status, region);
}

Person **read_n_people(int n, FILE *file) {
  Person **array = malloc(n * sizeof(Person *));
  if (array == NULL) return NULL;

  for (int i = 0; i < n; i++) {
    array[i] = read_person(file);
  }
  return array;
}

void deallocate_people(Person** array, int n) {
  if (array == NULL) return;
  for (int i = 0; i < n; i++) {
    free(array[i]);
  }
  free(array);
}

int main() {
  FILE *file = fopen("people.txt", "r");
  if (file == NULL) {
    perror("Failed to open file");
    return 1;
  }

  int n = 3;
  Person **people = read_n_people(n, file);
  fclose(file);

  if (people != NULL) {
    deallocate_people(people, n);
  }

  return 0;
}