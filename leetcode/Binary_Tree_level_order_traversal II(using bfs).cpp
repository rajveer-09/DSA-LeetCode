// 107. Binary Tree Level Order Traversal II

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

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // If the tree is empty, return an empty vector
        if (!root) return {};

        // Queue to help with level order traversal (BFS)
        queue<TreeNode*> q;

        // This will store the result in top-down order first
        vector<vector<int>> result;

        // Start BFS from the root
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); // Number of nodes at the current level
            vector<int> levelNodes; // To store nodes of this level

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front(); // Get the front node in the queue
                q.pop(); // Remove it from the queue

                // Add its value to the current level's list
                levelNodes.push_back(current->val);

                // Add children to the queue for next level
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            // Add the current level's nodes to the result
            result.push_back(levelNodes);
        }

        // Reverse the result to get bottom-up order
        reverse(result.begin(), result.end());

        return result;
    }
};
