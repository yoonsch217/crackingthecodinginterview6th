#include <iostream>
#include <string>

using namespace std;

int search(string s[], string str, int first, int last){
	if(first > last) return -1;
	int mid = (last + first) /2 ;

	cout << "I'm in seach function!" << endl;

	if(s[mid].compare("") == 0){

		cout << "mid is empty, so finding the nearest one!" << endl;

		int left = mid - 1;
		int right = mid + 1;
		while(true){
			if(left < first && right > last) return -1;
			else if(right <= last && s[right].compare("") != 0){
				mid = right;
				break;
			}
			else if(left >= first && s[left].compare("") != 0){
				mid = left;
				break;
			}
			right++;
			left--;
		}
	}

	cout << "mid is " << mid << endl;

	if(str.compare(s[mid]) == 0) return mid;

	else if(str.compare(s[mid]) < 0){
		return search(s, str, first, mid -1 );
	}
	else return search(s, str, mid+1, last);
}

int search(string s[], string str,  int len){
	if(s == nullptr || str == "") return -1;
	return search(s, str, 0, len-1);
}


int main()
{
  string arr[] =  {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << n << endl;

  cout<<search(arr, "dad", n) << endl;
  return 0;
}
