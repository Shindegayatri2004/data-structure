#include<iostream>
using namespace std;

int key[10], n;

class hash_m {
public:
    int t_no;
    string alb_name;
    string art_name;

    void create();
    void accept();
    void display();
    void search();
    void modify();
    void deleteRecord();
} h[100];

void hash_m::create() {
    cout << "\nEnter number of keys: ";
    cin >> n;

    cout << "\nEnter key (t_no) values:\n";
    for (int i = 0; i < n; i++) {
        cin >> key[i];
    }

    for (int i = 0; i < 10; i++) {
        h[i].t_no= -1;
    }
}

void hash_m::accept() {
    int loc;
    for (int i = 0; i < n; i++) {
        loc = key[i] % 10;
        while (true) {
            if (h[loc].t_no == -1) {
                h[loc].t_no = key[i];
                cin.ignore(); 
                cout <<"\nEnter name of album: ";
                getline(cin, h[loc].alb_name);
                cout << "Enter name of artist: ";
                getline(cin, h[loc].art_name);
                break;
            } else {
                loc = (loc + 1) % 10; 
            }
        }
    }
}

void hash_m::display() {
    cout << "\nLoc\tt_no\talb_Name\t\tart_name\n";
    for (int i = 0; i < 10; i++) {
        cout << i << "\t";
        if (h[i].t_no == -1) 
        {
            cout << "-1\t-1\t\t-1\n";
        } else {
            cout << h[i].t_no << "\t" << h[i].alb_name << "\t\t" << h[i].art_name << "\n";
        }
    }
}

void hash_m::search() {
    int s_key, loc;
    bool found = false;
    cout << "\nEnter key (t_no) to search: ";
    cin >> s_key;

    loc = s_key % 10;

    for (int i = 0; i < 10; i++) {
        int index = (loc + i) % 10;
        if (h[index].t_no == s_key) {
            cout << "\nKey found at location " << index << ":\n";
            cout << "album_Name = " << h[index].alb_name << "\n";
            cout << "artist_name = " << h[index].art_name << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Key not found.\n";
    }
}

void hash_m::modify() {
    int m_key, loc;
    bool found = false;
    cout << "\nEnter t_no to modify: ";
    cin >> m_key;

    loc = m_key % 10;

    for (int i = 0; i < 10; i++) {
        int index = (loc + i) % 10;
        if (h[index].t_no == m_key) {
            cout << "Current name: " << h[index].alb_name << "\n";
            cout << "Current address: " << h[index].art_name << "\n";

            cout << "Enter new name: ";
            cin >> h[index].alb_name;

            cout << "Enter new address: ";
            cin >> h[index].art_name;

            cout << "Record updated.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "track number not found.\n";
    }
}


void hash_m::deleteRecord() {
    int d_key, loc;
    bool found = false;
    cout << "\nEnter t_no to delete: ";
    cin >> d_key;

    loc = d_key % 10;

    for (int i = 0; i < 10; i++) {
        int index = (loc + i) % 10;
        if (h[index].t_no == d_key) {
            h[index].t_no = -2;
            h[index].alb_name = "-2";
            h[index].art_name = "-2";
            cout << "Record deleted.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "track number not found.\n";
    }
}

int main() {
    int ch;
    do {
        cout << "\n\n--- Hash Table Menu ---\n";
        cout << "1. Create\n2. Accept\n3. Display\n4. Search\n5. Modify\n6. Delete\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                h[0].create();
                break;
            case 2:
                h[0].accept();
                break;
            case 3:
                h[0].display();
                break;
            case 4:
                h[0].search();
                break;
            case 5:
                h[0].modify();
                break;
            case 6:
                h[0].deleteRecord();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (ch != 0);

    return 0;
}
