string uname;
string adminPass("hunter2");

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

void options(){
	string input;
	cin >> input;
	if(input == "passwd"){
		passwordReset();
	} else if(input == "nuke"){
		if(uname == "HackerMan"){
			nuke();
		} else {
			cout << "Unauthorized Access!!" << endl << cont;
			options();
		}
	} else if(input == "story"){
		story();
	} else if(input == "logout"){
		login();
	} else if(input == "users"){
		listUsers();
	} else {
		helpFile();
	}
}

void welcome(string username){
	cls();
	
	if(username == "HackerMan"){
		cout << "Countries nuked today:" << nuked << endl;
		cout << "Welcome, O great and powerful admin. What can I do for you today? "
			<< endl << shell << uname << "$ ";
	} else {
		cout << "Countries nuked today:" << nuked << endl;
		cout << "Welcome " << uname << "!"
			<< endl << shell << uname << "$ ";
	}

	options();
}



