#include <iostream>
using namespace std;

class Music {
    public:
    int id;
    string  title,singer;
     Music() {
        id = -1;
        title = "";
        singer = "";
        
     }

     Music(int id1, string title1, string singer1) {
        id = id1;
        title = title1;
        singer = singer1;

     }
};

class hashing {
    public:
    Music table[10];
    int table_size;

    
    hashing(int size) {
        table_size = size;
        for (int i=0; i<table_size; i++) {
            table[i] = Music();
        }
    }

    int hash_function (int key) {
        return key % table_size;
    }

    void insert_data (int key, string m_title, string m_singer) {
        int  index = hash_function(key);
        for (int i=0; i<table_size; i++) {
            int probe = (index + 1) % table_size;
            if (table[probe].id == -1) {
                table[probe] = Music(key, m_title, m_singer);
                cout << "\n\nInserted Music ID " << key << " at index " << probe << endl;
                return;
            }
            else {
                cout <<"\n\nCollision occur at index: "<<probe<<endl;
            }
        }
        cout << "Hash Table is full cannot insert music.\n";

    }

    void display() {
        cout << "\nMusic Library:\n";
        for (int i=0; i<table_size; i++) {
            cout << i <<": ";
            if(table[i].id != -1) {
                cout << "ID: " << table[i].id<<" ,Title: "<<table[i].title << " ,Singer: "<<table[i].singer << endl;
            }else {
                cout <<"Empty" << endl;
            }
        }
    }

    void search(int key) {
        int index = hash_function(key);
        for (int i=0; i<table_size; i++) {
            int probe = (index + i) % table_size;
            if(table[probe].id == key) {
                cout << "Music found at index: "<< probe << endl;
                cout << "ID: " << table[probe].id<<" ,Title: "<<table[probe].title << " ,Singer: "<<table[probe].singer << endl;
                return;
            }
        }
        cout << "Music not found.";
    }

    
};
