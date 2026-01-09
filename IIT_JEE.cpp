#include <iostream>
#include <string>
using namespace std;

int main() {
    string startClass, board, school, coaching;
    float score = 0, probability = 0.0;

    cout<<"\n";
    cout<<"       IIT JEE Selection Chance Prediction System\n";
    cout<<"----------------------------------------------------------\n";

    cout<<"Enter the class you started IIT preparation (7-12 or After 12): ";
    cin>>startClass;

    cout<<"Enter your School Board (CBSE / State): ";
    cin>>board;

    cout<<"Enter your Schooling Type (Dummy / Regular): ";
    cin>>school;

    cout<<"Enter your Coaching Mode (Online / Offline / Hybrid): ";
    cin>>coaching;

    if(startClass == "7" || startClass == "8")
       score += 45;
    else if(startClass == "9" || startClass == "10")
       score += 40;
    else if(startClass == "11") 
       score += 30;
    else if(startClass == "12")
       score += 15;
    else score += 8;

    if(board == "CBSE")
       score += 20;
    else score += 15;

    if(school == "Dummy")
        score += 18;
    else score += 6;

    if(coaching == "Hybrid")
        score += 20;
    else if(coaching == "Offline")
        score += 15;
    else score += 6;

    probability = score/100; 
                                     
    cout<<"------------------------------------------\n";
    cout<<"\n";
    cout<<"Estimated Probability Score: "<<score<<"%\n";
    cout<<"Probability Value (0 - 1 Scale): "<<probability<<endl;

    if(score >= 80) 
    {
       cout<<"Prediction Result: HIGH Chance of Selection\n";
    }
    else if(score >= 50) 
    {
       cout<<"Prediction Result: MEDIUM Chance of Selection\n";
    }
    else 
    {
       cout<<"Prediction Result: LOW Chance of Selection\n";
    }
      cout<<"------------------------------------------\n";
      return 0;
}
