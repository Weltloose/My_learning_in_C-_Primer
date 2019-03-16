#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#include <memory>
#include <algorithm>
#include <initializer_list>
#include <utility>

using namespace std;

class String{
public:
	String();
	String(char *);
	~String();
	String &operator += (const String &s);
	String operator + (const String &s);
	void print() const;
	String(const String &);
	String(String &&) noexcept	;
	int size() const;
	int capacity() const;
	void get_content(char *c) const;
private:
	char *from, *last, *first_free;
	allocator<char> alloc;
	void chk_n_alloc();
	void reallocate();
	void free();
};

void String::chk_n_alloc(){
	if(size() == capacity())
		reallocate();
}

void String::reallocate(){
	int c = size();
	auto newf = alloc.allocate(c * 2);
	auto ff = newf;
	auto tf = from;
	while(tf != first_free)
		alloc.construct(ff++, std::move(*tf++));
	free();
	from = newf;
	first_free = ff;
	last = from + c * 2;
}

void String::free(){
	int c = capacity();
	for_each(from, first_free, [=](decltype(*from) f){alloc.destroy(&f);});
	alloc.deallocate(from, c);
}

String::String(){
	from = alloc.allocate(1);
	first_free = from;
	alloc.construct(first_free++, '\0');
	last = from + 1;
	cout << "Using common\n";
}

String::String(char *str){
	int s = strlen(str) + 1;
	from = alloc.allocate(s);
	first_free = from;
	int i = 0;
	while(i != s)
		alloc.construct(first_free++, str[i++]);
	last = from + s;
	cout << "Using char\n";
}

String::~String(){
	int c = capacity();
	while(first_free != from)
		alloc.destroy(--first_free);
	alloc.deallocate(from, c);
}

int String::size() const{
	return first_free - from;
}

int String::capacity() const{
	return last - from;
}

void String::print() const{
	for_each(from, first_free, [=](char c){cout << c;});
	cout << endl;
}

String::String(const String &str){
	from = alloc.allocate(str.capacity());
	last = from + str.capacity();
	first_free = from + str.size(); 
	copy(str.from, str.first_free, from);
	cout << "using copy.\n";
}

String::String(String &&str) noexcept{
	from = str.from;
	first_free = str.first_free;
	last = str.last;
	cout << "using move.\n";
	str.from = str.first_free = str.last = NULL;
}

String &String::operator += (const String &s){
	while(size() + s.size() >= capacity())
		reallocate();
	copy(s.from, s.first_free, first_free);
	first_free = from + size() + s.size();
	return *this;
}
String String::operator + (const String &s){
	char c1[100], c2[100];
	get_content(c1);
	get_content(c2);
	return String(strcat(c1, c2));
}

void String::get_content(char *c) const{
	copy(from, first_free, c);
}

int main(){
	char c[] = "hello";
	String str(c);
	str.print();
	String str1(str);
	str1.print();
	String str2(str + str1);
	str2.print();
}
