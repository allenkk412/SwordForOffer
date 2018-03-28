class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() <= 0)
			return false;
		int start = 0;
		int end = sequence.size() - 1;

		return isLastOrder(sequence, start, end);

	}

private:
	bool isLastOrder(vector<int> sequence, int start, int end)
	{
		int rootValue = sequence[end];

		// 确定左子树序列终点 i
		int i = start;
		for (; i < end; i++)
		{
			if (sequence[i] >= rootValue)
				break;
		}

		// 判断右子树是否成立
		int j = i;
		for (; j < end; j++)
		{
			if (sequence[j] <= rootValue)
				return false;
		}

		bool left = true;
		if (i - 1 > start)
			left = isLastOrder(sequence, start, i - 1);

		bool right = true;
		if (i < end - 1)
			right = isLastOrder(sequence, i, end - 1);

		return (left && right);

	}

};