#include <iostream>
using namespace std;

class Employee
{
public:
    int salary;
    string name;
    Employee* left;
    Employee* right;

    // Constructor
    Employee(int sal, string empName)
    {
        salary = sal;
        name = empName;
        left = right = NULL;
    }

    // Insert a new employee based on salary
    Employee* insert(Employee* root, int sal, string empName)
    {
        if (root == NULL)
        {
            return new Employee(sal, empName);
        }

        if (sal < root->salary)
        {
            root->left = insert(root->left, sal, empName);
        }
        else
        {
            root->right = insert(root->right, sal, empName);
        }

        return root;
    }

    // Search for an employee by salary
    Employee* search(Employee* root, int sal)
    {
        if (root == NULL || root->salary == sal)
        {
            return root;
        }
        if (sal < root->salary)
        {
            return search(root->left, sal);
        }
        return search(root->right, sal);
    }

    // Update an employee's salary
    Employee* updateSalary(Employee* root, int oldSal, int newSal, string empName) 
    {
        root = deleteEmployee(root, oldSal);  // Delete old record
        return insert(root, newSal, empName); // Insert new record
    }

    // Display employees (Inorder traversal)
    void inorder(Employee* root) 
    {
        if (root == NULL) return;
        inorder(root->left);
        cout << "Name: " << root->name << ", Salary: " << root->salary << endl;
        inorder(root->right);
    }

    // Find the employee with the minimum salary
    Employee* minSalary(Employee* root)
    {
        if (root == NULL || root->left == NULL) 
        {
            return root;
        }
        return minSalary(root->left);
    }

    // Find the employee with the maximum salary
    Employee* maxSalary(Employee* root) 
    {
        if (root == NULL || root->right == NULL)
        {
            return root;
        }
        return maxSalary(root->right);
    }

    // Compute the average salary
    void calculateAverage(Employee* root, int &sum, int &count)
    {
        if (root == NULL) return;
        sum += root->salary;
        count++;
        calculateAverage(root->left, sum, count);
        calculateAverage(root->right, sum, count);
    }

    // Get the total number of employees
    int countEmployees(Employee* root) 
    {
        if (root == NULL) return 0;
        return 1 + countEmployees(root->left) + countEmployees(root->right);
    }

    // Delete an employee by salary
    Employee* deleteEmployee(Employee* root, int sal) 
    {
        if (root == NULL) return root;

        if (sal < root->salary) 
        {
            root->left = deleteEmployee(root->left, sal);
        } else if (sal > root->salary)
        {
            root->right = deleteEmployee(root->right, sal);
        }
        else
        {
            if (root->left == NULL)
            {
                Employee* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Employee* temp = root->left;
                delete root;
                return temp;
            }

            Employee* temp = minSalary(root->right);
            root->salary = temp->salary;
            root->name = temp->name;
            root->right = deleteEmployee(root->right, temp->salary);
        }
        return root;
    }
};

int main()
{
    Employee* root = NULL;
    Employee emp(0, ""); // Creating an object to use member functions

    int choice, salary, newSalary;
    string name;
    
    do
    {
        cout << "\n1. Insert Employee\n2. Search Employee\n3. Update Salary\n4. Display Employees\n";
        cout << "5. Minimum Salary\n6. Maximum Salary\n7. Average Salary\n8. Total Employees\n9. Delete Employee\n10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter employee name: ";
                cin >> name;
                cout << "Enter salary: ";
                cin >> salary;
                root = emp.insert(root, salary, name);
                break;

            case 2:
                cout << "Enter salary to search: ";
                cin >> salary;
                if (emp.search(root, salary))
                {
                    cout << "Employee found with salary: " << salary << endl;
                } 
                else
                {
                    cout << "Employee not found!\n";
                }
                break;

            case 3:
                cout << "Enter employee name: ";
                cin >> name;
                cout << "Enter old salary: ";
                cin >> salary;
                cout << "Enter new salary: ";
                cin >> newSalary;
                root = emp.updateSalary(root, salary, newSalary, name);
                break;

            case 4:
                cout << "Employee List (Sorted by Salary):\n";
                emp.inorder(root);
                break;

            case 5:
                if (root) cout << "Minimum Salary: " << emp.minSalary(root)->salary << endl;
                else cout << "No employees available!\n";
                break;

            case 6:
                if (root) cout << "Maximum Salary: " << emp.maxSalary(root)->salary << endl;
                else cout << "No employees available!\n";
                break;

            case 7:
                if (root) 
                {
                    int sum = 0, count = 0;
                    emp.calculateAverage(root, sum, count);
                    cout << "Average Salary: " << (sum / count) << endl;
                } 
                else
                {
                    cout << "No employees available!\n";
                }
                break;

            case 8:
                cout << "Total Employees: " << emp.countEmployees(root) << endl;
                break;

            case 9:
                cout << "Enter salary to delete: ";
                cin >> salary;
                root = emp.deleteEmployee(root, salary);
                cout << "Employee with salary " << salary << " deleted successfully.\n";
                break;

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 10);

    return 0;
}
