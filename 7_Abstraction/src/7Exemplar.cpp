#include <iostream>
using namespace std;

int joeSolve(int x, int y){
	return x * y;
}

int main(){
	int i;
	int j;
	cout << "Joe: Hey man, hows it going? Gimme a number!\nYou: ";
	cin >> i;
	cout << "Joe: K. Gimme another one!\nYou: ";
	cin >> j;
	cout << "Joe: Didja know that " << i << " times " << j << " is " << joeSolve(i,j)
		<< "?" << endl;
}