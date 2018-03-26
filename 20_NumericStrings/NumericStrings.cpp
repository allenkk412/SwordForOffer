class Solution {
public:
	// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
	// 整数（可以有正负号，也可以没有），而B是一个无符号整数
	bool isNumeric(const char* string)
	{
		if (string == nullptr)
			return false;

		bool numeric = scanInteger(&string);

		if (*string == '.')
		{
			++string;
			// 使用||的原因：
			// 小数可以没有整数部分，例如.123
			// 小数点后可以没有数字，例如233.
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