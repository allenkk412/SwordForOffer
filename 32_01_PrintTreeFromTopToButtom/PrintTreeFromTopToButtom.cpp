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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> TreeValue;

		if (root == nullptr)
			return TreeValue;

		deque<TreeNode*> dequeTreeNode;
		dequeTreeNode.push_back(root);
		while (dequeTreeNode.size())
		{
			TreeNode* pNode = dequeTreeNode.front();
			TreeValue.push_back(pNode->val);
			dequeTreeNode.pop_front();


			if (pNode->left != nullptr)
				dequeTreeNode.push_back(pNode->left);

			if (pNode->right != nullptr)
				dequeTreeNode.push_back(pNode->right);
		}

		return TreeValue;
	}
};