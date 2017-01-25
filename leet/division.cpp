/* Left shift each time if the divisor is less than the dividend
** Left shift == multiply by 2.
** Once divisor > dividend, go back one step
** Now dividend - divisor. This is the next value we have process
** Repeat the above steps until dividend < divisor */

#include <iostream>
#include <vector>

int division(int dividend, int divisor)
{
	if( dividend < 0 )
		dividend = ~dividend + 1;
	if( divisor < 0 )
		divisor = ~divisor + 1;
		
	if(dividend < divisor || dividend == 0 || divisor == 0)
		return 0;
	int factor = 1;
	int x = divisor;
	while(dividend >= x)
	{
		x<<=1; 						//left shift by 1=multiply by 2
		factor<<=1;					//left shift by 1=multiply by 2
	}
	//we went past the dividend, so go back one step
	x>>=1;
	factor>>=1;
	dividend = dividend - x;
	return factor+division(dividend, divisor);
}
		

int main(int argc, char const *argv[])
{
	std::cout<<"answer is "<< division(15000000,89) <<std::endl;
}
