#include <iostream>
using namespace std;



int partition(int *array, int, int);


//Quick sort function that takes in the array, first element and last element
void quickSort(int *array, int lowIndex, int highIndex)
{
    int pivot_location = 0;

    if (lowIndex >= highIndex)
    {
        return;
    }

    pivot_location = partition(array, lowIndex, highIndex);
    cout << endl << endl;

    quickSort(array, lowIndex, pivot_location);
    cout << endl << endl;

    quickSort(array, pivot_location + 1, highIndex);


}

//Function to move through the array and move the pivot location to a new location when needed, as the array is sorted.
int partition(int *array, int left, int right)
{
    int pivot;
    int tempVar;

    pivot = array[left];
    cout << "\n Pivot: " << pivot;
    int moveLeft = left-1;
    int moveRight = right+1;

    cout << "\n Left: " << moveLeft << " & Right: " << moveRight;
    while(moveLeft < moveRight)
    {
        do
        {
            moveRight--;
        }while(array[moveRight] > pivot);
        do
        {
            moveLeft++;   
        }while(array[moveLeft] < pivot);

        if(moveLeft < moveRight)
        {
            swap(array[moveLeft], array[moveRight]);
        }

    }
    return moveRight;
}
//function that will be called when the sort comes to a point where the right is less size than the left and needs to be swapped. 
void swap(int& lefty, int& righty)
{
    cout << "\n Swapped " << lefty << " & " << righty;
    int tempVar = lefty;
    lefty = righty;
    righty = tempVar;
}


//Display function to call to show the user what the array was before and after it has been sorted.
void displayQuickSortArray(int *array, int size)
{

    for(int i=0; i<size; i++)
    {
        cout << array[i] << " ";
    } 

}