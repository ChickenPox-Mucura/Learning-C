#include <stdio.h>

float exponentiation(float, float);

int main(void)
{
	float base;
	float exp;
	float res;
	
	printf("base number:\n");
	scanf("%f", &base);
	printf("exponent number:\n");
	scanf("%f", &exp);
	res = exponentiation(base, exp);
	
	printf("result: %.3f\n", res);
}

float exponentiation(float base, float exp)
{
	float count = 1;
	float res;

	if (exp != 0) {
		if (exp < 0) {
			res = count / base;
			++exp;
			while (exp < 0) {
				res /= base;
				++exp;
			}
		}
		else {
			res = base * count;
			++count;
			while (exp >= count) {
				res *= base;
				++count;
			}
		}
	}
	else
		res = 1;
	
	return res;

}
