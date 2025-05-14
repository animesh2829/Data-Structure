#include <iostream>
#include <math.h>
using namespace std;
class Medical
{
public:
    string patientName;
    int patientAge;
    int paitentId;
    string patientDiasese;
    string gender;

    Medical()
    {
        paitentId = -1;
        patientAge = 0;
        patientDiasese = "";
        patientName = "";
        gender = "";
    }

    void setData(int id, int age, string name, string dis, string gen)
    {

        paitentId = id;
        patientAge = age;
        patientName = name;
        gender = gen;
        patientDiasese = dis;
    }

    void display()
    {
        if (paitentId != -1)
        {
            cout << "PatientId :" << paitentId;
            cout << " PatientAge :" << patientAge;
            cout << " PatientName :" << patientName;
            cout << " PatientDisases :" << patientDiasese;
            cout << " Gender:" << gender << endl;
        }
        else
        {
            cout << "Empty : " << endl;
        }
    }
};

class Hash
{
private:
    Medical hashTable[100];

public:
    int size;
    Hash(int s)
    {
        size = s;
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int getPrime()
    {
        for (int i = size - 1; i >= 2; i--)
        {
            if (isPrime(i))
                return i;
        }
        return 3;
    }

    void insert(int id, int age, string name, string dis, string gen)
    {
        int index = hashFunction(id);
        int index1 = index;
        int prime = getPrime();
        int index2 = prime - (id % prime);
        int i = 0;
        while (hashTable[index].paitentId != -1)
        {
            i++;
            index = (index1 + i * index2) % size;
            if (i == size)
                return;
        }

        hashTable[index].setData(id, age, name, dis, gen);
        cout << "\nRecord Are Insert At " << index;
    }
    void displayRecord()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " -> ";
            hashTable[i].display();
        }
    }

    bool search(int id)
    {
        int index = hashFunction(id);
        int index1 = index;
        int prime = getPrime();
        int index2 = prime - (id % prime);
        int i = 0;
        while (hashTable[index].paitentId != -1)
        {

            if (hashTable[index].paitentId == id)
            {
                return true;
            }
            i++;
            index = (index1 + i * index2) % size;
        }

        return false;
    }

    void update(int id)
    {
        int index = hashFunction(id);
        int index1 = index;
        int prime = getPrime();
        int index2 = prime - (id % prime);
        int i = 0;
        int nage;
        string nname, ndis, ngen;
        while (hashTable[index].paitentId != -1)
        {

            if (hashTable[index].paitentId == id)
            {
                cout << "Enter PatientAge :";
                cin >> nage;
                cout << "Enter PatientName :";
                cin >> nname;
                cout << "Enter PatientDiasies :";
                cin >> ndis;
                cout << "Enter Gender :";
                cin >> ngen;
                hashTable[index].setData(id, nage, nname, ndis, ngen);
            }
        }
        i++;
        index = (index1 + i * index2) % size;
    }

    void delet(int id)
    {
        int index = hashFunction(id);
        int index1 = index;
        int prime = getPrime();
        int index2 = prime - (id % prime);
        int i = 0;
        int nage;
        string nname, ndis, ngen;
        while (hashTable[index].paitentId != -1)
        {

            if (hashTable[index].paitentId == id)
            {
                hashTable[index] = Medical();
            }
        }
        i++;
        index = (index1 + i * index2) % size;
    }
};
int main()
{
    int size;
    cout << "Enter the Size :";
    cin >> size;
    Hash h(size);

    int ch;
    int id, age;
    string name, dis, gen;

    while (1)
    {
        cout << "\nMedical Opreation " << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Display " << endl;
        cout << "3. Search" << endl;
        cout << "4. Update" << endl;
        cout << "5. Delete " << endl;
        cout << "6. Exit" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter PatientID :";
            cin >> id;
            cout << "Enter PatientAge :";
            cin >> age;
            cout << "Enter PatientName :";
            cin >> name;
            cout << "Enter PatientDisease :";
            cin >> dis;
            cout << "Enter Gender :";
            cin >> gen;

            h.insert(id, age, name, dis, gen);
            break;
        case 2:
            h.displayRecord();
            break;
        case 3:
            cout << "Enter PatientID :";
            cin >> id;
            if (h.search(id))
            {
                cout << "Yes Patient Are Present " << endl;
            }
            else
            {
                cout << "Oppss!! Patient Are Not in Medical" << endl;
            }
            break;
        case 4:
            cout << "Enter PatientID :";
            cin >> id;
            h.update(id);
            break;
        case 5:
            cout << "Enter PatientID :";
            cin >> id;
            h.delet(id);
            break;
        case 6:
            return 0;
        }
    }

    return 0;
}
