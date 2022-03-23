/*
* Program 2: Sorting algorithms 
* Grace Harris
* CSC 2400 Design of Algorithms
* Instructor: Katherine Brown
*
* This program takes in different size arrays and based on choice of user will sort the arrays with different sorting algorithms
* and will let the user know in seconds how long it takes to sort the arrays.
*/


/*This section shows all the different files that the Driver.cpp will use depending on which sorts are initialized */

#include "bubble.cpp"
#include "insertion.cpp"
#include "selection.cpp"
#include "quick.cpp"
#include "merge.cpp"
#include "heap.h"
#include "counting.cpp"
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

/* Main function*/
int main()
{

    /* Variables needed to choice which sorting algorithm and which array size user wishes to sort with*/
    int choice;
    int sortChoice;
    time_t start, end; /*time variable to keep track of the timeframe it takes to sort each array chosen*/

    /* the different arrays that can be chosen*/

    int array[5] = {38, 19, 4, 87,6};
    int array2[10] = {56, 14, 9, 23, 42, 72, 99, 11, 43, 61};
    int array3[50] = {25 ,45 ,8 ,4 ,20 ,47 ,6 ,18 ,35 ,7 ,3 ,50 ,22 ,31 ,33 ,24 ,30 ,11 ,34 ,9 ,21 ,43 ,49 ,14 ,2 ,23 ,19 ,44 ,16 ,10 ,15 ,38 ,46 ,17 ,48 ,5 ,41 ,13 ,12 ,29 ,36 ,39 ,1 ,32 ,40 ,37 ,27 ,42 ,28 ,26};
    int array4[100] = {40 ,46, 30, 39, 11, 16, 22, 5, 24, 10, 29, 46, 46, 13, 44, 32, 11, 34, 13, 40, 47, 35, 47, 7, 17, 23, 42, 24, 44, 11, 26, 35, 32, 45, 9, 27, 31, 39, 38, 50, 46, 25, 38, 36, 31, 9, 23, 44, 24, 8, 44, 22, 15, 24, 13, 30, 34, 28, 47, 28, 3, 25, 11, 34, 17, 22, 8, 36, 28, 10, 21, 46, 39, 14, 15, 16, 17, 2, 49, 17, 1, 9, 47, 9, 48, 48, 50, 10, 42, 19, 38, 6, 7, 19, 50, 22, 50, 9, 21, 18};
    int array5[200] = {173, 70, 107, 52, 74, 5, 48, 122, 134, 22, 175, 146, 126, 37, 138, 133, 183, 170, 123, 68, 165, 106, 180, 163, 100, 73, 141, 149, 46, 182, 19, 90, 40, 118, 80, 8, 33, 75, 87, 38, 39, 185, 61, 88, 29, 17, 168, 51, 66, 139, 179, 23, 98, 113, 9, 77, 160, 31, 135, 166, 43, 192, 156, 155, 65, 188, 13, 27, 137, 18, 103, 150, 178, 120, 171, 190, 167, 76, 78, 197, 174, 132, 159, 129, 2, 57, 42, 158, 84, 108, 83, 114, 92, 64, 172, 117, 86, 194, 81, 125, 54, 3, 198, 184, 153, 36, 200, 1, 101, 50, 4, 45, 157, 196, 169, 102, 115, 15, 187, 6, 111, 14, 96, 67, 58, 164, 62, 55, 186, 47, 82, 95, 35, 89, 71, 195, 56, 112, 99, 151, 11, 152, 144, 181, 191, 32, 109, 104, 16, 110, 143, 44, 20, 91, 119, 130, 25, 41, 69, 105, 177, 85, 79, 97, 145, 176, 161, 12, 140, 21, 26, 121, 148, 28, 128, 93, 154, 7, 94, 30, 53, 60, 63, 193, 24, 189, 127, 136, 142, 124, 59, 199, 162, 49, 10, 72, 131, 147, 34, 116};
    int array6[400] = {353, 398, 151, 109, 69, 197, 233, 103, 274, 36, 111, 378, 14, 200, 81, 102, 89, 206, 177, 225, 384, 108, 242, 285, 337, 258, 70, 16, 227, 372, 204, 371, 175, 281, 296, 357, 8, 210, 63, 58, 229, 110, 17, 71, 344, 39, 289, 245, 130, 310, 120, 263, 7, 317, 282, 300, 302, 45, 215, 244, 85, 218, 320, 362, 346, 10, 354, 293, 326, 284, 351, 356, 180, 292, 82, 249, 93, 147, 209, 13, 264, 303, 321, 345, 28, 389, 33, 158, 241, 350, 195, 246, 358, 224, 48, 139, 166, 66, 367, 52, 6, 96, 223, 118, 155, 119, 113, 315, 169, 126, 270, 54, 172, 74, 275, 226, 49, 84, 316, 187, 163, 222, 361, 360, 369, 377, 19, 368, 115, 34, 26, 72, 186, 199, 90, 131, 182, 98, 193, 114, 162, 247, 148, 380, 359, 112, 46, 35, 298, 342, 92, 349, 73, 136, 95, 301, 376, 273, 373, 181, 18, 313, 311, 40, 161, 76, 37, 184, 397, 176, 304, 318, 216, 189, 396, 91, 167, 374, 352, 228, 134, 297, 47, 106, 1, 278, 143, 150, 42, 386, 160, 178, 251, 62, 171, 290, 141, 152, 205, 65, 129, 322, 391, 211, 234, 179, 100, 157, 83, 379, 127, 392, 168, 22, 330, 99, 325, 30, 395, 68, 306, 343, 123, 235, 51, 381, 67, 196, 137, 56, 133, 86, 207, 334, 237, 43, 122, 117, 383, 164, 266, 254, 124, 87, 286, 221, 142, 347, 288, 283, 253, 78, 15, 390, 80, 170, 97, 105, 309, 192, 135, 190, 365, 208, 256, 250, 262, 277, 213, 238, 287, 248, 230, 212, 174, 236, 382, 260, 125, 393, 11, 156, 385, 332, 132, 329, 60, 265, 5, 3, 149, 370, 280, 94, 145, 138, 214, 333, 323, 324, 116, 75, 348, 144, 154, 400, 312, 191, 305, 4, 201, 388, 279, 203, 363, 57, 339, 335, 202, 146, 217, 319, 107, 53, 2, 399, 271, 276, 308, 314, 239, 50, 59, 183, 38, 291, 261, 25, 338, 198, 140, 27, 104, 24, 32, 295, 328, 41, 232, 331, 61, 101, 267, 21, 307, 341, 255, 294, 128, 364, 188, 173, 185, 299, 269, 159, 55, 153, 387, 29, 252, 220, 336, 77, 23, 9, 64, 121, 194, 327, 12, 240, 394, 165, 257, 259, 231, 366, 31, 44, 243, 268, 272, 79, 355, 219, 340, 375, 88, 20};

    do{

        /*menu that will be printed for the user to choose which sorting algorithm they wish to use*/

        cout << "\t Please choice which type of sort you want to use!\n";
        cout << "1. \t \t Bubble Sorting\n";
        cout << "2. \t \t Heap Sorting\n";
        cout << "3. \t \t Insertion Sorting\n";
        cout << "4. \t \t Merge Sorting\n";
        cout << "5. \t \t Quick Sorting\n";
        cout << "6. \t \t Selection Sorting\n";
        cout << "7. \t \t Quit Sorts\n";
        cout << "Choose 1-7: " << endl;
        cin >> choice;

        /*Switch cases within do while loop to allow the user to chose as many sorts they want until they no longer want to sort arrays*/
        switch(choice)
        {
            //Case one is all the choices of array sizes for Bubble sort
            case 1 : cout << "\t \t Which size array do you wish to Bubble Sort? \n";
                    cout << "Size: 1. [5] , 2. [10] , 3. [50], 4. [100], 5. [200], or 6. [400]? : \n";
                    cin >> sortChoice;
                        if(sortChoice == 1)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayBubbleSortArray(array, 5);
                            cout << endl;
                            cout << "\t \t --- This is the array after we Bubble Sort!---\n";	
                            start = getTime(); 
                            bubbleSort(array,5);
                            end = getTime();
                            displayBubbleSortArray(array,5);
                            cout << endl;
                            cout << "\t \t BubbleSort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice ==2)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayBubbleSortArray(array2, 10);
                            cout << endl;
                            cout << "\t \t --- This is the array after we Bubble Sort!---\n";
                            start = getTime();
                            bubbleSort(array2,10);
                            end = getTime();
                            displayBubbleSortArray(array2,10);
                            cout << endl;
                            cout << "\t \t BubbleSort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 3)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayBubbleSortArray(array3, 50);
                            cout << endl;
                            cout << "\t \t --- This is the array after we Bubble Sort!---\n";
                            start = getTime();
                            bubbleSort(array3,50);
                            end = getTime();
                            displayBubbleSortArray(array3,50);
                            cout << endl;
                            cout << "\t \t BubbleSort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 4)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayBubbleSortArray(array4, 100);
                            cout << endl;
                            cout << "\t \t --- This is the array after we Bubble Sort!---\n";
                            start = getTime();
                            bubbleSort(array4,100);
                            end = getTime();
                            displayBubbleSortArray(array4,100);
                            cout << endl;
                            cout << "\t \t BubbleSort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 5)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayBubbleSortArray(array5, 200);
                            cout << endl;
                            cout << "\t \t --- This is the array after we Bubble Sort!---\n";
                            start = getTime();
                            bubbleSort(array5,200);
                            end = getTime();
                            displayBubbleSortArray(array5,200);
                            cout << endl;
                            cout << "\t \t BubbleSort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 6)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayBubbleSortArray(array6, 400);
                            cout << endl;
                            cout << "\t \t --- This is the array after we Bubble Sort!---\n";
                            start = getTime();
                            bubbleSort(array6, 400);
                            end = getTime();
                            displayBubbleSortArray(array6,400);
                            cout << endl;
                            cout << "\t \t BubbleSort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else
                        {
                            cout << "You didn't select a correct size! \n";
                            break;
                        }
            //Case 2 is for all arrays to sort with the Heap method
            case 2: cout << "\t \t Which size array do you wish to sort with a Heap? \n";
                    cout << "Size: 1. [5] , 2. [10] , 3. [50], 4. [100], 5. [200], or 6. [400]? : \n";
                    cin >> sortChoice;
                        if(sortChoice == 1)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            printArray(array, 5);
                            cout << endl;
                            cout << "\t \t --- This is the array after we sort using the Heap!---\n";
                            start = getTime();
                            heapSort(array,5);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t Array after completing all the swaps.\n";
                            printArray(array,5);
                            cout << endl;
                            cout << "\t \t Heap Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice ==2)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            printArray(array2, 10);
                            cout << endl;
                            cout << "\t \t --- This is the array after we sort using the Heap!---\n";
                            start = getTime();
                            heapSort(array2,10);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t Array after completing all the swaps.\n";
                            printArray(array2,10);
                            cout << endl;
                            cout << "\t \t Heap Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 3)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            printArray(array3, 50);
                            cout << endl;
                            cout << "\t \t --- This is the array after we sort using the Heap!---\n";
                            start = getTime();
                            heapSort(array3,50);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t Array after completing all the swaps.\n";
                            printArray(array3,50);
                            cout << endl;
                            cout << "\t \t Heap Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 4)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            printArray(array4, 100);
                            cout << endl;
                            cout << "\t \t --- This is the array after we sort using the Heap!---\n";
                            start = getTime();
                            heapSort(array4,100);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t Array after completing all the swaps.\n";
                            printArray(array4,100);
                            cout << endl;
                            cout << "\t \t Heap Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 5)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            printArray(array5, 200);
                            cout << endl;
                            cout << "\t \t --- This is the array after we sort using the Heap!---\n";
                            start = getTime();
                            heapSort(array5,200);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t Array after completing all the swaps.\n";
                            printArray(array5,200);
                            cout << endl;
                            cout << "\t \t Heap Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 6)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            printArray(array6, 400);
                            cout << endl;
                            cout << "\t \t --- This is the array after we sort using the Heap!---\n";
                            start = getTime();
                            heapSort(array6,400);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t Array after completing all the swaps.\n";
                            printArray(array6,400);
                            cout << endl;
                            cout << "\t \t Heap Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else
                        {
                            cout << "You didn't select a correct size! \n";
                            break;
                        }
            //Case 3 is for all arrays to be sorted using insertion sort
            case 3: cout << "\t \t Which size array do you wish to sort using Insertion? \n";
                    cout << "Size: 1. [5] , 2. [10] , 3. [50], 4. [100], 5. [200], or 6. [400]? : \n";
                    cin >> sortChoice;
                        if(sortChoice == 1)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayInsertionSortArray(array, 5);
                            cout << endl;
                            start = getTime();
                            insertionSort(array,5);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Insertion Sort---\n";
                            displayInsertionSortArray(array,5);
                            cout << endl;
                            cout << "\t \t Insertion Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice ==2)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayInsertionSortArray(array2, 10);
                            cout << endl;
                            start = getTime();
                            insertionSort(array2,10);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Insertion Sort---\n";
                            displayInsertionSortArray(array2,10);
                            cout << endl;
                            cout << "\t \t  Insertion Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 3)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayInsertionSortArray(array3, 50);
                            cout << endl;
                            start = getTime();
                            insertionSort(array3,50);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Insertion Sort---\n";
                            displayInsertionSortArray(array3,50);
                            cout << endl;
                            cout << "\t \t  Insertion Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 4)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayInsertionSortArray(array4, 100);
                            cout << endl;
                            start = getTime();
                            insertionSort(array4,100);
                            end = getTime(); 
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Insertion Sort---\n";
                            displayInsertionSortArray(array4,100);
                            cout << endl;
                            cout << "\t \t  Insertion Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 5)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayInsertionSortArray(array5, 200);
                            cout << endl;
                            start = getTime();
                            insertionSort(array5,200);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Insertion Sort---\n";
                            displayInsertionSortArray(array5,200);
                            cout << endl;
                            cout << "\t \t  Insertion Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 6)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayInsertionSortArray(array6, 400);
                            cout << endl;
                            start = getTime();
                            insertionSort(array6,400);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Insertion Sort---\n";
                            displayInsertionSortArray(array6,400);
                            cout << endl;
                            cout << "\t \t  Insertion Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else
                        {
                            cout << "You didn't select a correct size! \n";
                            break;
                        }
            //Case 4 is for all arrays to sort using Merge sort algorithms
            case 4: cout << "\t \t Which size array do you wish to sort using Merge Sort? \n";
                    cout << "Size: 1. [5] , 2. [10] , 3. [50], 4. [100], 5. [200], or 6. [400]? : \n";
                    cin >> sortChoice;
                        if(sortChoice == 1)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayMergeSortArray(array, 5);
                            cout << endl;
                            start = getTime();
                            mergeSort(array,0,4);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Merge Sort.---\n";
                            displayMergeSortArray(array,5);
                            cout << endl;
                            cout << "\t \t  Merge Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice ==2)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayMergeSortArray(array2, 10);
                            cout << endl;
                            start = getTime();
                            mergeSort(array2,0,9);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Merge Sort.---\n";
                            displayMergeSortArray(array2,10);
                            cout << endl;
                            cout << "\t \t  Merge Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 3)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayMergeSortArray(array3, 50);
                            cout << endl;
                            start = getTime();
                            mergeSort(array3,0,49);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Merge Sort.---\n";
                            displayMergeSortArray(array3,50);
                            cout << endl;
                            cout << "\t \t  Merge Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 4)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayMergeSortArray(array4, 100);
                            cout << endl;
                            start = getTime();
                            mergeSort(array4,0,99);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Merge Sort.---\n";
                            displayMergeSortArray(array4,100);
                            cout << endl;
                            cout << "\t \t  Merge Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 5)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayMergeSortArray(array5, 200);
                            cout << endl;
                            start = getTime();
                            mergeSort(array5,0,199);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Merge Sort.---\n";
                            displayMergeSortArray(array5,200);
                            cout << endl;
                            cout << "\t \t  Merge Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 6)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayMergeSortArray(array6, 400);
                            cout << endl;
                            start = getTime();
                            mergeSort(array6,0,399);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Merge Sort.---\n";
                            displayMergeSortArray(array6,400);
                            cout << endl;
                            cout << "\t \t  Merge Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else
                        {
                            cout << "You didn't select a correct size! \n";
                            break;
                        }
            //Case 5 is for all the arrays to be sorted using Quick sort.
            case 5: cout << "\t \t Which size array do you wish to sort using Quick Sort? \n";
                    cout << "Size: 1. [5] , 2. [10] , 3. [50], 4. [100], 5. [200], or 6. [400]? : \n";
                    cin >> sortChoice;
                        if(sortChoice == 1)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayQuickSortArray(array, 5);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            quickSort(array,0,4);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Quick Sort.---\n";
                            displayQuickSortArray(array,5);
                            cout << endl;
                            cout << "\t \t Quick Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 2)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayQuickSortArray(array2, 10);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            quickSort(array2,0,9);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Quick Sort.---\n";
                            displayQuickSortArray(array2,10);
                            cout << endl;
                            cout << "\t \t Quick Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 3)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayQuickSortArray(array3, 50);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            quickSort(array3,0,49);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Quick Sort.---\n";
                            displayQuickSortArray(array3,50);
                            cout << endl;
                            cout << "\t \t Quick Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 4)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayQuickSortArray(array4, 100);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            quickSort(array4,0,99);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Quick Sort.---\n";
                            displayQuickSortArray(array4,100);
                            cout << endl;
                            cout << "\t \t Quick Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 5)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayQuickSortArray(array5, 200);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            quickSort(array5, 0,199);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Quick Sort.---\n";
                            displayQuickSortArray(array5,200);
                            cout << endl;
                            cout << "\t \t Quick Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 6)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displayQuickSortArray(array6, 400);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            quickSort(array6,0,399);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Quick Sort.---\n";
                            displayQuickSortArray(array6,400);
                            cout << endl;
                            cout << "\t \t Quick Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else
                        {
                            cout << "You didn't select a correct size! \n";
                            break;
                        }
            //Case 6 is for all algorithms to be sorted through Selection sort.           
            case 6: cout << "\t \t Which size array do you wish to sort using Selection Sort? \n";
                    cout << "Size: 1. [5] , 2. [10] , 3. [50], 4. [100], 5. [200], or 6. [400]? : \n";
                    cin >> sortChoice;
                        if(sortChoice == 1)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displaySelectionSortArray(array, 5);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            selectionSort(array,5);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Selection Sort.---\n";
                            displaySelectionSortArray(array,5);
                            cout << endl;
                            cout << "\t \t Selection Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 2)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displaySelectionSortArray(array2, 10);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            selectionSort(array2,10);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Selection Sort.---\n";
                            displaySelectionSortArray(array2,10);
                            cout << endl;
                            cout << "\t \t Selection Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 3)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displaySelectionSortArray(array3, 50);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            selectionSort(array3,50);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Selection Sort.---\n";
                            displaySelectionSortArray(array3,50);
                            cout << endl;
                            cout << "\t \t Selection Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 4)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displaySelectionSortArray(array4, 100);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            selectionSort(array4,100);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Selection Sort.---\n";
                            displaySelectionSortArray(array4,100);
                            cout << endl;
                            cout << "\t \t Selection Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 5)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displaySelectionSortArray(array5, 200);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            selectionSort(array5,200);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Selection Sort.---\n";
                            displaySelectionSortArray(array5,200);
                            cout << endl;
                            cout << "\t \t Selection Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else if(sortChoice == 6)
                        {
                            cout << "\t \t--- This is the array before we begin the sorting---\n";
                            displaySelectionSortArray(array6, 400);
                            cout << endl;
                            cout << endl;
                            start = getTime();
                            selectionSort(array6,400);
                            end = getTime();
                            cout << endl;
                            cout << "\t \t --- This is the array after completing Selection Sort.---\n";
                            displaySelectionSortArray(array6,400);
                            cout << endl;
                            cout << "\t \t Selection Sort Timer: " << totalTime(start, end) << " seconds\n\n";
                            break;
                        }
                        else
                        {
                            cout << "You didn't select a correct size! \n";
                            break;
                        }
        }

    }while(choice!=7);
    //Once the choice 7 is made the program will print a message letting the user know the program has ended.
    cout << "Ending Sorting Program.";
    
    return 0;
}

