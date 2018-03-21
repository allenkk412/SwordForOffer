class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr || length <= 0)
			return;

		int originalLength = 0;
		int numberOfBlank = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			++originalLength;
			if (str[i] == ' ')
				++numberOfBlank;
			++i;
		}

		int newLength = originalLength + numberOfBlank * 2;
		if (newLength > length)
			return;

		int indexOfOriginal = originalLength;
		int indexOfNew = newLength;

		while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
		{
			if (str[indexOfOriginal] == ' ') {
				str[indexOfOriginal--] = '0';
				str[indexOfOriginal--] = '2';
				str[indexOfOriginal--] = '%';
			}
			else {
				str[indexOfOriginal--] = str[indexOfOriginal];
			}

			--indexOfOriginal;
		}

	}
};