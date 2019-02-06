#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{ int a[10];
  cout<<"Enter array elements";
  for(int i=0;i<10;i++)
   cin>>a[10];
  randomize();
  for(int i=0;i<10;i++)
  { int r=random(10);
    int temp=a[i];
    a[i]=a[r];
    a[r]=temp;
  }
  cout<<"Shuffled array";
  cout<<endl;
  for(int i=0;i<10;i++)
   cout<<a[i]<<" ";
  for(int i=1;i<10;i++)
  { int temp=a[i],j=i-1;
    while(j>=0 && a[j]<temp)
     { a[j+1]=a[j];
       j--;
     }
    a[j+1]=temp;
  }
  cout<<"Sorted array: ";
  for(int i=0;i<10;i++)
   cout<<a[i]<<" ";
  return 0;
}
  
