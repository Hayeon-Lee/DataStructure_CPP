#pragma once
#include <iostream>
using namespace std;

template <class T> class Tree; //전방선언

template <class T>
class TreeNode {
	friend class Tree<T>;
private:
	T data;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
public:
	TreeNode(T data=0, TreeNode<T>* leftChild=nullptr, TreeNode<T>* rightChild=nullptr);
};

template<class T>
TreeNode<T>::TreeNode(T data, TreeNode<T>* leftChild, TreeNode<T>* rightChild)
{
	this->data = data;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}

template <class T>
class Tree {
public:
	Tree(T n = 0);
	void buildTree(T *arr, int n);
	void Insert(TreeNode<T>* node); //과제
	TreeNode<T>* getRoot();
	TreeNode<T>* search(TreeNode<T>* current, T data);
	void Visit(TreeNode<T>* currentNode);
	void Inorder();
	void Inorder(TreeNode<T>* currentNode);
	void Preorder();
	void Preorder(TreeNode<T>* currentNode);
	void Postorder();
	void Postorder(TreeNode<T>* currentNode);
	Tree(const Tree<T>& s);
	TreeNode<T>* Copy(TreeNode<T>* origNode);
	bool operator==(const Tree& t) const;
	bool Equal(TreeNode<T> *a, TreeNode<T>*b);
private:
	TreeNode<T>* root;
};

template <class T>
Tree<T>::Tree(T n)
{
	root = new TreeNode<T>(n);
}

template <class T>
void Tree<T>::buildTree(T *arr, int n)
{
	for (int i = 1; i < n; i++) {
		Insert(new TreeNode<T>(arr[i]));
	}
}

template <class T>
void Tree<T>::Insert(TreeNode<T>* node)
{
	if (search(root, node->data) == nullptr) {
		TreeNode<T>* parent = nullptr;
		TreeNode<T>* current = root;

		while (current != nullptr) {
			parent = current;
			if (node->data < parent->data) {
				current = current->leftChild;
			}
			else {
				current = current->rightChild;
			}
		}
		if (node->data < parent->data) {
			parent->leftChild = node;
		}
		else {
			parent->rightChild = node;
		}
	}
}

template <class T>
TreeNode<T>* Tree<T>::getRoot() {
	return root;
}

template <class T>
TreeNode<T>* Tree<T>::search(TreeNode<T>* current, T data) {
	if (current == nullptr) return nullptr;
	if (data == current->data) {
		return current;
	}
	else if (data < current->data) {
		search(current->leftChild, data);
	}
	else {
		search(current->rightChild, data);
	}
}

template <class T>
void Tree<T>::Visit(TreeNode<T>* currentNode)
{
	cout << currentNode->data << ' ';
}

template <class T>
void Tree<T>::Inorder()
{
	Inorder(root);
}

template <class T>
void Tree<T>::Inorder(TreeNode<T>* currentNode)
{
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}

template <class T>
void Tree<T>::Preorder()
{
	Preorder(root);
}

template <class T>
void Tree<T>::Preorder(TreeNode<T>* currentNode)
{
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}

template <class T>
void Tree<T>::Postorder() {
	Postorder(root);
}

template <class T>
void Tree<T>::Postorder(TreeNode<T>* currentNode)
{
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}

template <class T>
Tree<T>::Tree(const Tree<T>& s)
{
	root = Copy(s.root);
}

template <class T>
TreeNode<T>* Tree<T>::Copy(TreeNode<T>* origNode) 
{
	if (!origNode) return 0;
	return new TreeNode<T>(origNode->data,
		Copy(origNode->leftChild),
		Copy(origNode->rightChild));
}

template <class T>
bool Tree<T>::operator==(const Tree& t) const
{
	return Equal(root, t.root);
}

template <class T>
bool Tree<T>::Equal(TreeNode<T>*a, TreeNode<T>*b)
{
	if ((!a) && (!b)) return true;  
	return (a && b                
		&& (a->data == b->data)
		&& Equal(a->leftChild, b->leftChild)
		&& Equal(a->rightChild, b->rightChild)); 
}
