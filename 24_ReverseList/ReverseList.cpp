/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr)
			return nullptr;

		ListNode* pReverseHead = nullptr;
		ListNode* pNode = pHead;
		ListNode* pPrev = nullptr;
		while (pNode != nullptr)
		{
			ListNode* pNext = pNode->next;
			pNode->next = pPrev;

			if (pNext == nullptr)
				pReverseHead = pNode;

			pPrev = pNode;
			pNode = pNext;
		}

		return pReverseHead;
	}
};