class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		bool found = false;
		int columns = array.size();
		int rows = (*array.begin()).size();

		if (!array.empty() && columns > 0 && rows > 0)
		{
			int column = columns - 1;
			int row = 0;
			while (row < rows && column >= 0)
			{
				if (array[column][row] == target)
				{
					found = true;
					break;
				}
				else if (array[column][row] > target)
					--column;
				else
					++row;
			}

		}
		return found;
	}
};