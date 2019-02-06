#include<iostream>
using namespace std;
struct tree
{ int data;
  tree *left,*right;
}*root;
void insert(int d)
{ if(root==NULL)
  { root=new tree;
    root->data=d;
    root->left=root->right=NULL;
  }
  else
  { tree *newnode=new tree;
    newnode->data=d;
    newnode->left=newnode->right=NULL;
    tree*pwalk=root;
    tree *parent;
    while(pwalk!=NULL)
    { parent=pwalk;
      if(d<pwalk->data)
       pwalk=pwalk->left;
      else
       pwalk=pwalk->right;
    }
    if(d<parent->data)
     parent->left=newnode;
    else
     parent->right=newnode;
  }
}
void inorder(tree *ro)
{ if(ro!=NULL)
  { inorder(ro->left);
    cout<<ro->data<<" ";
    inorder(ro->right);
  }
}
int largest()
{ tree *pwalk=root;
  while(pwalk->right!=NULL)
   pwalk=pwalk->right;
  return pwalk->data;
}
int smallest()
{ tree *pwalk=root;
  while(pwalk->left!=NULL)
   pwalk=pwalk->left;
  return pwalk->data;
}
tree *del(tree *root,int delkey)
{ tree *delptr=new tree;
  if(delkey<root->data)
   root->left=del(root->left,delkey);
  else if(delkey>root->data)
   root->right=del(root->right,delkey);
  else
  { if(root->left==NULL)
    { delptr=root->right;
      delete(root);
      return delptr;
    }
    else if(root->right==NULL)
    { delptr=root->left;
      delete(root);
      return delptr;
    }
    else
    { delptr=root->left;
      while(delptr->right!=NULL)
       delptr=delptr->right;
      root->data=delptr->data;
      root->left=del(root->left,delptr->data);
    }
  }
}
int main()
{ int ch;
  cout<<"MENU\n1.Insert\n2.Delete\n3.Find smallest\n4.Find largest\n5.Inorder\n6.Exit";
  do
  { cout<<"Enter choice";
    cin>>ch;
    if(ch==1)
    { int n;
      cout<<"Enter data";
      cin>>n;
      insert(n);
    }
    else if(ch==2)
    { int n;
      cout<<"Enter data to be deleted";
      cin>>n;
      del(root,n);
    }
    else if(ch==3)
    { int k=smallest();
      cout<<k;
    }
    else if(ch==4)
    { int k=largest();
      cout<<k;
    }
    else if(ch==5)
     inorder(root);
  }while(ch<=5);
  return 0;
}
       
