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
		*1.节点有右子树，则下一节点是右子树的最左子节点；
		*2.节点无右子树，但是它是父节点的左子节点，那么下一节点是它的父节点；
		*3.节点既无右子树，又不是其父节点的左子节点，则往上遍历，直到找到一个是它父节点的左子节点的节点
		*
		*1.存在右孩子，那么下一个节点就是右孩子的左孩子（的左孩子的左孩子......）
		*2.不存在右节点，下一个就是是其父节点且满足该父节点是其父节点的左孩子；
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