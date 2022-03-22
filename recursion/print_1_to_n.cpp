// A recursive function that prints 1 to n 

#include<bits/stdc++.h>
using namespace std;

void print(int i, int n)
{
    // base condition
    if(i >= n){
        return;
    }

    cout<<i<<" ";

    // recursive call
    print(i+1, n);
}

int main()
{
    print(1,6);
    cout<<endl;

    return 0;
}