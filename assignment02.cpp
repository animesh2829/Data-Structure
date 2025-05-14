
#include <iostream>
#include<stack>
using namespace std;

class EMP {
public:
    string name;
    int id;
    double salary;
    EMP* left;
    EMP* right;

    EMP(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
        left = NULL;
        right = NULL;
    }
}*root,*next1;

//EMP* root = NULL;

void insert(EMP* root, EMP* next) {
    if (root == NULL) {
        root = next; 
        return;
    }

    if (next->salary < root->salary) {
        insert(root->left, next);
    } else {
        insert(root->right, next);
    }
}

void create() {
    string n1;
    int i1, c;
    double s1;

    do {
        cout << "\nEnter the name, id, salary of emp: ";
        cin >> n1 >> i1 >> s1;

        EMP* next = new EMP(n1, i1, s1);
        insert(root, next); 

        cout << "\nWant to insert more? (0 to stop): ";
        cin >> c;
    } while (c != 0);
}



EMP* search1(EMP* root,int sal)
{
    if(root==NULL)return NULL;
    next1=root;
    if(next1->salary==sal)
    {
        return root;
    }
    else if(next1->salary>sal)
    {
        search1(next1->left,sal);
    }
    else if(next1->salary<sal){
        search1(next1->right,sal);
    }
    else{
        return NULL;
    }
    return next1;
}


void update(EMP* root,EMP* newNode)
{
if(root==NULL) return;
if(root->id==newNode->id)
{
  root->name=newNode->name;
  return;
}
else
{
  update(root->left,newNode);
  update(root->right,newNode);
   
}
}




void display(EMP* root) {
    if (root == NULL) return;
    cout << "Name: " << root->name << "\nID: " << root->id << " \nSalary: " << root->salary << endl;
    display(root->left);
  
    display(root->right);
}





void maxsal(EMP* root)
{
   if(root==NULL) return;
    while (root->right!=NULL) 
    { 
        root=root->right;
    }
    cout << "\nEmployee with Minimum Salary:\n";
    cout << "Name: " << root->name<< " ID: " << root->id<< " Salary: "<< root->salary << endl;
}




void minsal(EMP* root)
{
   if(root==NULL) return;

    while (root->left!=NULL) 
    { 
        root=root->left;
    }
    cout << "\nEmployee with Minimum Salary:\n";
    cout << "Name: " << root->name<< " ID: " << root->id<< " Salary: "<< root->salary << endl; 
}


void avgsal(EMP* root) {
    if (root==NULL) return;

    stack<EMP*> s;
    double total = 0;
    int cnt = 0;

    while (root!=NULL || !s.empty()) {
        if (root) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            s.pop();
            total += root->salary;
             cnt++;
            root = root->right;
        }
    }
    cout << "AverageSalary: " << total / cnt << endl;
}


int countNodes(EMP* root) {
    if (root == NULL) 
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}



EMP* delete1(EMP* root, int x) {
    if (root == NULL) return NULL;

    if (x < root->salary) {
        root->left = delete1(root->left, x);
    } 
    else if (x > root->salary) {
        root->right = delete1(root->right, x);
    } 
    else {
        if (root->left == NULL || root->right == NULL) 
        {
        if(root->left != NULL) 
        {
        next1=root->left;
        }
        else
        { next1=root->right;}

            delete root;
            return next1;
        }

       
        EMP* successor = root->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }

        root->salary = successor->salary; 
        root->right = delete1(root->right, successor->salary); 
    }
    return root;
}


int main() {
    root = NULL;
    int ch,val,id1;
    string name1;
    double sal1;

    do {
        cout<<"\n1. Create\n2. Search\n3. Update\n4. Display\n5. Minimum salary\n6. Maximum salary\n7. Find Average Salary\n8. Total number of employees\n9. exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                create();
                break;

            case 2:
            cout<<"\nEnter the salary that you want to search: ";
            cin>>val;
            next1 = search1(root, val);
            if(next1==NULL)
            {
              cout<<"\n NO node found!";
            }
            else
            {
              cout<<"name: "<<next1->name<<" ID:"<<next1->id<<" salary:"<<next1->salary;
            }
          
            break;

            case 3:
            cout<<"\nEnter id,name,sal for updating a node: ";
            cin>>id1>>name1>>sal1;
            update(root,new EMP(name1,id1,sal1));
                break;

                case 4:
                cout << "\nDisplaying Employees:\n";
                display(root);
                break;
            
                case 5:
                minsal(root);
                break;
            
                case 6:
                maxsal(root);
                break;
            
                case 7:
                avgsal(root);
                break;
            
                case 8:
                cout<<"\n"<<countNodes(root)<<" number of emp are there";
                break;
            
                case 9:
                cout<<"\n\nExiting from the code!";
                break;
            
                 default:
                 cout<<"\nInvalid case!";
            
               }
                }while(ch!=9);
                return 0;
        }
