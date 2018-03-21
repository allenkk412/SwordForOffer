/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		/* ˼·���ݹ飩������ǰ������ĵ�һ�����ִ������ڵ㣻����������ҵ����ڵ��λ�ã�ȷ�����������ڵ��������ݹ鹹������������*/
		if (pre.empty() || vin.empty() || vin.size() != pre.size())
			return NULL;

		vector<int> left_pre, right_pre, left_vin, right_vin;
		TreeNode *node = new TreeNode(pre[0]);

		int left_length = 0;
		while (pre[0] != vin[left_length] && left_length < pre.size())
			++left_length;

		for (int i = 0; i < left_length; i++)
		{
			left_pre.push_back(pre[i + 1]);
			left_vin.push_back(vin[i]);
		}

		for (int i = left_length + 1; i < pre.size(); i++)
		{
			right_pre.push_back(pre[i]);
			right_vin.push_back(vin[i]);
		}

		node->left = reConstructBinaryTree(left_pre, left_vin);
		node->right = reConstructBinaryTree(right_pre, right_vin);

		return node;

	}
};