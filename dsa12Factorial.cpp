//Program to find the factirial
#include <iostream>
using namespace std;

long long factorial(int n)
{
    if (n <= 1) // base case: if n is 0 or 1, factorial is 1
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int num;
    cout << "Enter a non-negative integer: ";
    cin >> num;

    if (num < 0)
    {
        cout << "Cannot compute factorial of a negative number.\n";
    }
    else
    {
        long long result = factorial(num);
        cout << "Factorial of " << num << " = " << result << endl;
    }
    return 0;
}