#include <iostream>
using namespace std;

//function that will sort the array with selection algorithm.
void selectionSort(int *array, int size)
{
    int minIndex;
    int minKey;
    int tempVar;

    for(int i = 0; i < (size -1); i++)
    {
        minIndex = i;
        minKey = array[i];
        
        //for loop that works through the array and sorts the elements if the element is less than the minkey.
        for(int j = i +1; j < size; j++)
        {
            if(array[j] < minKey)
            {
                minKey = array[j];
                minIndex = j;
            }
        }

        tempVar = array[minIndex];
        array[minIndex] = array[i];
        array[i] = tempVar;

    }
}

//display the array before and after it has been sorted with the selection sort algorithm
void displaySelectionSortArray(int *array, int size)
{
    for(int i =0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}