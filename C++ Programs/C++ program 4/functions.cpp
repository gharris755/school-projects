/****************************************************************************************************
 * File Name: functions.cpp                                                                         *
 * Author: Grace Harris                                                                             *
 * Date: 04/12/2021                                                                                 *
 * Purpose: This Program is a profit calculator for a spooky theme park.                            *
 * Will print out the largest profit month and smallest profit along with total and average profit. * 
 * **************************************************************************************************/




#include "program4.h" //include of program4.h page to show functions were assigned.


//getProfit function to take in the amount of months the user wishes to enter in and create two arrays for profit and months.
void getProfit(string *profitMonths, double *profit, int size){
    cout << "Please enter the names of the months to record. \n"; 

    for (int index =0; index < size; index++)
    {
        cout << "Month " << (index +1) << ": ";
        cin.ignore();
        getline(cin, *(profitMonths +index)); // taking in month into its own array.
        
        cout << "Profit " << (index +1) << ": $"; 
        cin >> *(profit + index); // taking in profit into its own array with the index correlated to the same month index.
        while(*(profit + index) < 0)
        {
            cout << "Wait a Sec! Can't make profit in the Negatives! Enter a number greater than zero! \n";
            cin >>*(profit + index);
            //While loop to validate that the user is not using a negative number in the profits array.
        }
    }
    
}


//getTotal function to take in the profit array and beginning adding each of the month's profits together for the full total.
double getTotal(double *profit,  int size){
    double total = 0.0;
    
    for (int i=0; i< size; i++) 
    {
        total += *(profit +i);
    }



    return total; //sends the total calculated to the main function.
}

//getMin function called to go through the profits array to determine which month had the lowest profit entered.
double getMin(double *profit, int num, int &month)
{
    double min = *(profit + 0);
    for (int i = 0; i < num; i++)
    {
        if (min > *(profit + i))
        {
            min = *(profit + i);
            month = i;
           
           
        }
    }
    return min; //returns minimum profit to the main function.
}   

//getMax function called to go through the profits array again and determine which month had the highest profit entered.
double getMax(double *profit, int num, int &months)
{
    double max = *(profit + 0);
    for (int i = 0; i < num; i++ )
    {
        if (max < *(profit + i ))
        {
            max = *(profit + i);
            months = i;
        }       

    }
    return max; //returns maximum profit to the main function.
}

//drawArt function used to print a photo that is associated to the theme park to the main function to print during program execution.
void drawArt()
{
                                                                                                    
    cout << "                                                                  %@@@@&* #@@@@*   *@." << endl;            
    cout << "                                                                  ,#&@@@@@@@@@@@@@@( %@@/" << endl;           
    cout << "                                                              &@@@@@@@@@@@@@@@@@@@@@@@@@@@  @#" << endl;      
    cout << "                                                            /@@&@@#@@@@@@@@@@@@@@@@@@@@@%@@%" << endl;      
    cout << "                                                                          *@@@@@@@@@@@@@@@@@@%" << endl;      
    cout << "                                                                             .@@@@@@@@@@@@@@@*" << endl;      
    cout << "                                                                                %@@@@@@@@@@@#@@" << endl;     
    cout << "                                                                                  &@@@@@@@@@@@@" << endl;    
    cout << "                                               ##                                  @@@@@@@@@@@@" << endl;     
    cout << "                                        ., %@@. .*#&@@@@@@&(,                    .  @@@@@@@@@@@" << endl;     
    cout << "                %@@@@&                &@/@@@@@@@@@@@@@@@@@@@@@@@@@@@*            @@@@@@@@@@@@@" << endl;      
    cout << "             /@@@@@@@.             .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(          @@@@@@@@@@)" << endl;      
    cout << "             (@@@@@@@@.           ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*     /@@@@@@@@@@#" << endl;       
    cout << "        (@@@@@@@@@@@@@&(.      *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#      &@@@@@@(" << endl;        
    cout << "    .@@@@@@@@@@@@@@@@@@@@@@*  &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/     &@@@@(" << endl;         
    cout << "   ,@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.  (@@@@." << endl;          
    cout << "   #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;            
    cout << "   .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/" << endl;             
    cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@." << endl;              
    cout << "  %@@@@@@@@,   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*" << endl;              
    cout << "    .##@(    &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#           ,@@@@@@@@@@@@@@@@@@@@@(" << endl;              
    cout << "         ./#@@@@@#     .@@@@@@@@@@@@@@@@@@@@@@@@#                 @@@@@@@@@@@@@@@@@@@(" << endl;              
    cout << "          *@@@#          @@@@@@@@@@@@@@@@@@@@@%                    ,@@@@@@@@@@@@@@@@@*" << endl;              
    cout << "                          #@@@@@@@@@@@@@@% @@*                       @@@@@@@@@@@@@@@@" << endl;               
    cout << "                           %@@@@@@@@@@@@%  #/                         @@@@@@@@@@@@@@*" << endl;               
    cout << "                            @@@@@@@@@@@@                              .@@@@@@@@@@@@&" << endl;                
    cout << "                             @@@@@@@@@@                                *@@@@@@@@@@@" << endl;                 
    cout << "                             ,@@@@@@@@,                                 &@@@@@@@@@/" << endl;                 
    cout << "                              %@@@@@@&                                   @@@@@@@@@" << endl;                  
    cout << "                               @@@@@@#                                   (@@@@@@@" << endl;                   
    cout << "                               %@@@@@%                                    @@@@@@#" << endl;                   
    cout << "                               .@@@@@&                                    #@@@@@/" << endl;                   
    cout << "                                @@@@@&                                    ,@@@@@#" << endl;                   
    cout << "                                %@@@@@                                    .@@@@@@ " << endl;                  
    cout << "                                /@@@@@                                    .@@@@@@," << endl;                  
    cout << "                                ,@@@@@.                                   ,@@@@@@" << endl;                   
    cout << "                                 @@@@@,                                   (@@@@@," << endl;                   
    cout << "                                 @@@@@*                                  .@@@@@#" << endl;                    
    cout << "                               *@@@@@@*                                 #@@@@@@" << endl;                     
    cout << "                               @@@@@@.                                  #@@@@%" << endl;                      
                                                                                                    
                                                                                                    
}




