#include<iostream>
#include<vector>

using namespace std;

int median(int left, int right) {
	int n = right - left + 1;
    n = (n + 1) / 2 - 1;
    return n + left;
}

template <typename iter>
int getSize(iter first, iter last) {
	int size = 0;

	while (first != last) {
		size++;
		++first;
	}

	return size;
}

template <typename iter>
void findQuartiles(iter first, iter last) {
	int size = getSize(first, last);

	int q2 = median(0, size);
	int q1 = median(0, q2);
	int q3 = median(q2 + 1, size);

	cout << "FIRST QUARTILE: ";
	for (int i = 0; i < q1; i++) {
		cout << *first << " ";
		++first;
	}

	cout << "\n";

	cout << "SECOND QUARTILE: ";
	for (int i = q1; i < q2; i++) {
		cout << *first << " ";
		++first;
	}

	cout << "\n";	

	cout << "THIRD QUARTILE: ";
	for (int i = q2; i < q3; i++) {
		cout << *first << " ";
		++first;
	}

	cout << "\n";

	cout << "FOURTH QUARTILE: ";
	for (int i = 0; i < q1; i++) {
		cout << *first << " ";
		++first;
	}

	cout << "\n";
}

int main() {
	std::vector<int> v1;

    for (int i = 16; i < 101; ++i) {
        v1.push_back(i);
    }

    findQuartiles(v1.begin(), v1.end());
}