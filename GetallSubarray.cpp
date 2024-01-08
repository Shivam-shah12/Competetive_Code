vector<vector<int>> getSubarray(vector<int>arr)
{
  vector<vector<int>>all;
  int n=arr.size();
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<=i;j++)
    {
      vector<int>temp;
      for(int k=j;k<=i;k++)
      {
        temp.push_back(arr[k]);
      }
      all.push_back(temp);
    }
  }
  return all;
}
