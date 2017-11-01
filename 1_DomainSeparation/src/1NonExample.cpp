// Kip DeCastro
// 10/31/17
// This is a crude login system for the Gibson, a theoretical super computer

#include <iostream>
using namespace std;
#include "1NonExample.h"

// Functionally clears the console
void cls(){
	
	cout << string( 100, '\n');
}

// Adds spaces to clean up input
void space(){
	
	cout << string( 10, '\n');
}

// Verifies administrator password and returns a pass or fail
bool adminPassword(){

	string passAttempt;
	cout << "Please enter the administrator password: ";
	cin >> passAttempt;
	if(passAttempt == adminPass){
		return 1;
	} else {
		return 0;
	}
}

// Displays a helpfile with a list of commands
void helpFile(){
	cls();
	cout << "Welcome to the Gibson's Helpfile. Here you will find some useful functions..."
		 << endl << endl
		 << gibLine << endl
		 << "\tstory\t\t: Read a fun story!" << endl
		 << "\tpasswd\t\t: Change the admin password" << endl
		 << "\tnuke\t\t: Nuke Russia or China. Start WWIII with panache!" << endl
		 << "\tusers\t\t: List all your fun friends who use the Gibson!" << endl
		 << "\tlogout\t\t: Logout, duh..." << endl
		 << gibLine << endl << cont << endl;
	space();
 	//system("pause");
 	cin.ignore().get();
	welcome(uname);
}

// An interface for nuking Russia or China
void nuke(){
	cls();
	char choice;
	cout << "Welcome to the Gibson's Nuclear command center. Rain down fiery justice. "
		 << endl << endl
		 << gibLine << endl;
		 cout << "\t1. Russia" << endl 
		 << "\t2. China" << endl
		 << "\t3. No one" << endl
		 << gibLine
		 << endl;
	space();
	if(!(cin >> choice)){
		cout << "Error! Invalid input!" << endl << cont;
		cin.ignore().get();
		nuke();
	} else if(choice == '1'){
		cls();
		cout << "I'm sure this couldn't end badly! " << endl << cont;
		nuked = nuked + " Russia";
	} else if(choice == '2'){
		cls();
		cout << "Great choice. We don't need manufacturing partners!" << endl << cont;
		nuked = nuked + " China";
	} else {
		cls();
		cout << "Boo. You're no fun..." << cont << endl;
	}
	cin.ignore().get();
	welcome(uname);
}

// Lists all the users on the system
void listUsers(){
	cls();
	cout << "Gibson Users" << endl;
	cout << gibLine << endl
		 << "HackerMan\tRole: Administrator" << endl
		 << "guest\t\tRole: guest" << endl << gibLine;
	space();
	cin.ignore().get();
	welcome(uname);
}

// Resets the admin password
void passwordReset(){
	string newPass;
	cls();
	cout << "Enter new admin password: ";
	cin >> newPass;
	adminPass = newPass;
	cout << "Password reset!" << endl << cont;
	cin.ignore().get();
	welcome(uname); 
}

// Tells a nice little story
void story(){
	cls();
	cout << "There once was a boy named billy..." << endl 
	<< "Billy fell right down the hilly..." << endl
	<< "He rolled around and smacked the ground..." << endl
	<< "He even busted his... (can you guess?)" << endl << cont;
	cin.ignore().get();
	cout << "shin!" << endl;
	cin.ignore().get();
	welcome(uname);
}

// Login menu
void login(){
	cls();
	string tempName;
	cout << "Welcome to the Gibson!\n\nPlease enter your username: ";
	cin >> tempName;
	if(tempName == "guest"){
		uname = tempName;
		welcome(uname);
	} else if(tempName == "HackerMan"){
		uname = tempName;
		if (adminPassword()){
			welcome(uname);
		} else {
			cout << "Password Incorrect." << endl << cont;
			cin.ignore().get();
			login();
		}
	} else {
		cout << "Username does not exist. To login as a guest, enter guest in the" 
			<< " username." << endl << cont;
		cin.ignore().get();
		login(); 
	}
}

int main(){
	login();
	return 0;
}

