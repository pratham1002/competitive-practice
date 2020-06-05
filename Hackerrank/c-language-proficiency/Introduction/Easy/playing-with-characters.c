#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char ch;
    char word[100];
    char sentence[100];

    scanf("%c", &ch);
    printf("%c\n", ch); 
    scanf("%s\n", word);
    printf("%s\n", word);
    scanf("%[^\n]%*c", sentence);
    printf("%s", sentence);
    return 0;
}
