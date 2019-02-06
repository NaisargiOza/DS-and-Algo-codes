//to find shortest path
//by relaxing edges
#include<iostream>
using namespace std;
int vert[10],mark[10]={0},distto[10]={100};
struct edge
{ int weight; }edgeto[10][10]={0};
struct last
{ int a,b; }lastedge[10];
class stk
{ int top,arr[10];
  public:
  stk()
  { top=-1; }
  void push(int n)
  { ++top;
    arr[top]=n;
  }
  int pop()
  { if(top==-1)
     return -1;
    int temp=arr[top];
    top--;
    return temp;
  }
}st;
void dijkstra(int novert)
{ int s;
  cout<<"Enter source vertex";
  cin>>s;
  distto[s]=0;
  int k=s;
  while(k!=-1)
  { for(int i=0;i<novert;i++)
    { if(edgeto[k][i].weight!=0 && mark[i]==0)
      { if(distto[i]>distto[k]+edgeto[k][i].weight)
        { distto[i]=distto[k]+edgeto[k][i].weight;
          lastedge[i].a=k;
          lastedge[i].b=i;
        }
      }
      mark[k]=1;
    }
    int min=100;
    for(int i=0;i<novert;i++)
    { if(distto[i]<min)
       if(mark[i]==0)
       { min=distto[i];
         k=vert[i];
       }
      if(min==100)
       k=-1;
    }
  }
}      
void findshortestpath(int novert)
{ int c,s;
  cout<<"Enter source and final vertex";
  cin>>s>>c;
  int k=c;
  while(k!=s)
  { st.push(lastedge[k].b);
    k=lastedge[k].a;
  }
  cout<<lastedge[s].b<<" ";
  k=st.pop();
  while(k!=-1)
  { cout<<k<<" ";
    k=st.pop();
  }
}
int main()
{ int novert;
  cout<<"Enter number of vertices";
  cin>>novert;
  cout<<"Enter vertices";
  for(int i=0;i<novert;i++)
   cin>>vert[i];
  int noedges;
  cout<<"Enter number of edges";
  cin>>noedges;
  cout<<"Enter starting point,ending point and weight of each edge";
  for(int i=0;i<noedges;i++)
  { int a,b,c;
    cin>>a>>b>>c;
    edgeto[a][b].weight=c;
  }
  for(int i=0;i<novert;i++)
  { distto[i]=100;
    mark[i]=0;
    lastedge[i].a=lastedge[i].b=0;
  }
  dijkstra(novert);
  cout<<endl;  
  for(int i=0;i<novert;i++)
   cout<<distto[i]<<" ";
  cout<<endl;
  findshortestpath(novert);
  return 0;
}

