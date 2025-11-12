#include <ostream>
#include "List.h"
#include "Node.h"
#include "ListArray.h"
using namespace std;

template <typename T>
class ListLinked : public List<T>
{

private:
	Node<T> *first;
	int n;
	int arr[];
public:
	ListLinked() 
	{
		first = nullptr;
		n = 0;
	}
	~ListLinked() 
	{
		for (int i = 0; i < n; i++)
		{
			Node<T> *aux = first->next;
			delete first;
			first = aux;
		}
	}
	T operator[](int pos) 
	{
		if (pos < 0 || pos > n)
		{
			throw out_of_range("La posicion esta fuera del rango");
		}
		Node<T> *current = first;
		for (int i = 0; i < pos; i++)
		{
			current = current->next;
		}
		return current->data;
	}
	friend ostream &operator<<(ostream &out, const ListLinked<T> &list) 
	{
		out << list->first->data;
		return out;
	}
	void insert(int pos, T e) {
		if(pos < 0 || pos > n) throw std::out_of_range("Posición fuera del rango de la array");
		if(pos == 0){
			Node<T>* aux = new Node<T>(e,first); 
			first = aux;
			n++;
		}
		else{
			Node<T>* prev = nullptr;
			Node<T>* aux = first;
			int i = 0;
			while(aux != nullptr && i < pos){
				prev = aux;
				aux = aux -> next;
				i++;
			}
			if(i == pos){
				prev->next = new Node<T>(e,aux); 
				n++;
			}	
		}
	}
	void append(T e) 
	{
		insert(n, e);
	}
	void prepend(T e) 
	{
		insert(0, e);
	}
	T remove(int pos){
    if (pos < 0 || pos >= n)
        throw std::out_of_range("Posición fuera de rango");

    Node<T>* to_delete;
    T value;

    if (pos == 0) {
        to_delete = first;
        first = first->next;
    } else {
        Node<T>* prev = first;
        for (int i = 0; i < pos - 1; i++)
            prev = prev->next;

        to_delete = prev->next;
        prev->next = to_delete->next;
    }

    value = to_delete->data;
    delete to_delete;
    n--;
    return value;
}

	T get(int pos) {
		if(pos < 0 || pos >= n) throw std::out_of_range("Posición fuera del rango de la array");
		Node<T>* aux = first;
		for(int i= 0; i < pos; i++) aux = aux->next;
		return aux->data;
	}
	int search(T e)  {
        Node<T>* aux = first;
		int i = 0;
		while(aux != nullptr && aux-> data != e){
			aux = aux-> next;
			i++;
		}
		if(aux != nullptr){ 
			return i;
		}else{ 
			return -1;
        }
	}
	bool empty() 
	{
		return n == 0;
	}
	int size() 
	{
		return n;
	}
};
