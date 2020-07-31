/*-------------------------------------------------Problem-------------------------------------------------------------------------

Print the elements of an array in the decreasing frequency if 2 numbers have same frequency then print the one which came first.

-------------------------------------------------------------------------------------------------------------------------------------*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool pcompare(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.second!=p2.second)
        return p1.second>p2.second;
    return false;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    map<int,pair<int,int> >mp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(mp.find(arr[i])!=mp.end())
        {
            mp[arr[i]].second++;
        }
        else
        {
            mp[arr[i]]=make_pair(arr[i],1);
        }
    }
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]].second!=-1)
        {
            v.push_back(mp[arr[i]]);
            mp[arr[i]].second=-1;
        }
    }
    sort(v.begin(),v.end(),pcompare);
    for(int i=0;i<v.size();i++)
    {
        int c=v[i].second;
        while(c--)
        {
            cout<<v[i].first<<" ";
        }
    }
	return 0;
}
/*------------------------------------------------------------Approach-------------------------------------------------------------------------

----Insert all elements and their counts into a map. This step takes O(n) time where n is number of elements.
----Copy contents of map to an vector and sort them by counts. This step takes O(m Log m) time where m is total number of distinct elements.
----Print elements in the vector

---------------------------------------------------------------------------------------------------------------------------------------------------*/
