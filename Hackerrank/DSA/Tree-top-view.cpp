// https://www.hackerrank.com/challenges/tree-top-view/problem

// incorrect

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

int loc = 0;

int max_left = 0;
int max_right = 0;

list<int> top;

void parseTree(Node *root) {

    // check for NULL
    if (root == NULL)
        return;

    // check root condition
    if (loc == 0 && max_left == 0 && max_right == 0)
        top.push_back(root->data);

    // check if leftmost yet
    if (loc < max_left)
    {
        top.push_front(root->data);
        max_left--;
    }
    
    // check if rightmost yet
    if (loc > max_right)
    {
        top.push_back(root->data);
        max_right++;
    }

    // make copy of loc
    int current_loc = loc;

    // go left
    loc--;
    parseTree(root->left);

    // reinistiallise loc
    loc = current_loc;

    // go right
    loc++;
    parseTree(root->right);

    return;
}

void topView(Node * root) {
    // start parsing the tree
    parseTree(root);

    // print the top view as a list
    for(auto it=top.begin(); it!=top.end(); it++)
        cout << *it << " ";
}
