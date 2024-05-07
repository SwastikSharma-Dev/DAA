#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int> &arr,vector<int> &dl){
int n=arr.size();
bool swapped=false;
for (int i = 0; i < n-1; i++)
{
for (int j = 0; j < n-i-1; j++)
{
if(arr[j]<arr[j+1]){
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
int temp1=dl[j];
dl[j]=dl[j+1];
dl[j+1]=temp1;
swapped=true;
}
}
if(!swapped)break;
}
}
vector<int> jobSequencing(vector<int> d,vector<int> p){
int maxDl=INT_MIN;
for (int i = 0; i<d.size(); i++)
{
if(d[i]>maxDl)maxDl=d[i];
}
vector<int> arr(maxDl);
arr.assign(maxDl,0);
for (int i = 0; i<p.size(); i++)
{
auto ptr=arr.begin()+d[i]-1;
while(ptr!=arr.begin()-1){
if(!(*ptr)){
(*ptr)=i+1;
break;
}
ptr--;
}
}
return arr;
}
int main(){
vector<int> deadline={1,2,1,2,3};
vector<int> profit={19,27,25,100,15};
bubbleSort(profit,deadline);
vector<int> arr=jobSequencing(deadline,profit);
for (int i = 0; i < arr.size(); i++)
{
cout<<arr[i]<<' ';
}cout<<endl;
return 0;
}
