/*
---------------------------------------Problem----------------------------------------------------

Given a positive number X. Find all Jumping Numbers smaller than or equal to X. 
Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. 
All single digit numbers are considered as Jumping Numbers. For example 7, 
8987 and 4343456 are Jumping numbers but 796 and 89098 are not.

---------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void JumpingNumber(int n)
{
    queue<int>q;
    for(int i=1;i<10;i++)
        q.push(i);
    cout<<0<<" ";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        int temp=q.front();
        q.pop();
        int rem=temp%10;
        int up_temp,low_temp;
        if(rem>0 && rem<9)
        {
            low_temp=temp*10+(rem-1);
            if(low_temp<=n)
            {
                q.push(low_temp);
            }
            up_temp=temp*10+(rem+1);
            if(up_temp<=n)
            {
                q.push(up_temp);
            }
        }
        else if(rem==0)
        {
            up_temp=temp*10+(rem+1);
            if(up_temp<=n)
            {
                q.push(up_temp);
            }
            
        }
        else if(rem==9)
        {
            low_temp=temp*10+(rem-1);
            if(low_temp<=n)
            {
                q.push(low_temp);
            }
        }
    }
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n<=10)
        {
            for(int i=0;i<=n;i++)
            {
                cout<<i<<" ";
            }
        }
        else{
            JumpingNumber(n);
        }
        cout<<"\n";
    }
	return 0;
}
/*
QUEUE IMPLEMENTATION:

-  <----------------------------------------|
-  <--------------------------------------- |
-  <------------------------------|         |
-  <------------------------------|         |
9                                 |         |
8                                 |         |
7                push into queue  |         |
6              if val less than n |         |push into queue if val less than given n.
5                                 |         |
4                                 |         |
3                                 |         |
    pop                           |         |
2 =======> 1)2*10+(2-1)==>21------|---------|
           2)2*10+(2+1)==>23 -----|---------|             
    pop                           |         
1 =======> 1) 1*10+(1-1)==>10-----|
           2) 1*10+(1+1)==>12-----|

---Perform untill queue is empty.
