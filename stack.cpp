#include<iostream>
using namespace std;
class stk
{ int top,stack[10],n;
  public:
  stk()
  { top=-1; 
    n=10; 
  }
  void push(int num)
  { if(top==n-1)
     { cout<<"Stack full";
       return;
     }
    stack[++top]=num;
  }
  void pop()
  { if(top==-1)
     { cout<<"Stack empty";
       return;
     }
    cout<<stack[top]<<endl;
    top--;
  }
};
int main()
{ int ch;
  stk s;
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
 
