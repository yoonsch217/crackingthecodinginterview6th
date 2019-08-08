#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Point{
	int row;
	int col;
	Point(int r, int c) : row(r), col(c){}
};

bool getPath(int** matrix, int currRow, int currCol, vector<Point*>& path, unordered_set<Point*>& duplicateVisits){
	if(currRow<0 || currCol < 0 || matrix[currRow][currCol] == -1) return false;

	Point* currPos = new Point(currRow, currCol);

	if(duplicateVisits.find(currPos) != duplicateVisits.end()) return false;

	bool atOrigin = currRow==0 && currCol==0;

	if(atOrigin || getPath(matrix, currRow-1, currCol, path, duplicateVisits)
			|| getPath(matrix, currRow, currCol-1, path, duplicateVisits)){
		path.push_back(currPos);
		return true;
	}

	duplicateVisits.insert(currPos);
	return false;
}


vector<Point*> getPath(int** matrix, int row, int col){
	vector<Point*> path;
	unordered_set<Point*> duplicateVisits;

	if(row!=0 || matrix != nullptr){
		if(getPath(matrix, row-1, col-1, path, duplicateVisits)) return path;
	}

	return path;
}


////

int** createMatrix(int r, int c){
	int** matrix = new int*[r];
	for(int i = 0; i < r; ++i)matrix[i] = new int[c];
	for(int i = 0; i < r;++i)
		for(int j = 0; j < c; ++j)
			matrix[i][j] = 1;
	return matrix;
}



int main() {

    //create a 5x7 matrix (5 rows and 7 columns)
    int** matrix = createMatrix(5, 7);
    //set specific points as off-limits
    matrix[1][3] = -1;
    matrix[2][5] = -1;
    matrix[3][2] = -1;
    matrix[0][1] = -1;


    vector<Point*> path = getPath(matrix, 5, 7);
    if (path.size() == 0){
        cerr << "Path does not exist!" << endl;

    }
    else {
        for (int i = 0; i < path.size(); ++i){
            cout << "[" << path[i]->row << "]" << "[" << path[i]->col << "]" << endl;
        }

    }

}
