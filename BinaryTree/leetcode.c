//��ֵ������
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
//������������
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

//��ת������
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
//1688�����е���Դ���
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
//��ͬ����
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