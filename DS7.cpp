#include <iostream>
using namespace std;

const float LOAD_FACTOR_THRESHOLD = 0.7;

int currentSize = 10;

class MedicalRecord {
public:
    string name;
    string history;
    string treatment;
};

class MedicalHashTable {
private:
    MedicalRecord* records;
    int* status; // 1 = occupied, 0 = empty, -2 = deleted
    int count;

    int hashFunction(string key) 
    {
        int sum = 0;
        for (char c : key) sum += c;
        return sum % currentSize;
    }

    int quadraticProbe(int index, int i) {
        return (index + i * i) % currentSize;
    }

    void rehash() {
        int oldSize = currentSize;
        currentSize *= 2;

        MedicalRecord* oldRecords = records;
        int* oldStatus = status;

        records = new MedicalRecord[currentSize];
        status = new int[currentSize];
        for (int i = 0; i < currentSize; i++) status[i] = 0;
        count = 0;

        for (int i = 0; i < oldSize; i++) {
            if (oldStatus[i] == 1) {
                addRecord(oldRecords[i].name, oldRecords[i].history, oldRecords[i].treatment);
            }
        }

        delete[] oldRecords;
        delete[] oldStatus;

        cout << "Rehashed. New size: " << currentSize << endl;
    }

public:
    MedicalHashTable() {
        records = new MedicalRecord[currentSize];
        status = new int[currentSize];
        for (int i = 0; i < currentSize; i++) status[i] = 0;
        count = 0;
    }

    void addRecord(string name, string history, string treatment) {
        float loadFactor = (float)(count + 1) / currentSize;
        if (loadFactor > LOAD_FACTOR_THRESHOLD) {
            rehash();
        }

        int index = hashFunction(name);
        for (int i = 0; i < currentSize; i++) {
            int pos = quadraticProbe(index, i);
            if (status[pos] != 1) {
                records[pos].name = name;
                records[pos].history = history;
                records[pos].treatment = treatment;
                status[pos] = 1;
                count++;
                cout << "Record added at index " << pos << endl;
                return;
            }
        }
        cout << "Hash table is full.\n";
    }

    void findRecord(string name) {
        int index = hashFunction(name);
        for (int i = 0; i < currentSize; i++) {
            int pos = quadraticProbe(index, i);
            if (status[pos] == 1 && records[pos].name == name) {
                cout << "Found at index " << pos << ": " << records[pos].name<< ", History: " << records[pos].history<< ", Treatment: " << records[pos].treatment << endl;
                return;
            }
        }
        cout << "Record not found.\n";
    }

    void updateRecord(string name) {
        int index = hashFunction(name);
        for (int i = 0; i < currentSize; i++) {
            int pos = quadraticProbe(index, i);
            if (status[pos] == 1 && records[pos].name == name) {
                cout << "Enter updated history: ";
                cin >> records[pos].history;
                cout << "Enter updated treatment: ";
                cin >> records[pos].treatment;
                cout << "Record updated.\n";
                return;
            }
        }
        cout << "Record not found.\n";
    }

    void deleteRecord(string name) {
        int index = hashFunction(name);
        for (int i = 0; i < currentSize; i++) {
            int pos = quadraticProbe(index, i);
            if (status[pos] == 1 && records[pos].name == name) {
                status[pos] = -2;
                count--;
                cout << "Record deleted.\n";
                return;
            }
        }
        cout << "Record not found.\n";
    }

    void displayAll() {
        cout << "\n--- Medical Records ---\n";
        for (int i = 0; i < currentSize; i++) {
            if (status[i] == 1) {
                cout << "Index " << i << ": " << records[i].name
                     << ", History: " << records[i].history
                     << ", Treatment: " << records[i].treatment << endl;
            }
        }
    }
};

int main() {
    MedicalHashTable system;
    int choice;

    do {
        cout << "\nMenu:\n1. Add Record\n2. Find Record\n3. Update Record\n4. Delete Record\n5. Display All\n6. Exit\nChoice: ";
        cin >> choice;

        string name, history, treatment;

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter medical history: ";
                cin >> history;
                cout << "Enter treatment plan: ";
                cin >> treatment;
                system.addRecord(name, history, treatment);
                break;

            case 2:
                cout << "Enter name to find: ";
                cin >> name;
                system.findRecord(name);
                break;

            case 3:
                cout << "Enter name to update: ";
                cin >> name;
                system.updateRecord(name);
                break;

            case 4:
                cout << "Enter name to delete: ";
                cin >> name;
                system.deleteRecord(name);
                break;

            case 5:
                system.displayAll();
                break;

            case 6:
                cout << "Exiting.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
