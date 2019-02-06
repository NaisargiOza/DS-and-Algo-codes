#include<iostream>
using namespace std;
int vert[5],edges[5][5]={0},visited[5]={0};
class stk
{ int top,arr[5];
  public:
  stk()
  { top=-1; }
  void push(int no)
  { top++;
    arr[top]=no;
  }
  int pop()
  { if(top==-1)
     return -1;
    int temp=arr[top];
    top--;
    return temp;
  }
}s;
void dfs(int k)
{ s.push(k);
  visited[k]=1;
  int v;
  v=s.pop();
  while(v!=-1)
  { 
    cout<<v<<" ";
    for(int i=0;i<5;i++)
    { if(edges[v][i]==1 && visited[i]==0)
       { s.push(vert[i]);
         visited[i]=1;
       }
    }
    v=s.pop();
  }
  for(int i=0;i<5;i++)
  { if(visited[i]==0)
     dfs(vert[i]);
  }  
  return;
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
  int v;
  cout<<"Enter source vertex";
  cin>>v;
  dfs(v);
  return 0;
}
