#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int factorial(int num) {
	if (num == 0 || num == 1) {
		return 1;
	}
	int fact = 1;
	for (int i = 2; i <= num; i++) {
		fact *= i;
	}
	return fact;
}

double power(double base, int exponent) {
	if (exponent == 0) {
		return 1;
	}
	else if (exponent == 1) {
		return base;
	}
	double result = base;
	for (int i = 1; i < exponent; i++) {
		result *= base;
	}
	return result;
}

//double bernoulli(int n) {

//}

double radians(double degrees) {
	return (degrees * 3.14159265359) / 180;
}

double cos(double x) { //  x is the degrees transformed into radians
	double value = 0L;
	int n = 7;
	for (int i = 0; i <= n; i++) {
		value += ((power(-1, i) / factorial(2 * i)) * power(x, 2 * i));
	}
	return value;
}


double sin (double x) { //  x is the degrees transformed into radians
	double value = 0L;
	int n = 7;
	for (int i = 0; i <= n; i++) {
		value += ((power(-1, i) / factorial(2 * i+1)) * power(x, 2 * i+1));
	}
	return value;
}

int main()
{
	cout << setprecision(2)<<cos(0)<< endl;
	return 0;
}
