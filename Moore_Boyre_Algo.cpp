#include <bits/stdc++.h>
using namespace std;

int Majority(vector<int>&nums,int size)
{
  int count=1;
  int curr_major_ind=0;
  int ind=1;
  while(ind<size)
  {
    if(nums[curr_major_ind]==nums[ind])
    {
      count++;
      ind++;
    }
    else
    {
      // agar curr->index wala element , Majority element 
      // nahi toh iska mtlb vo ek space kha raha jha par majority element
       // hona chahiye
      count--;
    }
    if(count==0)
    {
      // yadi mera count 0 hai 
      // iska mtlb me jisko majority mnn raha tha uske 
      // jitne alg alg candidate bhi toh iska mtlb vo
      // majority nhi ho skta
      // --> then choose new Majority element
      count=1;
      curr_major_ind=ind;
      ind++;
    }
  }
  int cnt=0;
  for(int i=0;i<size;i++)
  {
    if(nums[i]==nums[curr_major_ind])
      cnt++;
  }
  return cnt;
}

int main()
{
  init_code();
  int n;
  cout<<"Enter the length of Array ::  ";
  cin>>n;
  cout<<n<<endl;
  vector<int>nums(n);
  for(int i=0;i<n;i++)
  {
    cin>>nums[i];
  }
  cout<<Majority(nums,n);
  
 
  return 0;
}











