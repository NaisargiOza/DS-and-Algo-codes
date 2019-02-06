#include<iostream>
using namespace std;
int stk[10],top=-1;
void reheapup(int arr[],int i)
{ if(i==0)
   return;
  int parent=(i-1)/2;
  if(arr[parent]<arr[i])
  { int t=arr[i];
    arr[i]=arr[parent];
    arr[parent]=t;
  }
  reheapup(arr,parent);
}
void reheapdown(int arr[],int i,int size)
{ int leftkey,rightkey;
  leftkey=(2*i)+1;
  rightkey=leftkey+1;
  int largest=i;
  if(arr[leftkey]>=arr[largest] && leftkey<=size)
   largest=leftkey;
  if(arr[rightkey]>arr[largest] && rightkey<=size)
   largest=rightkey;
  if(largest!=i)
  { int t=arr[largest];
    arr[largest]=arr[i];
    arr[i]=t;
    reheapdown(arr,largest,size);
  }
}
void insert(int arr[],int element,int size)
{ size++;
  arr[size]=element;
  reheapup(arr,size);
}
int Delete(int arr[],int size)
{ int del=arr[0];
  arr[0]=arr[size];
  size--;
  reheapdown(arr,0,size);
  for(int i=0;i<=size;i++) 
   cout<<arr[i]<<" ";
  cout<<endl;
  return del;
}
void push(int num)
{ ++top;
  stk[top]=num;
}
int pop()
{ int temp=stk[top];
  top--;
  return temp;
}
int empty()
{ if(top==-1)
   return 0;
  return 1;
}
void Heapsort(int arr[],int size)
{ while(size>=0)
  { int k=Delete(arr,size);
    push(k);
    size--;
  }
  cout<<"Sorted array: ";
  while(empty()!=0)
  { int k=pop();
    cout<<k<<" ";
  }
}
int main()
{ int arr[10];
  cout<<"Enter elements";
  for(int i=0;i<10;i++)
   cin>>arr[i];
  for(int i=9;i>=0;i--)
   reheapup(arr,i);
  cout<<"Array: ";
  for(int i=0;i<10;i++)
   cout<<arr[i]<<" ";
  cout<<endl;
  Heapsort(arr,9);
  /*cout<<"Array:";
  for(int i=0;i<=n;i++)
   cout<<arr[i]<<" ";*/
  return 0;
}
