#include <iostream>

using namespace std;

bool findElement(int a[][4], int x){
	int row = 0;
	int col = 4-1;

	while(row < 4 && col >= 0){

		if(a[row][col] == x){
			cout << row << " " << col << endl;
			return true;
		}	
		else if(a[row][col] < x) row++;
		else col--;
		}

		return false;
}


int main(){
	int arr[4][4] = {{15, 20, 40, 85}, {20, 35, 80, 95}, {30, 55, 95, 105}, {40, 80, 100, 120}};

	if(!findElement(arr, 5)) cout << "NOT FOUND!!" << endl;

}
