#include <ncurses.h>

float exponentiation(float, float);
float curse(float, float);

int main(void)
{
	float base;
	float exp;
	
	while(1) {
		curse(base, exp);

		clear();
		endwin();
		refresh();
	}
}

float curse(float base, float exp)
{
	float res;

	initscr();
	addstr("base number:\n");
	refresh();
	move(1,0);
	scanw("%f", &base);
	addstr("exponent number:\n");
	refresh();
	move(3,0);
	scanw("%f", &exp);
	res = exponentiation(base, exp);
	
	move(1,0);
	printf("result: %.3f\n", res);
	refresh();
	getch();

	return res;
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
