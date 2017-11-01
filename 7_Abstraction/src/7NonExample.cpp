#include <iostream>
using namespace std;

int joeSolve(int x, int y){
	cout <<
	"..." << endl << "Oh and by the way, I'm sure you're interested to know that the memory addresses for that first number is "
		<< &x << ",\nand for that second number, its " << &y << ". \nOh yeah, here's that product, didja know that ts "; 
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