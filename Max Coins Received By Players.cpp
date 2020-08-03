/*-----------------------------------------------------------------------Problem-------------------------------------------------------------------

You are given an array A of size N. The array contains integers and is of even length. 
The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.
You need to determine the maximum possible amouint of money you can win if you go first.

------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int MoreMoney(int i,int j,vector<int>&v,vector< vector<int> >&dp)
{
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    else
    {
        if(i==j)
        {
            dp[i][j]=v[i];
            return dp[i][j];
        }
        if(i+1==j)
        {
            dp[i][j]=max(v[i],v[j]);
            return dp[i][j];
        }
        int player1=v[i]+min(MoreMoney(i+2,j,v,dp),MoreMoney(i+1,j-1,v,dp));
        int player2=v[j]+min(MoreMoney(i,j-2,v,dp),MoreMoney(i+1,j-1,v,dp));
        dp[i][j]=max(player1,player2);
    }
    return dp[i][j];
}

int main() {
    FAST_IO;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        vector< vector<int> >dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        cout<<MoreMoney(0,n-1,v,dp)<<"\n";
    }
    
	return 0;
}

/*------------------------------------------------Approach------------------------------------ 

--- if we have only one coin , then the coin will be taken by the player who have chance
--- if we have two coins then the max of those will be take by the player
--- if we more than two
    --- a  b   c   d
    --- i          j
    --- if ith coin is considered by player1 ,then player2 takes i+1 or j th coin
        -- player1 has a chance of taking i+2  or j-1 th coin
        -- player1=v[i]+min(F(i+2,j),F(i+1,j-1))
    --- if j th coin is considered by player1 then player2 takes i or j-1 th coin
        -- player1 has a chance of taking i+1 or j-2 th coin
        -- player1=v[j]+min(F(i,j-2),F(i+1,j-1))
        
 --------------------------------------------------------------------------------------------------*/
    
