#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) return result;

    map<int, vector<int>> mp;
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        TreeNode* node = front.first;
        int col = front.second;

        mp[col].push_back(node->val);

        if (node->left)
            q.push({node->left, col - 1});

        if (node->right)
            q.push({node->right, col + 1});
    }

    for (auto it : mp) {
        result.push_back(it.second);
    }

    return result;
}

int main() {
    /*
            3
          /   \
         9     20
              /  \
             15   7
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = verticalOrder(root);

    for (auto col : ans) {
        for (int x : col) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}