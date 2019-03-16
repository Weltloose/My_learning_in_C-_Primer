#include <iostream>
#include <vector>
#include <string>
#include <memory>   // library needed
#include <exception>

using namespace std;

class Test_ptr;

class Test{
public:
	friend class Test_ptr;
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
	Test_ptr begin();
	Test_ptr end();

	//Test_ptr end(){return Test(*this, data->size());}   //error.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

private:
	shared_ptr<vector<string>> data;
};

class Test_ptr{
public:
	Test_ptr(): cur(0){}
	Test_ptr(Test &t, int index = 0): wptr(t.data), cur(index){}
	string &def () const;
	Test_ptr &incr(); 
	void print() const {cout << def() << endl;}
private:
	shared_ptr<vector<string>> check (int, const string &) const;
	int cur;
	weak_ptr<vector<string>> wptr; 
};

Test_ptr Test::begin(){return Test_ptr(*this);}
Test_ptr Test::end(){return Test_ptr(*this, data->size());}   //success because Test is already defined.

shared_ptr<vector<string>> Test_ptr::check (int i, const string &msg) const{
	auto ptr = wptr.lock();   //return null if wptr.use_count() == 0. else return the shared_ptr.
	if(!ptr)
		throw runtime_error("unbound Test_ptr");
	if(i >= ptr->size()) throw out_of_range(msg);
	return ptr;
}

string &Test_ptr::def() const {
	auto ptr = check(cur, "Fetching Index Out Of Range");
	return (*ptr)[cur];
}

Test_ptr &Test_ptr::incr(){
	check(cur, "Increment past end of range");
	++cur;
	return *this;
}

int main(){
	vector<string> v{"a", "b", "c", "d"};
	Test t(v);
	Test s(t);
	s.pop();
	s.push("3");
	t.print();
	t.begin().print();
}