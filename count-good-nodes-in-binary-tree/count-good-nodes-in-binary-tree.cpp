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
    
    int cnt = 0;
    
    void func(TreeNode* root,int mx){
        if(root==NULL) return;
        if(mx<=root->val) cnt++;
        mx=max(mx,root->val);
        func(root->left,mx);
        func(root->right,mx);
    }
    
    int goodNodes(TreeNode* root) {
    
        cnt = 0;
        func(root,-100000);
        return cnt;
    }
};