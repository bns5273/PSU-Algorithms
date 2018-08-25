// bns5273
// p4

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;


int mergeInv(int array[], int temp[], int left, int mid, int right) {
	int count = 0;
	int i = left;
	int j = mid;
	int k = left;

	while ((i <= mid - 1) && (j <= right)) {
		if (array[i] <= array[j])
			temp[k++] = array[i++];

		else {
			temp[k++] = array[j++];
			count = count + (mid - i);
		}
	}

	// left
	while (i <= mid - 1)
		temp[k++] = array[i++];

	// right
	while (j <= right)
		temp[k++] = array[j++];

	// copy back
	for (i = left; i <= right; i++)
		array[i] = temp[i];

	return count;
}

int inv(int array[], int temp[], int left, int right) {
	int mid = (right + left) / 2;
	int count = 0;
	if (right > left) {
		count += inv(array, temp, left, mid);
		count += inv(array, temp, mid + 1, right);
		count += mergeInv(array, temp, left, mid + 1, right);
	}
	return count;
}


int main() {
	int in;
	string line;
	vector<int> current;
	ifstream input;
	input.open("input.txt");

	while (getline(input, line)) {
		stringstream ss;
		ss.str(line);
		while (ss >> in)
			current.push_back(in);
		int temp[128];
		int* array = &current[0];

		if (current.size() > 1) {
			cout << "The sequence has "
				<< inv(array, temp, 0, current.size() - 1)
				<< " inversions.\n";
		}
		current.clear();
	}

	input.close();
	return 0;
}