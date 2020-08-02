/*---------------------------------------------------------Problem----------------------------------------------
---Given two numbers x and n, find number of ways x can be expressed as sum of n-th power of unique natural numbers.
  ---Input  : x = 10, n = 2
  ---Output : 1
  ---Explanation: 10 = 12 + 32
---------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int reslt=0;

int PowNaturalNumber(int n,int r,int k,int x)
{
    if(n==0)
        reslt++;
    for(int i=k+1;i<=r;i++)
    {
        int a=n-(int)pow(i,x);
        if(a>=0)
            PowNaturalNumber(a,r,i,x);
    }
    return reslt;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n>>x;
	    int r=(int)floor(pow(n,1.0/x));
	    cout<<PowNaturalNumber(n,r,0,x)<<"\n";
	    reslt=0;
	}
	return 0;
}
