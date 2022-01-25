class Solution {
public:
    
      void postorderTraversal_Recursive(TreeNode* root, vector <int>& ans){
        if(!root) return;
        postorderTraversal_Recursive(root->left, ans);
        postorderTraversal_Recursive(root->right, ans);
          ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorderTraversal_Recursive(root, ans);
        return ans;
    }
};