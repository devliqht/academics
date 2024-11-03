#include <stdio.h>

int main() {
    int mark;
    printf("Enter student marks out of 100: "); scanf("%d", &mark);

    switch ((mark-1) / 10) {
        /*
            Let's say 80: 
            80-1 = 79
            79 / 10 = 7.9 (7); 
            case 7: Grade B

            Let's say 71:
            71 - 1 = 70;
            70 / 10 = 7;
            case 7: Grade B

            Let's say 70:
            70 - 1 = 69;
            69 / 10 = 6.9 (6);
            case 6: Grade C;
        */
        case 8:
        case 9:
        case 10:
            printf("Your grade is A");
            break;
        case 7:
            printf("Your grade is B");
            break;
        case 6:
            printf("Your grade is C");
            break;
        default:
            printf("Your grade is D");
            break;
    }
}