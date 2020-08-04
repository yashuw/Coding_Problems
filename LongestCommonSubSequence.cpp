/*-----------------------------------------------Problem--------------------------------------

Given two sequences, find the length of longest subsequence present in both of them.

----------------------------------------------------------------------------------------------*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int LongestCommonSubsequence(string s1,string s2)
{
    int m=s1.size();
    int n=s2.size();
    vector< vector<int> >mat(m+1,vector<int>(n+1,0));
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                mat[i][j]=1+mat[i-1][j-1];
            }
            else
            {
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    //-------------------------------Printing the subsequence -----------------------------------------
    int i=m,j=n;
    int size=mat[i][j];
    int index=size-1;
    char res[size];
    while(i>0)
    {
        while(j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                res[index--]=s1[i-1];
                i--;
                j--;
            }
            else if(mat[i-1][j]>mat[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(int i=0;i<size;i++)
        cout<<res[i]<<" ";
    //----------------------------------------------------------------------------------------------
    return mat[m][n];   ---------------->Return the LongestCommonSubsequence
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
        cout<<LongestCommonSubsequence(s1,s2)<<"\n";
    }
	return 0;
}

/*-----------------------------------------------Approach--------------------------
---There are two cases to include or not include a character into subsequence
    --if the character of string1 and string2 are equal ,then we surely add the character into subsequence
    --if character are not equal,then we have two cases
      --Matching character may appear in string1 before position of this character
      --Or it appear before this pos in string 2
