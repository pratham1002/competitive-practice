#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return (strcmp(a, b) > 0);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return (strcmp(a, b) < 0);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int c_a[26] = {0};
    int c_b[26] = {0};

    for (int i = 0; i < strlen(a); i++) {
        c_a[*(a + i) - 'a'] = 1;
    }

    for (int i = 0; i < strlen(b); i++) {
        c_b[*(b + i) - 'a'] = 1;
    }

    int distinct_a = 0;
    int distinct_b = 0;

    for (int i = 0; i < 26; i++) {
        if (c_a[i] == 1) {
            distinct_a += 1;
        }
        if (c_b[i] == 1) {
            distinct_b += 1;
        }
    }

    if (distinct_a == distinct_b) {
        return lexicographic_sort(a, b);
    }
    else {
        return distinct_a > distinct_b;
    }
}

int sort_by_length(const char* a, const char* b) {
    int l_a = strlen(a);
    int l_b = strlen(b);

    if (l_a == l_b) {
        return lexicographic_sort(a, b);
    }
    else {
        return (l_a > l_b);
    }
}

void swap(char** a, char** b) {
    char **temp = (char **)malloc(sizeof(char *));

    *temp = *a;
    *a = *b;
    *b = *temp;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    // implement bubble sort    
    unsigned int i, j;

    for(i = 0; i < len - 1; i++) {
        for(j = 0; j < len - i - 1; j++) {
            if(cmp_func(*(arr+j), *(arr+j+1))) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}