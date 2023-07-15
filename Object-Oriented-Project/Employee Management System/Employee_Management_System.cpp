#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include<unistd.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;

class Employee_management {
	private:
		char name[30];
		char id[5];
		char designation[10];
		int age, ctc;
		char experience[20];
		
	public:
		void menu();
		void waitForEnter();
		void insert();
		void display();
		void modify();
		void search();
		void deleted();
};

void Employee_management::menu()
{
	int password_user();
	password_user();
	while(true)
	{
		int choice;
		char x;
		system("cls");
			cout << "\n\t\t\t-------------------------------------------------------";
			cout << "\n\t\t\t>>               EMPLOYEE MANGEMENT SYSTEM             <<";
			cout << "\n\t\t\t-------------------------------------------------------";
		cout << "\n\t\t\t\t 1. Enter New Record " <<endl;
		cout << "\n\t\t\t\t 2. Display Record " <<endl;
		cout << "\n\t\t\t\t 3. Modify Record " <<endl;
		cout << "\n\t\t\t\t 4. Search Record " <<endl;
		cout << "\n\t\t\t\t 5. Delete Record " <<endl;
		cout << "\n\t\t\t\t 6. Exit " <<endl;
		
			cout << "\n\t\t\t......................................................." << endl;
			cout << "\n\t\t\t>>	    	Choose Option: [1/2/3/4/5/6]    	<<" <<endl;
			cout << "\n\t\t\t......................................................." << endl;
		cout << "\n Enter Your Choice : ";
		cin>>choice;
	
		switch(choice)
		{
			case 1:
				do{
					insert();
					cout << "\n\n\t\t\t Add Another Employee Record Press (Y, N) : ";
					cin >> x;
				}while(x=='y' || x=='Y');
				waitForEnter();
				break;
			case 2:
				display();
				break;
			case 3:
				modify();
				break;
			case 4:
				search();
				break;
			case 5:
				deleted();
				break;
			case 6:
				system("cls");
				cout << "\n\n\n\n\t--------------------------------------------------------------------------"<<endl;
				cout << "\n\t\t\t>> EMPLOYEE MANAGEMENT SYSTEM - By Parth Developer <<";
				cout << "\n\n\t--------------------------------------------------------------------------"<<endl;
				for(int i=10; i>=1; i--) {
					cout << i << " Second remaining...\r" << flush;
					sleep(1);
				}
				exit(0);
				break;
			default:
				cout << "\n\n\n\t\t\t\t Invaild Choice... Please Try Again... \n";
		}
		getch();
	}
}

void Employee_management::insert()
{
	system("cls");
	fstream file;
	cout << "\n--------------------------------------------------------------------------"<<endl;
	cout << "--------------------------------Employee Insert Data----------------------"<<endl;
	cout << "\n Enter Name of Employee : ";
	cin >> name;
	cout << "\n Enter Employee ID [max 4 digits] : ";
	cin >> id;
	cout << "\n Enter Designation : ";
	cin >> designation;
	cout << "\n Enter Employee Age : ";
	cin >> age;
	cout << "\n Enter Employee CTC : ";
	cin >> ctc;
	cout << "\n Enter Employee Experience : ";
	cin >> experience;
	file.open("Employee_Record.txt", ios::app | ios::out);
	file << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
	file.close();
}

void Employee_management::display()
{
	system("cls");
	int total = 1;
	fstream file;
	cout << "\n\t\t\t\t-------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t-------------------------- Employee Record Data -------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
	if(!file)
	{
		cout << "\n\t\t\t No Data is Present...";
		file.close();
	}
	else{
		file >> name >> id >> designation >> age >> ctc >> experience;
		cout << "\n---------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n||	NAME   ||	 ID   ||	 DESIGNATION	  ||	  AGE   ||   CTC   ||	EXPERIENCE	 ||";
		cout << "\n---------------------------------------------------------------------------------------------------------------------" << endl;
		while(!file.eof())
		{
			cout << "\n";
			cout << total++ << ". " << name << "\t\t " << id << "\t\t " << designation << "\t\t\t " << age << "\t\t " << ctc << "\t\t " << experience << "\n";
			file >> name >> id >> designation >> age >> ctc >> experience;
		}
	}
	cout << "\n\n\n";
	for(int i=10; i>=1; i--) {
		cout << i << " Second remaining...\r" << flush;
		sleep(1);
	}
	file.close();
	waitForEnter();
}

void Employee_management::modify()
{
	system("cls");
	char checkId[5];
	int found = 0;
	fstream file, file1;
	cout << "\n------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Employee Modify Data -----------------------------" << endl;
	file.open("Employee_Record.txt",ios::in);
	if(!file) {
		cout << "\n\t\t No Data is Present....";
		file.close();
	}
	else{
		cout << "\nEnter Employee id : ";
		cin >> checkId;
		file1.open("record.txt", ios::app | ios::out);
		file >> name >> id >> designation >> age >> ctc >> experience;
		while(!file.eof()) {
			if(strcmp(checkId, id) == 0)
			{
				cout << "\n Enter Name of Employee : ";
				cin >> name;
				cout << "\n Enter Employee ID [max 4 digits] : ";
				cin >> id;
				cout << "\n Enter Designation : ";
				cin >> designation;
				cout << "\n Enter Employee Age : ";
				cin >> age;
				cout << "\n Enter Employee CTC : ";
				cin >> ctc;
				cout << "\n Enter Employee Experience : ";
				cin >> experience;
				cout << "\n\n Successfully Modify Details of Employee";
				file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";
				found++;
			}
			else{
				file1 << " " << name << " " << id << designation << " " << age << " " << ctc << " " << experience << "\n";
			}
			file >> name >> id >> designation >> age >> ctc >> experience;
		}
		if(found == 0) {
			cout << "\n\n\t Employee ID Not Found... Please Try Again ";
		}
		file1.close();
		file.close();
		remove("Employee_Record.txt");
		remove("record.txt");
	}
	waitForEnter();
}

void Employee_management::search()
{
	system("cls");
	fstream file; 
	char checkId[5];
	cout << "\n----------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------ Employee Search Data -------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
	cout << "\n\n Enter Employee ID : ";
	cin >> checkId;
	if(!file) {
		cout << "\n\t\t\t No Data is Present... ";
		file.close();
	}
	else{
			file >> name >> id >> designation >> age >> ctc >> experience;	
			while(!file.eof())
			{
				if(strcmp(checkId, id) == 0)
				{
					cout << "\n------------------------------\n\n";
					cout << "Employee Name: " << name << endl;
					cout << "Employee ID: " << id << endl;
					cout << "Employee Designation: " << designation << endl;
					cout << "Employee Age: " << age << endl;
					cout << "Employee CTC: " << ctc << endl;
					cout << "Employee Exprience: " << experience << endl;
					cout << "\n------------------------------\n";
				}
				file >> name >> id >> designation >> age >> ctc >> experience;	
			}
	}
	for(int i=10; i>=1; i--) {
		cout << i << " Second remaining...\r" << flush;
		sleep(1);
	}
	file.close();
	waitForEnter();
}

void Employee_management::deleted()
{
	system("cls");
	char checkId[5];
	fstream file, file1;
	int found = 0;
	cout << "\n----------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------ Employee Delete Data -------------------------------------" << endl;
	file.open("Employee_Record.txt", ios::in);
	if(!file) {
		cout << "\n\t\t\t No Data is Present... ";
		for(int i=5; i>=1; i--) {
			cout << i << " Second remaining...\r" << flush;
			sleep(1);
		}
		file.close();
	}
	else{
		cout << "\nEnter Employee Id To Remove Data : ";
		cin >> checkId;
		file1.open("record.txt", ios::app | ios::out);
		file >> name >> id >> designation >> age >> ctc >> experience;	
		while(!file.eof())
		{
			if(strcmp(checkId, id) != 0)
			{
				file1 << " " << name << " " << id << " " << designation << " " << age << " " << ctc << " " << experience << "\n";		
			}else{
				found++;
				cout << "\n\t\t\t Successfully Delete Data";
			}
			file >> name >> id >> designation >> age >> ctc >> experience;
		}
		if(found == 0) {
			cout << "\n\n\t Employee ID Not Found... Please Try again";
		}
		cout << "\n\n\n";
		for(int i=5; i>=1; i--) {
			cout << i << " Second remaining...\r" << flush;
			sleep(1);
		}
		file1.close();
		file.close();
		remove("Employee_Record.txt");
		remove("record.txt");
	waitForEnter();
	}
}

void Employee_management::waitForEnter()
{
	cout << "\n\n Press enter to go back : ";
	cin.get();
}

int password_user()
{
	string pass_reg = "";
	string name_reg = "";
	string pass = "";
	string name = "";
	fstream file;
	char ch;
	system("cls");
	
	cout << "\n\t\t\t-------------------------------------------------------";
	cout << "\n\t\t\t||       WELCOME TO EMPLOYEE MANGEMENT SYSTEM         ||";
	cout << "\n\t\t\t-------------------------------------------------------";
	cout << "\n\t\t		 -| Press: [1] Register & [2] Login |-";
	
	int selection;
	cout << "\n\n Please Enter Value : ";
	cin >> selection;
	
	// if user press 1 then register
	if(selection == 1) 
	{
		system("cls");
		cout << "\n\t\t\t\t-------------------------------";
		cout << "\n\t\t\t\t>>	REGISTRATION EMPLOYEE	<<";
		cout << "\n\t\t\t\t-------------------------------";
		cout << "\n\n\t\t\t\t Enter Your Name : ";
		cin >> name_reg;
		cout << "\n\t\t\t\t Enter Your Password : ";
		ch = _getch();
		while(ch != 13)
		{
			pass_reg.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		
		file.open("Ep_data.txt",ios::app);
		file<< " " << name_reg << " " << pass_reg << "\n";
		file.close();
		cout << " \n Registration Succesfully Save...";
		getch();
		password_user();
	}
	else if(selection == 2)
	{
		// if user press 2 then login
		system("cls");
		file.open("Ep_data.txt",ios::in);
		cout << "\n\t\t\t\t---------------------------------";
		cout << "\n\t\t\t\t>>	  LOGIN EMPLOYEE    <<";
		cout << "\n\t\t\t\t---------------------------------";
		cout << "\n\n\t\t\t\t Enter Your Name : ";
		cin >> name;
		cout << "\n\t\t\t\t Enter Your Password : ";
		ch = _getch();
		while(ch != 13)
		{
			pass.push_back(ch);
			cout << '*';
			ch = _getch();
		}
		file >> name_reg >> pass_reg;
		while(!file.eof())
		{
			if(pass == pass_reg && name == name_reg)
			{
				cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
				for(int a=1; a<8; a++)
				{
					Sleep(500);
					cout << "...";
				}
				cout << "\n\n Acessed Granted.. \n\n";
				system("PAUSE");
				system("cls");
				break;
			}else{
				cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
				for(int a=1; a<8; a++)
				{
					Sleep(500);
					cout << "...";
				}
				cout << "\n\n Acess Aborted.. \n\n";
				system("PAUSE");
				system("cls");
				password_user();
			}
			file >> name_reg >> pass_reg;
		}		
		file.close();
	}
	else
	{
		cout << "\nInvaild Input Plase try Again..\n";
		password_user();
	}
	
	return 0;
}

int main()
{
	Employee_management system;
	system.menu();
	
	
	
	return 0;
}