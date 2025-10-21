// https://dodona.be/en/courses/5451/series/63963/activities/1745565750
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
	unsigned char bitmask_x = 0b11100000;
	unsigned char shifted_x = encoded & bitmask_x;
	unsigned char x = shifted_x >> 5;
	unsigned char bitmask_y = 0b00011111;
	unsigned char y = encoded & bitmask_y;
	struct Small_Point decoded = {x, y};
	return decoded;
}