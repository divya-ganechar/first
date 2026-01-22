//Bucket Sort
#include <iostream>
#include <vector>
#include <algorithm>  // for sort()
using namespace std;

void bucketSort(float arr[], int n) {
    // Create empty buckets
    vector<float> bucket[10];

    // 1. Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * 10; // index = bucket number
        bucket[index].push_back(arr[i]);
    }

    // 2. Sort each bucket
    for (int i = 0; i < 10; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }

    // 3. Combine all buckets into arr[]
    int idx = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[idx++] = bucket[i][j];
        }
    }
}

int main() {
    float arr[] = {0.23, 0.89, 0.45, 0.12, 0.37, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bucketSort(arr, n);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
