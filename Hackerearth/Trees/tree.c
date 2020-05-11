#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// node structure
typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
} NODE;

// createes a new node returns a pointer to the node
NODE * newNode(int data)
{
    NODE *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL; 
    node->right = NULL; 
  
    return(node); 
}

// in-order traversal of the tree by recursive method
void traverse(NODE *root)
{
    if(root->left!=NULL)
        traverse(root->left);

    printf("%d ", root->data);

    if (root->right!=NULL)
        traverse(root->right);
}

// maximum height of a tree
int tree_height(NODE *root)
{
    if (root == NULL)
        return 0;

    int lh = tree_height(root->left);
    int rh = tree_height(root->right);

    return ((lh > rh) ? (lh + 1) : (rh + 1));
}

/* check if tree is height balanced.
a binary tree in which the left and right subtrees of every node differ in height by no more than 1. */
bool isBalanced(NODE *root)
{
    if(root==NULL)
        return true;
    int lh = tree_height(root->left);
    int rh = tree_height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

int main()
{
    int t, root_data;

    // input root data value and number of nodes 
    scanf("%d %d\n", &t, &root_data);

    NODE *root = newNode(root_data);

    // input tree
    for(int i = 0; i < t-1; i++)
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

    // print in-order traversal of the tree

    printf("in-order traversal: \n");

    traverse(root);

    printf("\n");

    int max_height = tree_height(root);

    printf("%d\n", max_height);

    printf("%d\n", isBalanced(root));

    return 0;
}