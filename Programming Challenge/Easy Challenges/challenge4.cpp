/****************************************************************
* 17/01/2016													*
* Nicholas Judd: a program a day challenge 						*
* Title: [easy] challenge #4									*
* Text: You're challenge for today is to create a random 		*
*	password generator! For extra credit, allow the user to 	*
* 	specify the amount of passwords to generate. For even more 	*
* 	extra credit, allow the user to specify the length of the 	*
*	strings he wants to generate!								*
****************************************************************/
#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char const *argv[])
{
	int num, length;
	std::string password;
	std::cout << "Number of passwords to generate: ";
	std::cin >> num;
	std::cout << "Length of each password: ";
	std::cin >> length;

	for (int i = 0; i < num; i++){
		for (int x = 0; x < length; x++){
			char output = 48 + (rand() % (int)(122 - 48 + 1));
			password.push_back(output);
		}
		std::cout << password << std::endl;
		password.clear();
	}
	return 0;
}