#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    cout<<"print stack top element:";
    cout<<st.top()<<endl;
    cout<<"print stack size:";
    cout<<st.size()<<endl<<endl;

    cout<<"print stack all elmenet:"<<endl;
    while (!st.empty())
    {
       cout<<st.top()<<endl;
       st.pop();
    }
    
    


}