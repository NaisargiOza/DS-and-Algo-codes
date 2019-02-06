#include<iostream>
using namespace std;
int main()
{ int arr[10];
  cout<<"Enter array elements";
  for(int i=0;i<10;i++)
   cin>>arr[i];
  int n=10;
  for(int gap=n/2;gap>0;gap/=2)
  { for(int i=gap;i<n;i++)
     for(int j=i;j>=gap;j-=gap)
      if(arr[j]<arr[j-gap])
      { int temp=arr[j];
        arr[j]=arr[j-gap];
        arr[j-gap]=temp;
      }
    cout<<gap<<" sort: ";
    for(int m=0;m<n;m++)
     cout<<arr[m]<<" ";
    cout<<endl;
  }
  return 0;
}
