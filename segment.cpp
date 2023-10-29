#include <iostream>
#include <vector>
using namespace std;
// Segment Tree

class Segment
{
private:
	vector<int> seg;

public:
	Segment(int n)
	{
		seg.resize(4 * n);
	}
	void build(int ind, int low, int high, int arr[])
	{
		if (low == high)
		{
			seg[ind] = arr[low];
			return;
		}
		int mid = (low + high) / 2;
		//    cout<<ind*2+1<<" "<<low<<" " << mid<<endl;
		build(ind * 2 + 1, low, mid, arr);
		//    cout<<ind*2+2<<" "<<mid+1<<" "<<high<<endl;
		build(ind * 2 + 2, mid + 1, high, arr);
		seg[ind] = min(seg[ind * 2 + 1], seg[ind * 2 + 2]);
	}
    int query(int ind, int L, int R, int low, int high)
{

	// no overlap
	if (R < low || high < L)
		return INT_MAX;
	// complete overlap
	if (low >= L && high <= R)
		return seg[ind];
	// partial overlap.
	int mid = (low + high) / 2;
	int left = query(ind * 2 + 1, L, R, low, mid);
	int right = query(ind * 2 + 2, L, R, mid + 1, high);
	// look in left or right and then return min(left,right)
	return min(left, right);
}
    void update(int ind, int low, int high, int i, int val)
{
	if (low == high)
	{
		seg[ind] = val;
		return;
	}
	int mid = (low + high) >> 1;
	// check karo apni required index left hogi ya right me
	if (i <= mid)
	{
		update(ind * 2 + 1, low, mid, i, val);
	}
	else
	{
		update(ind * 2 + 2, mid + 1, high, i, val);
	}
}
    void show()
	{
		for(auto val:seg)
		cout<<val<<" ";
		cout<<endl;
	}
};


// eg -->
//    L .... low..... high..... R  --> valid case --> (overlap)
//    L ...... R ......  low .....  high       --> (no overlap)
//    low .....  high ....  L ..... R---> (no overlap)
//    low ..... L .....  high ....  high --> (partial)
//    L ..... low .....  R ..... high   ---> (partial)




int main()
{
	int n;
	cout<<"Enter array size : ";
	cin>>n;
	int arr[n]={2,1,0,4,3,7};
	Segment s(n);
	s.build(0,0,n-1,arr);
	cout<<s.query(0,0,1,0,n-1);
	cout<<endl;
	s.show();
	


	return 0;
}
