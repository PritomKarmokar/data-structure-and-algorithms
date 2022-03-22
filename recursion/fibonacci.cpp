#include<bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    if(n <= 1)
        return n;
    
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    int n;
    cout<<"Enter the value of n (n>0) : ";
    cin>>n;

    int val = fibo(n);
    cout<<n<<" th fibonacci is : "<<val<<endl;

    return 0;
}

