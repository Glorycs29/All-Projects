#include<iostream>
using namespace std;

int addition(void);
int multification(void);
int subtraction(void);
float division(void);
float modulo(void);

int main()
{
    start:
    cout << "---------------------- WELCOME TO OUR CALCULATOR APPLICATION -------------------------" << endl;
    cout << "*************************Please Follow The Instruction ******************************"<< endl;
    cout << "\t\t\t 1. Please Press 'A' for Addition " << endl;
    cout << "\t\t\t 2. Please Press 'S' for Subtraction " << endl;
    cout << "\t\t\t 3. Please Press 'M' for Multification " << endl;
    cout << "\t\t\t 4. Please Press 'D' for Division " << endl;
    cout << "\t\t\t 5. Please Press 'O' for Modulo " << endl;
    cout << "\t\t\t 6. Please Press 'E' for EXIT " << endl;
    selectagain:
    cout << "\n\n\t Select : ";
    char value, again;
    cin >> value;
    
    if (value == 'a' || value == 'A')
    {
        int add = addition();
        cout << "\n\n\t\t Addition is : " << add << endl << endl;
        cout << "\nDo You Want to use our Application Again (Y or N) ?" << endl;
        cin >> again;
        if(again == 'Y' || again == 'y') {
            goto start;
        }else if(again == 'N' || again == 'n') {
            cout << "\n\n\t\t********* Thank You to Using Application *************" << endl;
            cout << "\n\t\t Created By Parth " << endl;
        }else{
            cout << "\n\t You have Entered Wrong Choice Please Enter (y or n)" << endl;
            goto selectagain;
        }
    }
    else if (value == 'm' || value == 'M')
    {
        int mul = multification();
        cout << "\n\n\t\t Multification is : " << mul << endl << endl;
        cout << "\nDo You Want to use our Application Again (Y or N) ?" << endl;
        cin >> again;
        if(again == 'Y' || again == 'y') {
            goto start;
        }else if(again == 'N' || again == 'n') {
            cout << "\n\n\t\t********* Thank You to Using Application *************" << endl;
            cout << "\n\t\t Created By Parth " << endl;
        }else{
            cout << "\n\t You have Entered Wrong Choice Please Enter (y or n)" << endl;
            goto selectagain;
        }
    }else if (value == 's' || value == 'S') {
        int sub = subtraction();
        cout << "\n\n\t\t Subtraction is : " << sub << endl << endl;
        cout << "\nDo You Want to use our Application Again (Y or N) ?" << endl;
        cin >> again;
        if(again == 'Y' || again == 'y') {
            goto start;
        }else if(again == 'N' || again == 'n') {
            cout << "\n\n\t\t********* Thank You to Using Application *************" << endl;
            cout << "\n\t\t Created By Parth " << endl;
        }else{
            cout << "\n\t You have Entered Wrong Choice Please Enter (y or n)" << endl;
            goto selectagain;
        }
    }else if (value == 'd' || value == 'D') {
        float div = division();
        cout << "\n\n\t\t Division is : " << div << endl << endl;
        cout << "\nDo You Want to use our Application Again (Y or N) ?" << endl;
        cin >> again;
        if(again == 'Y' || again == 'y') {
            goto start;
        }else if(again == 'N' || again == 'n') {
            cout << "\n\n\t\t********* Thank You to Using Application *************" << endl;
            cout << "\n\t\t Created By Parth " << endl;
        }else{
            cout << "\n\t You have Entered Wrong Choice Please Enter (y or n)" << endl;
            goto selectagain;
        }
    }else if (value == 'o' || value == 'O') {
        float mod = modulo();
        cout << "\n\n\t\t Modulo is : " << mod << endl << endl;
        cout << "\nDo You Want to use our Application Again (Y or N) ?" << endl;
        cin >> again;
        if(again == 'Y' || again == 'y') {
            goto start;
        }else if(again == 'N' || again == 'n') {
            cout << "\n\n\t\t********* Thank You to Using Application *************" << endl;
            cout << "\n\t\t Created By Parth " << endl;
        }else{
            cout << "\n\t You have Entered Wrong Choice Please Enter (y or n)" << endl;
            goto selectagain;
        }
    }else if(value == 'E' || value == 'e' ) {
        cout << "\n\n\t\t********* Thank You to Using Application *************" << endl;
        cout << "\n\t\t Created By Parth " << endl;
        exit(0);
    }else{
        cout << "\n\t You have Entered Wrong Choice Select : \n" << endl;
        goto start;
    }



    return 0;
}

int addition() {
    int a, total = 0;
    char ch;
    add:
    cout << "\n\tEnter a Number : ";
    cin >> a;
    total = total + a;
    selectagain:
    cout << "\tDo you want to add more numbers, (Y or N) : ";
    cin >> ch;
    if(ch == 'Y' || ch == 'y') {
        goto add;
    }else if(ch == 'N' || ch == 'n') {
        return total;
    }else{
        cout << "\n\t You have Entered Wrong Choice Please Enter (y or n)" << endl;
        goto selectagain;
    }
    return total;
}

int subtraction() {
    int a, b, total=0;
    char ch;
    cout << "\n\tEnter A Number : ";
    cin >> a;
    cout << "\n\tEnter B Number : ";
    cin >> b;
    if(a > b) {
        total = a - b;
    }else{
        total = b - a;
    }
    return total;
}

int multification() {
    int a, total = 1;
    char ch;
    mul:
    cout << "\n\tEnter a Number : ";
    cin >> a;
    total = total * a;
    selectagain:
    cout << "\tDo you want to multiply more numbers, (Y or N) : ";
    cin >> ch;
    if(ch == 'Y' || ch == 'y') {
        goto mul;
    }else if(ch == 'N' || ch == 'n') {
        return total;
    }else{
        cout << "\n\t You have Entered Wrong Choice Please Enter (y or n)" << endl;
        goto selectagain;
    }
    return total;
}

float division() {
    float a, b;
    float total;
    char ch;
    cout << "\n\tEnter A Number : ";
    cin >> a;
    cout << "\n\tEnter B Number : ";
    cin >> b;
    if(a > b) {
        total = a / b;
    }else{
        total = b / a;
    }
    return total;
}

float modulo() {
    int a, b;
    float total;
    char ch;
    cout << "\n\tEnter A Number : ";
    cin >> a;
    cout << "\n\tEnter B Number : ";
    cin >> b;
    if(a > b) {
        total = a % b;
    }else{
        total = b % a;
    }
    return total;
}