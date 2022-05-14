#include <iostream>
using namespace std;

static float fixedPaidWorker() {
    char workerType;
    int hours;

    do {
        cout << "Input worker type please. P = Manager, B = Non-Manager" << endl;
        cin >> workerType;
    } while (workerType != 'P' && workerType != 'B');

    switch (workerType)
    {
    case 'P': //Manager
        return 300; // fixed salary TODO

    case 'B': //Non-Manager
        do {
            cout << "Hours worked:" << endl;
            cin >> hours;
        } while (hours < 0);

        if (hours <= 10) {
            return (hours * 15);
        }
        else if (hours <= 20) {
            return ((hours - 10) * 12) + 150;
        }
        else {
            return (10 * 12) + 150; //maximum overtime pay
        }
    }
}

static float contractWorker() {
    int hour;
    char category;

    do {
        cout << "Please enter a category (B = Recovery, S = Maintainance)" << endl;
        cin >> category;
    } while (category != 'S' && category != 'B');

    do {
        cout << "Hours worked:" << endl;
        cin >> hour;
    } while (hour > 100);

    switch (category) {
    case 'S':
        if (hour <= 50) {
            return (hour * 10);
        }
        else {
            return (((hour - 50) * 5) + 500);
        }
        break;
    case 'B':
        return (hour * 20);
        break;
    default:
        break;
    }
}

static float subcontractWorker() {
    char toySize;
    int numToys;

    do {
        cout << "Type in the code for the size of the toy. ie, B - Large, S - Medium, K - small:" << endl;
        cin >> toySize;
    } while (toySize != 'B' && toySize != 'S' && toySize != 'K');

    do {
        cout << "Insert number of toys made this month:" << endl;
        cin >> numToys;
    } while (numToys < 0);

    switch (toySize) {
    case 'B':
        return (numToys * 8);
        break;

    case 'S':
        return (numToys * 5);
        break;

    case 'K':
        return (numToys * 2);
        break;

    default:
        break;
    }
}

static void printEmployeeInfo(string name, int id, float income) {
    cout << "Employee name: " << name << endl;
    cout << "Employee ID: " << id << endl;
    cout << "Income for the month: " << income << endl;
}

int main() {
    string employeeName;
    int employeeId;
    char employeeType;
    float income;

    cout << "Please enter the employee's name:" << endl;
    cin >> employeeName;

    do {
        cout << "Please enter the employee's ID:" << endl;
        cin >> employeeId;
    } while (employeeId < 0);

    do {
        cout << "Please enter the employee code (G, K, S):" << endl;
        cin >> employeeType;
    } while (employeeType != 'G' && employeeType != 'K' && employeeType != 'S');

    switch (employeeType) {
    case 'G':
        income = fixedPaidWorker();
        break;

    case 'K':
        income = contractWorker();
        break;

    case 'S':
        income = subcontractWorker();
        break;

    default:
        break;
    }

    printEmployeeInfo(employeeName, employeeId, income);

    return 0;
}
