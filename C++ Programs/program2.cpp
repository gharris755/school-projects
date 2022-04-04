/**************************************************************************************************
 * File Name: program2.cpp                                                                        *
 * Author: Grace Harris                                                                           *
 * Date: 03/04/2021                                                                               *
 * Purpose: This program assists the user with cooking measurements, visual measurement charts,   *
 *  as well as showing the user how many conversions they completed.                              *
 * ************************************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // This section begins the program by identifying the variables that will be used.
    int choice, subChoice, subChoice2, subChoice3;
    double subChoiceA, subChoiceB, gallons, pints, quarts, cups;
    int conversions = 0;
    
    
    
    // This section begins the main menu do-while loop and also makes a while loop should someone put in a wrong number selection.
    do {
    cout << "\n--MAIN MENU--\n\n";

    cout << "What would you like to look at?\n";
    cout << "1. Oven Temperatures & Conversations\n";
    cout << "2. View Solids Measurements\n";
    cout << "3. Liquids Measurements & Conversions \n";
    cout << "4. End the Program\n";
    cout << "CHOOSE 1-4: ";
    cin >> choice;

    
    while (choice <1 || choice > 4){
        cout << "\n\n Invalid input. Please choose an option from the menu. \n\n";
        
        cout << "--MAIN MENU--\n\n";

        cout << "What would you like to look at?\n";
        cout << "1. Oven Temperatures & Conversations\n";
        cout << "2. View Solids Measurements\n";
        cout << "3. Liquids Measurements & Conversions \n";
        cout << "4. End the Program\n";
        cout << "CHOOSE 1-4: ";
        cin >> choice;
    }

    
    // This section begins the switch cases for the submenus depending on which selection was made in the Main Menu
    switch(choice){

        case 1: //This case is for selecting conversions for Celsius and Fahrenheit temperatures.
                do{       
                    cout << "\n--OVEN TEMPERATURES--\n\n";

                    cout << "Water boils at 100 degrees Celsius and 212 degrees Fahrenheit.\n";
                    cout << "Water freezes at 0 degrees Celsius and 32 degrees Fahrenheit.\n";
                    cout << "What do you want to do?\n";
                    cout << "1. Convert a temperature from Celsius to Fahrenheit.\n";
                    cout << "2. Convert a temperature from Fahrenheit to Celsius.\n";
                    cout << "3. Go back to MAIN MENU.\n";
                    cout << "CHOOSE 1-3: ";
                    cin >> subChoice;

                    
                    if (subChoice == 1){
                        cout << "\n What is the temperature in Celsius?: \n";
                        cin >> subChoiceA;
                        cout << "\n RESULT: " << subChoiceA << " degrees Celsius is " << fixed << setprecision(2) << (subChoiceA * (9.0/5.0) +32) << " degrees Fahrenheit.\n";
                        conversions++; // The conversion++ in each if/else keeps track of conversions made to print out later at the end of program.
                    }

                    
                    else if (subChoice == 2){
                        cout << "\n What is the temperature in Fahrenheit?: \n";
                        cin >> subChoiceB;
                        cout << "\n RESULT: " << subChoiceB << " degrees Fahrenheit is " << fixed << setprecision(2) << ((subChoiceB - 32) * (5.0/9.0)) << " degrees Celsius.\n";
                        conversions++;
                    }
            
                }while(subChoice != 3);
                break;
                
                

                

        case 2: //This case is for selecting visual measurement charts for Butter and Dry Goods.
                do{
                    cout << "\n--SOLID MEASUREMENTS--\n\n";

                    cout << "What do you want to do?\n";
                    cout << "1. View a chart for butter.\n";
                    cout << "2. View a chart for Dry Goods such as flour & sugar.\n";
                    cout << "3. Go back to MAIN MENU.\n";
                    cout << "CHOOSE 1-3: ";
                    cin >> subChoice2;

                    if (subChoice2 == 1){
                        cout << fixed << setw(40) << "  Butter \n";
                        cout << fixed <<   setw(25) << "CUPS"  << setw(25) << "GRAMS \n";
                        cout << fixed <<  setw(25) << "1/4 cup of Butter"  << setw(25) << "57 grams \n";
                        cout << fixed  << setw(25) << "1/3 cup of Butter" <<  setw(25) << "76 grams \n";
                        cout << fixed  << setw(25) << "1/2 cup of Butter" << setw(25) << "113 grams \n";
                        cout << fixed  << setw(25) << "1 cup of Butter" <<  setw(25) << "227 grams \n";
                    }

                    else if (subChoice2 == 2){
                        cout << fixed << setw(60) << "  DRY GOODS (FLOUR & SUGAR) \n";
                        cout << fixed << setw(25) << "1/8 cup" << setw(25) << "16 grams" << setw(25) << ".563 ounces \n";
                        cout << fixed << setw(25) << "1/4 cup" << setw(25) << "32 grams" <<  setw(25) << "1.13 ounces \n";
                        cout << fixed << setw(25) << "1/3 cup" << setw(25) << "43 grams" <<  setw(25) << "1.5 ounces \n";
                        cout << fixed << setw(25) << "1/2 cup" << setw(25) << "64 grams" <<  setw(25) << "2.25 ounces \n";
                        cout << fixed<< setw(25) << "2/3 cup" << setw(25) << "85 grams" << setw(25) << "3 ounces \n";
                        cout << fixed<< setw(25) << "3/4 cup" << setw(25) << "96 grams" << setw(25) << "3.38 ounces \n";
                        cout << fixed << setw(25) << "1 cup" << setw(25) << "128 grams" <<  setw(24) << "4.5 ounces\n";
                    }
                }while (subChoice2 != 3);   
                break;
                

        case 3: //This case is for selecting conversions of liquid measurements.
                do{        
                    cout << "\n --LIQUIDS MEASUREMENTS--\n\n";

                    cout << "What measurement do you know? \n";
                    cout << "1. I know how many gallons I have.\n";
                    cout << "2. I know how many quarts I have \n";
                    cout << "3. I know how many pints I have. \n";
                    cout << "4. I know how many cups I have \n";
                    cout << "5. Go back to MAIN MENU \n";
                    cout << "CHOOSE 1-5: ";
                    cin >> subChoice3;

                    if (subChoice3 == 1){
                        cout << "\n How many gallons do you have?: \n";
                        cin >> gallons; 
                        cout << gallons << " gallons is " << fixed << setprecision(2) << (gallons * 4.0) << " quarts, " << fixed << setprecision(2) << (gallons * 8.0) << " pints, or " << fixed << setprecision(2) << (gallons * 16.0) << " cups. \n";
                        conversions++;
                    }

                    else if (subChoice3 == 2){
                        cout << "\n How many quarts do you have?: \n";
                        cin >> quarts;
                        cout << quarts << " quarts is " << fixed << setprecision(2) << (quarts / 4.0) << " gallons, " << fixed << setprecision(2) << (quarts * 2) << " pints, or " << fixed << setprecision(2) << (quarts * 4.0) << " cups. \n";
                        conversions++;
                    }

                    else if (subChoice3 == 3){
                        cout << "\n How many pints do you have?: ";
                        cin >> pints;
                        cout << pints << " pints is " << fixed << setprecision(2) << (pints / 8.0) << " gallons, " << fixed << setprecision(2) << (pints / 2.0) << " quarts, or " << fixed << setprecision(2) << (pints * 2.0) << " cups. \n";
                        conversions++;
                    }

                    else if (subChoice3 == 4){
                        cout << "\n How many cups do you have?: ";
                        cin >> cups;
                        cout << cups << " cups is, " << fixed << setprecision(2) << (cups /16.0) << " gallons, " << fixed << setprecision(2) << (cups / 4.0) << " quarts, & " << fixed << setprecision(2) << (cups / 2.0) << " pints. \n";
                        conversions++;
                    }
                }while (subChoice3 != 5);   
                break;
                
                

        case 4: //This case is selected when the user is finished with their cooking inquiries.
                cout << "\n Thank you for using the measurement program. \n";
                cout << "Hopefully you can cook something really special for me\n";
                cout << "because you made " << conversions << " conversions!"; //conversions are printed to finally screen to show how many the user completed during the menu loops.
        }


    } while (choice !=4);        



                    
    return 0;
}