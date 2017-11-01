// header file for gibsonLogin.cpp
// Simple struct to store user name and privelege level
#include <vector>

struct User{
	string name;
	string pass;
	int priv;
};

string adminName = "HackerMan";
string adminPass("hunter2");

vector<User> userVect;

User defaultAdmin = {"HackerMan", "hunter2", 3};
User guest = {"guest", "guest", 0};



User currentUser;



string uname;


string shell("DaGibson:~ ");
string nuked("");
string gibLine("-----------------------------------------------------------------------------");
string cont("Press enter to continue...");

void cls();
void login();
bool adminPassword();
void helpFile();
void nuke();
void listUsers();
void passwordReset();
void story();
void createUser();

bool privCheck(int tmpPriv){
	if(currentUser.priv >= tmpPriv){
		return 1;
	} else {
		return 0;
	}
}

// Gets user input in the form of strings
void options(){
	string input;
	cout << endl << shell << uname << "$ ";
	cin >> input;
	if(input == "passwd"){
		if(privCheck(1)){
			passwordReset();
		} else {
			cout << "Command not recognized. To see the HelpFile, try 'help'!";
			options();
		}
	} else if(input == "nuke"){
		if(privCheck(3)){
			nuke();
		} else {
			cout << "Command not recognized. To see the HelpFile, try 'help'!";
			options();
		}
	} else if(input == "story"){
		story();
	} else if(input == "logout"){
		login();
	} else if(input == "create"){
		if(privCheck(1)){
			createUser();
		} else {
			cout << "Command not recognized. To see the HelpFile, try 'help'!";
			options();
		}
		
	} else if(input == "users"){
		listUsers();
	} else if(input == "help") {
		helpFile();
	} else {
		cout << "Command not recognized. To see the HelpFile, try 'help'!";
		options();
	}
}

// Welcomes user and provides a baby bash
void welcome(string username){
	cls();
	
	if(currentUser.priv > 0){
		cout << "Countries nuked today:" << nuked << endl;
		cout << "Welcome, O great and powerful " << currentUser.name;
	} else {
		cout << "Welcome " << currentUser.name;
	}
	options();
}



