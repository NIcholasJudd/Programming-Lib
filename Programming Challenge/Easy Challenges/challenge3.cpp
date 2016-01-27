/****************************************************************
* 17/01/2016													*
* Nicholas Judd: a program a day challenge 						*
* Title: [easy] challenge #3									*
* Text: Welcome to cipher day!									*
* 	write a program that can encrypt texts with an alphabetical *
*	caesar cipher. This cipher can ignore numbers, symbols, and *
*	whitespace. for extra credit, add a "decrypt" function to 	*
*	your program!												*
****************************************************************/
#include <iostream>
#include <string>
std::string encrypt(std::string&);
std::string decrypt(std::string);
int main(int argc, char const *argv[])
{
	std::string message;
	if (argc == 3){
		message = argv[2];
		if (*argv[1] == 'e' ){
			std::cout << encrypt(message) << std::endl;
		}else if (*argv[1] == 'd'){
			std::cout << decrypt(message) << std::endl;
		}
	}
	return 0;
}

std::string encrypt(std::string & message){
	for (int i = 0; i < message.size(); i++){
		message[i] += 3;
	}
 return message;
}

std::string decrypt(std::string message){
	for (int i = 0; i < message.size(); i++){
		message[i] -= 3;
	}
	return message;
}