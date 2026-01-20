//program to implement binary search
#include <iostream>
using namespace std;

// Function for sequential (linear) search
int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i; // Element found, return index
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {10, 5, 20, 15, 30, 25};
    int n = 6; 

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int index = sequentialSearch(arr, n, target);

    if (index != -1)
        cout << "Element " << target << " found at index " << index << "." << endl;
    else
        cout << "Element " << target << " not found in the array." << endl;

    return 0;
}
