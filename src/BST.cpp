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
	BinarySearchTree() : root(nullptr) {};
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

template<typename T>
typename BinarySearchTree<T>::Node * BinarySearchTree<T>::copy_tree(const Node* other) {
	if (!other) {
		return nullptr;
	}
	Node* new_node = new Node(other->data);
	new_node->left = copy_tree(other->left);
	new_node->right = copy_tree(other->right);
	return new_node;
}
template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other) : root(copy_tree(other.root)){}
template<typename T>
void BinarySearchTree<T>::destroy_recursive(Node* node) {
	if (node) {
		destroy_recursive(node->left);
		destroy_recursive(node->right);
		delete node;
	}
}
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {
	destroy_recursive(root);
}
template<typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& other) {
	BinarySearchTree copy(other);
	if (this != &copy) {
		swap(*this, copy);
	}
	return *this;
}
template<typename T>
void BinarySearchTree<T>::print_recursive(Node* root, const string& prefix, bool isLeft) const {
	if (root) {
		cout << prefix;
		cout << (isLeft ? "|--" : "\\--");
		cout << root->data << endl;
		
		print_recursive(root->left, prefix + (isLeft ? "|  " : "   "), true);
		print_recursive(root->right, prefix + (isLeft ? "|   " : "   "), false);
	} 
}
template<typename T>
void BinarySearchTree<T>::print() const {
	cout << "Tree: " << endl;
	print_recursive(root);
}
template<typename T>
bool BinarySearchTree<T>::insert(T key) {
	if (!root) {
		root = new Node(key);
		return true;
	}
	Node* tmp = root;
	while (tmp) {
		if (tmp->data > key) {
			if (tmp->left)
				tmp = tmp->left;
			else {
				tmp->left = new Node(key);
				return true;
			}
		}
		else if (tmp->data < key) {
			if (tmp->right)
				tmp = tmp->right;
			else {
				tmp->right = new Node(key);
				return true;
			}
		}
		else return false;
	}
}
template<typename T>
bool BinarySearchTree<T>::contains_recursive(Node* node, const T key) const {
	if (node) {
		if (node->data == key) return true;
		else if (node->data < key) return contains_recursive(node->right, key);
		else return contains_recursive(node->left, key);
	}
	else
		return false;
}
template<typename T>
bool BinarySearchTree<T>::contains(T key) const {
	return contains_recursive(root, key);
}
template<typename T>
void BinarySearchTree<T>::erase_recursive(Node*& node, const T key) {
	if (!node) {
		return;
	}
	if (key < node->data) {
		erase_recursive(node->left, key);
	}
	else if (key > node->data) {
		erase_recursive(node->right, key);
	}
	else {
		if (!node->left) {
			Node* tmp = node->right;
			delete node;
			node = tmp;
		}
		else if (!node->right) {
			Node* tmp = node->right;
			delete node;
			node = tmp;
		}
		else {
			node->data = find_min(node->right)->data;
			erase_recursive(node->right, node->data);
		}
	}
}
template<typename T>
typename BinarySearchTree<T>::Node * BinarySearchTree<T>::find_min(Node* node) const {
	while (node->left) {
		node = node->left;
	}
	return node;
}
template<typename T>
bool BinarySearchTree<T>::erase(T key) {
	if (contains(key)) {
		erase_recursive(root, key);
		return true;
	}
	return false;
}
template<typename T>
int BinarySearchTree<T>::count_recursive(Node* node) {
	if (!node) return 0;
	return count_recursive(node->recursive) + count_recursive(node->left) + 1;
}
template<typename T>
int BinarySearchTree<T>::count() {
	return count_recursive(root);
}
template<typename T>
typename BinarySearchTree<T>::Node * BinarySearchTree<T>::search_recursive(Node* node, T key) {
	if (!node || node->data == key) return root;
	if (node->data < key)
		return search_recursive(node->right, key);
	return search_recursive(node->left, key);
}
template<typename T>
bool BinarySearchTree<T>::search(T key) {
	if (search_recursive(root, key)) return true;
	return false;
}