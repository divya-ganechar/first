// Write a program to perform operation on 2D//// Array

#include<iostream>
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

int arr[MAX_ROWS][MAX_COLS];
int rows= 0, cols= 0;

void createArray() 
{
    cout<<"Enter number of rows (max "<< MAX_ROWS << "): ";
    cin>>rows;
    cout<<"Enter number of columns (max "<< MAX_COLS << "): ";
    cin>>cols;

    if(rows<=0 || rows> MAX_ROWS || cols<= 0 || cols> MAX_COLS) 
    {
        cout<<"Invalid dimensions!\n";
        rows=cols=0;
        return;
    }

    cout<<"Enter elements:\n";
    for(int i=0; i<rows; ++i) 
    {
        for(int j=0; j<cols; ++j) 
        {
            cout<<"Element ["<<i<<"]["<<j<<"]: ";
            cin>>arr[i][j];
        }
    }
}

void displayArray() 
{
    if (rows == 0 || cols == 0) {
        cout << "Array is empty. Create it first.\n";
        return;
    }

    cout<<"2D Array:\n";
    for(int i=0; i<rows; ++i) 
    {
        for(int j=0; j<cols; ++j) 
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void insertElement() 
{
    int r, c, val;
    cout<<"Enter row index (0 to "<<rows- 1<< "): ";
    cin>>r;
    cout<<"Enter column index (0 to "<<cols-1<<"): ";
    cin>>c;

    if(r<0 || r>=rows || c<0 || c>=cols) 
    {
        cout<<"Invalid position!\n";
        return;
    }

    cout<<"Enter value to insert: ";
    cin>>val;
    arr[r][c]=val;
    cout<<"Value inserted.\n";
}

void updateElement() 
{
    int r, c, val;
    cout<<"Enter row index: ";
    cin>>r;
    cout<<"Enter column index: ";
    cin>>c;

    if(r<0 || r>=rows || c<0 || c>=cols) 
    {
        cout<<"Invalid position!\n";
        return;
    }

    cout<<"Enter new value: ";
    cin>>val;
    arr[r][c] = val;
    cout<<"Value updated.\n";
}

void searchElement() 
{
    int val;
    bool found = false;
    cout<<"Enter value to search: ";
    cin>>val;

    for(int i=0; i<rows; ++i) 
    {
        for(int j=0; j<cols; ++j) 
        {
            if (arr[i][j] == val) 
            {
                cout<<"Found at ["<<i<<"]["<<j<<"]\n";
                found = true;
            }
        }
    }

    if(!found)
        cout << "Value not found in array.\n";
}

void deleteRow() 
{
    int rowToDelete;
    cout<<"Enter row number to delete (0 to "<<rows - 1<<"): ";
    cin>>rowToDelete;

    if(rowToDelete <0 || rowToDelete >= rows) 
    {
        cout<<"Invalid row index!\n";
        return;
    }

    for(int i=rowToDelete; i<rows - 1; ++i) 
    {
        for(int j=0; j<cols; ++j) 
        {
            arr[i][j] = arr[i + 1][j];
        }
    }

    rows--;
    cout<<"Row deleted successfully.\n";
}

void deleteColumn() 
{
    int colToDelete;
    cout<<"Enter column number to delete (0 to "<<cols - 1<<"): ";
    cin>>colToDelete;

    if(colToDelete < 0 || colToDelete >= cols) 
    {
        cout<<"Invalid column index!\n";
        return;
    }

    for(int j = colToDelete; j<cols - 1; ++j) 
    {
        for(int i=0; i<rows; ++i) 
        {
            arr[i][j] = arr[i][j + 1];
        }
    }

    cols--;
    cout<<"Column deleted successfully.\n";
}

int main() 
{
    int choice;

    do {
        cout <<"\n=== 2D Array Operations ===\n";
        cout <<"1. Create Array\n";
        cout <<"2. Display Array\n";
        cout <<"3. Insert Element\n";
        cout <<"4. Update Element\n";
        cout <<"5. Search Element\n";
        cout <<"6. Delete Row\n";
        cout <<"7. Delete Column\n";
        cout <<"8. Exit\n";
        cout <<"Enter your choice: ";
        cin >>choice;

        switch (choice) 
        {
            case 1: 
             createArray();
             break;
            case 2: 
             displayArray(); 
             break;
            case 3: 
             insertElement(); 
             break;
            case 4: 
             updateElement(); 
             break;
            case 5: 
             searchElement(); 
             break;
            case 6:
             deleteRow(); 
             break;
            case 7:
             deleteColumn(); 
             break;
            case 8:   
             cout<<"Exiting program.\n"; 
            break;
            default: 
             cout<<"Invalid choice. Try again.\n";
        }

    } 
    while(choice != 8);
    return 0;
}