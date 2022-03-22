#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n <= 1) return 1;

    return n * fact(n-1); 
}

int main()
{
    int n;

    cout<<"Enter the value of n (n > 0) : ";
    cin>>n;

    int result = fact(n);

    cout<<n<<" ! = "<<result<<endl;

    return 0;
}