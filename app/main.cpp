#include <vector>
#include <iostream>

#include "BST.cpp"

using namespace std;

vector<int> find_uniques(const vector<int>& in) {
	vector<int> result;
	BinarySearchTree<int> bst;
	for (int i : in) {
		bool flag = bst.insert(i);
		if (flag) { // ��������������� if(flag) � if(flag == true)
			result.push_back(i);
		}
		else {
			result.pop_back();
		}
	}
	return result;
}
int main() {
	vector<int> vect{1, 5, 5, 2, 7, 9, 11, 11};
	vector<int> unique = find_uniques(vect);
	cout << "first vector: ";
	for (int i = 0; i < vect.size(); ++i) {
		cout << vect[i] << " ";
	}
	cout << endl;
	cout << "unique vector: ";
	for (int i = 0; i < unique.size(); ++i) {
		cout << unique[i] << " ";
	}
	
}