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

// creates a new node returns a pointer to the node
NODE * newNode(int data)
{
    NODE *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL; 
    node->right = NULL;

    return (node);
}

// in-order traversal of the tree by recursive method
void traverse(NODE *root)
{
    if(root->left!=NULL)
        traverse(root->left);

    printf("%d -> ", root->data);

    if (root->right!=NULL)
        traverse(root->right);
}

NODE *node_mirror = NULL;

// search a node by its value
NODE * findNode(NODE *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
        return root;

    NODE *mirror_copy = node_mirror;

    if (node_mirror != NULL)
        node_mirror = node_mirror->right;   

    NODE *searchLeft = findNode(root->left, val);

    if (searchLeft != NULL)
        return searchLeft;

    node_mirror = mirror_copy;

    if (node_mirror != NULL)
        node_mirror = node_mirror->left;

    NODE *searchRight = findNode(root->right, val);
    
    if (searchRight != NULL)
        return searchRight;

    return NULL;
}

int main()
{
    int N, Q;

    // input root data value and number of nodes 
    scanf("%d %d\n", &N, &Q);
    NODE *root = newNode(1);

    // input tree
    for(int i = 0; i < N-1; i++)
    {
        int parent_val, data;
        char side;

        scanf("%d %d %c", &parent_val, &data, &side);

        NODE *parent_node = findNode(root, parent_val);

        if (side == 'L')
            parent_node->left = newNode(data);

        if (side == 'R')
            parent_node->right = newNode(data);
    }

    // mirror images
    for (int i = 0; i < Q; i++)
    {
        int val;
        scanf("%d", &val);
        node_mirror = root;
        NODE *node = findNode(root, val);

        if (node_mirror != NULL)
            printf("%d\n", node_mirror->data);
        else
            printf("-1\n");
    }

        return 0;
}