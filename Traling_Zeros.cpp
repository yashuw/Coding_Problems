//Given a number n, you have to tell the number of zeroes at the end of n! where

//n! = 1.2.3.....(n-2).(n-1).(n)

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int n;
    cin>>n;
    long long int sumz=0;
    while(n>5)
    {
        sumz+=n/5;
        n=n/5;
    }
    cout<<sumz<<"\n";
    return 0;
}

/*
-----------------------------Approach-------------------------------------
n! = Highest power of 5 in n! will give the no.of trailing zeros at end.
--------------------------------------------------------------------------
*/
