/****************************************************************
* 14/01/2016													*
* Nicholas Judd: a program a day challenge 						*
* Title: [easy] challenge #2									*
* Text: Hello, coders! An important part of programming 		*
* 	is being able to apply your programs, so your challenge 	*
*	for today is to create a calculator application that 		*
*	has use in your life. It might be an interest calculator, 	*
*	or it might be something that you can use in the classroom. *
*	For example, if you were in physics class, you might want 	*
*	to make a F = M * A calc.									*
* EXTRA CREDIT: make the calculator have multiple functions! 	*
*	Not only should it be able to calculate F = M * A, 			*
*	but also A = F/M, and M = F/A!								*
****************************************************************/

#include <iostream>
#include <string>
#include <cmath>
void binToDec(int);
void decToBin(int);
int main(int argc, char const *argv[])
{
	
	if (*argv[1] == '1'){
		long long unsigned int data = atoi(argv[2]);
		std::cout << data << std::endl;
		binToDec(data);
	}else if (*argv[1] == '2') {
		int data = atoi(argv[2]);
		decToBin(data);
	}
	return 0;
}

void binToDec(int data){
int output = 0;

    for(int i=0; data > 0; i++) {

        if(data % 10 == 1) {
            output += (1 << i);
        }
        data /= 10;
    }

std::cout << output << std::endl;
}

void decToBin(int data){
	std::string binary;
	while (data > 0){
		if ((data % 2) > 0){
			binary.push_back('1');
		}else {
			binary.push_back('0');
		}
		data = data / 2;
	}
	for (int i = binary.size(); i >= 0; i--){
		std::cout << binary[i];
	}
	std::cout << std::endl;
}