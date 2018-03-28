class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int rows, columns;
		if (matrix.size() > 0)
		{
			rows = matrix.size();
			columns = matrix[0].size();
		}

		vector<int> result;

		/*
		*       startX-------->endX    startY
		*                                 |
		*                                 |
		*                                 |
		*                              endY
		*/

		int startX = 0, endX = columns - 1;
		int startY = 0, endY = rows - 1;

		while (startX <= endX && startY <= endY)
		{
			/* 从左到右输出 */
			if (startX <= endX && startY <= endY)
			{
				for (int i = startX; i <= endX; i++)
					result.push_back(matrix[startY][i]);
				++startY;
			}
			/* 从上到下输出*/
			if (startX <= endX && startY <= endY)
			{
				for (int i = startY; i <= endY; i++)
					result.push_back(matrix[i][endX]);
				--endX;
			}

			/* 从右到左输出 */
			if (startX <= endX && startY <= endY)
			{
				for (int i = endX; i >= startX; i--)
					result.push_back(matrix[endY][i]);
				--endY;
			}

			/* 从下到上输出 */
			if (startX <= endX && startY <= endY)
			{
				for (int i = endY; i >= startY; i--)
					result.push_back(matrix[i][startX]);
				++startX;
			}
		}
		return result;
	}
};