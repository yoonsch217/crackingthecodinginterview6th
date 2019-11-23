#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

string insertInside(string str, int leftIdx){
	string left = str.substr(0, leftIdx + 1);
	string right = str.substr(leftIdx + 1, str.length() - leftIdx);
	return left + "()" + right;
}

set<string> generateParens(int remaining){
	set<string> mSet;
	if(remaining == 0) mSet.insert("");

	else{
		set<string> prev = generateParens(remaining - 1);
		for(string str : prev){
			for(int i = 0; i < str.length(); i++){
				if(str.at(i) == '('){
					string s = insertInside(str, i);
					mSet.insert(s);
				}
			}
			mSet.insert("()"+str);
		}

	}
	return mSet;

}


void addParen(vector<string>& list, int left, int right, string str, int idx){
	if(left < 0 || right < left) return;

	if(left == 0 && right == 0){
		list.push_back(str);
	}

	else{
		str.at(idx) = '(';
		addParen(list, left-1, right, str, idx+1);

		str.at(idx) = ')';
		addParen(list, left, right-1, str, idx+1);
	}
}

vector<string> generateParens2(int count){
	char tmp_list[2*count];
	for(int i = 0; i < 2*count; i++) tmp_list[i] = '.'; //initialize the string with dummy chars
	string str = tmp_list;
	vector<string> list;
	addParen(list, count, count, str, 0);
	return list;
}


int main(){
	int input;
	cin >> input;

	set<string> result = generateParens(input);

	for(string s : result) cout << s << " , ";
	cout << endl;

	//
	vector<string> result2 = generateParens2(input);

	for(string s : result2) cout << s << " , ";
	cout << endl;
}
