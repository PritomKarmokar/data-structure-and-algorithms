#include<bits/stdc++.h>
using namespace std;

void print(int i, int n)
{   
    // base condition
    if(i > n){
        cout<<endl;
        return;
    }

    // recursive call
    print(i+1, n);

    cout<<i<<" ";

}

int main()
{
    print(1, 6);
    cout<<endl;
    return 0;
}