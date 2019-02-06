//sorted based on the indices of the elements
#include<iostream>
using namespace std;
void keyindex(int *arr)
{ int count[7],aux[10];
  for(int i=0;i<7;i++)
   count[i]=0;
  for(int i=0;i<10;i++)
   count[arr[i]+1]++;
  for(int i=1;i<7;i++)
   count[i]+=count[i-1];
  for(int i=0;i<10;i++)
   aux[count[arr[i]]++]=arr[i];
  for(int i=0;i<10;i++)
   arr[i]=aux[i];
}
int main()
{ int arr[10];
  cout<<"Enter 10 elements from 0 to 5";
  for(int i=0;i<10;i++)
   cin>>arr[i];
  keyindex(arr);
  cout<<"Sorted array: ";
  for(int i=0;i<10;i++)
   cout<<arr[i]<<" ";
  return 0;
}
