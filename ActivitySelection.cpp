#include<bits/stdc++.h>
using namespace std;
vector<int> activitySelection(vector<int> s,vector<int> f){
int n=s.size();
int j=0;
vector<int> arr;
arr.push_back(0);
for (int i = 1; i<n; i++)
{
if(f[j]<=s[i]){
arr.push_back(i);
j=i;
}
}
return arr;
}
int main(){
vector<int> start={10,12,20};
vector<int> finish={20,25,30};
vector<int> arr=activitySelection(start,finish);
for (int i = 0; i < arr.size(); i++)
{
cout<<arr[i]<<' ';
}cout<<endl;
return 0;
}
