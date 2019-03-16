#include <iostream>
#include <vector>
#include <string>
#include <memory>   // library needed

using namespace std;

class Test{
public:
	Test():data(make_shared<vector<string>>()){}
	Test(vector<string> &v):data(make_shared<vector<string>>(v)){}
	Test(Test &t): data(t.data){}
	string pop(){
		string t = (*data.get())[data.get()->size() - 1];
		data.get()->pop_back();
		return t;
	}
	void push(const string &s){
		data.get()->push_back(s);
	}
	void print(){
		for(const auto & s : *data)
			cout << s << ' ';
		cout << endl;
	}
private:
	shared_ptr<vector<string>> data;
};

int main(){
	vector<string> v{"a", "b", "c", "d"};
	Test t(v);
	Test s(t);
	s.pop();
	s.push("3");
	t.print();
}