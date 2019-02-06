#include<iostream>
using namespace std;
class stk
{ int top,n;
  int stack[1];
  public:
  stk()
  { //stack=new int[1];
    top=-1;
    n=10;
  }
  void resize(int sz)
  { int copy[sz];
    for(int i=0;i<n;i++)
     copy[i]=stack[i];
    stack=copy;
  }
  void push(int num)
  { if(top==n-1)
     resize(2*n);
    stack[++top]=num;
  }
  void pop()
  { if(top==-1)
     { cout<<"Stack empty";
       return;
     }
    cout<<stack[top];
    top--;
    if(top==n/4)
     resize(n/2);
  }
};
int main()
{ stk s;
  int ch;
  cout<<"MENU\n1.Push\n2.Pop\n3.Exit";
  cout<<"Enter choice";
  cin>>ch;
  do
  { if(ch==1)
     { int num;
       cout<<"Enter number";
       cin>>num;
       s.push(num);
     }
    else if(ch==2)
     s.pop();
    cout<<"Enter choice";
    cin>>ch;
  }while(ch!=3);
  return 0;
}
     
