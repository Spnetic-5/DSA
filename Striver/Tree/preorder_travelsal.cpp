class Solution {
    void preorderTraversal_Recursive(TreeNode* root, vector <int>& ans){
        if(!root) return;
        ans.push_back(root->val);
        preorderTraversal_Recursive(root->left, ans);
        preorderTraversal_Recursive(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderTraversal_Recursive(root, ans);
        return ans;
    }
};