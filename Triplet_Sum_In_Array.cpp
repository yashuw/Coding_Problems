#include<bits/stdc++.h>
using namespace std;
void findTriplets(int arr[], int n)
{
    bool found=false;
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++)
    {
        int l=i+1;
        int r=n-1;
        int x=arr[i];
        while(l<r)
        {
            if(x+arr[l]+arr[r]==0)
            {
                cout<<"Triplet are :\n";
                cout<<x<<"  "<<arr[l]<<"  "<<arr[r]<<"\n";
                found=true;
                l++;
                r--;
            }
            else if(x+arr[l]+arr[r]<0)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    if(found==false)
    {
      cout<<"No Triplet Found \n";
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
    int a[n]={0};
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    findTriplets(a,n);
  }
}

/*
------------------------------------Approach------------------------------------------------
--Done using Two pointers
--Sort the array 
--run loop from i to n-2
  --Intialize two variables
      left_ponter=i+1
      right_pointer=n-1
 --Run a loop while left_pointer<right_pointer
    ---if arr val of i + arr val of left_pointer + arr val of right_pointer  equals zero
        ---print values
    --- if sum less than Zero
        ---move left_pointer
    ---if sum greater than zer0
        ---dec right_pointer
----------------------------------------------------------------------------------------------
*/
