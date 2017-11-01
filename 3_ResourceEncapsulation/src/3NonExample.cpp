#include <iostream>
#include <string>
using namespace std;

class Sally{
public:
	string getSecret();
	string secret = "I like long walks on the beach and I once mugged a small child";
};

string Sally::getSecret(){
	return secret.substr(0,30);
}

int main(){
	Sally sal;
	cout << "Announcer: Sally, tell us your secret!" << endl << endl;
	cout << "Sally: Well, " << sal.secret << ". How about you?"<< endl << endl;
	return 0;
}