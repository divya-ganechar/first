// program for voting system
#include <iostream>
#include <string>
using namespace std;

#define CANDIDATE_COUNT 4

string candidates[CANDIDATE_COUNT] = {"BJP", "INC", "RJD", "BSP"};
int votes[CANDIDATE_COUNT] = {0};
int spoiledVotes = 0;

void castVote() 
{
    int choice;
    cout << "\n### Cast Your Vote ###\n";
    cout << "Select candidate number (1-" << CANDIDATE_COUNT << "):\n";
    for (int i = 0; i < CANDIDATE_COUNT; i++) 
    {
        cout << i + 1 << ". " << candidates[i] << endl;
    }
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice >= 1 && choice <= CANDIDATE_COUNT) 
    {
        votes[choice - 1]++;
        cout << "Vote cast successfully for " << candidates[choice - 1] << "!\n";
    } 
    else
    {
        spoiledVotes++;
        cout << "Invalid vote counted as spoiled.\n";
    }
}

void showVotes() 
{
    cout << "\n### Voting Statistics ###\n";
    for (int i = 0; i < CANDIDATE_COUNT; i++) 
    {
        cout << candidates[i] << " - " << votes[i] << " votes\n";
    }
    cout << "Spoiled Votes: " << spoiledVotes << endl;
}

void showWinner() 
{
    int maxVotes = 0;
    int winnerIndex = -1;
    bool tie = false;

    for (int i = 0; i < CANDIDATE_COUNT; i++)
   {
        if (votes[i] > maxVotes)
        {
            maxVotes = votes[i];
            winnerIndex = i;
            tie = false; 
        } 
        else if (votes[i] == maxVotes && maxVotes != 0) 
        {
            tie = true;
        }
    }

    cout << "\n### Election Result ###\n";
    if (maxVotes == 0) 
    {
        cout << "No votes have been cast yet.\n";
    } 
    else if (tie) 
    {
        cout << "It's a tie! No single winner.\n";
    } 
    else 
    {
        cout << "Winner is " << candidates[winnerIndex] << " with " << maxVotes << " votes!\n";
    }
}

int main() 
{
    int choice;
    do 
    {
        cout << "\n====== Voting System Menu ======\n";
        cout << "1. Cast Vote\n";
        cout << "2. Show Votes\n";
        cout << "3. Show Winner\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                castVote();
                break;
            case 2:
                showVotes();
                break;
            case 3:
                showWinner();
                break;
            case 0:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } 
    while (choice != 0);
 return 0;
}