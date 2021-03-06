//单值二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    if (root->left && root->left->val != root->val)
        return false;
    if (root->right && root->right->val != root->val)
        return false;
    else
        return isUnivalTree(root->left) && isUnivalTree(root->right);

}
//二叉树最大深度
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftDpeth = maxDepth(root->left);
    int rightDpeth = maxDepth(root->right);
    if (leftDpeth > rightDpeth)
        return leftDpeth + 1;
    else
        return rightDpeth + 1;
}

//翻转二叉树
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;
    else
    {
        invertTree(root->left);
        invertTree(root->right);
        struct TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        return root;
    }
}
//1688比赛中的配对次数
int numberOfMatches(int n) {
    int i = 0;
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            i = i + n / 2;
            n /= 2;
        }
        else
        {
            i = i + (n - 1) / 2;
            n = (n - 1) / 2 + 1;
        }
    }
    return i;
}
//相同的树
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL && q != NULL)
        return false;
    if (p != NULL && q == NULL)
        return false;
    if (p->val != q->val)
        return false;
    else
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}
//另一个树的子树
bool isSametree(struct TreeNode* root_1, struct TreeNode* root_2)
{
    if (root_1 == NULL && root_2 == NULL)
        return true;
    if (root_1 == NULL && root_2 != NULL)
        return false;
    if (root_1 != NULL && root_2 == NULL)
        return false;
    if (root_1->val != root_2->val)
        return false;
    else
        return isSametree(root_1->left, root_2->left) && isSametree(root_1->right, root_2->right);
}
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (s == NULL)
        return false;
    if (isSametree(s, t))
        return true;
    else
        return isSubtree(s->left, t) || isSubtree(s->right, t);

}