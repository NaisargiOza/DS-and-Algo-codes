#include<iostream>
using namespace std;
struct node
{ char data;
  int val;
  node *left,*right,*middle;
}*root;
void insert(node *root,char *word)
{ if(root==NULL)
  { root=new node;
    root->val=-1;
    root->left=root->right=root->middle=NULL;
    root->data=*word;
  }
  if(root->data>(*word))
   insert(root->left,word);
  else if(root->data<(*word))
   insert(root->right,word);
  else
  { if(*(word+1))
     insert(root->middle,word+1);
    else
     root->val=1;
  }
}
void disp(node *root,char buffer[],int depth)
{ cout<<"a";
  if(root)
  { cout<<"b";
    disp(root->left,buffer,depth);
    buffer[depth]=root->val;
    if(root->val!=-1)
    { buffer[depth+1]='\0';
      for(int i=0;i<depth;i++)
       cout<<buffer[i];
      cout<<endl;
    }
    disp(root->middle,buffer,depth+1);
    disp(root->right,buffer,depth);
  }
}
void DISPLAY(node *root)
{ char buffer[100];
  disp(root,buffer,0);
}
int search(node *root,char *word)
{ cout<<"A";
  if(!root)
   return 0;
  if(*word<root->data)
   return search(root->left,word);
  else if(*word>root->data)
   return search(root->right,word);
  else
  { if(*(word+1)=='\0')
     return 1;
    return search(root->middle,word+1);
  }
  cout<<"A";
}
int main()
{ 
  char word[10];
  cout<<"MENU\n1.Insert a word\n2.Display\n3.Search\n4.Exit";
  int ch;
  do
  { cout<<"Enter choice ";
    cin>>ch;
    if(ch==1)
    { cout<<"Enter word";
      cin>>word;
      insert(root,word);
    }
    else if(ch==2)
    { DISPLAY(root);
    }
    else if(ch==3)
    { cout<<"Enter a word";
      cin>>word;
      int n=search(root,word);
      if(n==0)
       cout<"WOrd not found";
      else
       cout<<"Word found";
    }
  }while(ch<4);
  return 0;
}
      
  
  
