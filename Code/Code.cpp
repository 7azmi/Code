#include <iostream>
using namespace std;


static float fixedPaidWorker() {
    char workerType;
    float fixedSalary;

    cout << "Input worker type please. P = Manager, B = Non-Manager" << endl;
    do {
        cin >> workerType;
    } while (workerType != 'P' && workerType != 'B');

    cout << "Input worker fixed salary." << endl;
    do {
        cin >> fixedSalary;
    } while (fixedSalary <0);

    switch (workerType)
    {
    case 'P': //Manager
        return fixedSalary;

    case 'B': //Non-Manager

    int hours;
    float overtimePay;

        cout << "Hours worked: (additional)" << endl;
        do {
            cin >> hours;
        } while (hours < 0);

        if (hours <= 10) {
            overtimePay = (hours * 15);
        }
        else if (hours <= 20) {
            overtimePay = ((hours - 10) * 12) + 150;
        }
        else {
            overtimePay = 270; //maximum overtime pay
        }

        return fixedSalary + overtimePay;
    }

    return 0;//if you feel useless in life, just remember this line of code.
}

static float contractWorker() {
    float payment;
    int hours;
    char category;

    cout << "Please enter a category (B = Recovery, S = Maintainance)" << endl;
    do {
        cin >> category;
    } while (category != 'S' && category != 'B');

    cout << "Hours worked:" << endl;
    do {
        cin >> hours;
    } while (hours < 0);

    if(hours > 100) hours = 100;//limitation

    switch (category) {
    case 'S':
        if (hours <= 50) {
            payment = hours * 10;
        }
        else {
            payment = (((hours - 50) * 5) + 500);
        }
        break;
    case 'B':
        payment = hours * 20;
        break;
    }

    return payment;
}

static float subcontractWorker() {
    char toySize;
    int numToys;

    cout << "Type in the code for the size of the toy. ie, B - Large, S - Medium, K - small:" << endl;
    do {
        cin >> toySize;
    } while (toySize != 'B' && toySize != 'S' && toySize != 'K');

    cout << "Insert number of toys made this month:" << endl;
    do {
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
    //(:
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

        cout << "Please enter the employee's ID:" << endl;
    do {
        cin >> employeeId;
    } while (employeeId < 0);

        cout << "Please enter the employee code (G, K, S):" << endl;
    do {
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
