// complete the selection_sort function

#include <cs50.h>
#include <stdio.h>

// function prototypes
void selection_sort(int arr[], int size);
void print_array(int arr[], int size);

// size of array
#define SIZE 10

int main(void)
{ 
    // initialize array
    int arr[] = {1, 8, 4, 6, 0, 3, 5, 2, 7, 9};
  
    // sort array
    selection_sort(arr, SIZE); 
    
    // print out the array
    print_array(arr, SIZE); 
    
    // done
    return 0; 
} 

// Function to print an array
void print_array(int arr[], int size) 
{ 
    for (int i = 0; i < size; i++) 
    {
        printf("%i ", arr[i]); 
    }
    printf("\n"); 
}

// selection sort
void selection_sort(int arr[], int size) 
{
    // TODO
    int s = 0;
    int a = 0;
    for (int i = 0; i < size - 1; i++)
    {
        s = i;
        for (int j = i + 1; j < size - 1; j++)
        {
            if (arr[j] < arr[s])
            {
                s = j;
            }
        }
        a = arr[s];
        arr[s] = arr[i];
        arr[i] = a;
    }
}
