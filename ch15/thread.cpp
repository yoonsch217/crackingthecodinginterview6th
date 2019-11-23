#include <iostream>
#include <thread>
#include <vector>

using namespace std;


void worker(vector<int>::iterator start, vector<int>::iterator end, int* result){
	int sum = 0;
	for(auto itr = start; itr < end; itr++) sum += *itr;

	*result = sum;

	thread::id this_id = std::this_thread::get_id();

	printf("Thread id: %x, from %d to %d  result is %d \n", this_id, *start, *(end-1), sum);

}

int main(){
	vector<int> data(10000);
	for(int i = 0; i < 10000; i++) data[i] = i;

	vector<int> partial_sums(4);

	vector<thread> workers;
	for(int i = 0; i < 4; i++){
		//thread 생성자의 첫번째 인자로 함수를 전달하고, 그 뒤로 함수의 parameter들을 쭉 쓴다
		workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i+1) * 2500, &partial_sums[i]));
	}

	for(int i = 0; i < 4; i++){
		workers[i].join();
	}

	int total = 0;

	for(int i = 0; i < 4; i++) total += partial_sums[i];

	cout << "Total: " << total << endl;
}
