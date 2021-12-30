#include <iostream>

using namespace std;

int serach(int a[], int left, int right, int x){
	int mid = (left + right) / 2;
	if(x == a[mid]) return mid;
	if(right < left) return -1;

	if(a[left] < a[mid]){ // Left is ordered
		if(x >= a[left] && x < a[mid]) return search(a, left, mid-1, x);
		else return search(a, mid+1, right, x);
	}

	if(a[mid] < a[left]){ //Right is ordered
		if(x > a[mid] && x < a[right]) return search(a, mid+1, right, x);
		else return search(a, left, mid - 1, x);
	}

	if(a[left] == a[mid]){  //tricky case
		if(a[mid] != a[right]) return search(a, mid+1, right, x);
		else{
			int result = search(a, left, mid-1, x);
			if(result == -1) return search(a, mid+1, right, x);
			else return result;
		}
	}

	return -1;
}
