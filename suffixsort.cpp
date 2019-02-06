#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct suffix
{ int index;
  char *suff;
};
bool cmp(suffix a,suffix b)
{ return strcmp(a.suff,b.suff)<0?1:0; }
int *buildSuffixArray(char txt[],int n)
{ suffix suffarr[n];
  for(int i=0;i<n;i++)
  { suffarr[i].index=i;
    suffarr[i].suff=(txt+i);
  }
  sort(suffarr,suffarr+n,cmp);
  int *arr=new int[n];
  for(int i=0;i<n;i++)
   arr[i]=suffarr[i].index;
  return arr;
}
int main()
{ cout<<"Enter an array";
  char txt[10];
  cin>>txt;
  int n=strlen(txt);
  int *suffixarr = buildSuffixArray(txt,  n);
  for(int i=0;i<n;i++)
  { cout<<*(suffixarr+i)<<" "; }
  return 0;
}
