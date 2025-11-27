// https://dodona.be/en/courses/5451/series/63967/activities/1014294880
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void search_file(char *string, char *path) {
  int MAX_LINE_LENGTH = 1024;
  FILE *file = fopen(path, "r");

  if (file == NULL) {
    fprintf(stderr, "Fout: kan bestand '%s' niet openen\n", path);
    return;
  }

  char line[MAX_LINE_LENGTH];

  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    if (strstr(line, string) != NULL) {
      printf("%s", line);
    }
  }

  fclose(file);
}

int main(int argc, char *argv[]) {
  if (argc <2) {
    printf("Niet genoeg argumenten meegegeven.");
    return 1;
  } else {
    for (int i = 2; i < argc; i++) {
      search_file(argv[1], argv[i]);
    }
  }
  return 0;
}