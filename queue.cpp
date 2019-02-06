#include<iostream>
using namespace std;
class q
{ int front,back,n;
  int queue[10]; 
  public:
  q()
  { front=-1;
    back==-1;
    n=10;
  }
  void enqueue(int num)
  { if(back==n-1)
     { cout<<"Queue full";
       return;
     }
    if(front==-1)
     front=back=0;
    else
     back++;
    queue[back]=num;
  }
  void dequeue()
  { if(front==-1)
     { cout<<"Queue empty";
       return;
     }
    cout<<queue[front];
    if(front==back)
     front=back=-1;
    else
     front++;
  }
};
int main()
{ int ch;
  q s;
  cout<<"MENU\n1.Push\n2.Pop\n3.Exit";
  cout<<"Enter choice";
  cin>>ch;
  do
  { if(ch==1)
    { int num;
      cout<<"Enter number";
      cin>>num;
      s.enqueue(num);
    }
    else if(ch==2)
     s.dequeue();
    cout<<"Enter choice";
    cin>>ch;
  }while(ch!=3);
  return 0;
}
 
    
