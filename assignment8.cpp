#include <iostream>
using namespace std;

#define MAX 100

class OBST
{
public:
    int p[MAX];
    int q[MAX];
    int w[MAX][MAX];
    int c[MAX][MAX];
    int r[MAX][MAX];
    int key[MAX];
    int size;

    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int d)
        {
            data = d;
            left = right = nullptr;
        }
    };

    void insert(int n, int ki[], int pi[], int qi[])
    {
        size = n;
        for (int i = 1; i <= size; i++)
            key[i] = ki[i - 1];
        for (int i = 1; i <= size; i++)
            p[i] = pi[i - 1];
        for (int i = 0; i <= size; i++)
            q[i] = qi[i];
    }

    void calweight()
    {
        for (int i = 0; i <= size; i++)
        {
            w[i][i] = q[i];
            for (int j = i + 1; j <= size; j++)
            {
                w[i][j] = w[i][j - 1] + p[j] + q[j];
            }
        }
    }

    void calcost()
    {
        for (int i = 0; i <= size; i++)
        {
            c[i][i] = 0;
            r[i][i] = 0;
        }

        for (int l = 1; l <= size; l++)
        {
            for (int i = 0; i <= size - l; i++)
            {
                int j = i + l;
                c[i][j] = MAX;

                for (int k = i + 1; k <= j; k++)
                {
                    int cost = c[i][k - 1] + c[k][j] + w[i][j];
                    if (cost < c[i][j])
                    {
                        c[i][j] = cost;
                        r[i][j] = k;
                    }
                }
            }
        }
    }

    void display()
    {
        cout << "\nWeight matrix:\n";
        for (int i = 0; i <= size; i++)
        {
            for (int j = 0; j <= size; j++)
            {
                cout << w[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void displaycost()
    {
        cout << "\nCost matrix:\n";
        for (int i = 0; i <= size; i++)
        {
            for (int j = 0; j <= size; j++)
            {
                cout << c[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void displayRoot()
    {
        cout << "\nRoot matrix:\n";
        for (int i = 0; i <= size; i++)
        {
            for (int j = 0; j <= size; j++)
            {
                cout << r[i][j] << "\t";
            }
            cout << endl;
        }
    }

    Node *createTree(int i, int j)
    {
        if (i == j)
            return nullptr;

        int rootIndex = r[i][j];
        Node *root = new Node(key[rootIndex]);
        root->left = createTree(i, rootIndex - 1);
        root->right = createTree(rootIndex, j);
        return root;
    }

    void displayTree(Node *root)
    {
        if (root == nullptr)
            return;

        cout << root->data << " ";
        displayTree(root->left);
        displayTree(root->right);
    }

    void constructTreeAndDisplay()
    {
        cout << "\nPreorder traversal of OBST:\n";
        Node *root = createTree(0, size);
        displayTree(root);
        cout << endl;
    }
};

int main()
{
    OBST obst;

    // Example keys and probabilities
    int n = 4;
    int keys[] = {10, 20, 30, 40};      // Keys in sorted order
    int p[] = {3, 3, 1, 1};             // Probabilities for successful search
    int q[] = {2, 3, 1, 1, 1};          // Probabilities for unsuccessful search

    obst.insert(n, keys, p, q);
    obst.calweight();
    obst.calcost();
    obst.display();
    obst.displaycost();
    obst.displayRoot();
    obst.constructTreeAndDisplay();

    return 0;
}
