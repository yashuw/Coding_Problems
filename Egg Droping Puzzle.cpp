/*-------------------------------------------------------------------Problem-----------------------------------------------------
Suppose you have N eggs and you want to determine from which floor in a K-floor 
building you can drop an egg such that it doesn't break. You have to determine 
the minimum number of attempts you need in order find the critical floor in the 
worst case while using the best strategy.There are few rules given below. 

	An egg that survives a fall can be used again.
	A broken egg must be discarded.
	The effect of a fall is the same for all eggs.
	If the egg doesn't break at a certain floor, it will not break at any floor below.
	If the eggs breaks at a certain floor, it will break at any floor above.

-----------------------------------------------------------------------------------------------------------------------------------*/
	


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int arr[m+1][n+1]={0};
        //If we have one floor then no.of trial will be 1, 
        //if we have Zero floor no.of trial will be 0
        for(int i=1;i<m+1;i++)
        {
            arr[i][1]=1;
            arr[i][0]=0;
        }
        //if no.of floors are i and 1 egg ,then we require j trails
        for(int i=1;i<n+1;i++)
        {
            arr[1][i]=i;
        }
        for(int i=2;i<m+1;i++)
        {
            for(int j=2;j<n+1;j++)
            {
                int minval=INT_MAX;
                for(int k=1;k<=j;k++)
                {
                    int val=1+max(arr[i-1][k-1],arr[i][j-k]);
                    minval=min(minval,val);
                }
                arr[i][j]=minval;
            }
        }
        cout<<arr[m][n]<<"\n";
        
    }
	return 0;
}
