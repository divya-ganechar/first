//Radix Sort
#include <iostream>
#include <vector>
using namespace std;

// Function to get the maximum number in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to perform counting sort based on a digit
void countingSort(int arr[], int n, int exp) {
    vector<int> output(n);      // output array
    int count[10] = {0};        // digits 0–9

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so that count[i] now contains the actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array in reverse order (for stability)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function for Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Apply counting sort for each digit (1, 10, 100, ...)
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, n);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
