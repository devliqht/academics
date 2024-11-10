#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int arr[100][100];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int result = 1;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int k, l;
            for(k=i; k<rows; k++) {
                for(l=j; l<cols; l++) {
                    int flag = 1;
                    for(int p=i; p<=k; p++) {
                        for(int q=j; q<=l; q++) {
                            if(arr[p][q] != arr[i][j]) {
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 0)
                            break;
                    }
                    if(flag == 1)
                        result = max(result, (k-i+1)*(l-j+1));
                }
            }
        }
    }
    printf("The largest submatrix with equal elements has size %d\n", result);
    return 0;
}