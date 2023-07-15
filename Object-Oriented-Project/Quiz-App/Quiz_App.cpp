#include<iostream>
using namespace std;

int playQuiz();

int main()
{
	play:
	int final=0;
	int playQuiz(void);
	char playagain;
	
	final = playQuiz();
	cout << "Your Total Score is : " << final << endl;
	
	if(final >= 6) {
		cout << "You are Pass" << endl;
		cout << "Do You Wantto Play QUIZ again 'y' or 'n' " << endl;
		cin >> playagain;
		if(playagain == 'y' || playagain == 'Y') {
			playQuiz();
		}else{
			cout << "Thank You To Play QUIZ..." << endl;
		}
	}else{
		cout << "You are Fail" << endl;
		cout << "Do You Wantto Play QUIZ again 'y' or 'n' " << endl;
		cin >> playagain;
		if(playagain == 'y' || playagain == 'Y') {
			goto play;
		}else{
			cout << "Thank You To Play QUIZ..." << endl;
		}
	}
	
	return 0;
}

int playQuiz() {
	playinsidefunc:
	char c;
	char option;
	int score = 0;
	
	cout << "---------- WelCome To Quiz Game -----------" << endl;
	cout << "------ Please Follow The Instruction ------" << endl;
	cout << "Step 1 : Quix Contains Total 10 Question : " << endl;
	cout << "Step 2 : You Will Given 1 Marks For Each Right ANSWER " << endl;
	cout << "Step 3 : There Will be No Nagative Marking " << endl;
	cout << "Step 4 : Please Press 's' To Start The Quiz " << endl;
	cout << "Step 5 : Please Select Option a, b, c, d " << endl;
	cout << "Step 6 : If You Score >=6, You Will Pass The Quiz " << endl;
	
	cin >> c;
	if(c == 's' || c == 'S') {
		cout << "Q1. What is The Captial Of India" << endl;
		cout << "(a) Delhi (b) Mumbai (c) Kolkata (d) Channai" << endl;	
		cin >> option;
		if(option == 'a' || option == 'A') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
		cout << "Q2. Who is The Prime Minister Of India" << endl;
		cout << "(a) Narendra Modi (b) Aditynath (c) Kerjriwal (d) Yesh Patel " << endl;	
		cin >> option;
		if(option == 'a' || option == 'A') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
		cout << "Q3. What is The Natinal Bird Of India" << endl;
		cout << "(a) Pigen (b) Peacock (c) Sparrow (d) Parrot" << endl;	
		cin >> option;
		if(option == 'b' || option == 'B') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
		cout << "Q4. What is The National Animal Of India" << endl;
		cout << "(a) Dog (b) Zebra (c) Lion (d) Tiger" << endl;	
		cin >> option;
		if(option == 'd' || option == 'D') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
		cout << "Q5. What is The National Flower Of India" << endl;
		cout << "(a) Lotus (b) Rose (c) Lily (d) Sunflower" << endl;	
		cin >> option;
		if(option == 'a' || option == 'A') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
		cout << "Q6. Who is The Chief Minister Of UP" << endl;
		cout << "(a) Aditynath (b) Kejriwal (c) Yesh Patel (d) Rahul Gandhi" << endl;	
		cin >> option;
		if(option == 'a' || option == 'A') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
		cout << "Q7. What is The Captial Of Gujrat" << endl;
		cout << "(a) Amreli (b) Surat (c) Rajkot (d) Gandhi nager " << endl;	
		cin >> option;
		if(option == 'd' || option == 'D') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
		cout << "Q8. What is The Captial Of Jharkhand" << endl;
		cout << "(a) Dhanbad (b) Ranchi (c) Ramgarh (d) Patana" << endl;	
		cin >> option;
		if(option == 'b' || option == 'B') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
		cout << "Q9. Who is The Leader Of Congress " << endl;
		cout << "(a) Rohan (b) Narendra (c) Rahul (d) Sonia" << endl;	
		cin >> option;
		if(option == 'c' || option == 'C') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
		cout << "Q10. Which One Of The Following State Comes in North India" << endl;
		cout << "(a) Delhi (b) Banglore (c) Keral (d) Channai" << endl;	
		cin >> option;
		if(option == 'a' || option == 'A') {
			score = score + 1;
		}else{
			score = score + 0;
		}
		
	}else{
		cout << "You Have Enterd Wrong Value, Please Enter 's' To Start" << endl;
		goto playinsidefunc;
	}
	
	return score;
}