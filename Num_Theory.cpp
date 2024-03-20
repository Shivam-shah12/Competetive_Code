#include <bits/stdc++.h>
using namespace std;


void init_code()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif 
    }
/*
    According to the theorem , if num &  p are co-prime , then { modInverse(b) = power(b,p-2)  }
*/

long long modInverse(long long num,int p)
{
     return power(num,p-2,p);
}

// Best ways to used mod --> function of mod
int m=1e9;
int mod(int x)
{
return ((x % m)+m)%m;
}

long long power(long long a,long long b,long long mod)
{
	long long res=1;
	while(b)
	{
		if(b&1)
		{
			res=(res*a)%mod;
			b--;
		}
		else
		{
			a=(a*a)%mod;
			b/=2;
		}
	}
	return res;
}

long long nCr(int n,int r)
{
  if(n<r)
     return 0;
  if(r==0)
      return 1;
  vector<int>fac(n+1,0);
  fac[0]=1;
  for(int i=1;i<=n;i++)
  {
    fac[i]=fac[i-1]*i;
  }

  return fac[n] * modInverse(fac[r],mod)%mod * modInverse(fac[n-r],mod)%mod;
}


// Time Complexity O(sqrt(n))
bool is_prime(int n)
{
	if(n==1)return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

// Seive Eratosthenes
void get_all_prime(int n)
{
	int arr[n+1]={0};
   for(int i=1;i<=n;i++)
   	arr[i]=1;

   arr[0]=arr[1]=0;

   for(int i=2;i*i<=n;i++)
   {
   	if(arr[i]==1)
   	{
   		for(int j=i*i;j<=n;j+=i)
          arr[j]=0;
   	}
   }
    return;
}

// Prime factorization
void prime_factor(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			int cnt=0;
			while(n%i==0){
                 cnt++;
                 n/=i;
			}
			cout<<i<<"^"<<cnt<<" ";
		}
	}
	if(n>1)
		cout<<n<<"^ "<<1<<" ";
}

// seive Prime Factorization (best ways)
void sieve_prime_factor(int n)
{
	int maxn=n+1;
	int arr[maxn];
	// we put all values is -1, means all are prime
	fill(arr,arr+maxn,-1);
	
	for(int i=2;i<maxn;i++)
	{
        if(arr[i]==-1)
        {
        // sare multiple ko composite mark kar do,mtlb prime ke sare multiple
        // prime se toh divide ho hi jayenge
        	for(int j=i;j<maxn;j+=i)
        		{
        			arr[j]=i;
        		}
        }
	}
    while(n!=1 && n<maxn)
    {
    	cout<<arr[n];
    	n=n/arr[n];
    	if(n>1)
    		cout<<" * ";
    }
    return;

}

