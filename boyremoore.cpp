//BOYRE-MOORE ALGORITHM
//TO FIND A PATTERN IN A STRING
#include<iostream>
#include<string.h>
using namespace std; 
int max (int a, int b)
{ return (a > b)? a: b; } 
void fill(char *str,int size,int right[10]) 
{ int i; 
  for(i = 0;i<10;i++) 
   right[i] = -1; 
  for(i = 0;i<size;i++) 
   right[(int) str[i]] = i; 
}
void search(char *txt,char *pat) 
{ int m = strlen(pat); 
  int n = strlen(txt); 
  int right[10]; 
  fill(pat,m,right); 
  int s = 0;  
  while(s <= (n - m)) 
  { int j = m-1; 
    while(j >= 0 && pat[j] == txt[s+j]) 
     j--; 
    if (j < 0) 
    { cout<<"pattern occurs at shift = "<<s; 
      s+=(s+m<n)?m-right[txt[s+m]]:1; 
    } 
    else
     s += max(1,j-right[txt[s+j]]); 
  } 
} 
int main() 
{ 
    char txt[10];
    cout<<"Enter text";
    cin>>txt; 
    char pat[10];
    cout<<"Enter pattern";
    cin>>pat; 
    search(txt, pat); 
    return 0; 
} 
