#include "mai.h"

using namespace std;

int main() {
	vector<int> vec = { 10,20,30,40,50 };
	vec.push_back(60);
	cout << "capacity :" << vec.capacity() << endl;
	cout << "size :" << vec.size() << endl;
	for (auto it = vec.cbegin(); it != vec.cend(); it++){
		cout << *it << endl;

	}
}
