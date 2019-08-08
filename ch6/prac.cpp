#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

	int answer;
	cin >> answer;
	int result[] = {0,0,0,0};

	vector<vector<int>> mat(10, vector<int>(0));


		
	vector<int> v0;
	for(int i = 0; i < 15; i++){
		if((i&1)==1) {
			mat.at(0).push_back(i);
		}
	}	
	
	vector<int> v1;
	for(int i = 0; i < 15; i++){
		int tmp = i;
		tmp >>=1;

		if((tmp&1)==1) {
			mat.at(1).push_back(i);
		}
	}

	vector<int> v2;
	for(int i = 0; i < 15; i++){
		int tmp = i;
		tmp>>=2;
		if((tmp&1)==1) mat.at(2).push_back(i);
	}

	vector<int> v3;
	for(int i = 0; i < 15; i++){
		int tmp = i;
		tmp>>=3;
		if((tmp&1)==1) mat.at(3).push_back(i);
	}


	while(!mat.at(0).empty()){
		if(mat.at(0).back() == answer) result[0] = 1;
		mat.at(0).pop_back();
	}
	while(!mat.at(1).empty()){
		if(mat.at(1).back() == answer) result[1] = 1;
		mat.at(1).pop_back();
	}
	while(!v2.empty()){
		if(v2.back() == answer) result[2] = 1;
		v2.pop_back();
	}
	while(!v3.empty()){
		if(v3.back() == answer) result[3] = 1;
		v3.pop_back();
	}

	for(int i = 3; i >-1; i--) cout << result[i];

	cout << endl;

}
