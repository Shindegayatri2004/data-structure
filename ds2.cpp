#include<iostream>
using namespace std;

class BST
{
int data;
int current;
BST *left;
BST *right;

BST(int x)
{
data=x;
}


void insert( int current,int key)
{
if(current=NULL)
{
    int x;
    cout << "Enter the data you want to insert: ";
    cin >> x;
    X=newnode;
    return new BST(x);
    
    else
    {
    while(current!=null)
    {
    prev=current;
    if(key<current.data)
    {
    current=current.left;
    }
    else
    {
    current=current.right;
    }
    }
    temp=newnode(key);
    if(temp.data<prev.data)
    {
    prev.left=temp;
    }
    else
    {
    prev.right=temp;
    }
    }
    }
  }
void preorder(BST* current)
 {
    if (current == NULL) 
    {
    return;
    }
    cout << current->data << " ";
    preorder(current->left);
    preorder(current->right);
}

void inorder(BST* current)
 {
    if (current == NULL) 
    {
    return;
    }
    inorder(current->left);
    cout << current->data << " ";
    inorder(current->right);
}

void postorder(BST* current) {
    if (current == NULL) 
    {
    return;
    }
    postorder(current->left);
    postorder(current->right);
    cout << current->data << " ";
}
};  

int main
{
BST *root=NULL;
int ch,char,key,choice;

do{
cout<<"enter your choice";
cout<<"1.insert\n 2.preorder \n 3.inorder 4.postorder\n ";
cin>>choice;

switch(choice)
{
case 1:
if(root=NULL)
{
cout<<"creating the root node";
cout<<"enter the root node value";
cin>>val;
root=new BST(val);
}
else
{
cout<<"inserting the newnode";
cout<<"enter value to thye newnode";
cin>>val;
BST *newnode=new BST(val);
insert(root,newnode);
}
break;
case 2:
cout<<"preorder";
preorder(root);
cout<<"endl";
break;

case 3:
cout<<"inorder";
inorder(root);
cout<<"endl";
break;

case 4:
cout<<"postorder";
postorder(root);
cout<<"endl";
break;
default:
  cout << "Wrong Choice\n";
}

cout << "Do you want to continue? If yes, press 1: ";
cin >> ch1;

} while (ch1 == 1);

 return 0;
}




    
    
