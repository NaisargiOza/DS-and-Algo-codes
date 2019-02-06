#include<iostream>
using namespace std;
int vert[5];
int edges[6][6]={0};
int visited[6]={0};
class Queue
{ int front,rear,arr[5];
  public:
  Queue()
  { front=rear=-1; }
  void enqueue(int s)
  { if(rear==-1)
     front=rear=0;
    else
     rear++;
    arr[rear]=s;
  }
  int dequeue()
  { if(front==-1)
     return 0;
    int temp=arr[front];
    if(front==rear)
     front=rear=-1;
    else
     front++;
    return temp;
  }
}q;
void bfs()
{ int s;
  cout<<"Enter source vertex";
  cin>>s;
  q.enqueue(s);
  visited[s]=1;
  int v=q.dequeue();
  while(v!=0)
  { 
    cout<<v<<" ";
    for(int i=1;i<=5;i++)
    { if(edges[v][i]==1 && visited[i]==0)
       { q.enqueue(i);
         visited[i]=1;
       }
    }
    v=q.dequeue();
  }
}
int main()
{ int no_edges;
  cout<<"Enter 5 vertices";
  for(int i=0;i<5;i++)
   cin>>vert[i];
  cout<<"Enter number of edges";
  cin>>no_edges;
  for(int i=1;i<=no_edges;i++)
  { int s,e;
    cout<<"Enter starting and ending vertices of the edges";
    cin>>s>>e;
    edges[s][e]=edges[e][s]=1;
  }
  bfs();
}
