#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

#include "BST.cpp"

#define SIZE 1000

size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}
template<typename F>
double measure_time(F func) {
	auto start = chrono::steady_clock::now();
	func();
	auto end = chrono::steady_clock::now();
	auto duration = end - start;
	return chrono::duration <double, milli>(duration).count();
}

int main() {
	//OG BST
	double average_fill_time = 0;
	for (int attempt = 0; attempt < 100; ++attempt) {
		BinarySearchTree<int> bst;
		auto fill_op = [&]() {
			for (int i = 0; i < SIZE; ++i) {
				bst.insert(lcg());
			}
		};
		average_fill_time += measure_time(fill_op);
	}
	average_fill_time /= 100;
	cout << "Average fill time (bst): " << fixed << std::setprecision(5) << average_fill_time << " ms" << endl;
	double average_search_time = 0;
	for (int attempt = 0; attempt < 1000; ++attempt) {
		BinarySearchTree<int> bst;
		for (int i = 0; i < SIZE; ++i) {
			bst.insert(lcg());
		}
		auto search_op = [&]() {
			int target = lcg();
			bst.search(target);
		};
		average_search_time += measure_time(search_op);
	}
	average_search_time /= 1000;
	cout << "Average search time (bst): " << fixed << setprecision(5) << average_search_time << " ms" << endl;
	double average_add_remove_time = 0;
	for (int attempt = 0; attempt < 1000; ++attempt) {
		BinarySearchTree<int> bst;
		for (int i = 0; i < SIZE; ++i) {
			bst.insert(lcg());
		}
		auto add_remove = [&]() {
			int target = lcg();
			bst.insert(target);
			bst.erase(target);
		};
		average_add_remove_time += measure_time(add_remove);
	}
	average_add_remove_time /= 1000;
	cout << "Average insert&remove time (bst): " << fixed << setprecision(5) << average_add_remove_time << " ms" << endl;
	//vector
	vector<int> vect(SIZE);
	generate(vect.begin(), vect.end(), [&]() { return lcg(); });

	double vector_fill_time = measure_time([&]() {
		vector<int> copy_vect(vect);
	});
	cout << "Vector fill time: " << fixed << setprecision(5) << vector_fill_time << " ms" << endl;
	double vector_search_time = measure_time([&]() {
		int target = lcg();
		find(vect.begin(), vect.end(), target);
	});
	cout << "Vector search time: " << fixed << setprecision(5) << vector_search_time << " ms" << endl;
	double vector_add_remove_time = measure_time([&]() {
		int target = lcg();
		vect.push_back(target);
		vector<int>::iterator it = find(vect.begin(), vect.end(), target);
		if (it != vect.end()) vect.erase(it);
	});
	cout << "Vector add/remove time: " << fixed << std::setprecision(5) << vector_add_remove_time << " ms" << endl;
}
