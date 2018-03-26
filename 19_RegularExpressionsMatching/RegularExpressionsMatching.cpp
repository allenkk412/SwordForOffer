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
			//   ֱ���ַ�ƥ��ɹ�  ||  ����pattern��'.'ƥ��ɹ�
			if (*pattern == *str || (*pattern == '.' && *str != '\0'))
				return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
			//      �ַ�ƥ��ɹ���'*'�ַ�ֻ����һ�� || �ַ�ƥ��ɹ���'*'�ַ�����һ������ || �ַ�ƥ�䲻�ɹ���'*'�������
			// ״̬���� move on next state       || stay on the current state    || ignore a '*'
			else
				return matchCore(str, pattern + 2);
		}

		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 1);

		return false;
	}
};