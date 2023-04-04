#include <iostream>
#include <string>
using namespace std;

int getSize(long d)
{
  string num = to_string(d);
  return num.length();
}

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits

int getDigit(int number)
{
  if (number < 9)
    return number;
  return number / 10 + number % 10;
}

int sumOfTwoStep(long int CreditCardNum )
{
  int sum = 0;
  string num = to_string(CreditCardNum) ;
  for (int i = getSize(CreditCardNum) - 2; i >= 0; i -= 2)
    sum += getDigit(int(num[i] - '0') * 2);

  return sum;
}

int sumOfDegitNotMultiplyByTwo(long number)
{
  int sum = 0;
  string num = to_string(number) ;
  for (int i = getSize(number) - 1; i >= 0; i -= 2)
    sum += num[i] - '0';
  return sum;
}

bool Validate(long CreditCardNum) {
   if(getSize(CreditCardNum)<=16 && getSize(CreditCardNum)>=14 &&
     (sumOfTwoStep(CreditCardNum) + sumOfDegitNotMultiplyByTwo(CreditCardNum)% 10) == 0)
      {
        return true;
    }
	else
        return false;
}

int main()
{
    long CreditCardNum;
    cin>>CreditCardNum;
    Validate(CreditCardNum);

    return 0;
}
