#include<iostream>
using namespace std;
void merge(int arr[10],int low,int mid,int high)
{ int i=low,j=mid+1,h=low;
  int temp[10];
  while(i<=mid && j<=high)
  { if(arr[i]<arr[j])
    { temp[h]=arr[i];
      i++;
    }
    else
    { temp[h]=arr[j];
      j++;
    }
    h++;
  }
  while(i<=mid)
  { temp[h]=arr[i];
    i++;h++;
  }
  while(j<=high)
  { temp[h]=arr[j];
    h++;j++;
  }
  i=low;
  while(i<=high)
  { arr[i]=temp[i];
    i++;
  }
}
void mergesort(int arr[10],int low,int high)
{ if(low<high)
  { int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
  }
}
int main()
{ int arr[10];
  cout<<"Enter array elements";
  for(int i=0;i<10;i++)
   cin>>arr[i];
  int low=0;
  int high=9;
  mergesort(arr,low,high);
  cout<<"Sorted array: ";
  for(int i=0;i<10;i++)
   cout<<arr[i]<<" ";
  return 0;
}
