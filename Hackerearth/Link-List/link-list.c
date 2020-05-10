#include <stdio.h>
#include <stdlib.h>

// node of the linked-list data structure
typedef struct NODE
{
    int data;
    struct NODE *next;
} node;

/* print the linked list */
void print_list(node **head)
{
    node *current = *head;

    while(current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("\n");

    return;
}

/* Given a reference (pointer to pointer) to the head of a list 
   and an int,  inserts a new node on the front of the list. */
void push_front(node **head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}    

/* Given a reference (pointer to pointer) to the head 
   of a list and an int, appends a new node at the end  */
void push_back(node **head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = data;
    new_node->next = NULL;

    // if link list is empty then head is set to inserted element
    if((*head) == NULL)
        (*head) = new_node;
    else
    {
        node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

/*insert element into the linked list, index begins with 0*/
void push_at_index(node **head, int insert_index, int data)
{
    if(insert_index == 0)
    {
        return (push_front(head, data));
    }
    else 
    {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        node *current = *head;
        node *current_forward = current;
        current_forward = current_forward->next;
        
        int current_index = 1;

        while (current_forward->next != NULL && current_index != insert_index)
        {  
            current_forward = current_forward->next;
            current = current->next;
            current_index += 1;
        }

        if(current_index == insert_index)
        {
            new_node->next = current_forward;
            current->next = new_node;

            return;
        }
        else if(current_index == insert_index -1)
        {
            free(new_node);
            return (push_back(head, data));
        }
        else
        {
            free(new_node);
            printf("Invalid insertion attempt\n");
            return;
        }
    }
}

int main()
{
    node *head = NULL;

    // push_back(&head, -1);
    // push_front(&head, 0);
    // push_front(&head, 1);
    // push_back(&head, 2);
    // push_back(&head, 3);
    // push_at_index(&head, 5, 100);
    // print_list(&head);

    return 0;
}