//to find shortest path
//to find negative cycles
//Bellman-Ford algorithm
#include<iostream>
using namespace std;
int vert[10];
struct edge
{ int weight; }edgeto[10][10];
int distto[10],e[10]; 
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
void findshortestpath(int novert)
{ for(int i=0;i<novert;i++)
  { cout<<e[i]<<" "<<i<<endl; }
  int c,s;
  cout<<"Enter source and final vertex";
  cin>>s>>c;
  int k=c;
  while(k!=s)
  { st.push(k);
    k=e[k];
  }
  cout<<s<<" ";
  k=st.pop();
  while(k!=-1)
  { cout<<k<<" ";
    k=st.pop();
  }
}
void negcycle(int novert)
{ distto[0]=0;
  for(int j=1;j<novert;j++)
  { for(int k=0;k<novert;k++)
    { for(int i=0;i<novert;i++)
      { if(edgeto[k][i].weight!=0)
        { if(distto[i]>distto[k]+edgeto[k][i].weight)
          { cout<<k;
            distto[i]=distto[k]+edgeto[k][i].weight;
            e[i]=k;
          }
        }
      }
    }
  }
  int flag=0;
  for(int l=0;l<novert;l++)
   for(int t=0;t<novert;t++)
   { if(edgeto[l][t].weight!=0)
      if(distto[t]>distto[l]+edgeto[l][t].weight)
       flag=1;
   }
  if(flag==0)
   findshortestpath(novert);
  else
   cout<<"Negative cycle found";
}    
int main()
{ cout<<"Enter numkber of vertices";
  int novert,noedge;
  cin>>novert;
  cout<<"Enter vertices";
  for(int i=0;i<novert;i++)
   cin>>vert[i];
  cout<<"Enter number of edges";
  cin>>noedge;
  for(int i=0;i<noedge;i++)
  { distto[i]=100;
    //e[i]=0;
    for(int j=0;j<noedge;j++)
     edgeto[i][j].weight=0;
   }
  cout<<"Enter start,end point and weight of each edge";
  for(int i=0;i<noedge;i++)
  { int a,b,c;
    cin>>a>>b>>c;
    edgeto[a][b].weight=c;
  }
  negcycle(novert);
  return 0;
}
