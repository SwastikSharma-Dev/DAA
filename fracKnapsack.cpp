#include<iostream>
#include<vector>
using namespace std;
void display(double arr[]){
for (int i = 0; i < 3; i++)
{
cout<<arr[i]<<' ';
}cout<<endl;
}
void bubbleSort(double arr[],int arr2[][2],int n){
bool swapped=false;
for (int i = 0; i < n-1; i++)
{
for (int j = 0; j < n-i-1; j++)
{
if(arr[j]<arr[j+1]){
swap(arr[j],arr[j+1]);
swap(arr2[j],arr2[j+1]);
swapped=true;
}
}
if(!swapped)break;
}
}
double fractionalKnapsack(int arr[][2],int n,double ratio[],int maxWeight){
double profit=0;
int i=0;
while(maxWeight && i<n)
{
if(arr[i][1]>maxWeight){
profit=profit+(maxWeight*ratio[i]);
break;
}
profit=profit+arr[i][0];
maxWeight=maxWeight-arr[i][1];
i++;
}
return profit;
}
int main(){
int arr[][2]={{100,20},{80,10},{210,30}};
int maxWeight=50;
int n=sizeof(arr)/(2*sizeof(int));
double ratio[n];
for(int i=0;i<3;i++){
ratio[i]=(double)arr[i][0]/arr[i][1];
}
display(ratio);
bubbleSort(ratio,arr,n);
display(ratio);
cout<<"max profit will be "<<fractionalKnapsack(arr,n,ratio,maxWeight)<<endl;
return 0;
}
