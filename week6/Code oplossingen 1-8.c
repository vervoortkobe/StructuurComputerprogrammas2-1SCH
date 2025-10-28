#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************************
 *                                                Oefening 1                                                *
 ************************************************************************************************************/

void flatten(int multi[][2], int single[], int length) {
	int idx = 0;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 2; j++) {
			single[idx] = multi[i][j];
			idx++;
		}
	}
}

/************************************************************************************************************
 *                                                Oefening 2                                                *
 ************************************************************************************************************/

char *substring(char *str1, char *str2) {
	while (*str1 != '\0') {
		char *temp_str1 = str1;
		char *temp_str2 = str2;
		while (*temp_str1 != '\0' &&
             *temp_str2 != '\0' &&
             *temp_str1 == *temp_str2) {
			temp_str1++;
			temp_str2++;
		}
		if (*temp_str2 == '\0') {
			return str1;
		}
		str1++;
	}
	return NULL;
}

/************************************************************************************************************
 *                                                Oefening 3                                                *
 ************************************************************************************************************/

struct Point {
	int x;
	int y;
};

struct Rectangle {
	/* Het field lb verwijst naar het punt dat de linkerbovenhoek van de rechthoek voorstelt.
	 * Dit field stel dus de positie van de rechthoek voor. */
	struct Point lb;
	int width;
	int height;
};

/*
 * Let op dat je bij elk van deze functies een pointer naar de rechthoek moet meegeven ipv de rechthoek zelf.
 * Als je dit niet zou doen, zou de rechthoek helemaal niet veranderd worden buiten de scope van de functie zelf.
 */
void set_point(struct Point new_lb, struct Rectangle *r) {
	r->lb = new_lb;
	/*
	 * Dit is hetzelfde als:
	 * (*r).lb = new_lb;
	 */
}

void set_width(int new_width, struct Rectangle *r) {
	r->width = new_width;
}

void set_height(int new_height, struct Rectangle *r) {
	r->height = new_height;
}

/************************************************************************************************************
 *                                                Oefening 4                                                *
 ************************************************************************************************************/

struct date {
	int year, month, day;
};

void increment_day(struct date *date) {
	int max_days_in_current_month;
	switch (date->month) {
		case 2: max_days_in_current_month = 28; break;
		case 4: case 6: case 9: case 11: max_days_in_current_month = 30; break;
		default: max_days_in_current_month = 31; break;
	}

	if (date->day < max_days_in_current_month) {
		date->day = date->day + 1;
	} else if (date->month != 12) {
		date->day = 1;
		date->month = date->month + 1;
	} else {
		date->day = 1;
		date->month = 1;
		date->year = date->year + 1;
	}
}

/************************************************************************************************************
 *                                                Oefening 5                                                *
 ************************************************************************************************************/

struct Small_Point {
	unsigned char x;
	unsigned char y;
};

unsigned char encode(struct Small_Point point) {
	unsigned char shifted_x = point.x << 5;
	unsigned char encoded = shifted_x | point.y;
	return encoded;
}

struct Small_Point decode(unsigned char encoded) {
	unsigned char bitmask_x = 0b11100000; // uint8_t bitmask_x = 224;
	unsigned char shifted_x = encoded & bitmask_x;
	unsigned char x = shifted_x >> 5;

	unsigned char bitmask_y = 0b00011111; // uint8_t bitmask_y = 31;
	unsigned char y = encoded & bitmask_y;

	struct Small_Point decoded = { x, y };
	return decoded;
}

/* Geen deel van de oefening: test of de encoding en decoding voor een bepaald Point werkt. */
char test_encode(struct Small_Point original) {
	unsigned char encoded = encode(original);
	struct Small_Point decoded = decode(encoded);
	char is_same = original.x == decoded.x && original.y == decoded.y;
	return is_same;
}

/************************************************************************************************************
 *                                                Oefening 6                                                *
 ************************************************************************************************************/

#include <stdint.h>

enum Color {
	BLACK, WHITE
};
enum Type {
	PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING
};

struct Chess_Piece {
	enum Color color;
	enum Type type;
	unsigned char x;
	unsigned char y;
};

uint16_t encode_piece(struct Chess_Piece piece) {
	uint16_t shifted_color = piece.color << 9;
	uint16_t shifted_type = piece.type << 6;
	uint16_t shifted_x = piece.x << 3;
	uint16_t encoded = shifted_color | shifted_type | shifted_x | piece.y;
	return encoded;
}

struct Chess_Piece decode_piece(uint16_t encoded) {
	uint16_t bitmask_color = 0b0000001000000000;
	uint16_t bitmask_type =  0b0000000111000000;
	uint16_t bitmask_x =     0b0000000000111000;
	uint16_t bitmask_y =     0b0000000000000111;
	uint16_t shifted_color = encoded & bitmask_color;
	enum Color color = shifted_color >> 9;

	uint16_t shifted_type = encoded & bitmask_type;
	enum Type type = shifted_type >> 6;

	uint16_t shifted_x = encoded & bitmask_x;
	unsigned char x = shifted_x >> 3;

	unsigned char y = encoded & bitmask_y;

	struct Chess_Piece piece = {color, type, x, y};
	return piece;
}

/* Geen deel van de oefening: test of de encoding en decoding voor een bepaald Chess_Piece werkt. */
char test_encode_piece(struct Chess_Piece original) {
	uint16_t encoded = encode_piece(original);
	struct Chess_Piece decoded = decode_piece(encoded);
	char is_same = original.color == decoded.color && original.type == decoded.type && original.x == decoded.x && original.y == decoded.y;
	return is_same;
}

/************************************************************************************************************
 *                                                Oefening 7                                                *
 ************************************************************************************************************/

struct Timestamp {
	int hour;
	int minute;
	int second;
};

struct Timestamp calc_difference(struct Timestamp t1, struct Timestamp t2) {
	int total_seconds1 = t1.second + (t1.minute * 60) + (t1.hour * 3600);
	int total_seconds2 = t2.second + (t2.minute * 60) + (t2.hour * 3600);
	int difference = total_seconds1 - total_seconds2;

	int h_difference = difference / 3600;
	int m_difference = (difference % 3600) / 60;
	int s_difference = difference % 60;

	struct Timestamp result = { h_difference, m_difference, s_difference };
	return result;
}

/************************************************************************************************************
 *                                                Oefening 8                                                *
 ************************************************************************************************************/

void matrix_multiply(double matrix1[][4], double matrix2[][5], double result[][5]) {
  for (int row_index = 0; row_index < 3; row_index++) {
    for (int column_index = 0; column_index < 5; column_index++) {
      int sum = 0;
      for (int i = 0; i < 4; i++) {
        sum += matrix1[row_index][i] * matrix2[i][column_index];
      }
      result[row_index][column_index] = sum;
    }
  }
}

// Print een 3X5 matrix
void print_matrix(double result[][5]) {
	for (int row = 0; row < 3; row++) {
		printf("[");
		for (int column = 0; column < 5; column++) {
			printf("%g", result[row][column]);
			if (column != 4) { // Niet de laatste kolom (5 - 1)
				printf(",");
			}
		}
		printf("]\n");
	}
}

int main(void) {
	/* Oef 1 */
	printf("Oef 1\n");
	int multi[6][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}};
	int single[12];
	flatten(multi, single, 6);

	for (int i = 0; i < 12; i++) {
		printf("%i ", single[i]);
	}
	printf("\n");

	/* Oef 2 */
	printf("\n\nOef 2\n");
	char string1[] = "abcdefgh";
	char string2[] = "def";
	char *result = substring(string1, string2);
	if (result == NULL) {
		printf("%s is not a substring of %s\n", string2, string1);
	} else {
		printf("%s is a substring of %s and starts from %s\n", string2, string1, result);
	}

	/* Oef 3 */
	printf("\n\nOef 3\n");
	struct Point lb = {10, 10};
	struct Rectangle rectangle = {lb, 1, 2};
	struct Point new_lb = {20, 20};
	printf("lb.x = %i\n", rectangle.lb.x);
	set_point(new_lb, &rectangle);
	printf("lb.x = %i\n", rectangle.lb.x);

	/* Oef 4 */
	printf("\n\nOef 4\n");
	struct date d = {.year = 2021, .month = 10, .day = 31};
	printf("Old date: %i/%i/%i\n", d.day, d.month, d.year);
	increment_day(&d);
	printf("New date: %i/%i/%i\n", d.day, d.month, d.year);

	/* Oef 5 */
	printf("\n\nOef 5\n");
	// Test of de encoding en decoding werkt voor alle mogelijke waarden van x en y.
	char oef_5_flag = 1;
	for (unsigned char x = 0; x < 8; x++) {
		for (unsigned char y = 0; y < 32; y++) {
			struct Small_Point original_point = { x, y };
			char is_same = test_encode(original_point);
			if (!is_same) {
				oef_5_flag = 0;
				printf("Fout bij het encoderen/decoderen van Small_Point (%i;%i)\n", x, y);
			}
		}
	}
	if (oef_5_flag) {
		printf("Geen fouten bij het encoderen/decoderen van alle mogelijke Small_Points");
	} else {
		printf("Fout opgemerkt bij het encoderen/decoderen van minstens 1 Small_Point");
	}


	/* Oef 6 */
	printf("\n\nOef 6\n");
	// Test of de encoding en decoding werkt voor alle mogelijke waarden van de kleur, het type, en de x- en y-positie van een Chess_Piece
	char oef_6_flag = 1;
	for (enum Color c = 0; c < 2; c++) {
		for (enum Type t = 0; t < 6; t++) {
			for (unsigned char x = 0; x < 8; x++) {
				for (unsigned char y = 0; y < 8; y++) {
					struct Chess_Piece original_piece = { c, t, x, y };
					char is_same = test_encode_piece(original_piece);
					if (!is_same) {
						oef_6_flag = 0;
						printf("Fout bij het encoderen/decoderen van Chess_Piece (%i;%i;%i;%i)\n", c, t, x, y);
					}
				}
			}
		}
	}
	if (oef_6_flag) {
		printf("Geen fouten bij het encoderen/decoderen van alle mogelijke Chess_Piece");
	} else {
		printf("Fout opgemerkt bij het encoderen/decoderen van minstens 1 Chess_Piece");
	}

	/* Oef 7 */
	printf("\n\nOef 7\n");
	struct Timestamp diff = calc_difference((struct Timestamp) {11, 2, 3}, (struct Timestamp) {10, 0, 0});
	printf("Verschil is %i uren, %i minuten en %i seconden\n", diff.hour, diff.minute, diff.second);

	/* Oef 8 */
	printf("\n\nOef 8\n");
	//                     K1  K2  K3  K4
	double matrix1[][4] = {{1,  2,  3,  4}, // rij 1
                           {5,  6,  7,  8}, // rij 2
                           {9, 10, 11, 12}  // rij 3
	};

	//                      K1  K2  K3  K4  K5
	double matrix2[][5] = {{20, 19, 18, 17, 16}, // rij 1
                           {15, 14, 13, 12, 11}, // rij 2
                           {10,  9,  8,  7,  6}, // rij 3
                           { 5,  4,  3,  2,  1}  // rij 4
	};
	double matrix_result[3][5];

	matrix_multiply(matrix1, matrix2, matrix_result);
	print_matrix(matrix_result);
}
