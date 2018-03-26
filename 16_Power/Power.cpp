class Solution {
public:
	double PowerWithUnsignedExponent(double base, unsigned int exponent)
	{
		if (exponent == 0)
			return 1;
		if (exponent == 1)
			return base;
		double result = PowerWithUnsignedExponent(base, exponent / 2);
		result *= result;
		if (exponent % 2 == 1)
			result *= base;

		return result;
	}

	double Power(double base, int exponent) {
		if (base == 0.0 && exponent < 0)
			return 0.0;

		//unsigned int absExponent;
		unsigned int absExponent = (unsigned int)(exponent);
		if (exponent < 0)
			absExponent = (unsigned int)(-exponent);
		double result = PowerWithUnsignedExponent(base, absExponent);
		if (exponent < 0)
			return 1.0 / result;
		return result;
	}
};