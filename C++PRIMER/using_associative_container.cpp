#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){
	map<string, int> word_cnt;  
	set<string> exclude = {"and", "or", "the"};
	string words[] = {"hello", "are", "this", "is", "the", "best", "practice", "and", "one", "it", "is"};
	for(const auto &word : words)
		if(exclude.find(word) == exclude.end())
			++word_cnt[word];
	word_cnt.insert({"welcome", 1});  
	auto temp = word_cnt.insert({"welcome", 1}); //insert returns a pair with element type <iterator, bool> THe first element stores an iterator to the element with the given key, bool is false if key already exist.
	if(!temp.second) ++temp.first->second;
	word_cnt.insert(pair<string, int>("nowelcome", 3));
	word_cnt.insert(map<string, int>::value_type("oh", 4));
	auto i = word_cnt.find("oh");
	if(i != word_cnt.end())
		cout << "The founded element " << i->first << " occurs " << i->second << " times " << endl; 
	for(const auto &w : word_cnt)
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

}