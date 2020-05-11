#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> traversal;

int level = -1;

void traverse(TreeNode* root)
{
    if (root == NULL)
        return;

    level++;

    if (traversal.size() == level)
        traversal.push_back({});
        
    traversal[level].push_back(root->val);
    traverse(root->left);

    traverse(root->right);

    level--;
}