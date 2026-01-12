//Write a program to find the address of given 2D array index where base address is given

#include <iostream>
using namespace std;

int main() 
{
    int baseAddress, rows, cols, i, j, choice;

    cout<<"Enter base address: ";
    cin>>baseAddress;

    cout<<"Enter total rows and columns: ";
    cin>>rows>>cols;

    cout<<"Enter index (i j): ";
    cin>>i>>j;

    cout<<"Choose data type:\n";
    cout<<"1. int\n2. char\n3. float\n4. double\n";
    cin>>choice;

    int size;
    switch (choice)
     {
        case 1: 
         size = sizeof(int); 
         break;
        case 2:
         size = sizeof(char);
         break;
        case 3:
         size = sizeof(float);
         break;
        case 4:
         size = sizeof(double); 
         break;
        default:
         cout<<"Invalid choice!"; 
         return 0;
    }

    //calculating address here
    int address = baseAddress + ((i*cols)+j) * size;

    cout<<"Address of A["<<i<<"]["<<j<<"] = "<<address<<endl;
    return 0;
}