/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		stack<int> nodes;
		vector<int> answer;

		ListNode *pNode = head;
		while (pNode != nullptr)
		{
			nodes.push(pNode->val);
			pNode = pNode->next;
		}

		int tmpval;
		while (!nodes.empty())
		{
			tmpval = nodes.top();
			answer.push_back(tmpval);
			nodes.pop();
		}
		return answer;
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> answer;
		while (head != nullptr)
		{
			if (head->next != nullptr)
			{
				printListFromTailToHead(head->next);
			}

			answer.push_back(head->val);
		}

		return answer;
	}
};