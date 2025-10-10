// https://dodona.be/en/courses/5451/series/63961/activities/71402181
void rotate(int *pa, int *pb, int *pc) {
    int nexta = *pb;
    int nextb = *pc;
    int nextc = *pa;
    *pa = nexta;
    *pb = nextb;
    *pc = nextc;
}