#include <iostream>
using namespace std;

//function that is called to use bubble sort algorithm, takes in the array and its size.
void bubbleSort(int *array, int size)
{
    int tempSwapper;
    
    for(int maxElement = (size-1); maxElement > 0; maxElement--)
    {
        for(int i=0; i < maxElement; i++)
        {
            if(array[i] > array[i+1])
            {
                tempSwapper = array[i];
                array[i] = array[i+1];
                array[i+1] = tempSwapper;
            }
        }
    }
}
//function called to display the array before and after it has been sorted.
void displayBubbleSortArray(int *array, int size)
{
    for(int i=0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

