#include <iostream>
#include <thread>
#include <string>

using namespace std;

int current = 1;

void fizzBuzz(bool div3, bool div5, int max, string toPrint){
	while(true){
		if(current > max) return;

		if((current%3==0)==div3 && ((current%5==0)==div5)){
			printf("Current value is %d, and print: %s\n", current, toPrint.c_str());
			current++;

		}
	}

}

int main(){
	cout << "start!!" << endl;

	thread t1(fizzBuzz, true, true, 20, "FizzBuzz\n");
	thread t2(fizzBuzz, false, true, 20, "Buzz\n");
	thread t3(fizzBuzz, true, false, 20, "Fizz\n");
	thread t4(fizzBuzz, false, false, 20, "\n");

	t1.join();
	t2.join();
	t3.join();
	t4.join();

}
