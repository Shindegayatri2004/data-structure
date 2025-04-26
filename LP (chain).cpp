#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

int keys[TABLE_SIZE], chain[TABLE_SIZE];

class MedicalRecord {
public:
    int prn;
    string name;
    string address;

    void create();
    void accept();
    void display();
    void search();
    void modify();
    void deleteRecord();
} records[TABLE_SIZE];

void MedicalRecord::create() {
    int n;
    cout << "\nEnter number of records: ";
    cin >> n;

    cout << "Enter PRN values:\n";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        records[i].prn = -1;
        records[i].name = "-1";
        records[i].address = "-1";
        chain[i] = -2;
    }
}

void MedicalRecord::accept() {
    int n;
    cout << "\nEnter number of records to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int prn;
        string name, address;
        cout << "\nEnter PRN: ";
        cin >> prn;

        int index = prn % TABLE_SIZE;
        int originalIndex = index;
        bool inserted = false;

        do {
            if (records[index].prn == -1) {
                records[index].prn = prn;
                cout << "Enter name: ";
                cin >> records[index].name;
                cout << "Enter address: ";
                cin >> records[index].address;
                inserted = true;
                break;
            } else {
                index++;
                if (index >= TABLE_SIZE) index = 0;
            }
        } while (index != originalIndex);

        if (!inserted) {
            cout << "Table full. Couldn't insert PRN " << prn << ".\n";
        }
    }
}

void MedicalRecord::display() {
    cout << "\nIndex\tPRN\tName\tAddress\tChain\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << "\t" << records[i].prn << "\t" << records[i].name << "\t" << records[i].address << "\t" << chain[i] << "\n";
    }
}

void MedicalRecord::search() {
    int prn;
    cout << "\nEnter PRN to search: ";
    cin >> prn;

    int index = prn % TABLE_SIZE;
    bool found = false;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;
        if (records[pos].prn == prn) {
            cout << "Record found at index " << pos << ":\n";
            cout << "Name: " << records[pos].name << ", Address: " << records[pos].address << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }
}

void MedicalRecord::modify() {
    int prn;
    cout << "\nEnter PRN to modify: ";
    cin >> prn;

    int index = prn % TABLE_SIZE;
    bool found = false;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;
        if (records[pos].prn == prn) {
            cout << "Current Name: " << records[pos].name << ", Address: " << records[pos].address << endl;
            cout << "Enter new name: ";
            cin >> records[pos].name;
            cout << "Enter new address: ";
            cin >> records[pos].address;
            cout << "Record updated.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }
}

void MedicalRecord::deleteRecord() {
    int prn;
    cout << "\nEnter PRN to delete: ";
    cin >> prn;

    int index = prn % TABLE_SIZE;
    bool found = false;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;
        if (records[pos].prn == prn) {
            records[pos].prn = -1;
            records[pos].name = "-1";
            records[pos].address = "-1";
            chain[pos] = -2;
            cout << "Record deleted.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n\n--- Medical Record Hash Table Menu ---\n";
        cout << "1. Create\n2. Accept\n3. Display\n4. Search\n5. Modify\n6. Delete\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: records[0].create(); break;
            case 2: records[0].accept(); break;
            case 3: records[0].display(); break;
            case 4: records[0].search(); break;
            case 5: records[0].modify(); break;
            case 6: records[0].deleteRecord(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
