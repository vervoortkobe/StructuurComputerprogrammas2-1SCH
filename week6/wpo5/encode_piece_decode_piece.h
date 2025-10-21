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
  uint16_t shifted_color = piece.color << 9;
  uint16_t shifted_type = piece.type << 6;
  uint16_t shifted_x = piece.x << 3;
  return shifted_color | shifted_type | shifted_x | piece.y;
}

struct Chess_Piece decode_piece(uint16_t encoded) {
  uint16_t bitmask_color = 0b0000001000000000;
  uint16_t shifted_color = encoded & bitmask_color;
  enum Color color = shifted_color >> 9;

  uint16_t bitmask_type = 0b0000000111000000;
  uint16_t shifted_type = encoded & bitmask_type;
  enum Type type = shifted_type >> 6;

  uint16_t bitmask_x = 0b0000000000111000;
  uint16_t shifted_x = encoded & bitmask_x;
  unsigned char x = shifted_x >> 3;

  uint16_t bitmask_y = 0b0000000000000111;
  unsigned char y = encoded & bitmask_y;

  struct Chess_Piece piece = {color, type, x, y};
  return piece;
}