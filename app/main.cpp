#include <vector>
#include <iostream>

#include "BST.cpp"

using namespace std;

vector<int> find_uniques(const vector<int>& in) {
	vector<int> result;
	BinarySearchTree<int> bst;
	for (int i : in) {
		bool flag = bst.insert(i);
		if (flag) { // Ёквивалентность if(flag) и if(flag == true)
			result.push_back(i);
		}
		else {
			result.pop_back();
		}
	}
	return result;
}
int main() {
	vector<int> vect{3, 2, 2, 4};
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
	cout << endl;
	BinarySearchTree<string> bst;
	bst.insert("6");
	bst.insert("5");
	bst.insert("4");
	bst.insert("3");
	bst.insert("7");
	bst.insert("8");
	bst.print();
	bst.erase("5");
	bst.print();
}