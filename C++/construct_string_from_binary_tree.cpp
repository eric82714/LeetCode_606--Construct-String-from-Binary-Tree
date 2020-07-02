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
    string dfs(TreeNode* tree) {
        if(!tree) return "()";
            
        string s = "(" + to_string(tree->val); 
        string l = dfs(tree->left);
        string r = dfs(tree->right);
        
        if(r != "()") s += l + r;
        else if(l != "()") s += l;
        
        s += ")";
        
        return s;
    }
            
    string tree2str(TreeNode* t) {
        if(!t) return "";
        string result = dfs(t); 
        return result.substr(1, result.size()-2);
    }
};
