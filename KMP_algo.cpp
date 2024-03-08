void find(vector<int>&lps,string str,int ind,int n)
{
  int len=0;
  lps[0]=0;
  while(ind<n)
  {
     // compare char of ind with char of len
    if(str[ind]==str[len])
    {
      len++;
      lps[ind]=len;
      ind++;
    }
    else if(len==0){
        lps[ind]=len;
        ind++;
    }
    else
    {
      len--;
    }
  }

}
