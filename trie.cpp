#include<iostream>
#include<string.h>
using namespace std;
struct node
{ char val[10];
  node *link1;
  node *link2;
  node *link3;
  node *link4;
  node *link5;
};
class trie
{ node *root;
  public:
  trie()
  { root=new node;
    strcpy(root->val,"-");
    root->link1=NULL;
    root->link2=NULL;
    root->link3=NULL;
    root->link4=NULL;
    root->link5=NULL;
  }
  void insert(char word[])
  { node *temp;
    temp=root;
    int pos=0,done=0;
    char cur=word[pos];
    while(done==0)
    { node *newnode=new node;
      strcpy(newnode->val,"-");
      newnode->link1=NULL;
      newnode->link2=NULL;
      newnode->link3=NULL;
      newnode->link4=NULL;
      newnode->link5=NULL;
      cur=word[pos];
      switch(cur)
      { case 'a':case 'A':if(temp->link1==NULL)
                           temp->link1=newnode;
                          temp=temp->link1;
                          break;
        case 'b':case 'B':if(temp->link2==NULL)
                           temp->link2=newnode;
                          temp=temp->link2;
                          break;
        case 'c':case 'C':if(temp->link3==NULL)
                           temp->link3=newnode;
                          temp=temp->link3;
                          break;
        case 'd':case 'D':if(temp->link4==NULL)
                           temp->link4=newnode;
                          temp=temp->link4;
                          break;
        case 'e':case 'E':if(temp->link5==NULL)
                           temp->link5=newnode;
                          temp=temp->link5;
        case '\0':strcpy(temp->val,word);
                  done=1;
      }
      pos++;
    }
  }
  void disp(node *rt)
  { if(rt!=NULL)
    { if(strcmp(rt->val,"-")!=0)
       cout<<rt->val<<endl;
      disp(rt->link1);
      disp(rt->link2);
      disp(rt->link3);
      disp(rt->link4);
      disp(rt->link5);
    }
  }
  void DISPLAY()
  { disp(root); }
  void search(char word[])
  { node *temp;
    int pos=0,done=0;
    char cur;
    temp=root;
    while(done==0)
    { cur=word[pos];
      switch(cur)
      { case 'a':case 'A':if(temp->link1==NULL)
                          { cout<<"Wrong word";
                            done=1;
                          }
                          temp=temp->link1;
                          break;
       case 'b':case 'B':if(temp->link2==NULL)
                         { cout<<"Wrong word";
                           done=1;
                         }
                         temp=temp->link2;
                         break;  
       case 'c':case 'C':if(temp->link3==NULL)
                         { cout<<"Wrong word";
                           done=1;
                         }
                         temp=temp->link1;
                         break;
       case 'd':case 'D':if(temp->link4==NULL)
                          { cout<<"Wrong word";
                            done=1;
                          }
                          temp=temp->link4;
                          break;
       case 'e':case 'E':if(temp->link5==NULL)
                          { cout<<"Wrong word";
                            done=1;
                          }
                          temp=temp->link5;
                          break;
       case '\0':cout<<"Word found";
                 done=1;
                 break;
      }
      pos++;
    }
  }
};
int main()
{ trie T;
  char word[10];
  cout<<"MENU\n1.Insert a word\n2.Display\n3.Search\n4.Exit";
  int ch;
  do
  { cout<<"Enter choice ";
    cin>>ch;
    if(ch==1)
    { cout<<"Enter word";
      cin>>word;
      T.insert(word);
    }
    else if(ch==2)
    { T.DISPLAY();
    }
    else if(ch==3)
    { cout<<"Enter a word";
      cin>>word;
      T.search(word);
    }
  }while(ch<4);
  return 0;
}
