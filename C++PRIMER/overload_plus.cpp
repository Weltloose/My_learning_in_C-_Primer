#include <iostream>
#include <string>

using namespace  std;

class String{
private:
	string a;
public:
	String(const string &str): a(str){}
	String() = default;
	String(const char *str): a(str){}
	// String operator + (const String &s2){
	// 	return String(a + s2.a);
	// }  //error.
	void print(){cout << a << endl;}
	friend String operator + (const String &s1, const String &s2){
		return String(s1.a + s2.a);
	}
	friend ostream &operator << (ostream &os, const String &s){  //istream and ostream are both not copiable. So must use their reference
		os << s.a << endl;
		return os;
	}
	friend istream &operator >> (istream &is, String &s){  //return istream & or ostream & so that can use cout << a << b. otherwise cout << a; cout << b; 
		is >> s.a;
		if(is) cout << "success" << endl;
		else s.a = ""; 
		return is;
	}
};



int main(){
	String str1("hi");
	String str2 = "hi" + str1; 
	String str3;
	cin >> str3;
	cout << str2 << str3;
}