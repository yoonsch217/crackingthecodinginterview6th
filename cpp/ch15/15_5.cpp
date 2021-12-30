#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>

using namespace std;

class FooBad{
	public:

	int pauseTime = 1000;
	static mutex lock1, lock2;

	FooBad(){

		lock1.lock();
		lock2.lock();
	}

	static void first(){
		cout << "First " << endl;

		lock1.unlock();
	}

	static void second(){
		lock1.lock();
		lock1.unlock();

		cout << "Second " << endl;

		lock2.unlock();
	}

	static void third(){
		lock2.lock();
		lock2.unlock();

		cout << "Third " << endl;
	}
};

class Foo{
	public:

	int pauseTime = 1000;
	static mutex lock1, lock2;

	FooBad(){

		lock1.lock();
		lock2.lock();
	}

	static void first(){
		cout << "First " << endl;

		lock1.unlock();
	}

	static void second(){
		lock1.lock();
		lock1.unlock();

		cout << "Second " << endl;

		lock2.unlock();
	}

	static void third(){
		lock2.lock();
		lock2.unlock();

		cout << "Third " << endl;
	}
};


int main(){
	FooBad f;

//	thread t1(f.first);
//	thread t2(f.second);
//	thread t3(f.third);

//	t1.join();
//	t2.join();
//	t3.join();


	
}
