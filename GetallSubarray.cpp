vector<vector<int>> getSubarray(vector<int>arr)
{
  vector<vector<int>>all;
  int n=arr.size();
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      vector<int>temp;
      for(int k=i;k<=j;k++)
      {
        temp.push_back(arr[k]);
      }
      all.push_back(temp);
    }
  }
  return all;
}
