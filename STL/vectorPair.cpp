#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<pair<int, int>> v;
    v.push_back(make_pair(1234, 98));
    v.push_back(make_pair(2345, 96));
    v.push_back(make_pair(3456, 88));
    v.push_back(make_pair(4567, 89));
    v.push_back(make_pair(45, 8));
    for (auto i : v)
    {
        cout << i.first << " , " << i.second << endl;
    }
    cout << "Capacity: " << v.capacity() << endl;
    cout << "size: " << v.size() << endl;
    return 0;
}