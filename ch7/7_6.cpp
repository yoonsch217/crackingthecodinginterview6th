class Piece{
	private:
		int row;
		int col;

		int top_shape;
		int bottom_shape;
		int right_shape;
		int left_shape;

	public:
		bool isCorner(){
			int count = 0;
			if(top_shape == 0) count++;
			if(bottom_shape == 0) count++;
			if(right_shape == 0) count++;
			if(left_shape == 0) count++;
			return count==2;
		}

		bool hasOneFlat(){

		}

		bool hasCounter(int shape){

		}


};

class Board{
	private:
		Piece Answer[N][N];

};

class Game{
	Piece pieces[N*N];
	Board board;

	Piece[] findCorner(){
		Piece rtn[4];
		int count = 0;
		for(int i = 0; i < N*N; i++){
			if(pieces[i].isCorner()){
				rtn[count] = pieces[i];
				count++;	
			}
		}
		return rtn;
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i==0&&j==0) continue;

			if(i==0){
				for(int idx = 0; idx < N*N; idx++){
					if(pieces[idx].hasOneFlat() && pieces[idx].hasCounter(board.answer[i][j-1].right_shape)){
						board.answer[i][j] = pieces[idx];
					}
				}
				
			}
			if(pieces[idx].hasCounter(board.answer[i][j-1]) && pieces[idx].hasCounter(board.answer[i-1][j]))
				board.answer[i][j] = pieces[idx];
		}
	}

};
