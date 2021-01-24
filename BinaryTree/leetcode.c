//单值二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return true;
//    }
//    if (root->left && root->left->val != root->val)
//        return false;
//    if (root->right && root->right->val != root->val)
//        return false;
//    else
//        return isUnivalTree(root->left) && isUnivalTree(root->right);
//
//}
//二叉树最大深度
//int maxDepth(struct TreeNode* root) {
//    if (root == NULL)
//        return 0;
//    int leftDpeth = maxDepth(root->left);
//    int rightDpeth = maxDepth(root->right);
//    if (leftDpeth > rightDpeth)
//        return leftDpeth + 1;
//    else
//        return rightDpeth + 1;
//}

//翻转二叉树
//struct TreeNode* invertTree(struct TreeNode* root) {
//    if (root == NULL)
//        return NULL;
//    else
//    {
//        invertTree(root->left);
//        invertTree(root->right);
//        struct TreeNode* tmp = root->right;
//        root->right = root->left;
//        root->left = tmp;
//
//        return root;
//    }
//}