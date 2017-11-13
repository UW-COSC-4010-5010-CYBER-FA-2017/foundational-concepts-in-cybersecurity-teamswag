#include <iostream>
using namespace std;

int main(){
	int num;
	cout << "Give me a number and I'll tell you if its even or odd: ";
	cin >> num;
	if(num % 2 == 0){
		cout << "Even" << endl;
	} else {
		cout << "Odd" << endl;
	}
}