

//function that does all the work with merging the elements in the array and moving them around to their new locations when sorted.
void merge(int *array, int first, int mid, int last)
{
    int partitionSize = last - first + 1;
    int positionMerge = 0;
    int leftPosition = 0;
    int rightPosition=0;
    int* numbersMerged = new int[partitionSize];

    leftPosition = first;
    rightPosition = mid + 1;

    while(leftPosition <= mid && rightPosition <= last)
    {
        if(array[leftPosition] < array[rightPosition])
        {
            numbersMerged[positionMerge] = array[leftPosition];
            ++leftPosition;
        }
        else
        {
            numbersMerged[positionMerge] = array[rightPosition];
            ++rightPosition;
            
        }
        ++positionMerge;
    }

    while(leftPosition <= mid)
    {
        numbersMerged[positionMerge] = array[leftPosition];
        ++leftPosition;
        ++positionMerge;
    }

    while(rightPosition <= last)
    {
        numbersMerged[positionMerge] = array[rightPosition];
        ++rightPosition;
        ++positionMerge;

    }

    for(positionMerge =0; positionMerge < partitionSize; ++positionMerge)
    {
        array[first + positionMerge] = numbersMerged[positionMerge];
    }
    
    delete [] numbersMerged;


}


//main merge sort function that will be called from the driver and then initialize the mergeSort function that does all the heavy lifting
void mergeSort(int *array, int first, int last)
{
    int mid = 0;

    if(first < last)
    {
        mid = (first + last) / 2;

        mergeSort(array, first, mid);
        mergeSort(array, mid + 1, last);

        merge(array, first, mid, last);


    }
}


//displays the array before and after it has been sorted with merge sort.
void displayMergeSortArray(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}