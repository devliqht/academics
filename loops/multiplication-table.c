#include <stdio.h>

/*
    Create a program that takes two numbers m and n as input and prints out a multiplication table 
    from 1 x 1 up to m x n.

    Enter the value of m: 5
    Enter the value of n: 5
    1	2	3	4	5
    2	4	6	8	10
    3	6	9	12	15
    4	8	12	16	20
    5	10	15	20	25

    Enter the value of m: 3
    Enter the value of n: 2
    1	2
    2	4
    3	6
*/

int main(void) {
    int m, n;
    printf("Enter the value of m: "); scanf("%d", &m);
    printf("Enter the value of n: "); scanf("%d", &n);

    /*
        m = rows
        n = columns
    */

   for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", j*i);
        }
        printf("\n");
   }


   return 0;
}