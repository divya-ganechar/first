#include <iostream>
using namespace std;
int main() 
{
    const int num_questions = 20;
    const int right_ans = 4;

    char answers[num_questions];
    int total_marks = 0;
    int correct_count = 0;
    int wrong_count = 0;
    int not_attempted_count = 0;

    int consecutive_wrong = 0;  // To track streak of wrong answers

    cout << "Checking each question:\n";
    cout << "'t' for correct, 'f' for wrong, 'n' for not attempted\n";

    for (int i=0; i < num_questions; i++) 
    {
        cout << "Question " << (i+1)<< ": ";
        cin >> answers[i];

        // Validation of input
        while (answers[i] != 't' && answers[i] != 'f' && answers[i] != 'n')
        {
            cout << "Invalid input! Enter 't' (correct), 'f' (wrong), or 'n' (not attempted): ";
            cin >> answers[i];
        }

        if (answers[i] == 't') 
        {
            total_marks += right_ans;
            correct_count++;
            consecutive_wrong = 0;  //consecutive order reset
        } 
        else if (answers[i] == 'f') 
        {
            consecutive_wrong++;  
            total_marks -= consecutive_wrong;
            wrong_count++;
        } 
        else if (answers[i] == 'n') 
        {
            not_attempted_count++;
        }
    }

    cout << "\n--- Result ---\n";
    cout << "Number of Correct Answers : " << correct_count << endl;
    cout << "Number of Wrong Answers   : " << wrong_count << endl;
    cout << "Number of Not Attempted   : " << not_attempted_count << endl;
    cout << "Final Score               : " << total_marks << " out of " << (num_questions * right_ans) << endl;

    //grade calculation
    double percentage = (double)total_marks / (num_questions * right_ans) * 100;
    char grade;

      if (percentage >= 90)
        grade = 'A';
      else if (percentage >= 80)
        grade = 'B';
      else if (percentage >= 70)
        grade = 'C';
      else if (percentage >= 60)
        grade = 'D';
      else
        grade = 'F';
      cout << "Grade                      : " << grade << endl;
      return 0;
}
