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

void PowNaturalNumber(int n,int r,int x)
{
    if(n==0)
    {
        reslt++;
        return;
    }
    if(r<=0)
        return;
    if(n<0)
        return;
    int val=pow(r,x);
    if(n>=val)
        PowNaturalNumber(n-val,r-1,x);
    PowNaturalNumber(n,r-1,x);
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n>>x;
	    int r;
	    for(int i=1;pow(i,x)<=n;i++)
            	r=i;
	    PowNaturalNumber(n,r,x);
	    cout<<reslt<<"\n";
	    reslt=0;
	}
	return 0;
}
