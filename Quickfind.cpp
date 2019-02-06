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
    int pid=arr[p];
    int qid=arr[q];
    for(int k=0;k<10;k++)
     if(arr[k]==pid)
      arr[k]=qid;
  }
  void Find()
  { int p,q;
    cout<<"Enter numbers whose connectivity should be checked";
    cin>>p>>q;
    if(arr[p]==arr[q])
     cout<<"Connected";
    else
     cout<<"Not connected";
  }
};
int main()
{ UF uf;
  cout<<"MENU\n1.Union\n2.Find\n3.Exit";
  int ch;
  cout<<"Enter choice";
  cin>>ch;
  do
  { if(ch==1)
     uf.Union();
    else if(ch==2)
     uf.Find();
    cout<<"Enter choice ";
    cin>>ch;
  } while(ch!=3);
  return 0;
}
