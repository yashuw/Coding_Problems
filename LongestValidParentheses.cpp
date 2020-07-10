#include <bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int LongestValidPara(string s)
{
    int n=s.length();
    int dp[n+1];
    dp[0]=0;
    int maxlen=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
            dp[i+1]=0;
        else if(s[i]==')')
        {
            int j=i-dp[i]-1;
            if(j>=0 && (s[i]==')' && s[j]=='('))
            {
                
                dp[i+1]=dp[i]+dp[j]+2;
                maxlen=max(maxlen,dp[i+1]);
            }
            else
            {
                dp[i+1]=0;
            }
        }
    }
    return maxlen;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<LongestValidPara(s)<<"\n";
    }
    
	return 0;
}

/*
---------Approach-------------
It is done using Dyamic Programing 
--if char of a string is a open parentheses then dp val will be "0" ,bcz a open parenthesis  will not be a valid parenthesis
--if char of a string is closing parenthesis then we have two case
  ---if we found a open parenthesis at j  then it will be a valid one else dp val is "0"
      --for that i use j=i-dp[i]-1
      --i---current position
      --dp[i]--len of valid paren before i
      --j will give the position of open parentheses
      --dp val will be length of valid before i and after j + valid len before j+present two parenthesis
        ---dp[i+1]=dp[i]+dp[j]+2
      
Ex:
index: 0  1  2  3  4  5  
       )  (  )  (  )  )
        \  \  \  \  \  \
DP :   0  0  0  2  0  2  0
       0  1  2  3  4  5  6

*/

