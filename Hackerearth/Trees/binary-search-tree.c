#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE * newNode(int data) {
    NODE *new_node = (NODE *)malloc(sizeof(NODE));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

NODE *insert(NODE *root, int data) {
    if (root == NULL) {
        return newNode(data);
    }   
    else {
        if(data <= root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

void preOrderTraversal(NODE *root) {
    if (root == NULL) {
        return;
    }
    else {
        printf("%d\n", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// prints subtree of a value
int findByValue(NODE *root, int data) {
    if (root==NULL) {
        return 0;
    }
    else {
        if (root->data == data) {
            preOrderTraversal(root);
            return 1;
        }
        else {
            if (!findByValue(root->left, data)) {
                return findByValue(root->right, data);
            } 
            else {
                return 1;
            }
        }
    }
}

int main() {
    int N, root_data;
    scanf("%d\n%d ", &N, &root_data);

    NODE *root = newNode(root_data);

    for (int i = 0; i < N - 1; i++) {
        int data;
        scanf("%d", &data);

        root = insert(root, data);
    }

    int Q;

    scanf("%d", &Q);

    int a = findByValue(root, Q);

    return 0;
}