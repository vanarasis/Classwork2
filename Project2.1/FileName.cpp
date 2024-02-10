#include <iostream>
// iostream stands for input output statments 
using namespace std;

int main()
{
    // Initialize an array of integers
    int arr[] = { 1, 2, 3, 4, 5, 10, 9, 8, 7, 6 };
    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort algorithm implementation
    // Outer loop for passes through the array
    for (int i = 0; i < n - 1; i++)
    {
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++)
        {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1])
            {   
                // here this indicates swaping 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    // return value 0
    return 0;
}