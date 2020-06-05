#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b) {
    return (strcmp(a, b) > 0);
}

void swap(char** a, char** b) {
    char **temp = (char **)malloc(sizeof(char *));

    *temp = *a;
    *a = *b;
    *b = *temp;
}

int next_permutation(int n, char **s) {
    // printf("n = %d\n", n);
    if (n == 2)
    {
        // printf("n is 2 and the compare function returns = %d for parameter 1 as %s , 2 as %s\n", strcmp(*(s), *(s + 1)), *s, *(s+1));
        // check if they are in lexographic, if true swap them
        if (strcmp(*(s), *(s + 1)) < 0) {
            swap(s, s + 1);
            return 1;
        }
        else {
            return 0;
        }
    }
    // if n > 2 then recursively call make_permutation and exclude the first element
    int m = next_permutation(n - 1, s + 1);

    // if m is 1 then the function succussfully swapped the 2 numbers else a reordering is required
    if (m == 0) {
        // if reordering not possible return 0
        if(strcmp(*(s), *(s + 1)) >= 0) {
            return 0;
        }
        else {
            // now rearrange
            // the smallest element greater than the first one takes its place
            
            int i, flag = 0;

            for (i = 1; i < n; i++) {
                if (strcmp(*s,*(s+i)) >= 0) {
                    flag = 1;
                    // printf("loop breaks at i = %d\n", i);
                    break;
                }
            }
            // printf("flag = %d\n", flag);
            if (flag) {
                // printf("swaping %s, %s\n", *s, *(s + i - 1));
                swap(s, s + i - 1);
            }
            else {
                // printf("swaping %s, %s\n", *s, *(s + n - 1));
                swap(s, s + n - 1);
            }
            s = s + 1;
            n -= 1;

            //  other elements are sorted lexographically
            for(i = 0; i < n - 1; i++) {
                for(int j = 0; j < n - i - 1; j++) {
                    if(lexicographic_sort(*(s+j), *(s + j +1))) {
                        swap(s + j, s + j + 1);
                    }
                }
            }
                
            return 1;
        }
    }
    else {
        return 1;
    }
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}