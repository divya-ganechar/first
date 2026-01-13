//program to arrange character array as per change in integer array

#include <iostream>
using namespace std;

int main(){
    int n;
    cout <<"Enter size of arrays: ";
    cin >>n;
    char chars[n];
    int numbers[n];

    cout << "Enter "<<n<<" characters: ";
    for(int i = 0; i < n; i++){
        cin >>chars[i];
    }
    // Input integer array
    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++){
        cin>>numbers[i];
    }
    // Arrange char array based on integer array
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(numbers[i] > numbers[j]){
                // Swap integers
                int tempNum = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tempNum;

                // Swap corresponding chars
                char tempChar = chars[i];
                chars[i] = chars[j];
                chars[j] = tempChar;
            }
        }
    }
    // Print arranged arrays
    cout <<"\nArranged integers: ";
    for(int i = 0; i < n; i++)
        cout << numbers[i] << " ";

    cout <<"\nArranged characters: ";
    for(int i = 0; i < n; i++)
        cout <<chars[i]<< " ";
    return 0;
}