//lecture:-15-4
#include<iostream>
using namespace std;
int vert[7],edges[7][7]={0},visited[7]={0};
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
void dfs(int novert,int source)
{ s.push(source);
  visited[source]=1;
  int v=s.pop();
  stk out;
  while(v!=-1)
  { cout<<v;
    int i=0;
    for(;i<novert;i++)
    { if(visited[i]==0 && edges[v][i]!=0)
      { s.push(vert[i]);
        visited[i]=1;
      }
      out.push(vert[i]);
    }
    v=s.pop();
  }
  /*while(v!=-1)
  { v=out.pop();
    cout<<v<<" ";
  }*/
  for(int i=0;i<novert;i++)
  { if(visited[i]==0)
     dfs(novert,vert[i]);
  }
  cout<<endl;
  /*while(v!=-1)
  { v=out.pop();
    cout<<v<<" ";
  }*/
  return;
}
int main()
{ int no_edges;
  cout<<"Enter 7 vertices";
  for(int i=0;i<7;i++)
   cin>>vert[i];
  cout<<"Enter number of edges";
  cin>>no_edges;
  for(int i=1;i<=no_edges;i++)
  { int s,e;
    cout<<"Enter starting and ending vertices of the edges";
    cin>>s>>e;
    edges[s][e]=1;
  }
  int source;
  cout<<"Enter source vertex";
  cin>>source;
  dfs(7,source);
  return 0;
}
