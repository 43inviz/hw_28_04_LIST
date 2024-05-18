#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>

class List
{
	Node<T>* _head;
	int _size;
public:

	List(Node<T>* head, int size) {
		_head = head;
		_size = size;
	}
	List() :_head{nullptr},_size{0}{}
	~List();
	List(const List& list);

	

	void addToTail(T data);
	void addToHead(T data);

	void addAt(T inputData, int index);
	void delAt(int index);

	void removeFromHead();
	void removeFromTail();

	void removeAll();
	void show();

	int getPositionElement(T data);
	int changeValueOfElements(T seatchedVal, T changedVal);
	void reverse();
};

template<typename T>
inline List<T>::~List()
{
	if (_head != nullptr) {
		delete _head;
	}
}

template<typename T>
inline List<T>::List(const List& list)
{
	removeAll();

	Node<T>* node = list._head;

	while (node != nullptr)
	{
		addToTail(node->_data);

		node = node->_ptrNext;
	}
}

template<typename T>
inline void List<T>::addToTail(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (_head == nullptr) {
		_head = newNode;
	}
	else {
		Node<T>* copyHeadNode = _head;
		while (copyHeadNode->getPtrNext() != nullptr) {
			copyHeadNode = copyHeadNode->getPtrNext();
		}

		copyHeadNode->setPtrNext(newNode);

	}

	_size++;
}

template<typename T>
inline void List<T>::addToHead(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (_head == nullptr) {
		_head = newNode;
	}
	else {
		newNode->setPtrNext(_head);
		_head = newNode;
		
	}
}

template<typename T>
inline void List<T>::addAt(T inputData, int index)
{
	try {
		if (index < 0 || index > _size) {
			//cout << "Wrong index\n";
			throw exception("Wrong index\n");
		}


		if (index == 0) {
			addToTail(inputData);
		}
		else {
			Node<T>* newNode = new Node<T>(inputData);
			Node<T>* currentNode = _head;
			for (int i = 0; i < index - 1; i++) {
				currentNode = currentNode->getPtrNext();

			}
			newNode->setPtrNext(currentNode->getPtrNext());
			currentNode->setPtrNext(newNode);
		}
		_size++;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}

template<typename T>
inline void List<T>::delAt(int index)
{
	try {
		if (index >= 0 && index < _size) {
			if (_head == nullptr) {
				/*cout << "Nothing to delete\n";*/
				throw exception("Nothing to delete\n");
			}

			if (index == 0) {
				removeFromHead();
			}
			else {
				Node<T>* predNode = _head;

				for (int i = 0; i < index - 1; i++) {
					predNode = predNode->getPtrNext();
				}

				Node<T>* currentNode = predNode->getPtrNext();
				predNode->setPtrNext(currentNode->getPtrNext());
				delete currentNode;

			}

			_size--;
		}
		else {
			//cout << "You enter wrong index\n";
			throw exception("You enter wrong index\n");
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	
}

template<typename T>
inline void List<T>::removeFromHead()
{
	if (_head != nullptr) {
		Node<T>* delNode = _head;
		_head = _head->getPtrNext();
		delete delNode;
		_size--;
	}
}

template<typename T>
inline void List<T>::removeFromTail()
{
	if (_head != nullptr) {
		Node<T>* delNode = _head;
		Node <T>* predNode = nullptr;
		while (delNode->getPtrNext() != nullptr) {
			predNode = delNode;
			delNode = delNode->getPtrNext();
		}

		if (predNode == nullptr) {
			delete delNode;
			_head == nullptr;
		}
		else {
			predNode->setPtrNext(nullptr);
			delete delNode;
		}
	}

	_size--;
}

template<typename T>
inline void List<T>::removeAll()
{
	while (_head != nullptr) {
		removeFromHead();
	}
}

template<typename T>
inline void List<T>::show()
{
	Node<T>* node = _head;
	while (node != nullptr) {
		cout << node->getData() << " ";
		node = node->getPtrNext();
	}
	cout << std::endl;
}

template<typename T>
inline int List<T>::getPositionElement(T data)
{
	Node<T>* node = _head;
	int index = 0;
	for (int i = 0; i < _size; i++) {
		
		if (node->getData() == data) {
			return index;
			
		}
		node = node->getPtrNext();
		index++;
	}
	
	return -1;
	
}

template<typename T>
inline int List<T>::changeValueOfElements(T searchedVal, T changedVal)
{
	Node<T>* node = _head;
	int countOfChanges = 0;
	for (int i = 0; i < _size; i++) {
		if (node->getData() == searchedVal) {
			node->setData(changedVal);
			countOfChanges++;
		}
		node = node->getPtrNext();

	}

	if (countOfChanges > 0) {
		return countOfChanges;
	}
	else {
		return -1;
	}
}

template<typename T>
inline void List<T>::reverse()
{
	Node<T>* currentNode = _head;
	Node<T>* predNode = nullptr;
	Node<T>* nextNode = nullptr;

	while (currentNode != nullptr) {
		nextNode = currentNode->getPtrNext();
		currentNode->setPtrNext (predNode);
		predNode = currentNode;
		currentNode = nextNode;
	}

	_head = predNode;
}
