#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main()
{

    queue<int>q;
    cout<<q.size()<<endl;
    q.push(8);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    cout<<q.front()<<endl;//first element
    cout<<q.size()<<endl;
    
return 0;
}