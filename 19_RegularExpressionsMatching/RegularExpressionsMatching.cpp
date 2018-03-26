class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == nullptr || pattern == nullptr)
			return false;

		return matchCore(str, pattern);
	}

	bool matchCore(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*str != '\0' && *pattern == '\0')
			return false;

		if (*(pattern + 1) == '*')
		{
			//   直接字符匹配成功  ||  利用pattern的'.'匹配成功
			if (*pattern == *str || (*pattern == '.' && *str != '\0'))
				return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
			//      字符匹配成功且'*'字符只代表一次 || 字符匹配成功且'*'字符代表一次以上 || 字符匹配不成功且'*'代表零次
			// 状态机： move on next state       || stay on the current state    || ignore a '*'
			else
				return matchCore(str, pattern + 2);
		}

		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 1);

		return false;
	}
};