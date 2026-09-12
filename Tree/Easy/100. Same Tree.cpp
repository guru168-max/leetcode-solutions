// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Input: p = [1,2,3], q = [1,2,3]
// Output: true

// Input: p = [1,2], q = [1,null,2]
// Output: false


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
    bool check(TreeNode* p, TreeNode* q)
    {
        if(p==NULL && q==NULL) return 1;
        if((!p&&q)  ||  (!q&&p)) return 0;
        bool firstONE=check(p->left, q->left);
        bool secondONE=check(p->right, q->right);
        if(p->val != q->val) return 0;
        return firstONE&&secondONE;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};
