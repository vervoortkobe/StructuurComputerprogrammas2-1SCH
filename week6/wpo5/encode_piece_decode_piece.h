// https://dodona.be/en/courses/5451/series/63963/activities/1678941806
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

}

struct Chess_Piece decode_piece(uint16_t encoded) {

}