#include<iostream>
using namespace std;
int vert[5];
struct ed
{ int sv,ev,cost; };
int parent[5];
int find(int v)
{ if(parent[v]==v)
   return v;
  return find(parent[v]);
}
void kruskals(int novert,ed *edges,int noedge)
{ for(int i=1;i<6;i++)
  { for(int j=1;j<6-i-1;j++)
    { if(edges[j].cost>edges[j+1].cost)
      { ed temp=edges[j];
        edges[j]=edges[j+1];
        edges[j+1]=temp;
      }
    }
  }
  int count=0;
  int i=0;
  while(count<novert-1 && i<noedge)
  { int s=edges[i].sv;
    int e=edges[i].ev;
    if(find(s)!=find(e))
    { cout<<"\n"<<s<<" "<<e;
      count++;
      parent[s]=e;
    }
    i++;
  }
}
int main()
{ cout<<"Enter5 vertices";
  for(int i=0;i<5;i++)
   cin>>vert[i];
  int noedges;
  cout<<"Enter number of edges";
  cin>>noedges;
  ed edges[noedges];
  for(int i=0;i<5;i++)
   parent[i]=i;
  for(int i=0;i<noedges;i++)
  { int s,e,w;
    cin>>s>>e>>w;
    edges[i].cost=w;
    edges[i].sv=s;
    edges[i].ev=e;
  }
  kruskals(5,edges,noedges); 
  return 0;
}
