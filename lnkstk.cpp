#include<iostream>
using namespace std;
struct lnk
{ int no;
  lnk *next;
};
class stack
{ lnk *top;
  public:
  stack()
  { top=NULL; }  
  void push(int num)
  { lnk*ptr=new lnk;
    if(ptr==NULL)
    { cout<<"Memory full";
      return;
    }
    ptr->no=num;
    if(top==NULL)
     ptr->next=NULL;
    else
     ptr->next=top;
    top=ptr;
  }
  void pop()
  { if(top==NULL)
     { cout<<"Stack empty";
       return;
     }
    cout<<top->no<<endl;
    lnk *temp=top;
    top=top->next;
    delete temp;
  }
};
int main()
{ stack s;
  cout<<"MENU\n1.Push\n2.Pop\n3.Exit";
  int ch;
  cout<<"Enter choice";
  cin>>ch;
  do
  { if(ch==1)
    { int n;
      cout<<"Enter a number";
      cin>>n;
      s.push(n);
    }
    else if(ch==2)
     s.pop();
    cout<<"Enter choice";
    cin>>ch;
  }while(ch!=3);
  return 0;
}
