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
	ListNode* MeetingNode(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;

		ListNode* pSlow = pHead->next;
		if (pSlow == nullptr)
			return nullptr;

		ListNode* pFast = pSlow->next;
		while (pFast != nullptr && pSlow != nullptr)
		{
			if (pFast == pSlow)
				return pSlow;

			pSlow = pSlow->next;

			pFast = pFast->next;
			if (pFast->next != nullptr)
				pFast = pFast->next;
		}

		return nullptr;
	}

	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode* meetingNode = MeetingNode(pHead);
		if (meetingNode == nullptr)
			return nullptr;

		ListNode* pNode1 = meetingNode;
		int n = 1;
		while (pNode1->next != meetingNode)
		{
			++n;
			pNode1 = pNode1->next;
		}

		pNode1 = pHead;
		for (int i = 0; i < n; ++i)
			pNode1 = pNode1->next;

		ListNode* pNode2 = pHead;
		while (pNode1 != pNode2)
		{
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		return pNode1;
	}
};