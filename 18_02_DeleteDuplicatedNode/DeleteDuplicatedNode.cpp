/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;

		ListNode* pPreNode = nullptr;
		ListNode* pNode = pHead;
		while (pNode != nullptr)
		{
			ListNode *pNext = pNode->next;
			bool needDelete = false;
			if (pNext != nullptr && pNext->val == pNode->val)
				needDelete = true;

			if (!needDelete)
			{
				pPreNode = pNode;
				pNode = pNode->next;
			}
			else
			{
				int value = pNode->val;
				ListNode* pToBeDel = pNode;
				while (pToBeDel != nullptr && pToBeDel->val == value)
				{
					pNext = pToBeDel->next;
					delete pToBeDel;
					pToBeDel = nullptr;
					pToBeDel = pNext;
				}

				if (pPreNode == nullptr)
					pHead = pNext;
				else
					pPreNode->next = pNext;
				pNode = pNext;
			}
		}

		return pHead;
	}
};