// https://dodona.be/en/courses/5451/series/63964/activities/2094473334

enum Color {
	BLACK, WHITE
};
enum Type {
	PAWN, BISHOP, KNIGHT, ROOK, QUEEN, KING
};

struct Piece {
	enum Color color;
	enum Type type;
};

#include <stdlib.h>
#include <stdio.h>

struct Piece *make_piece(enum Color color, enum Type type) {
	struct Piece *p = malloc(sizeof(struct Piece));
	p->color = color;
	p->type = type;
	return p;
}

struct Piece **read_chess_pieces(int n) {
	struct Piece **array = malloc(n * sizeof(struct Piece *));
	for (int i = 0; i < n; i++) {
		char c;
		scanf(" %c", &c);
		switch (c) {
			case 'P': array[i] = make_piece(BLACK, PAWN); break;
			case 'p': array[i] = make_piece(WHITE, PAWN); break;
			case 'B': array[i] = make_piece(BLACK, BISHOP); break;
			case 'b': array[i] = make_piece(WHITE, BISHOP); break;
			case 'N': array[i] = make_piece(BLACK, KNIGHT); break;
			case 'n': array[i] = make_piece(WHITE, KNIGHT); break;
			case 'R': array[i] = make_piece(BLACK, ROOK); break;
			case 'r': array[i] = make_piece(WHITE, ROOK); break;
			case 'Q': array[i] = make_piece(BLACK, QUEEN); break;
			case 'q': array[i] = make_piece(WHITE, QUEEN); break;
			case 'K': array[i] = make_piece(BLACK, KING); break;
			case 'k': array[i] = make_piece(WHITE, KING); break;
		}
	}
	return array;
}

void free_chess_pieces(struct Piece **array, int n) { //free each piece and the array itself
	if (array == NULL) return;
	for (int i = 0; i < n; i++) {
		if (array[i] != NULL) free(array[i]);
	}
	free(array);
}