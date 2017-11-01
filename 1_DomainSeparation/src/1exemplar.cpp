// Kip DeCastro
// 10/12/17
// 
// This code demonstrates code separation by way of having separate unit tests
// that test the programs functioning outside of actual data input.
#include <string>
#include <iostream>
using namespace std;
class Parent{
public:
	string pub = "This is public and accessible by anyone";
	string getPriv(){
		return priv;
	}
	string getProt(){
		return prot;
	}
private:
	string priv = "This is private and only accessible by this class";	

protected:
	string prot = "This is protected and accesible by this class and its children";
};

class Child : Parent {

};

string stringTester(string test){
	if(cin >> test){
		return test;
	} else { 
		return "Invalid";
	}
}

int main(){
	Parent daddy;
	Child son;

	cout << "Accessing the various strings stored in our classes..." << endl;
	cout << "Attempting to access pub from Parent..." << endl;
	cout << "Pub: ";
	try{ cout << daddy.prot; } catch(...){"Invalid";} 
	cout << endl;
	cout << "Attempting to access priv from Parent..." << endl;
	//cout << "Priv: " << stringTester(daddy.priv) << endl;
	cout << "Attempting to access prot from Parent..." << endl;
	//cout << "Prot: " << stringTester(daddy.prot) << endl;
}

