class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		/* ��stack2Ϊ��ʱ�����ܽ�stack1�е�Ԫ�ص�����ѹ��stack2ջ�� */
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