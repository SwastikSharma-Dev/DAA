#include<bits/stdc++.h>
using namespace std;
void knapsack(int wt[],int pr[],int n,int maxw){
  int sol[n+1][maxw+1];
  for(int i = 0; i < maxw+1; i++)
  {
    sol[0][i]=0;
  }
  for(int i = 0; i < n+1; i++)
  {
    sol[i][0]=0;
  }
  for (int i = 1; i < n+1; i++)
  {
    for (int w = 1; w < maxw+1; w++)
    {
      if(w>=wt[i-1]){
        sol[i][w]=max(pr[i-1]+sol[i-1][w-wt[i-1]],sol[i-1][w]);
      }
      else{
        sol[i][w]=sol[i-1][w];
      }
    }
  }
cout<<"Max Profit is"<<sol[n][maxw];
}
int main(){
  int n;
  cout<<"no of items:"<<endl;
  cin>>n;
  int w[n],p[n];
  for (int i = 0; i < n; i++)
  {
    cout<<"enter weight:"<<endl;
    cin>>w[i];
    cout<<"enter profit:"<<endl;
    cin>>p[i];
  }
  cout<<"enter max weight"<<endl;
  int maxwt;
  cin>>maxwt;
  knapsack(w,p,n,maxwt);
  return 0;
}
