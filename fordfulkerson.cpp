#include<iostream>
using namespace std;
int vert[10],visited[10]={0},parent[10];
struct edge
{ int flow,capacity,residue; }edgeto[10][10];
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
     return -1;
    int temp=arr[front];
    if(front==rear)
     front=rear=-1;
    else
     front++;
    return temp;
  }
}q;
int bfs(int novert,int s,int t,int parent[])
{ q.enqueue(s);
  visited[s]=1;
  int v=q.dequeue();
  parent[s]=-1;
  while(v!=-1)
  { 
    for(int i=0;i<novert;i++)
    { if(edgeto[v][i].capacity!=0 && visited[i]==0)
       { q.enqueue(vert[i]);
         parent[i]=v;
         visited[i]=1;
       }
    }
    v=q.dequeue();
  }
  cout<<"a";
  return visited[t];
}
int fordfulkerson(int novert,int s,int t,int parent[])
{ for(int i=0;i<novert;i++)
   for(int j=0;j<novert;j++)
    edgeto[i][j].residue=edgeto[i][j].capacity;
  int maxflow=0;
  while(bfs(novert,s,t,parent))
  { int path=100;
    for(int v=t;v!=s;v=parent[v])
    { int u=parent[v];
      if(path>edgeto[u][v].residue)
       path=edgeto[u][v].residue;
    }cout<<"b";
    for(int v=t;v!=s;v=parent[v])
    { int u=parent[v];
      edgeto[u][v].residue-=path;
      edgeto[u][v].residue+=path;
    }
    maxflow+=path;
  }
  return maxflow;
}
int main()
{ int novert;
  cout<<"Enter number of vertices";
  cin>>novert;
  cout<<"Enter vertices";
  for(int i=0;i<novert;i++)
   cin>>vert[i];
  for(int i=0;i<novert;i++)
  { visited[i]=parent[i]=0;
    for(int j=0;j<novert;j++)
    { edgeto[i][j].capacity=edgeto[i][j].flow=0; }
  }
  int noedges;
  cout<<"Enter number of edges";
  cin>>noedges;
  cout<<"Enter start,end point and capacity of each edge";
  for(int i=0;i<noedges;i++)
  { int a,b,c;
    cin>>a>>b>>c;
    edgeto[a][b].capacity=c;
  }
  int s,t;
  cout<<"Enter sourc and target vertex";
  cin>>s>>t;
  int ans;
  ans=fordfulkerson(novert,s,t,parent);
  cout<<"max flow is: "<<ans;
  return 0;
}
  
   
