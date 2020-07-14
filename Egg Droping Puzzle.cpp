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
        for(int i=1;i<n+1;i++)
        {
            arr[1][i]=i;
        }
        for(int i=2;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(i>j)
                {
                    arr[i][j]=arr[i-1][j];
                }
                else
                {
                    int minval=INT_MAX;
                    for(int k=1;k<=j;k++)
                    {
                        int val=1+max(arr[i-1][k-1],arr[i][j-k]);
                        if(val<minval)
                        {
                            minval=val;
                        }
                    }
                    arr[i][j]=minval;
                }
            }
        }
        cout<<arr[m][n]<<"\n";
        
    }
	return 0;
}
