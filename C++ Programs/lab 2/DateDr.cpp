//
//  DateDr.cpp
//  For Testing DateType Class
//
#include <string>
#include <iostream>
#include "DateType.h"
using namespace std;
int main(int argc, char *argv[])
{
     DateType date, AdjDate;
     int month = atoi(argv[1]); // throw error message if  12 < month or month < 1
     int day = atoi(argv[2]);   // throw error message if days < 1, or
                                // days > number of days in corresponding year and month
                                //(example: in January, 2016 if days > 30)
     int year = atoi(argv[3]);  // throw error message if year < 1900
     int daysAway = atoi(argv[4]);
     try
     {
          date.Initialize(month, day, year);
          cout << "\nInitial Date: " << date.GetMonthAsString() << " " << date.GetDay() << ", "
               << date.GetYear() << endl;
          AdjDate = date.Adjust(daysAway);
          cout << date.GetMonthAsString() << " " << date.GetDay() << ", "
               << date.GetYear() << " plus " << daysAway << " is " << AdjDate.GetMonthAsString() << " " << AdjDate.GetDay() << ", "
               << AdjDate.GetYear() << "\n"
               << endl;
     }
     catch (string msg)
     {
          cout << msg << endl;
     }
}
