#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string c = "1";
	string d = "123";
	int a = stoi(c);
	int b = stoi(d);
	
	cout << a << " + " << b << " = " << a+b << endl;
}
