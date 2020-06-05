#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for (int i = 1; i <= 2*n - 1; i++) {
        // upper half
        if (i <= n) {
            // first part
            for (int j = n; j >= n - i + 1; j--) {
                printf("%d ", j);
            }
            // second part
            for (int j = 1; j <= n - i; j++) {
                printf("%d ", n - i + 1);
            }
            // third part
            for (int j = 1; j <= n - i; j++) {
                printf("%d ", n - i + 1);
            }
            // fourth part
            for (int j = n - i + 1; j < n; j++) {
                printf("%d ", j+1);
            }
        }
        else {
            int p = i - n;
            for (int j = n; j >= p + 1; j--) {
                printf("%d ", j);
            }
            // second part
            for (int j = 1; j <= p; j++) {
                printf("%d ", p + 1);
            }
            // third part
            for (int j = 1; j <= p; j++) {
                printf("%d ", p + 1);
            }
            // fourth part
            for (int j = p + 1; j < n; j++) {
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }
    return 0;
}
