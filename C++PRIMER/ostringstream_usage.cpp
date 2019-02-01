#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

bool valid(string str){
	if(str.size() != 11) return 0;
	for(auto i = 0; i < str.size(); i++) if(str[i] > '9' || str[i] < '0') return 0;
	return 1;
}

int main(){
	vector<string> v{ "3keyou", "15113757645", "15113", "757645" };
	ostringstream formated, bad_num;
	for(const auto & str: v){
		if(!valid(str)){
			bad_num << ' ' << str;
		}
		else formated << ' ' << str;
	}
	cout << formated.str() << endl;
	cout << bad_num.str() << endl;
}