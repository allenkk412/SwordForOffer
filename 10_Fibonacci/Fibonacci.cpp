class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;

		// ���϶������
		// return Fibonacci(n -1) + Fibonacci(n - 2);

		// ���¶�����⣬���㱣��ǰ�������
		// ��������������������ظ�����
		int fibNMinusOne = 1;
		int fibNMinusTwo = 0;
		int fibN = 0;
		for (int i = 2; i <= n; i++)
		{
			fibN = fibNMinusOne + fibNMinusTwo;
			fibNMinusTwo = fibNMinusOne;
			fibNMinusOne = fibN;
		}

		return fibN;
	}
};

class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		int fibNLastOne = 2;
		int fibNLastTwo = 1;
		int fibN = 0;
		for (int i = 3; i <= number; i++)
		{
			fibN = fibNLastOne + fibNLastTwo;
			fibNLastTwo = fibNLastOne;
			fibNLastOne = fibN;
		}

		return fibN;
	}
};