#include<iostream>
using namespace std;
void sort(int a[])
{ for(int i=0;i<10;i++)
   { int pos,min=a[i];
     for(int j=i;j<10;j++)
      if(a[j]<min)
       { min=a[j];
         pos=j;
       }
     int temp=a[i];
     a[i]=min;
     a[pos]=temp;
    }
}
int main()
{ int a[10];
  cout<<"Enter numbers";
  for(int i=0;i<10;i++)
   cin>>a[i];
  sort(a);
  cout<<"\nSorted array:";
  for(int i=0;i<10;i++)
   cout<<a[i]<<" ";
  return 0;
}
