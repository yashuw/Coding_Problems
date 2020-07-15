/*----------------------Problem------------------------------------
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.
*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
    if(a<b && a<c)
        return a;
    else if(b<c)
        return b;
    return c;
}
int EditDistance(string s1,string s2)
{
    int m=s1.length()+1;
    int n=s2.length()+1;
    int distance[m][n];
    
    for(int i=0;i<n;i++)
    {
        distance[0][i]=i;
    }
    for(int i=0;i<m;i++)
    {
        distance[i][0]=i;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                distance[i][j]=distance[i-1][j-1];
            }
            else
            {
                distance[i][j]=1+min(distance[i-1][j],distance[i][j-1],distance[i-1][j-1]);
            }
        }
    }
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<distance[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return distance[m-1][n-1];
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        string s1,s2;
        cin>>s1>>s2;
        cout<<EditDistance(s1,s2)<<"\n";
    }
	return 0;
}

/*-----------------------Approach------------------------------

Example 1:
geek  gesek
        0   1   2   3   4   5
        $   g   e   s   e   k

0   $   0   1   2   3   4   5

1   g   1   0   1   2   3   4

2   e   2   1   0   1   2   3

3   e   3   2   1   1   1   2

4   k   4   3   2   2   2   1

----Done using Dynamic Programming
----Consider a 2D Matrix with size of s1 len as row size and s2 len as col size
----if s1[i]==s2[i] ,then consider diagonal value
----else consider min val of diagonal,left and top value

*/
