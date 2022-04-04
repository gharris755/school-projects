/**************************************************************************************************
 * File Name: program3.cpp                                                                        *
 * Author: Grace Harris                                                                           *
 * Date: 03/26/2021                                                                               *
 * Purpose: This program reads in information from a new file and organizes them among            *
 * a herbivore, carnivore, or other file depending type of animal read.                           *
 * ************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;


// This section identifies what functions and their types will be used in the program.
int carnOrHerb(string);
bool searchCarnivore(string);
bool searchHerbivore(string);
int printDino(ofstream&, ifstream&, string, int);
bool overTenGrand(string);
void printResults(int, int, int, int, int);
    

// Start of the main function.
int main(){


    string tempString;
    string dinoDirFile;
    string saurus;
    int dino_saurus=0;     // This section identifies variables in the main function.
    int carnivore = 0;     // variables set to equal zero are used for counters for the printResults function.
    int herbivore = 0;
    int oTG = 0;
    int totalDino =0; 

    
    ofstream carnFile;
    ofstream herbFile;     // These indicate files that will be opened and appended.
    ofstream otherFile;
   

    ifstream inputFile; // This indicates a file that will be opened and read.
    cout << "Enter the filename you wish to access (including .txt): ";;
    cin >> dinoDirFile;

    cout << "\n \nDinosaur Directory File Name (dinoDirectory.txt): \n" << dinoDirFile << endl << endl;

    inputFile.open(dinoDirFile);

    while (!inputFile.is_open()){
        cout << "ERROR COULD NOT OPEN FILE! Please enter file to open (including .txt): \n";
        cin >> dinoDirFile;
        inputFile.open(dinoDirFile);
    }
    // While loop to validate the file has opened.
    

        
    while(getline(inputFile, tempString, '#')){
        if (tempString.find("saurus")!= string::npos){
            dino_saurus++;
        }

        // while loop that validates while reading the input file we find 'saurus' and count each time we find a dinosaur.     
                

        carnOrHerb(tempString); // calls the carnOrHerb function

        if (carnOrHerb(tempString) == 1){
                    
            carnFile.open("carnOutFile.txt", ios::app);
            cout << tempString << " is being printed to the CARNIVORE file!" << endl;
            carnivore++;
            oTG = printDino(carnFile, inputFile, tempString, oTG);
            totalDino++;

            carnFile.close();

            // If statement that passes the string through the function and if it is carnivore it is moved to the carnivore output file.
            // Also counts a carnivore and a total Dinos

        }
        else if (carnOrHerb(tempString) == 2){
                    
            herbFile.open("herbOutFile.txt", ios::app);
            cout << tempString << " is being printed to the HERBIVORE file!" << endl;
            herbivore++;
            oTG = printDino(herbFile, inputFile, tempString, oTG);
            totalDino++;
                    
            herbFile.close();
            // Same as carnivore but instead is validating that the string is a herbivore and moved to its output file.
            //Still counting total dinos and now herbivores that are found.
        }
        else{
                    
            otherFile.open("otherOutFile.txt", ios::app);

            cout << tempString << " is being printed to the OTHER file!" << endl;
            oTG = printDino(otherFile, inputFile, tempString, oTG);
            otherFile.close();
            // This is when after the string passes through carnOrHerb and is determined the string does not go with carnivore or herbivore.

        }


                  
      
              
                

    }
                
            
            
       
      
    inputFile.close(); // closes the input file

    cout << endl;

 
    printResults(carnivore, herbivore, totalDino, oTG, dino_saurus) ; 
    // prints out what file each string was sent to.
    // Prints out the input file that was opened.
    // Prints out all the counters so we can see how many of each animal was sent to each output file.
    // Also shows a counted amount of what dinosaurs weighed more than 10,000 lbs.
 

    
    

    
    

 
    return 0;
}

// CarnOrHerb function that determines if the string is Carnivore, Herbivore, or Other.
int carnOrHerb(string saurus){
  

    if (searchCarnivore(saurus)){
        return 1;
    }
    else if (searchHerbivore(saurus)){
        return 2;
    }
    else{
        return -1;
    }

}

// searchCarnivore Function that identifies if the string is carnivore or if the string needs to check and see if it could also be a herbivore.
bool searchCarnivore(string saurus){
    ifstream carn;
    
    string dinoName;
    bool isCarn = false;
   

    carn.open("Carnivores.txt");
    
    if (carn.is_open())
    {

        while(getline(carn, dinoName, '#'))
        {
           if (saurus == dinoName){
             isCarn = true;
           }
          
           
  
        }

        carn.close();
        

    }

    else{
        cout << "Unable to open the file!";
      
      }
    return isCarn;

}

// searchHerbivore Function that identifies if the string is a herbivore if not then the program knows it goes to the other output file.
bool searchHerbivore(string tempString){
    ifstream herb;
    string dinoName;
    bool isHerb = false;
    herb.open("Herbivores.txt");

    if (herb.is_open())
    {
        while(getline(herb, dinoName, '#'))
        {
        
           if (tempString == dinoName){
               
               isHerb = true;
           }
        
  
        }
  
        

        herb.close();
   

    }

    else
    {
        cout << "Unable to open the file!";
    }

    return isHerb;
        
  

}

// printDino function that sends all the strings through and then sends to output files to append correctly.

int printDino(ofstream& outputFile, ifstream& inputFile, string tempString, int oTG){
    string temp;
    

    outputFile << "NAME: " <<  tempString << endl;
    getline(inputFile, temp, '#');
    outputFile << "HEIGHT/LENGTH: " << temp << endl;
    getline(inputFile, temp, '#');
    if (overTenGrand(temp)){
        oTG++;
    }
    outputFile << "MASS: " << temp << endl;
    getline(inputFile, temp, '#');
    outputFile << "EATS: " << temp << endl;
    getline(inputFile, temp, '#' );
    outputFile << "DESCRIPTION: " << temp << endl << endl;

    return oTG;

    


}

// overTenGrand function that determines if the weight found for each animal is over 10,000 lbs or not.

bool overTenGrand(string mass){
    int comma;
    int massNum=0;
    stringstream ss (mass);
    string token;

    ss >> token;
    ss >> token;
    ss >> token;
    
    comma = token.find(',');
    if (comma != string::npos ){
        token.erase(comma, 1);
    }
    massNum = stoi(token);
    if (massNum > 10000){
        return true;
    }
    else{
        return false;
    }
        
    
}


// printResults Function that prints out all the totals collected through out running the program.

void printResults(int totalCarns, int totalHerbs, int totalDino, int oTG, int dino_saurus){
    string line(50, '-');
    cout << line << endl;
    cout << "TOTAL CARNIVORE DINOS" << fixed <<  setw(7)<< " : " << totalCarns << endl;
    cout << "TOTAL HERBIVORE DINOS" << fixed << setw(7)<< " : " << totalHerbs << endl;
    cout << "TOTAL DINOS" << fixed << setw(17) << ": " << totalDino << endl;
    cout << "DINOS OVER 10,000 LBS " << fixed << setw(6) << ": "  << oTG << endl;
    cout << "DINO NAMES END IN 'SAURUS': " << dino_saurus << endl;
    cout << line << endl;
}



