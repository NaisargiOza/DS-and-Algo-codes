#include<iostream>
using namespace std;
int vert[5];
int selected[6]={0};
int edges[6][6]={0};
void prims(int no_vert)
{ int tedges=0;
  int source;
  cout<<"Enter source vertex";
  cin>>source;
  selected[source]=1;
  int min,x,y;
  while(tedges<no_vert-1)
  { min=9999;
    for(int i=1;i<=no_vert;i++)
    { if(selected[i]!=0)
      for(int j=1;j<=no_vert;j++)
      { if(selected[j]==0 && edges[i][j]!=0)
         if(edges[i][j]<min)
         { x=i;
           y=j;
           min=edges[i][j];
         }
      }
    }
    selected[y]=1;
    cout<<"\n"<<x<<" "<<y;
    tedges++;
  }
}
int main()
{ cout<<"Enter 5 vertices";
  for(int i=0;i<5;i++)  
   cin>>vert[i];
  int noedges;
  cout<<"Enter number of edges";
  cin>>noedges;
  for(int i=1;i<=noedges;i++)
  { int s,v;
    cout<<"Enter starting and end point of each edge and its cost";
    cin>>s>>v;
    cin>>edges[s][v];
    edges[v][s]=edges[s][v];
  }
  prims(5);
  return 0;
}
