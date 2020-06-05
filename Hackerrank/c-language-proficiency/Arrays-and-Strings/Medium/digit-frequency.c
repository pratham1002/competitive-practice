#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char s[1000];
    scanf("%s", s);
    int count[10] = {0};

    for (int i = 0; i < strlen(s); i++) {
        if ((int) s[i] >= 48 && (int) s[i] <= 57) {
            count[(int) s[i] - 48] += 1;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", count[i]);
    }
    return 0;
}
