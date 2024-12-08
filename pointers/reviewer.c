#include <stdio.h>

int f(int* p, int* q) {
    /*
        *p = &i; == 0
        *q = &j; == 1;
    */
    p = q;  // *p = q == &j == 1; p now points to the same address as q, which is &j
    *p = 2; // Editing *p will edit the value of the address it's pointing to, &j, to 2. (So from 1 to 2)
    return *q; // returns 2 since *q is still pointing to j.
}
int main(void) {
    int i = 0, j = 1, k;
    k = f(&i, &j); // k == 2, since return *q == return 2;
    if (j == k) printf("%d", k); // 2 == 2 so it prints

    // Bingo
    return 0;
}