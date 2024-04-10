#pragma once
#include <random>
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node(const T d) : data(d), left(nullptr), right(nullptr) {};
	};
	Node* root;
	Node* copy_tree(const Node* other);
	Node* find_min(Node* node) const;
	Node* search_recursive(Node* node, T key);
	void erase_recursive(Node*& node, const T key);
	void destroy_recursive(Node* node);
	void print_recursive(Node* node, const string& prefix = "", bool isLeft = true) const;
	bool contains_recursive(Node* node, const T key) const;
	int count_recursive(Node* node);
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& other);
	~BinarySearchTree();
	BinarySearchTree& operator=(const BinarySearchTree& other);

	void print() const;
	bool insert(T key);
	bool contains(T key) const;
	bool erase(T key);
	int count();
	bool search(T key);
};