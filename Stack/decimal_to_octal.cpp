// Program for Decimal to Octal Conversion

#include <iostream>
using namespace std;
#define stacksize 10
#define true 1
#define false 0
struct stack
{
    int top;
    int items[stacksize];
};
struct stack s;

int initialize()
{
    s.top = -1;
}
int empty()
{
    if (s.top == -1)
        return true;
    else
        return false;
}
int push(int x)
{
    if (s.top == stacksize - 1)
    {
        cout << "stack overflow";
        exit(1);
    }
    s.top = s.top + 1;
    s.items[s.top] = x;
}
int pop()
{
    if (empty())
    {
        cout << "stack underflow";
        exit(1);
    }
    int x = s.items[s.top];
    s.top = s.top - 1;
    return x;
}
int main()
{
    int n, rem;
    cout << "Enter decimal number: ";
    cin >> n;
    initialize();
    while (n != 0)
    {
        rem = n % 8;
        push(rem);
        n = n / 8;
    }
    while (!empty())
    {
        cout << pop();
    }

    return 0;
}