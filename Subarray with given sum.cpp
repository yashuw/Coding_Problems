Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void subarraysum(int val[],int n,int sum)
{
   int currsum=val[0];
   int start=0,i;
   for(int i=1;i<=n;i++)
   {
      while(currsum>sum && start<i-1)
      {
          currsum-=val[start];
          start++;
      }
      if(currsum==sum)
      {
        cout<<start+1<<" "<<i<<"\n";
        return ;
      }
      if(i<n)
        currsum+=val[i];    
   }
   cout<<-1<<"\n";
   return;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum;
        cin>>n>>sum;
        int val[n];
        for(int i=0;i<n;i++)
        {
            cin>>val[i];
        }
        subarraysum(val,n,sum);
    }
    
	return 0;
}

//Approach ,This done using concept Sliding Window 
  //Add the elements, to currsum till it is less than given Sum.
  //If it becomes more than Sum, start deleting elements from start in the currsum.
  //if the currsum again becomes less than Sum, again start adding elements to currsum
//Time Complexity---O(n)
//Space Complexity---O(1)
