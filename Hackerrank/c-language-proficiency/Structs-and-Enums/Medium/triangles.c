#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double area(triangle tr) {
    double a = tr.a;
    double b = tr.b;
    double c = tr.c;

    double s = (a + b + c) / 2;

    return sqrt(s*(s-a)*(s-b)*(s-c));
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/

    // find the areas
    double areas[n];

    for(int i = 0; i < n; i++) {
        areas[i] = area(*(tr+i));
    }
    
    // selection sort simulataneously on areas and trinagle

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (areas[j] < areas[min]) {
                min = j;
            }
        }

        // exchange i and min

        // first for areas
        double temp = areas[min];
        areas[min] = areas[i];
        areas[i] = temp;

        // for triangle
        triangle *ptr = (triangle*)malloc(sizeof(triangle));
        *ptr = *(tr + min);
        *(tr + min) = *(tr + i);
        *(tr + i) = *ptr;
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}