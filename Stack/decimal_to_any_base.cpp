// Program for Decimal to Any Base Conversion

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

char push(char x)
{
    if (s.top == stacksize - 1)
    {
        cout << "stack overflow";
        exit(1);
    }
    s.top = s.top + 1;
    s.top[s.items] = x;
}

char pop()
{
    if (empty())
    {
        cout << "stack underflow";
        exit(1);
    }
    char x = s.items[s.top];
    s.top = s.top - 1;
    return x;
}
int main()
{
    int n, rem, base;
    char ch;
    cout << "Enter decimal number: ";
    cin >> n;
    cout << "Enter base: ";
    cin >> base;
    initialize();
    while (n != 0)
    {
        rem = n % base;
        if (rem < 10)
        {
            ch = rem + 48;
            push(ch);
        }
        else
        {
            ch = rem + 55;
            push(ch);
        }
        n = n / base;
    }
    while (!empty())
    {
        cout << pop();
    }
    return 0;
}