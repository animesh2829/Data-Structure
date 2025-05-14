#include<iostream>
using namespace std;

class GRAPH{
 public:
  int v,e,x,y;
  int m[5][5]={0};
  GRAPH(int a,int b)
  {
    v=a;
    e=b;
  }
   

void edge()
{
  cout<<"\nEnter source and termination vertex:";
   for(int i=0;i<e;i++)
   {
     cin>>x>>y;
     m[x][y]=1;
     m[y][x]=1;
   }
}

void display()
{
  cout<<"\nDisplaying:\n";
   for(int i=0;i<v;i++)
   {
     for(int j=0;j<v;j++)
     {
       cout<<m[i][j];
     }
     cout<<endl;
   }
}
};


int main()
{
  int n1,n2;
  
  cout<<"\nEnter the edges:";
  cin>>n1;
  cout<<"\nEnter the vertices:";
  cin>>n2;
  GRAPH g(n1,n2);
  
  g.edge();
  
  g.display();
  return 0;
}