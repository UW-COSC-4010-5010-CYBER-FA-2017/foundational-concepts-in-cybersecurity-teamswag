#include <iostream>
using namespace std;

int main(){
	int num;
	int num2 = 0;
	bool tf = 0;
	cout << "Give me a number and I'll tell you if its even or odd: ";
	cin >> num;
	while(num2 < num){
		num2 = num2 + 2;
	}
	if(num2 == num){
		tf = 1;
	}
	
	cout << num << endl;
	
	if(tf == 1){
		cout << "Even" << endl;
	} else {
		cout << "Odd" << endl;
	}
}