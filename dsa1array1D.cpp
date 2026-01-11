//performimg operations on array

#include<iostream>
using namespace std;

const int MAX_SIZE = 100;

void display(int arr[], int size) 
{
    cout<<"Array elements:";
    for(int i=0;i<size;i++)
      cout<<arr[i]<<" ";
      cout<<endl;
}

void traverse(int arr[], int size) 
{
    cout<<"Traversing array:\n";
      for(int i=0; i<size; i++)
        cout<<"Element at index "<< i <<": "<< arr[i]<<endl;
}

int insert(int arr[], int size, int element, int position) 
{
    if(size>= MAX_SIZE) 
    {
        cout<<"Array is full. Can't insert."<<endl;
        return size;
    }
    if(position < 0 || position > size) 
    {
        cout <<"Invalid position!"<<endl;
        return size;
    }

    for(int i=size; i>position; i--)
        arr[i]= arr[i-1];

    arr[position]=element;
    return size+1;
}

int delElement(int arr[], int size, int position) 
{
    if(size<= 0) 
    {
        cout<<"Array is empty..... There is no element to delete."<<endl;
        return size;
    }
    if(position<0 || position>=size) 
    {
        cout<<"Invalid position...."<<endl;
        return size;
    }

    for(int i=position; i<size-1; i++)
        arr[i]=arr[i+1];

    return size-1;
}

int merge(int arr1[], int size1, int arr2[], int size2, int merged[]) 
{
    int i;
    for(i=0; i<size1; i++)
        merged[i] = arr1[i];
    for(int j=0; j<size2; j++)
        merged[i+j] =arr2[j];
    return size1+size2;
}

int main() 
{
    int arr[MAX_SIZE], size=0;
    int choice;

    cout<<"Enter number of elements in array: ";
    cin>>size;

    if (size>MAX_SIZE || size<0) 
    {
        cout<<"Invalid size!";
        return 1;
    }

      cout<<"Enter "<<size <<" elements:\n";
      for(int i=0; i<size; i++)
        cin>>arr[i];

    do {
        cout <<"\n==== Choose any option which you want to perform ====\n";
        cout <<"1. Display Array\n";
        cout <<"2. Traverse Array\n";
        cout <<"3. Insert Element\n";
        cout <<"4. Delete Element\n";
        cout <<"5. Merge with Another Array\n";
        cout <<"6. Exit\n";
        cout <<"Enter your choice from 1 to 6 :";
        cin >>choice;

        switch(choice)
       {
        case 1:
            display(arr,size);
            break;

        case 2:
            traverse(arr,size);
            break;

        case 3: 
        {
            int element,position;
            cout<<"Enter element to insert";
            cin>>element;
            cout<<"Enter position (0 to "<<size<<"):";
            cin>>position;
            size=insert(arr,size,element,position);
            break;
        }

        case 4: 
        {
            int position;
            cout<<"Enter position to delete (0 to "<<size-1 <<"): ";
            cin>>position;
            size=delElement(arr, size, position);
            break;
        }

        case 5: 
        {
            int arr2[MAX_SIZE], size2;
            cout<<"Enter number of elements in second array: ";
            cin>>size2;

            if(size2+size >MAX_SIZE) 
            {
                cout<<"Merging exceeds max array size!"<<endl;
                break;
            }

            cout<<"Enter "<<size2<<" elements:\n";
            for(int i=0; i<size2; i++)
                cin>>arr2[i];

            int merged[MAX_SIZE];
            int mergedSize = merge(arr, size, arr2, size2, merged);
            cout<<"Merged array: ";
   
            display(merged, mergedSize);
            break;
        }

        case 6:
            cout<<"Exiting program." <<endl;
            break;

        default:
            cout<<"Invalid choice. Try again."<<endl;
        }

    } 
     while(choice != 6);
     return 0;
}