#include<iostream>
using namespace std;
class UF
{ int arr[10],sz[10];
  public:
  UF()
  { for(int i=0;i<10;i++)
     arr[i]=i;
    sz={'1'};
  }
  void Union()
  { int p,q;
    cout<<"Enter 2 numbers to be connected";
    cin>>p>>q;
    int i=arr[p];
    while(i!=arr[i])
     { i=arr[i]; }
    int j=arr[q];
    while(j!=arr[j])
     { j=arr[j]; }
    if(sz[i]<sz[j])
     { arr[i]=j;
       sz[j]+=sz[i];
     }
    else
     { arr[j]=i;
       sz[i]+=sz[j];
     }
  }
  void Connected()
  { int p,q;
    cout<<"Enter 2 numbers whose connectivity has to be checked";
    cin>>p>>q;
    int i=arr[p];
    while(i!=arr[i])
     { i=arr[i]; }
    int j=arr[q];
    while(j!=arr[j])
     { j=arr[j]; }
    if(i==j)
     cout<<"Yes\n";
    else
     cout<<"No\n";
  }
};
int main()
{ UF uf;
  cout<<"MENU\n1.Union\n2.Connected\n3.Exit";
  int ch;
  cout<<"Enter choice";
  cin>>ch;
  do
  { if(ch==1)
     uf.Union();
    else if(ch==2)
     uf.Connected();
  } while(ch!=3);
  return 0;
}
