/*
struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};
*/
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr)
			return nullptr;
		/*
		*1.�ڵ���������������һ�ڵ����������������ӽڵ㣻
		*2.�ڵ������������������Ǹ��ڵ�����ӽڵ㣬��ô��һ�ڵ������ĸ��ڵ㣻
		*3.�ڵ�������������ֲ����丸�ڵ�����ӽڵ㣬�����ϱ�����ֱ���ҵ�һ���������ڵ�����ӽڵ�Ľڵ�
		*
		*1.�����Һ��ӣ���ô��һ���ڵ�����Һ��ӵ����ӣ������ӵ�����......��
		*2.�������ҽڵ㣬��һ���������丸�ڵ�������ø��ڵ����丸�ڵ�����ӣ�
		*
		*/

		TreeLinkNode *pNext = nullptr;
		if (pNode->right != nullptr)
		{
			TreeLinkNode *pRight = pNode->right;
			while (pRight->left != nullptr)
			{
				pRight = pRight->left;
			}
			pNext = pRight;
		}
		else if (pNode->next != nullptr)
		{
			TreeLinkNode *pParent = pNode->next;
			TreeLinkNode *pCurrent = pNode;
			while (pParent->right == pCurrent && pParent != nullptr)
			{
				pCurrent = pParent;
				pParent = pParent->next;
			}
			pNext = pParent;
		}
		return pNext;
	}
};