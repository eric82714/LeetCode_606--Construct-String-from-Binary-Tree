# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if not t: return ""
        result = self.dfs(t)
        return result[1:-1]
    
    def dfs(self, tree):
        if not tree: return "()"
            
        s = "(" + str(tree.val) 
        l = self.dfs(tree.left)
        r = self.dfs(tree.right)
        
        if r != "()": s += l + r 
        elif l != "()": s += l
        
        s += ")"
        
        return s
