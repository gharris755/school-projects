#include <iostream>
using namespace std;

//function called with the array and its size to sort using insertion method.
void insertionSort(int *array, int size)
{
    int element;
    int j;

    for(int i=1; i < size; i++)
    {
        element = array[i];
        j = i-1;
        while (j >= 0 && array[j] > element)
        {
            array[j+1] = array[j];
            j = j-1;
        }

        array[j+1] = element;
    }
}

//will display the array before and after it has been sorted with insertion.
void displayInsertionSortArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}