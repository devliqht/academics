#include <stdio.h>
#include <limits.h>

int main(void) {
    unsigned long unsigned_example = ULONG_MAX; // Unsigned 64-bit Integer
    long signed_example_pos = LONG_MAX;         // Signed 64-bit Integer (High)
    long signed_example_neg = LONG_MIN;         // Signed 64-bit Integer (Low)

    printf("Unsigned 64-bit integer range: \n");
    printf("%d - %lu\n", 0, unsigned_example);


    printf("\nSigned 64-bit integer range: \n");
    printf("%ld - %ld\n", signed_example_neg, signed_example_pos);

    return 0;
}