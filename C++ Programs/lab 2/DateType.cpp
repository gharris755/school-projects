// File DateType.cpp  contains the implementation of class DateType

#include "DateType.h"
#include <fstream>
#include <iostream>

using namespace std;

// Nmber of days in each month
static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,
                            31, 30, 31};	

// Nmaes of the months
static string conversionTable[] = {"Error", "January", "February", 
    "March", "April", "May", "June", "July", "August", "September",
    "October", "November", "December"};

void DateType::Initialize
     (int newMonth, int newDay, int newYear)
// Post: If newMonth, newDay and newYear represent a valid date,
//       year is set to newYear;
//       month is set to newMonth;
//       day is set to newDay;
//       otherwise a string exception is thrown, stating the
//       first incorrect parameter.
{
   day = newDay;
   month = newMonth;
   year = newYear;
  
   // complete your program here
}

int DateType::GetMonth() const
// Accessor function for data member month.
{
   return month;
}

string DateType::GetMonthAsString() const
// Returns data member as a string
{
   int month;
   int days;
   days = daysInMonth[month];
   
   return conversionTable[month];


   //complete your program here
}

int DateType::GetYear() const
// Accessor function for data member year.
{
  return month; // complete your program here
}

int DateType::GetDay() const
// Accessor function for data member day.
{
  return day;// complete your program here
}

bool DateType::leapYear(int year) const
{
   
   if(year % 4 == 0)
   {
      if(year % 400 == 0)
      {
         return true;
      }
      else if (year % 100 == 0)
      {
         return false;
      }
      else
      {
         return true;
      }
      
   }
   return false;
  
     // complete your program here
}

DateType DateType::Adjust(int daysAway) const
// Pre:  Self has been initialized
// Post: Function value = newDate daysAway from self
{
   int newDay;
   int newMonth;
   int newYear;
   int daysInThisMonth;

   newDay = day + daysAway;
   newMonth = month;
   newYear = year;

   bool finished = false;

   while(!finished)
   {
      daysInThisMonth = daysInMonth[newMonth];
      if (newMonth = 2)
      {
         if (leapYear(newYear))
         {
            
            daysInThisMonth;
         }
      }
      if(newDay <= daysInThisMonth)
      {
         finished = true;
      }
      else
      {
         newDay = newDay - daysInThisMonth;
         newMonth = (newMonth % 12) + 1;

         if (newMonth = 1)
         {
            newYear;
         }
      
      }
      DateType returnDate;

      returnDate.Initialize(newMonth, newDay, newYear);
      return returnDate;
   

   }// complete your program here
}
