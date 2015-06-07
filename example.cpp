#include "finally.hpp"
#include <iostream>

using namespace std;

int main() {
	int i = 0;
	cout << "i: " << i << endl;
	TryFinally(
		Try{
			try {
				i = 1;
				cout << "Try! i: " << i << endl;
				//throw(std::exception());
				i = -1;
				cout << "Try (2)! i: " << i << endl;
			} catch (const std::exception &e) {
				i = 2;
				cout << "Caught! i: " << i << endl;
			}	
		},
		Finally{
			i = 3;
			cout << "Finally! i: " << i << endl;
		}
	);
	cout << "i: " << i << endl;
	return 0;
}
