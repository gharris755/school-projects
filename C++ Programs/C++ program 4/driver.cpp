/****************************************************************************************************
 * File Name: driver.cpp                                                                            *
 * Author: Grace Harris                                                                             *
 * Date: 04/12/2021                                                                                 *
 * Purpose: This Program is a profit calculator for a spooky themepark.                             *
 * Will print out the largest profit month and smallest profit along with total and average profit. * 
 * **************************************************************************************************/


// this section identifies the "program4.h" that has all the libraries and functions to make the driver.cpp file more organized and neat.

#include "program4.h"

// start of the main function.
int main(){

   // This section identifies the local variables needed within the main function to complete the profit calculations.
    int size;
    int minMonth;
    int maxMonth;
    string* months;
    string line(100, '-');
    double* profit;
    double total = 0.0;
    double max = 0.0;
    double min = 0.0;
    char repeat = 'y';

    do{ // do while loop begins to allow the user multiple input sessions if needed.
        
        cout << line << endl;

        cout << fixed << setw(25) << "\t \t Welcome to CarnEvil's Terrorible Theme Park Profit Calculator!" << endl;

        cout << line << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        drawArt(); // 1st function called to print out a picture associated with the themepark.

        cout << endl;
        cout << endl;
        cout << endl;

        cout << line << endl;



        cout << "How many months of profit do you wish to enter?:  \n"; //asking the user how many months they wish to calculate from.

        cin >> size;

        cout << endl;
        cout << endl;

        cout << "Let's enter some profits!\n" << endl;
        cout << "When you enter in the date, enter in the month & year like this: 'April 2020'. " << endl;
        cout << endl;
        cout << endl;



        months = new string[size]; // dynamically allocated array for the months that are going to be calculated.
        profit = new double[size]; // dynamically allocated array for the profits that will be calculated.

        getProfit(months, profit, size); // getProfit function called to begin creating the arrays.

        total = getTotal(profit, size); // setting the total to the variable in the getTotal function that is returned to the main as the total.

        min = getMin(profit, size, minMonth); // setting the min total variable to the number that is returned to the main function as the min profit.

        max = getMax(profit, size, maxMonth); // setting the max total variable to the number that is returned to the main function as the max profit.




        cout << line << endl; // setting up area to print out each profit needed.
        cout << line << endl;

        
        cout << right << setw(10) << "\t    Total Profits: " << right  << " " << setprecision(2) << " $" << total << endl; // total profits printed out.
        cout << right << setw(10) << "\t   Average Profit:  " << right << setprecision(2) << " $" << (total/size) << endl; // average profit calculated and printed out.
        cout << right << setw(10) << " Date with Largest Profit: " << right << "  " << *(months + maxMonth) << setprecision(2) << " totaling $" << max << endl;
        cout << right << setw(10) << "Date with Smallest Profit: " << right << "  " << *(months + minMonth) << setprecision(2) << " totaling $" << min << endl;
        // Last two rows are the smallest and largest profits total called from the pointer memory address and printed out. 


        cout << line << endl;
        cout << line << endl; // end of the printed out area.

        cout << "Would you like to run the program again? (y/n)" << endl;// asking user if they wish to create another set of calculations before ending program.
        cin >> repeat; 
    
        

        delete [] months;// both "deletes" remove the dynamically allocated arrays before the program either ends or creates a new calculation cycle.
        delete [] profit;
    } while (repeat == 'y'); //validation for do while loop to either end or complete new cycle.

  
    return 0;
}