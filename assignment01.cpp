#include<iostream>
using namespace std;

class BT
{
    public:

      int data;
      BT *left;
      BT *right;

      BT(int ic)
      {
        data=ic;
        left=NULL;
        right=NULL;
      }
}*root;


void pre(BT* root)
{ if(root==NULL) return;
  cout<<root->data<<" ";
  pre(root->left);
  pre(root->right);

}
void ino(BT* root)
{ if(root==NULL) return;
  ino(root->left);
  cout<<root->data<<" ";
  ino(root->right);
  

}
void post(BT* root)
{ if(root==NULL) return;
  post(root->left);
 
  post(root->right);
  cout<<root->data<<" ";

}
void insert(BT *root,BT* next)
{
    char c1;
 
    cout<<"\nDo u want to insert at (L/R): ";
    cin>>c1;
    if(c1=='l'||c1=='L')
    {
        if(root->left!=NULL)
        {
            insert(root->left,next);
        }
        else{
            root->left=next;
        }
    }
    else if(c1=='R'||c1=='r')
    {
        if(root->right!=NULL)
        {
            insert(root->right,next);
        }
        else{
            root->right=next;
        }
    }
    else{
        cout<<"\nInvalid choice!";
    }


    
}


void create()
{
    int x,cx;
do{
    cout<<"\nEnter the data: ";
    cin>>x;
    BT* next=new BT(x);
    if(root==NULL)
    {
        root=next;
    }
    else
    {
        insert(root,next);
    }
    cout<<"\nEnter if u want to continue(0/1): ";
    cin>>cx;
   }while(cx!=1);
}


int count(BT* root)
{
    if(root==NULL) return 0;
    return 1+count(root->left)+count(root->right);
}


void anc(BT* root)
{
    if(root==NULL)return;
    cout<<root->data;
}

void leaf(BT* root)
{
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL)
    {
        cout<<root->data;
    }
    leaf(root->left);
    leaf(root->right);
}


int height(BT* root)
{
    if(root==NULL)return -1;
    return(1+min(height(root->left),height(root->right)));
}
int main()
{
    root=NULL;

    int ch;
do
{
    cout<<"\nEnter your choice: \n1. create\n2. pre\n3. ino\n4. post\n5. count\n6. leaf\n7. ancsetor\n8. height\n9.exit";
    cin>>ch;
    switch(ch)
    {
        case 1:
        create();
        break;

        case 2:
        pre(root);
        break;

        case 3:
        ino(root);
        break;

        case 4:
        post(root);
        break;

        case 5:
        cout<<count(root);
        break;

        case 6:
        leaf(root);
        break;

        case 7:
         anc(root);
        break;

        case 8:
        cout<<height(root);
        break;

        case 9:
        cout<<"\nExiting from the code!";
        break;

        default:
        cout<<"\nInvalid edge!";
    }
}while(ch!=8);
    return 0;
}