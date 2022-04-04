#include <iostream>
#include <fstream> 
#include "BinaryTree.h" //include for the header file where all the functions are accessed.

using namespace std;

int main() //main function where the program will be initiated
{
	BinaryTree tree; //Tree object created to link to the header file and its functions.

  


    //Main function consists of the instructions for the game cout to the player and calling the GamePlay function 
    //which initializes the game and the other functions connected to it.

    cout << "Welcome to the My Animal Guessing Game!" << endl;
    cout << endl;
    cout << "Think of an animal and I am going to try and guess it." << endl;
    cout << endl;
    cout << "I am going to ask you Yes or No questions if I can't guess your animal YOU WIN!" << endl;
    cout << endl;
    cout << "Let's start playing!\n\n";

    cout << endl;





    tree.GamePlay(); //tree object used to access the function in header file.
	
	return 0;

}
