//program to reverse given string using stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() 
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    stack<char> st;

    // Push all characters onto stack
    for (int i = 0; i < s.length(); i++) {
        st.push(s[i]);
    }

    // Pop from stack and build reversed string
    string rev = "";
    while (!st.empty()) 
    {
        rev += st.top();
        st.pop();
    }

    cout << "Original string: " << s << endl;
    cout << "Reversed string: " << rev << endl;

    return 0;
}