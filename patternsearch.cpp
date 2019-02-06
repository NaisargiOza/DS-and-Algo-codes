//knuth-moris-pratt algorithm
//to find a pattern in a string
#include<iostream>
#include<string.h>
using namespace std;
void check(int n,int dfa[3][50])
{ char txt[20];
  string pat1="abc";
  cout<<"Enter text";
  cin>>txt;
  int state=0;
  int m=strlen(txt),i,j;
  for(i=0;i<m;i++)
  { for(j=0;j<3;j++)
    { if(txt[i]==pat1[j])
       state=dfa[j][state];
    }
    if(state==n+1)
    { cout<<"Pattern found";
      break;
    }
  }
  if(i==m)
   cout<<"Pattern not found";
}
void kmp(char pat[])
{ int n=strlen(pat);
  int dfa[3][50];
  string pat1="abc";
  for(int i=0;i<3;i++)
  { if(pat1[i]==pat[0])
     dfa[i][0]=1;
    else
     dfa[i][0]=0;
  }
  int x=0,i,j;
  for(i=0;i<n;i++)
  { for(j=0;j<3;j++)
    { if(pat1[j]==pat[i])
       dfa[j][i]=i+1;
      else
       dfa[j][i]=dfa[j][x];
    }
    x=dfa[j][x];
  }
  /*for(int i=0;i<3;i++)
  { for(int j=0;j<n;j++)
     cout<<dfa[i][j]<<" ";
    cout<<endl;
  }*/
  check(n,dfa);
}
int main()
{ char pat[20];
  cout<<"Enter pattern";
  cin>>pat;
  kmp(pat);
  return 0;
}
 
