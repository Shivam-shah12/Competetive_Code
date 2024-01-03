#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// MAX Heap

void heapify(vector<int>&arr,int ind)
{
    int size=arr.size();
    int largest=ind;
    int left=2*ind+1;
    int right=2*ind+2;
    if(left<size && arr[largest]<arr[left])
    largest=left;
    if(right<size && arr[largest]<arr[right])
    largest=right;

    if(largest!=ind)
    {
        swap(arr[largest],arr[ind]);
        heapify(arr,largest);
    }
}
void insert(vector<int>&arr,int num)
{
    int size=arr.size();
    if(size==0)
    {
        arr.push_back(num);
    }
    else{
        arr.push_back(num);
        for(int i=size/2-1;i>=0;i--)
        {
            heapify(arr,i);
        }
    }
}

void deleteNode(vector<int> &arr, int num)
{
  int size = arr.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == arr[i])
      break;
  }
  swap(&arr[i], &arr[size - 1]);

  arr.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(arr, i);
  }
}
void printArray(vector<int> &arr)
{
  for (int i = 0; i < arr.size(); ++i)
    cout << arr[i] << " ";
  cout << "\n";
}

// ****************************  MIN Heap ********************************
void min_heap(int *a, int m, int n){
   int j, t;
   t= a[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && a[j+1] < a[j])
         j = j + 1;
      if (t < a[j])
         break;
      else if (t >= a[j]) {
         a[j/2] = a[j];
         j = 2 * j;
      }
   }
   a[j/2] = t;
   return;
}
void build_minheap(int *a, int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      min_heap(a,k,n);
   }
}
