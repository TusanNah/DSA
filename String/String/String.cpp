#include "string"
#include "iostream"
#include "stringstream"
using namespace std;
void main() {
	string a = "abcdef";
	string b = "b";
	string c = a + b;
	string d = a.substr(2, 3); //2 is the first index which will be cut in string,				
	cout << c;		//3 is the number of char which will be cut from the first index		
	cout << endl << d;
	string s = "java c++ python c#";
	stringstream ss(s);
	string temp;
	while (ss) {

	}
}