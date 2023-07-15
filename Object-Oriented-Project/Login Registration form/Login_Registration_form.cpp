#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forget();

int main()
{
	int c;
	cout << "\t\t\t___________________________________________________________________\n\n\n";
	cout << "\t\t\t                        Welcome To Login Page                      \n\n\n";
	cout << "\t\t\t_________________________        MENU       _______________________\n\n";
	cout << "\t| Press 1 : LOGIN                        |"<<endl;
	cout << "\t| Press 2 : REGISTER                     |"<<endl;
	cout << "\t| Press 3 : You Forget Your PASSWORD     |"<<endl;
	cout << "\t| Press 4 : EXIT                         |"<<endl;
	cout << "\n\t\t\t Please Enter Your Choice : ";
	cin >> c;
	cout << endl;
	
	switch(c)
	{
		case 1 :
				login();
				break;
		case 2 : 
				registration();
				break;
		case 3 :
				forget();
				break;
		case 4 :
				cout << "\t\t\t Thank You \n\n";
				break;
		default :
			system("cls");
			cout << "\t\t\t Please Select From The Option Given Above \n"<<endl;
			main();
	}	
	return 0;
}

void login()
{
	int count;
	string userId, password, id, pass;
	system("cls");
	cout << "\t\t\t Please Enter The Username and Password : "<<endl;
	cout << "\t\t\t USERNAME  : ";
	cin >> userId;
	cout << "\t\t\t PASSWORD  : ";
	cin >> password;
	
	ifstream input("records.txt");
	
	while(input>>id>>pass)
	{
		if(id==userId && pass==password)
		{
			count=1;
			system("cls");
		}
	}
	input.close();
	
	if(count==1) 
	{
		cout << userId << "\n Your LOGIN is Successfull \n Thanks For Logging in ! \n";
		main();	
	}else{
		cout << "\n LOGIN ERROR \n Please Check Your Username and Password \n";
	}
}

void registration()
{
	string ruserId, rpassword, rid, rpass;
	system("cls");
	cout << "\t\t\t Enter The Username : ";
	cin >> ruserId;
	cout << "\t\t\t Enter The Password : ";
	cin >> rpassword;
	
	ofstream f1("records.txt", ios::app);
	f1<<ruserId<<' '<<rpassword<<endl;
	system("cls");
	cout << "\n\t\t\t Registration is Successfull! \n";
	main();
}

void forget()
{
	int option;
	system("cls");
	cout << "\t\t\t You Forget Password? No Worries \n";
	cout << "Press 1 : Search Your Id by Username " << endl;
	cout << "Press 2 : Go Back to The Main Menu "<< endl;
	cout << "\t\t\t Enter Your Choice : ";
	cin >> option;
	
	switch(option)
	{
		case 1 :{
			int count=0;
			string suserId, sid, spass;
			cout << "\n\t\t\t Enter The Username which you Remembered : ";
			cin >> suserId;
			ifstream f2("records.txt");
			while(f2>>sid>>spass)
			{
				if(sid==suserId)
				{
					count=1;
				}
			}
			f2.close();
			if(count==1) 
			{
				cout << "\n\n Your Account is Found! \n";
				cout << "\n\n Your Password is : " << spass<<endl;
				main();
			}else{
				cout << "\n\t Sorry! Your Account is not Found! \n";
				main();
			}
			break;
		}
		case 2 :{
			main();
			break;
		}
		default :
			cout << "\t\t\t Wrong Choice ! Please Try Again "<<endl;
			forget();
	}
}
