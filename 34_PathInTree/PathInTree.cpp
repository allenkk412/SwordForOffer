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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> SumPaths;
		vector<int> path;
		if (root == nullptr)
			return SumPaths;

		int currentSum = 0;
		FindPath(root, expectNumber, SumPaths, path, currentSum);
		return SumPaths;
	}

private:
	void FindPath(TreeNode *root, int expectNumber, vector<vector<int>> & SumPaths, vector<int> &path, int currentSum)
	{
		currentSum += root->val;
		path.push_back(root->val);

		bool isLeaf = (root->left == nullptr) && (root->right == nullptr);
		if (currentSum == expectNumber && isLeaf == true)
		{
			SumPaths.push_back(path);
		}

		if (root->left != nullptr)
			FindPath(root->left, expectNumber, SumPaths, path, currentSum);
		if (root->right != nullptr)
			FindPath(root->right, expectNumber, SumPaths, path, currentSum);
		path.pop_back();
	}

};