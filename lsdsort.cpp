//sorting based on least significant digit
#include<iostream>
using namespace std;
int GetMax(int arr[])
{ int m=0;
  for(int i=0;i<10;i++)
   if(arr[i]>m)
    m=arr[i];
  return m;
}
void keyindex(int arr[],int j)
{ int count[11],aux[10];
  for(int i=0;i<11;i++)
   count[i]=0;
  for(int i=0;i<10;i++)
   count[((arr[i]/j)%10)+1]++;
  for(int i=1;i<11;i++)
   count[i]+=count[i-1];
  for(int i=0;i<10;i++)
  { aux[count[(arr[i]/j)%10]]=arr[i];
    count[(arr[i]/j)%10]++;
  }
  for(int i=0;i<10;i++)
   arr[i]=aux[i];
}
int main()
{ int arr[10];
  cout<<"Enter 10 numbers";
  for(int i=0;i<10;i++)
   cin>>arr[i];
  int m=GetMax(arr);
  for(int j=1;m/j>0;j*=10)
  { keyindex(arr,j);
  }
  cout<<"Sorted aray: ";
  for(int i=0;i<10;i++)
   cout<<arr[i]<<" ";
  return 0;
}
