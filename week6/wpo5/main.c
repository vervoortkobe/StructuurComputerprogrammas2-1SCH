#include "flatten.h"

int main(void) {
    int multi[][2] = {{1, 2},{3, 4},{5, 6},{7, 8}};
    int length = sizeof(multi) / sizeof(multi[0]);
    int single[length * 2];
    flatten(multi, single, length);
    return 0;
}