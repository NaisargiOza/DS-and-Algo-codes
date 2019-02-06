#include<iostream>
using namespace std;
int main()
{ int arr[10];
  for(int l=0;l<10;l++)
   cin>>arr[l];
  int i=0,j=9;
  while(i<=j)
  { while(arr[i]<=0)
     i++;
    while(arr[j]>0)
     j++;
    if(arr[i]>arr[0] && arr[j]<=arr[0])
    { int temp=arr[i];
      arr[i]=arr[j];
      arr[j]=temp;
    }
  }
  int temp=arr[0];
  arr[0]=arr[i];
  arr[i]=temp;
  for(int l=0;l<i;l++)
   {for(int k=0;k<i-l-1;k++)
    {if(arr[l]>arr[l+1])
    { int t=arr[l];
      arr[l]=arr[l+1];
      arr[l+1]=t;
    }}}
  for(int l=i;l<10;l++)
   {for(int k=0;k<i-l-1;k++)
    {if(arr[l]>arr[l+1])
    { int t=arr[l];
      arr[l]=arr[l+1];
      arr[l+1]=t;
    }}}
  cout<<"Sorted array: ";
  for(int l=0;l<10;l++)
   cout<<arr[l]<<" ";
  return 0;
}
