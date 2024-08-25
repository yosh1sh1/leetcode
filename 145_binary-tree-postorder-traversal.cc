#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> bfs(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        vector<int> res;
        while (!que.empty()) {
            TreeNode* p = que.front();
            que.pop();
            if (p == nullptr) continue;

            res.push_back(p->val);
            que.push(p->right);
            que.push(p->left);
        }

        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;

        dfs(root->left, vec);
        dfs(root->right, vec);
        vec.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        // return bfs(root);

        vector<int> res;
        dfs(root, res);
        return res;
    }
};

int main() {
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);

    t1.right = &t2;
    t2.left = &t3;

    Solution sol;
    vector<int> res = sol.postorderTraversal(&t1);

    for (auto v : res) {
        cout << v << ", ";
    }
    cout << endl;

    return 0;
}
