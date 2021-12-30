#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getPerms(string s, string curr, vector<string>& res){
	int n = s.size();

	if(n==0){
		res.push_back(curr);
		return;
	}

	for(int i = 0; i < n; i++){
		string s1 = curr + s.substr(i,1);
		string s2 = s.substr(0,i) + s.substr(i+1, n-1-i);
		getPerms(s2, s1, res);
	}

}

vector<string> getPerms(string s){
	vector<string> result;
	string curr = "";
	getPerms(s, curr, result);

	return result;
}


int main(){

	string a;
	cin >> a;
	vector<string> result = getPerms(a);

	for(int i = 0; i < result.size(); ++i) cout << result[i] << endl;

	return 0;

}
