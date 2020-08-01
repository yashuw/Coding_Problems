/*------------------------------------------------------Problem----------------------------------------------------------
Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number.
-------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int SubArraySum(int a[],int n)
{
    int max_ending_here=0,max_so_far=0;
    for(int i=0;i<n;i++)
    {
        max_ending_here+=a[i];
        if(max_ending_here<0)
            max_ending_here=0;
        if(max_so_far<max_ending_here)
            max_so_far=max_ending_here;
    }
    return max_so_far;
}
int MaxCircularArraySum(int a[],int n)
{
    int max_subarr_sum=SubArraySum(a,n);
    int max_wrap=0;
    for(int i=0;i<n;i++)
    {
        max_wrap+=a[i];
        a[i]=-a[i];
    }
    max_wrap+=SubArraySum(a,n);
    return (max_wrap>max_subarr_sum)? max_wrap : max_subarr_sum;
}

int main() {
	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	cout<<MaxCircularArraySum(a,n);
	return 0;
}

