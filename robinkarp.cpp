//Robin-Karp algorithm
//to find a pattern in a string using the hashing method(prime number)
#include<iostream> 
#include<string.h>
using namespace std;
void search(char pat[],char txt[],int q) 
{ int M = strlen(pat); 
  int N = strlen(txt); 
  int i,j,p=0,t=0,h=1; 
  for(i=0;i<M-1;i++) 
   h=(h*26)%q; 
  for(i=0;i<M;i++) 
  { p = (26*p + pat[i])%q; 
    t = (26*t + txt[i])%q; 
  } 
  for(i=0;i<=N-M;i++) 
  { if ( p == t ) 
    { for (j = 0;j<M;j++) 
      { if(txt[i+j]!=pat[j]) 
         break; 
      } 
      if (j == M) 
       cout<<"Pattern found at index "<<i<<endl; 
    } 
    if ( i < N-M ) 
    { t =(26*(t-txt[i]*h)+txt[i+M])%q; 
      if(t<0) 
       t=(t+q); 
    } 
  } 
} 
int main() 
{ char txt[20];
  cout<<"Enter text";
  cin>>txt; 
  char pat[20];
  cout<<"Enter pattern";
  cin>>pat; 
  int q = 101;  
  search(pat,txt,q); 
  return 0; 
} 
