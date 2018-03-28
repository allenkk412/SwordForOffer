/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;
		//if(pRoot->left == nullptr && pRoot->right == nullptr)
		//    return;

		if (pRoot->left != nullptr)
			Mirror(pRoot->left);
		if (pRoot->right != nullptr)
			Mirror(pRoot->right);

		if (pRoot->left != nullptr || pRoot->right != nullptr)
		{
			TreeNode* pNode = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = pNode;
		}
	}
};