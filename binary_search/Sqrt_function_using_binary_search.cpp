#include<bits/stdc++.h>
using namespace std;

double sqrt(double num)
{
    double low = 0.0;
    double high = num;
    double mid;
    while(high - low > 0.000001){
        mid = (low + high)/2;

        cout<<low<<" "<<high<<" "<<mid*mid<<endl;

        if(mid * mid > num)     // then we don't to search the mid to number portion
            high = mid;
        else                   // then mid * mid < num 
            low = mid;
    }

    cout<<mid*mid<<" "<<mid<<endl;

    return mid;
}

int main()
{
    int val = 15;
    cout<<sqrt(val)<<endl;
}