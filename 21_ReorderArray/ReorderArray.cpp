class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int length = array.size();
		if (length == 0 || length == 1)
			return;

		vector<int> newArray;
		vector<int>::iterator ite;

		for (ite = array.begin(); ite != array.end(); ite++)
		{
			if (*ite % 2 == 1)
				newArray.push_back(*ite);
		}

		for (ite = array.begin(); ite != array.end(); ite++)
		{
			if (*ite % 2 == 0)
				newArray.push_back(*ite);
		}

		array = newArray;
	}
};