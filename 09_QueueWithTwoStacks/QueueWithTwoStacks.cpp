class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		/* 当stack2为空时，才能将stack1中的元素弹出并压入stack2栈中 */
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				int tmp = stack1.top();
				stack1.pop();
				stack2.push(tmp);
			}
		}

		// if(stack2.empty())
		//    throw new exception("queue is empty");

		int head = stack2.top();
		stack2.pop();
		return head;

	}

private:
	stack<int> stack1;
	stack<int> stack2;
};