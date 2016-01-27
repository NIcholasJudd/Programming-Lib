/****************************************************************
* 14/01/2016                                                    *
* Nicholas Judd: a program a day challenge                      *
* Title:  [easy] challenge #1                                   *
* Text:  create a program that will ask the users name, age,    *
*   and reddit username. have it tell them the information back,*
*   in the format: your name is (blank), you are (blank) years  *
*   old, and your username is (blank)                           *
*   for extra credit, have the program log this information in a*
*   file to be accessed later.                                  *
*****************************************************************/

 


#include <iostream>
#include <string>
int main(int argc, const char * argv[]) {
    std::string title[] = {"Name", "Age", "Reddit Username"};
    std::string data[2];
    for (int i = 0; i < 3; i++){
    	std::cout << "What is your " << title[i] << ": ";
    	getline (std::cin, data[i]);
    }
    std::cout << "your name is " + data[0] +", you are "+ data[1] +" years old, and your username is " + data[2] << std::endl;
    return 0;
}