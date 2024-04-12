#include <vector>
#include <iostream>

#include "BST.cpp"

using namespace std;

vector<int> find_uniques(const vector<int>& in) {
	vector<int> result;
	BinarySearchTree<int> bst;
	for (int i : in) {
		bool flag = bst.insert(i);
		if (flag) {
			result.push_back(i);	
		}
		else {
			vector<int>::iterator it = find(result.begin(), result.end(), i);
			result.erase(it);
		}
	}
	return result;
}
int main() {
	vector<int> vect{3, 2, 2, 4, 11, 4,11, 35, 6, 7};
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
	cout << "Count of Nodes " << bst.count() << endl;
	bst.erase("6");
	bst.print();
	cout << "Count of Nodes " << bst.count() << endl;
	string str = "4";
	cout << "bst tree contains " << str << "? - " << (bst.contains(str) ? "Yes" : "No") << endl;
	string str1 = "7";
	cout << "bst tree contains " << str1 << "? - " << (bst.contains(str1) ? "Yes" : "No") << endl;
	bst.search("6");
}