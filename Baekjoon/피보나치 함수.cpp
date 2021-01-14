#include <iostream>
using namespace std;

pair<int, int> fibonacci[41];

int main() {
	fibonacci[0] = {1, 0};
	fibonacci[1] = {0, 1};
	
	for(int i = 2; i <= 40; i++) {
		fibonacci[i].first = fibonacci[i - 1].first + fibonacci[i - 2].first;
		fibonacci[i].second = fibonacci[i - 1].second + fibonacci[i - 2].second;
	}
	
	int count;
	cin >> count;
	
	for(int testCase = 0; testCase < count; testCase++) {
		int index;
		cin >> index;
		
		cout << fibonacci[index].first << " " << fibonacci[index].second << endl;
	}
}