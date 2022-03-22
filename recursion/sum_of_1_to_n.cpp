#include<bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if(n <= 1) return n;

    return n + sum(n-1);
}

int main()
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int ans = sum(n);
    cout<<"Sum upto "<<n<<" is = "<<ans<<endl;

    return 0;
}