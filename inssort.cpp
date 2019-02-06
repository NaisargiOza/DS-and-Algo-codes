#include<iostream>
using namespace std;
void inssort(int a[])
{ for(int i=1;i<10;i++)
  { int temp=a[i],j=i-1;
    while(j>=0 && a[j]>temp)
    { a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;
  }
}
int main()
{ int a[10];
  cout<<"Enter array elements";
  for(int i=0;i<10;i++)
   cin>>a[i]; 
  inssort(a);
  cout<<"Sorted array";
  cout<<endl;
  for(int i=0;i<10;i++)
   cout<<a[i]<<" ";
  return 0;
}
