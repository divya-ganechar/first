//Bus Reservation System 

#include<iostream>
using namespace std;

int main(){
    const int MAX_BUSES = 3;
    const int MAX_SEATS = 10;

    string busNames[MAX_BUSES] = {"Bus A", "Bus B", "Bus C"};
    int seats[MAX_BUSES][MAX_SEATS] = {0}; 

    int choice;
    do{
        cout<< "\n=== Bus Booking System ===\n";
        cout<< "1. Show Available Buses\n";
        cout<< "2. Book a Seat\n";
        cout<< "3. Show Bookings\n";
        cout<< "4. Exit\n";
        cout<< "Enter your choice: ";
        cin>>choice;

        if(choice == 1) 
        {
            cout<<"\nAvailable Buses:\n";
            for (int i=0; i<MAX_BUSES; i++) 
            {
                cout<<i+1<<". "<<busNames[i]<<endl;
            }

        } 
        else if(choice == 2) 
        {
            int busIndex, seatNumber;

            cout<<"\nEnter bus number (1-"<<MAX_BUSES<<"): ";
            cin>>busIndex;

            if(busIndex < 1 || busIndex > MAX_BUSES) 
            {
                cout<<"Invalid bus number!\n";
                continue;
            }
            busIndex--; 

            cout<<"\nSeat status for "<<busNames[busIndex]<<":\n";
            for(int i=0; i<MAX_SEATS; i++) 
            {
                cout<<"Seat "<<i+1<<": "<<(seats[busIndex][i] == 0 ? "Available" : "Booked")<<endl;
            }

            cout<<"\nEnter seat number to book (1-" << MAX_SEATS << "): ";
            cin>>seatNumber;

            if(seatNumber < 1 || seatNumber > MAX_SEATS) 
            {
                cout<<"Invalid seat number!\n";
                continue;
            }
            seatNumber--; 

            if(seats[busIndex][seatNumber] == 1) 
            {
                cout<<"Seat already booked.\n";
            }
            else 
            {
                seats[busIndex][seatNumber] = 1;
                cout<<"Seat booked successfully!\n";
            }
              
        } 
        else if(choice == 3) 
        {
            cout<<"\nBooking Details:\n";
            for(int i=0; i<MAX_BUSES; i++) 
            {
                cout<<"\n"<<busNames[i]<<":\n";
                for(int j=0; j < MAX_SEATS; j++) 
                {
                    if(seats[i][j] == 1) 
                    {
                        cout<<"Seat "<<j+1<<": Booked\n";
                    }
                }
            }

        } 
        else if(choice == 4) 
        {
            cout<<"Exiting the program.......\n";
        }
         else 
         {
            cout<<"Invalid choice. Try again.\n";
         }

    } 
      while (choice != 4);
    return 0;
}