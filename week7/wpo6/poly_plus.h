// https://dodona.be/en/courses/5451/series/63964/activities/196666416
#include <stdlib.h>
#include <string.h>

enum type {
	INT, CHAR, STRING, ERROR
};

union poly {
	int integer;
	char character;
	char *string;
};

struct variant {
	union poly u;
	enum type type;
};

struct variant *plus(struct variant a, struct variant b) {
	struct variant *result = (struct variant *) malloc(sizeof(struct variant));
	if (a.type == INT && b.type == INT) { //ints -> som
		result->type = INT;
		result->u.integer = a.u.integer + b.u.integer;
		return result;
	} else if (a.type == CHAR && b.type == CHAR) { //chars -> string
		char *new_string = (char *) calloc(2 + 1, sizeof(char));
		sprintf(new_string, "%c%c", a.u.character, b.u.character);
		result->type = STRING;
		result->u.string = new_string;
		return result;
	} else if (a.type == STRING && b.type == STRING) { //strings -> concat
		char *new_string = (char *) calloc(strlen(a.u.string) + strlen(b.u.string) + 1, sizeof(char));
		strcat(new_string, a.u.string);
		strcat(new_string, b.u.string);
		result->type = STRING;
		result->u.string = new_string;
		return result;
	} else {
		result->type = ERROR;
		return result;
	}
}