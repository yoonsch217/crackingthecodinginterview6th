#include <iostream>
#include <string>
#include <algorithm>
#include <hash_map>
#include <vector>

using namespace std;

string sortChars(string s){
	char content[s.length()];
	strcpy(content, s.c_str());
	sort(content, content + s.length());
	return content;
}

void sort(string arr[], int len){
	hash_map<string, string> mapList;
	hash_map<string, string>::iterator it;

	for(int i = 0; i < len, i++){
		string key = sortChars(arr[i]);
		mapList.insert(hash_map<string, string>::value_type(key, arr[i]));
	}

	int idx = 0;
	vector<string> keySet;
	for(it = mapList.begin(); it != mapList.end(); ++it){
		keySet.push_back(it->first);
	}

	for(it = mapList.begin(); it!=mapList.end(); it++) cout << it->second << endl;



}

