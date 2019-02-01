#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <list>
#include <exception>
#include <cstring>

using namespace std;

int main(){
	
	char ia[] = "Hello World"; 
	string str(ia, 7);
	cout << str << endl;
	string temp(str, 3);   // It's different between wether the first argument is a string or char*.
	cout << temp << endl;
	string temp2(ia, 6, 5);
	cout << temp2 << endl;

	string temp3 = str.substr(1, 6); //starting from pos 1, has 5 characters
	cout << temp3 << endl;
	string temp4 = str.substr(2);
	cout << temp4 << endl;

	str.insert(str.size(), 5, '!');
	cout << str << endl;
	str.erase(str.size() - 5, 5);
	cout << str << endl;

	const char *cp = "Stately, plump Buck";
	str.assign(cp, 7); // s == "Stately"
	cout << str << endl;
	str.insert(str.size(), cp + 7); // s == "Stately, plump Buck"
	cout << str << endl;

	str.replace(1, 3, "NotOk");  //
	cout << str << endl;

	auto pos = str.find("plump"); //-1 if not found.  also: rfind
	cout << pos << endl;

	auto pos1 = str.find_first_of("otp"); //find the first position of one character in auge. also: find_last_of, find_first_not_of
	cout << pos1 << endl;

	int i = 42;
	string s = to_string(i);
	cout << s << endl;

	double d = stod(s);
	cout << d / 5 << endl;

	string st = " 123s321"; //
	int num = atoi(st.c_str());
	cout << num * 2 << endl;
	num = strtol(st.c_str(), NULL, 16);   //base 16
	cout << num << endl;
	num = stoi(st, NULL, 4);   //base 4
	cout << num << endl;
	st = "ab123.321";
	double n = stod(st.substr(st.find_first_of("+-.1234567890")));  //the argument should be starting from numeric value, space is also fine.
	cout << endl << n << endl; //
}