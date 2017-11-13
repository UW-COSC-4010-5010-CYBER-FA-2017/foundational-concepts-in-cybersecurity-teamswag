// Kip DeCastro
// 10/31/17
// This is a crude login system for the Gibson, a theoretical super computer

#include <iostream>

using namespace std;
#include "1Exemplar.h"



// Functionally clears the console
void cls(){
	
	cout << string( 100, '\n');
}

// Adds spaces to clean up input
void space(){
	cout << string( 5, '\n');
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
		 << "\tstory\t\t: Read a fun story!" << endl;
		 if(privCheck(1)){
		 	cout << "\tpasswd\t\t: Change user passwords" << endl;
		 }
		 if(privCheck(1)){
		 	cout << "\tcreate\t\t: Create new users" << endl;
		 }
		 if(privCheck(3)){
		 	cout << "\tnuke\t\t: Nuke Russia or China. Start WWIII with panache!" << endl;
		 }
	cout << "\tusers\t\t: List all your fun friends who use the Gibson!" << endl
		 << "\tlogout\t\t: Logout, duh..." << endl
		 << gibLine << endl << cont << endl;
	space();
 	//system("pause");
 	cin.ignore().get();
	welcome(currentUser.name);
}


void createUser(){
	string tmpName;
	string tmpPass;
	int tmpPriv;
	bool tf = 1;
	User tmpUser;
	cout << "Welcome to the Gibson's user creation portal!" << endl
		 << gibLine << endl
		 << "Username: ";
	cin >> tmpName;
	for(int i = 0; i < userVect.size(); i++){
		if(userVect[i].name == tmpName){
			tf = 0;
		}
	}
	while(!tf){
		cout << "User already exists!! Try a different username." << endl;
		tf = 1;
		cout << "Username: ";
		cin >> tmpName;
		for(int i = 0; i < userVect.size(); i++){
			if(userVect[i].name == tmpName){
				tf = 0;
			} 
		}
	}
	cout << "Password: ";
	cin >> tmpPass;
	tf = 1;
	cout << "Privelege Level: ";
	cin >> tmpPriv;

	if(tmpPriv > currentUser.priv){
		tf = 0;
	}

	while(!tf){
		cout << "Privelege level too high! Try again!" << endl;
		tf = 1;
		cout << "Privelege Level: ";
		cin >> tmpPriv;
		if(tmpPriv > currentUser.priv){
			tf = 0;
		}
	}
	cout << endl << endl;
	tmpUser.name = tmpName;
	tmpUser.pass = tmpPass;
	tmpUser.priv = tmpPriv;
	userVect.push_back(tmpUser);
	cout << "User " << userVect.back().name << " created!!" << endl << cont;
	cin.ignore().get();
	welcome(currentUser.name);
}

// An interface for nuking Russia or China
void nuke(){
	string tempName;
	string tempPass;
	cls();
	char choice;
	cout << "Re-Enter Username: ";
	cin >> tempName;
	cout << "Re-Enter Password: ";
	cin >> tempPass;
	if(tempName != currentUser.name || tempPass != currentUser.pass){
		cout << "Invalid credentials!!";
		login();
	}
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
	welcome(currentUser.name);
}

// Lists all the users on the system
void listUsers(){
	cls();
	cout << "Gibson Users" << endl;
	cout << gibLine << endl;
	for(int i = 0; i < userVect.size(); i++){
		if(userVect[i].priv <= currentUser.priv){
			cout << "\tName: " << userVect[i].name << endl << "\tRole: ";
			if(userVect[i].priv > 0){
				cout << "Admin"; 
			} else {
				cout << "User";
			}
			if(currentUser.priv > 0){
				cout << endl << "\tPrivelege Level: " << userVect[i].priv;
			}
			cout << endl << endl;
		}
	}
	cout << gibLine << endl << cont << endl;
	space();
	cin.ignore().get();
	welcome(currentUser.name);
}

// Resets the admin password
void passwordReset(){
	string newPass;
	string tempName;
	cout << "Username? ";
	cin >> tempName;
	for(int i = 0; i < userVect.size(); i++){
		if(tempName == userVect[i].name){
			if(userVect[i].priv < currentUser.priv || userVect[i].name == currentUser.name){
				cout << "New password:";
				cin >> newPass;
				userVect[i].pass = newPass;
				cout << "Password Changed!";
			} else {
				cout << "User not found!";
			}
		} else {
			cout << "User not found!";
		}
	}
	cin.ignore().get();
	welcome(currentUser.name); 
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
	string tempPass;
	cout << "Welcome to the Gibson!\n\nPlease enter your username: ";
	cin >> tempName;
	cout << "Password: ";
			cin >> tempPass;
	for(int i = 0; i < userVect.size(); i++){
		if(userVect[i].name == tempName){
			if(userVect[i].pass == tempPass){
				currentUser = userVect[i];
				welcome(currentUser.name);
			}
		}
		
		
	}
	cout << "Invalid credentials! Try username: guest password: guest" << endl << cont;
	cin.ignore().get();
	login();
}

int main(){
	userVect.push_back(defaultAdmin);
	userVect.push_back(guest);
	login();
	return 0;
}

