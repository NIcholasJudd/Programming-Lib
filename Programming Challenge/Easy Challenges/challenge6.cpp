/****************************************************************
* 22/01/2016													*
* Nicholas Judd: a program a day challenge 						*
* Title: [easy] challenge #6									*
* Text: You're challenge for today is to create a program that 	*
* can calculate pi accurately to at least 30 decimal places. 	*
* Try not to cheat :)											*
****************************************************************/
#include <iostream>
#include <iomanip>
int main(int argc, char const *argv[])
{
	long double pi = 3.0;
	long double temp = 2;
	for (int i = 0; i < 100; i++){
		
		pi +=  4/(temp * (temp+1) * (temp+2)) - 4/((temp+2) * (temp + 3) * (temp + 4));
		temp = temp + 4;
	}
			
	std::cout << std::setprecision(30) <<  pi << std::endl;

	return 0;
}
