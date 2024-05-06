#include <iostream>
using namespace std;




template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front(); //Видалення першого елемента


	void push_back(T data); //Додати в кінець списку


	void clear(); //Очищення памяті


	int GetSize() { return Size; }


	T& operator[](const int index);


	void push_front(T data); // Додати перший елемент


	void insert(T data, int index); // Вставити елемент


	void removeAt(int index); // Видалити елемент


	void pop_back(); //Видалення останнього елемента

private:


	template<typename A>
	class Node
	{
	public:
		Node * pNext;
		T data;

		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

/*template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}



int main() {


    List<int> lst;


    cout << "push front" << endl;

    lst.push_front(5);
    lst.push_front(7);
    lst.push_front(101);

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << endl;
    }

    cout << endl << "push back " << endl << endl;

    lst.push_back(8);

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << endl;
    }

    cout << endl << "pop back " << endl << endl;

    lst.pop_back();

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << endl;
    }

    cout << endl << "pop front " << endl << endl;
    lst.pop_front();
    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << endl;
    }

    cout << endl << "insert" << endl << endl;

    lst.insert(90, 2);

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << endl;
    }

    cout << endl << "remove" << endl << endl;

    lst.removeAt(1);

    for (int i = 0; i < lst.GetSize(); i++) {
        cout << lst[i] << endl;
    }

    cout << endl << "Size" << endl << lst.GetSize() << endl;

    lst.clear();





    return 0;
};