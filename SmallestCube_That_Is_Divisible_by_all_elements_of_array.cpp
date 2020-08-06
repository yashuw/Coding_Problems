/*------------------------------------------------------------Problem----------------------------------------------------------

Given an array arr[], the task is to find the smallest perfect cube which is divisible by all the elements of the given array.

-------------------------------------------------------------------------------------------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
void PrimeFactor(long long int n,map<long long int,long long int>&mp)
{
	long long int count2=0;
	while (n % 2 == 0)  
    {  
        cout << 2 << " ";
		count2++;  
        
        n = n/2;  
    } 
	mp[2]=max(mp[2],count2); 
  	for (long long int i = 3; n>1; i = i + 2)  
    {  
    	long long int countp=0;
        while (n % i == 0)  
        {  
        	countp++;
            cout << i << " ";  
            n = n/i;  
        } 
		mp[i]=max(countp,mp[i]); 
    }  
          
}
int main()
{
	long long int n;
	cin>>n;
	vector<long long int>v(n);
	map<long long int,long long int>mp;
	for(long long int i=0;i<n;i++)
	{
		cin>>v[i];
		PrimeFactor(v[i],mp);
		cout<<"\n";
	}
	
	map<long long int,long long int>::iterator it;
	long long int mul=1;
	for(it=mp.begin();it!=mp.end();it++)
	{
		long long int fval=(*it).first;
		long long int temp=(((*it).second)/3);
		if((*it).second%3==0)
		{
			mul*=pow(fval,temp);
		}
		else
		{
			mul*=pow(fval,temp+1);
		}
	}
	cout<<"\n\n";
	cout<<pow(mul,3)<<"\n";
	return 0;	
}

/*----------------------------------------------------Approach---------------------------------------------
---Find Prime Factors of all elements of array
---Pick the highest exponents of all prime factors
---if exponent is multiple of 3 then multiply final ans with  pow(primefactor,exponent/3)
---if exponent is not a multiple of 3 then multiply final ans with pow(primefactor,(exponent/3)+1)

-------------------------------------------------------------------------------------------------------------
