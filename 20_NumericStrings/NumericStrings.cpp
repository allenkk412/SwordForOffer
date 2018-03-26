class Solution {
public:
	// ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ������A��C����
	// �����������������ţ�Ҳ����û�У�����B��һ���޷�������
	bool isNumeric(const char* string)
	{
		if (string == nullptr)
			return false;

		bool numeric = scanInteger(&string);

		if (*string == '.')
		{
			++string;
			// ʹ��||��ԭ��
			// С������û���������֣�����.123
			// С��������û�����֣�����233.
			numeric = scanUnsignedInteger(&string) || numeric;
		}

		if (*string == 'e' || *string == 'E')
		{
			++string;
			numeric = scanInteger(&string) && numeric;
		}

		return numeric && *string == '\0';
	}

	bool scanInteger(const char** str)
	{
		if (**str == '+' || **str == '-')
			++(*str);
		return scanUnsignedInteger(str);
	}

	bool scanUnsignedInteger(const char** str)
	{
		const char* before = *str;
		while (**str != '/0' && **str >= '0' && **str <= '9')
			++(*str);

		return before < *str;
	}

};