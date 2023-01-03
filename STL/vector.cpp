#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(5, 2);
    cout << "Capacity: " << v.capacity() << endl;
    v.push_back(6);
    cout << "Elements:    ";
    for (auto i : v)
    {
        cout << i << "  ";
    }
    cout <<endl<< "Capacity: " << v.capacity()<<endl;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    for (auto i : v)
    {
        cout << i << "  ";
    }
    cout << "Capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;
    return 0;
}
