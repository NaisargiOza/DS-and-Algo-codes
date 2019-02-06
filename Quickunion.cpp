#include<iostream>
using namespace std;
class UF
{ int arr[10];
  public:
  UF()
  { for(int i=0;i<10;i++)
     arr[i]=i;
  }
  void Union()
  { int p,q;
    cout<<"Enter numbers to be connected";
    cin>>p>>q;
    int i=arr[p];
    while(arr[i]!=i)
    { i=arr[i]; }
    int j=arr[q];
    while(arr[j]!=j)
    { j=arr[j]; }
    arr[i]=j;
  }
  void Connected()
  { cout<<"Enter 2 numbers";
    int p,q;
    cin>>p>>q;
    int i=arr[p];
    while(arr[i]!=i)
    { i=arr[i]; }
    int j=arr[q];
    while(arr[j]!=j)
    { j=arr[j]; }
    if(i==j)
     cout<<"Yes\n";
    else
     cout<<"No\n";
  }
};
int main()
{ UF uf;
  int ch;
  cout<<"MENU\n1.Union\n2.Connected\n3.Exit";
  cout<<"Enter choice";
  cin>>ch;
  do
  { if(ch==1)
     uf.Union();
    else if(ch==2)
     uf.Connected();
    cout<<"Enter choice";
    cin>>ch;
  }while(ch!=3);
  return 0;
}
