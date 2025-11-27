// https://dodona.be/en/courses/5451/series/63967/activities/489422191
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info {
  char *name, *location, *year_of_birth;
} Info;

void insert_person(char *database_path, struct info *info) {
  FILE *db = fopen(database_path, "a");
  fprintf(db, "%s\n%s\n%s\n", info->name, info->location, info->year_of_birth);
  fclose(db);
}

Info *find_person(char *database_path, char *name) {
  FILE *db = fopen(database_path, "r");
  char *name_read = calloc(1000, sizeof(char)); // NIET: char name_read[1000];
  char *location_read = calloc(1000, sizeof(char));
  char *year_of_birth_read = calloc(1000, sizeof(char));
  while (fgets(name_read, 1000, db) != NULL) {
    fgets(location_read, 1000, db);
    fgets(year_of_birth_read, 1000, db);

    name_read[strcspn(name_read, "\n")] = '\0';
    location_read[strcspn(location_read, "\n")] = '\0';
    year_of_birth_read[strcspn(year_of_birth_read, "\n")] = '\0';

    if (strcmp(name_read, name) == 0) {
      Info *info_found = malloc(sizeof(Info));
      info_found->name = name_read;
      info_found->location = location_read;
      info_found->year_of_birth = year_of_birth_read;
      fclose(db);
      return info_found;
    }
  }
  free(name_read);
  free(location_read);
  free(year_of_birth_read);
  fclose(db);
  return NULL;
}