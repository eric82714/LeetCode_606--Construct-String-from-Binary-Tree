/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char* dfs(struct TreeNode* tree){
    if(!tree) return "()";
    
    char* l = dfs(tree->left);
    char* r = dfs(tree->right);
    char* s = malloc((strlen(l)+strlen(r)+10) * sizeof(char));
    *(s+0) = '(';
    int index = 1;
    if(tree->val < 0 && tree->val > -10){
        *(s+(index++)) = '-';
        *(s+(index++)) = '0' + abs(tree->val);
    }
    else if(tree->val <= -10 && tree->val > -100){
        *(s+(index++)) = '-';
        *(s+(index++)) = '0' + (abs(tree->val)/10);
        *(s+(index++)) = '0' + (abs(tree->val)%10);
    }
    else if(tree->val <= -100 && tree->val > -1000){
        *(s+(index++)) = '-';
        *(s+(index++)) = '0' + (abs(tree->val)/100);
        *(s+(index++)) = '0' + ((abs(tree->val)-100*(abs(tree->val)/100)) /10);
        *(s+(index++)) = '0' + (abs(tree->val)%100);
    }
    else if(tree->val >= 0 && tree->val < 10) 
        *(s+(index++)) = '0' + tree->val;
    else if(tree->val >= 10 && tree->val < 100){
        *(s+(index++)) = '0' + (tree->val/10);
        *(s+(index++)) = '0' + (tree->val%10);
    }
    else if(tree->val >= 100 && tree->val < 1000){
        *(s+(index++)) = '0' + (tree->val/100);
        *(s+(index++)) = '0' + ((tree->val-100*(tree->val/100)) /10);
        *(s+(index++)) = '0' + (tree->val%100);
    }
    
    if(strcmp(r, "()") != 0){
        for(int i = 0; i < strlen(l); i++, index++)
            *(s+index) = *(l+i);
        for(int j = 0; j < strlen(r); j++, index++)
            *(s+index) = *(r+j);
    }
    else if(strcmp(l, "()") != 0){
        for(int i = 0; i < strlen(l); i++, index++)
            *(s+index) = *(l+i);      
    }
    
    *(s+index) = ')';    
    *(s+(++index)) = '\0';
    return s;
}

char* tree2str(struct TreeNode* t){
    if(!t) return "";
    char* tmp = dfs(t);
    int index = 0;
    char* result = malloc(strlen(tmp) * sizeof(char));
     for(int i = 1; i < strlen(tmp)-1; i++, index++)
         *(result+index) = *(tmp+i);
    *(result+index) = '\0';
    return result;
}
