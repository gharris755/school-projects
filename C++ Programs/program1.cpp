/****************************************************************
 * File Name: Program1.cpp                                          *
 * Author: Grace Harris                                         *
 * Date: 02/11/2021                                             *
 * Purpose: This program calculates the user's life expectancy. *
*****************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    /* Starting point identifying which variables to use. */
    char yesOrNo, userGender; 
    int lifeExpectancy,  weight, exercise, marriage, job, friends, education;
    int userAge = 0;
    bool smoke, doesDrink, pets, caretaker, breakfast, family, fruits, veggies;

    cout << "********** Life Expectancy Calculator **********" << endl;

    /* This section begins to take in user's inputs for each question. */
    string userName;
    cout << "What is your name?: " << endl;
    getline (cin,userName);

    cout << "Enter your current age: "<< endl;
    cin >> userAge;

    cout << "Are you male or female? (Enter m or f): " << endl;
    cin >> userGender;


    cout << "\n What is your weight status? ";
    cout << "\n (1) Underweight, (2) Just right, (3) Overweight, (4) Obese";
    cout << "\n Enter 1, 2, 3, or 4: " << endl;
    cin >> weight;

    cout << "\n Do you smoke cigarettes? (Enter y or n): " << endl;
    cin >> yesOrNo;

    /* Creating true/false boolean */
    if (yesOrNo == 'y')
        smoke = true;
    else  
        smoke = false;
    

    cout << "Do you drink more than one alcoholic beverage every day?" << endl;
    cout << "(Enter y or n): " << endl;
    cin >> yesOrNo;

    /* Creating true/false boolean */
    if (yesOrNo == 'y')
        doesDrink = true;
    else  
        doesDrink = false;



    cout << "Do you exercise?" << endl;
    cout << "(1) None, (2) Very Little, (3) Periodically, (4) Active, (5) Athlete" << endl;
    cout << "\n (Enter 1, 2, 3, 4, or 5): "<< endl;
    cin >> exercise;

    cout << "\n Do you have a pet? (Enter y or n): "<< endl;
    cin >> yesOrNo;

    /* Creating true/false boolean */
    if (yesOrNo == 'y')
        pets = true;
    else 
        pets = false;

 
    cout << "\n Are you married?" << endl;
    cout << "(1) Divorced, (2) Single, (3) Married, (4) Happily Married" << endl;
    cout << "(Enter 1, 2, 3, or 4): \n"<< endl;
    cin >> marriage;


    cout << "Are you a caretaker? (Enter y or n): \n" << endl;
    cin >> yesOrNo;

    /* Creating true/false boolean */
    if (yesOrNo == 'y')
        caretaker = true;
    else  
        caretaker = false;



    cout << "How do you feel about your job?" << endl;
    cout << "(1) Hate it!, (2) Dislike it, (3) It's ok, (4) Enjoyable, (5) Love it!" << endl;
    cout << "(Enter 1, 2, 3, 4, or 5): " << endl;
    cin >> job;



    cout << "Do you eat breakfast every day? (Enter y or n): " << endl;
    cin >> yesOrNo;

    /* Creating true/false boolean */
     if (yesOrNo == 'y')
        breakfast = true;
    else 
        breakfast = false;
   

    cout << "Did either of your biological parents or any of your biological" << endl;
    cout << "grandparents die before the age of 50? (Enter y or n): " << endl;
    cin >> yesOrNo;

    /* Creating true/false boolean */
    if (yesOrNo == 'y')
        family = true;
    else 
        family = false;
   

    cout << "Do you eat fruits every day? (Enter y or no): " << endl;
    cin >> yesOrNo;

    /* Creating true/false boolean */
     if (yesOrNo == 'y')
        fruits = true;
    else 
        fruits = false;


    cout << "Do you eat vegetables every day? (Enter y or no): " << endl;
    cin >> yesOrNo;


    /* Creating true/false boolean */
     if (yesOrNo == 'y')
        veggies = true;
    else 
        veggies = false;



    cout << "Do you hang out with your friends?" << endl;
    cout << "(1) Never, (2) Periodically, (3) Often" << endl;
    cout << "(Enter 1, 2, or 3): " << endl;
    cin >> friends;


    cout << "What is your education level?" << endl;
    cout << "(1) No degrees, (2) Highschool degree, (3) Associates degree," << endl;
    cout << "(4) Bachelors degree, (5) Masters/PHD Degree" << endl;
    cout << "(Enter 1, 2, 3, 4, or 5): " << endl;
    cin >> education;


    /* After input has been taking this section now begins processing the information for the output */
    if (userAge > 60) 
        lifeExpectancy = userAge;
    else 
        lifeExpectancy = 60;

    cout << "Starting Life Expectancy: " << lifeExpectancy << endl; 

    if (userGender == 'f')
        lifeExpectancy = lifeExpectancy + 4;

    else 
        lifeExpectancy = lifeExpectancy + 0;

    cout << "Life Expectancy after gender: " << lifeExpectancy << endl;

    
    if (weight == 1)
        lifeExpectancy = lifeExpectancy - 1;

    else if (weight == 2)
        lifeExpectancy = lifeExpectancy + 5;

    else if (weight == 3)
        lifeExpectancy = lifeExpectancy -2;

    else 
        lifeExpectancy = lifeExpectancy -5;

    cout << "Life Expectancy after weight: " << lifeExpectancy << endl;



    if (smoke)
        lifeExpectancy = lifeExpectancy - 5;
    
    else
        lifeExpectancy = lifeExpectancy + 5;

    cout << "Life Expectancy after smoke: " << lifeExpectancy << endl;

    
    if (doesDrink == 'y')
        lifeExpectancy = lifeExpectancy -5;
    
    else
        lifeExpectancy = lifeExpectancy + 2;

    cout << "Life Expectancy after alcohol: " << lifeExpectancy << endl;

    if (exercise == 1)
        lifeExpectancy = lifeExpectancy -5;
    
    else if (exercise == 2)
        lifeExpectancy = lifeExpectancy -2;
    
    else if (exercise == 3)
        lifeExpectancy = lifeExpectancy + 0;
    
    else if (exercise == 4)
        lifeExpectancy = lifeExpectancy + 5;
    
    else
        lifeExpectancy = lifeExpectancy + 7;

    cout << "Life Expectancy after exercise: " << lifeExpectancy << endl;

    
    if (pets == 'y')
        lifeExpectancy = lifeExpectancy + 3;
    
    else
        lifeExpectancy = lifeExpectancy - 1;

    cout << "Life Expectancy after pet: " << lifeExpectancy << endl;

    if (marriage == 1)
        lifeExpectancy = lifeExpectancy - 5;

    else if (marriage == 2)
        lifeExpectancy =lifeExpectancy - 2;

    else if (marriage == 3)
        lifeExpectancy = lifeExpectancy + 2;

    else
        lifeExpectancy = lifeExpectancy + 5;

    cout << "Life Expectancy after married: " << lifeExpectancy << endl;

    if (caretaker == 'y')
        lifeExpectancy = lifeExpectancy - 2;
    
    else
        lifeExpectancy = lifeExpectancy + 0;

    cout << "Life Expectancy after caretaker: " << lifeExpectancy << endl;

    if (job == 1)
        lifeExpectancy = lifeExpectancy - 5;

    else if (job == 2)
        lifeExpectancy = lifeExpectancy - 2;

    else if (job == 3)
        lifeExpectancy = lifeExpectancy + 0;

    else if (job == 4)
        lifeExpectancy = lifeExpectancy + 2;

    else
        lifeExpectancy = lifeExpectancy + 5;

    cout << "Life Expectancy after job stress: " << lifeExpectancy << endl;

    if (breakfast == 'y')
        lifeExpectancy = lifeExpectancy + 5;

    else
        lifeExpectancy = lifeExpectancy - 2;

    cout << "Life Expectancy after breakfast: " << lifeExpectancy << endl;

    if (family == 'y')
        lifeExpectancy =  lifeExpectancy - 2;

    else 
        lifeExpectancy = lifeExpectancy + 5;

    cout << "Life Expectancy after died: " << lifeExpectancy << endl;

    if (fruits == 'y')
        lifeExpectancy = lifeExpectancy + 5;
    
    else    
        lifeExpectancy = lifeExpectancy - 5;

    cout << "Life Expectancy after fruits: " << lifeExpectancy << endl;

    if (veggies == 'y')
        lifeExpectancy = lifeExpectancy + 5;

    else
        lifeExpectancy = lifeExpectancy - 5;

    cout << "Life Expectancy after vegetables: " << lifeExpectancy << endl;

    if (friends == 1)
        lifeExpectancy = lifeExpectancy - 2;

    else if (friends == 2)
        lifeExpectancy = lifeExpectancy + 0;

    else
        lifeExpectancy = lifeExpectancy + 2;

    cout << "Life Expectancy after friends: " << lifeExpectancy << endl;


    if (education == 1)
        lifeExpectancy = lifeExpectancy - 5;

    else if (education == 2)
        lifeExpectancy = lifeExpectancy - 2;

    else if (education == 3)
        lifeExpectancy = lifeExpectancy + 2;

    else if (education == 4)
        lifeExpectancy = lifeExpectancy + 5;

    else
        lifeExpectancy = lifeExpectancy + 7;

    cout << "Life Expectancy after education level: " << lifeExpectancy << endl;

    if (lifeExpectancy < userAge) /* Final part configures if last Life Expectancy total is less than the user's age */
        lifeExpectancy = userAge; /* If the Life Expectancy is less it will automatically print out the user's current age */

    cout << "**************************************************" << endl;

    cout << setw(22) << "Name: " << left << setw(30) << userName << endl;
    cout << right << setw(22) << "Currant Age: " << left << setw(30) << userAge << endl;
    cout << right << setw(22) << "Life Expectancy: " << left << setw(30) << lifeExpectancy << endl;  

    

    cout << "**************************************************";
    /* Last section creates the final output of the user's name, current age, and life expectancy within its own box */

    return 0;
}