// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

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

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

bool searchVal(Node *root, int val) {
    // cout << "search for " << val << endl;
    if (root == NULL) {
        return false;
    }
    else if (root->data == val) {
        return true;
    } 
    else if (val < root->data) {
        return searchVal(root->left, val);
    }
    else {
        return searchVal(root->right, val);
    }
        
}


Node *lca(Node *root, int v1,int v2) {
		// Write your code here.

    if (root == NULL) {
        return NULL;
    }

    int min, max;
    if (v1<v2) {
        min = v1;
        max = v2;
    }
    else {
        min = v2;
        max = v1;
    }
    // cout << "min = " << min << " max = " << max << endl;
    // the values are located on different sides of the root

    if (min == root->data && searchVal(root->right, max)) {
        return root;
    }
    else if (max == root->data && searchVal(root->left, min)) {
        return root;
    }
    else if (searchVal(root->left, min) && searchVal(root->right, max)) {
        return root;
    }
    else {
        if (max < root->data) {
            return lca(root->left, v1, v2);
        }
        else {
            return lca(root->right, v1, v2);
        }
    }

}

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}
