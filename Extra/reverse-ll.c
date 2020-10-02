#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
} list;


void  print(list *l) {
    if (l == NULL) {
        printf("\n");
        return;
    }
    else {
        printf("%d ", l->data);
        return print(l->next);
    }
}

void push_front(list **l, int x) {
    list *p;

    p = malloc(sizeof(list));
    p->data = x;
    p->next = *l;
    *l = p;
}

void reverse(list *l, list**h) {
    if (l->next == NULL) {
        *h = l;
        return;
    }

    reverse(l->next, h);
    (l->next)->next = l;
    l->next = NULL;
}

int main() {
    list *head = NULL;
    push_front(&head, 4);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 1);
    print(head);
    reverse(head, &head);
    print(head);
    return 0;
}