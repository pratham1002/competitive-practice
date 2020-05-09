#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
} NODE;

NODE * newNode(int data)
{
    NODE *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL; 
    node->right = NULL; 
  
    return(node); 
}

void traverse(NODE *root)
{
    if(root->left!=NULL)
        traverse(root->left);

    printf("%d ", root->data);

    if (root->right!=NULL)
        traverse(root->right);
}

int main()
{
    int t,root_data;

    scanf("%d %d\n", &t, &root_data);

    NODE *root = newNode(root_data);

    printf("%d\n", root->data);

    // input tree
    for(int i = 0; i < t; i++)
    {
        NODE *current = root;
        char str[20];
        scanf("%[^\n]%*c", str);

        for (int i = 0; i < 20; i++)
        {            
            if(str[i] == 'L')
            {
                if(current->left == NULL)
                {
                    current->left = newNode(-1);
                    current = current->left;
                }
                else
                    current = current->left;                  
            }
            else if(str[i] == 'R')
            {
                if(current->right == NULL)
                {
                    current->right = newNode(-1);
                    current = current->right;
                }
                else
                    current = current->right;
            }
            else
            {
                int data;
                scanf("%d\n", &data);
                current->data = data;
                break;
            }
        }
    }

    traverse(root);

    return 0;
}