/*
------------------------------Problem---------------------------------------
There are N stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time.
Count the number of ways, the person can reach the top
----------------------------------------------------------------------------
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int mod=(int)1e9+7;
void multiply(long long int F[2][2],long long int M[2][2])
{
    long long int ans[2][2]={0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				ans[i][j]=((ans[i][j]%mod)+((F[k][j]%mod)*(M[i][k]%mod))%mod)%mod;
			}
		}
	 } 
	 F[0][0]=ans[0][0];
	 F[0][1]=ans[0][1];
	 F[1][0]=ans[1][0];
	 F[1][1]=ans[1][1];
}
void power(long long int F[2][2],long long int n)
{
    if(n==0||n==1)
        return ;
    long long int M[2][2]={{1,1},{1,0}};
    power(F,n/2);
    multiply(F,F);
    if(n%2!=0)
        multiply(F,M);
}
long long int CountWays(long long int n)
{
    long long int F[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    power(F,n);
    return F[0][0]%mod;
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        cout<<CountWays(n)<<"\n";
    }
	return 0;
}


/*
----------------------------------------------Approach----------------------------------------------------
----N = 1  ==> 1.
----N = 2. (1 + 1), (2)  ==> 2.
----N = 3. (1 + 1 + 1), (2 + 1), (1 + 2)  ==> 3.
----N = 4. (1 + 1 + 1 + 1), (2 + 1 + 1), (1 + 2 + 1), (1 + 1 + 2), (2 + 2)  ==> 5 .......

----We can be observe that it form Fibonacci Series.
    ----The number of ways of reaching  N  Stair's as 1s and 2s is (N + 1)th Fibonacci number.
    ----Used Finding Fibonaccci Number in Log(N) Time 
----------------------------------------------------------------------------------------------------------
*/

/*
-----------------Related Problem -------------------
=>Ways to represent a number as a sum of 1’s and 2’s
*/
