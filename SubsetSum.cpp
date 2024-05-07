#include <bits/stdc++.h>

using namespace std;
bool solve(vector<int> &arr, int n, int sum, int index) {
    if (sum < 0 || index == n+1)
    {
        return false;
    }
    if (index == n && sum == 0)
    {
        return true;
    }

    if (solve(arr, n, sum - arr[index], index + 1)) {
        return true;
    }
    return solve(arr, n, sum, index + 1);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
   bool answer=solve(arr,n,k,0);
   return answer;
}
int main()
{
  
  int n=10;
  cout<<"Enter the Size of Array: ";
  cin>>n;
  vector <int> arr(n);
  cout<<"Enter the Input for Array."<<endl;
  for(int i=0; i<n; i++)
    {
      cout<<"Index-"<<i<<" : ";
      cin>>arr[i];
    }
  int k;
  cout<<"Enter the Sum Required: ";
  cin>>k;
  if(subsetSumToK(n,k,arr))
  {
    cout<<"YES, the given sum is possible from some combination of the elements of the given array.";
  }
  else
  {
    cout<<"NO, the given sum is not possible from some combination of the elements of the given array.";
  }
}
