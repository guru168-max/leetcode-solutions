class Solution {
public:

    // When I stand at any node:
    // 1. Ask the left child: "Give me your height."
    // 2. Ask the right child: "Give me your height."
    //
    // These heights are returned by the recursive calls.
    //
    // Example:
    // If the current node is 5:
    //
    //          5
    //         / \
    //        8   6
    //
    // height(8) = 2
    // height(6) = 2
    //
    // So at node 5:
    // left_height = 2
    // right_height = 2
    //
    // Now I can calculate the diameter THROUGH the current node:
    //
    // left_height + right_height
    // 2 + 2 = 4
    //
    // I compare this diameter with the global maximum diameter.
    //
    // After calculating the diameter, I need to give my HEIGHT
    // back to my parent.
    //
    // My height is:
    //
    // 1 + max(left_height, right_height)
    //
    // Why max?
    // Because when my parent continues a path through me,
    // it can only continue down ONE side: left OR right.
    
    int dept = 0;

    int height(TreeNode* root)
    {
        // NULL has height 0.
        //
        // This is where the 0 comes from when a node
        // has no left or right child.
        if(root == NULL)
            return 0;

        // Ask left child for its height.
        int left_height = height(root->left);

        // Ask right child for its height.
        int right_height = height(root->right);

        // Now both child heights are available.
        //
        // Calculate the diameter THROUGH the current node.
        dept = max(dept, left_height + right_height);

        // Now return the current node's height
        // to its parent.
        return 1 + max(left_height, right_height);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        height(root);

        // dept contains the maximum diameter
        // found anywhere in the tree.
        return dept;
    }
};
