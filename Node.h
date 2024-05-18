#pragma once
template <typename T>
class Node
{
	T _data;
	Node* _ptrNext;

public:
	Node(T data);

	T getData()const {
		return _data;
	}

	Node* getPtrNext() const{
		return _ptrNext;
	}

	void setData(T data) {
		_data = data;
	}
	
	void setPtrNext(Node* next) {
		
		_ptrNext = next;
		
		
	}
};

template<typename T>
inline Node<T>::Node(T data)
{
	_data = data;
	_ptrNext = nullptr;
}


