#include "node.h";

#pragma once


/*Într-o listă liniară simplu înlănţuită, alocată dinamic, cu cel puţin 3 noduri, fiecare element 
reţine în câmpul nr un număr real, iar în câmpul urm adresa următorului element din listă
sau valoarea NULL în cazul în care este ultimul nod al listei. Dacă p reţine adresa primului 
element din listă, scrieţi o expresie C/C++ a cărei valoare este egală cu suma valorilor reale 
reţinute în primele trei noduri ale listei.*/


struct Lista {

	Node<int>* head = NULL;

	void add(int data) {

		if (head == NULL) {

			head = new Node<int>();

			head->data = data;

			head->next = NULL;

		}
		else {

			Node<int>* nou = new Node<int>();

			Node<int>* aux = head;

			while (aux->next != NULL) {

				aux = aux->next;

			}

			aux->next = nou;

			nou->data = data;

			nou->next = NULL;

		}

	}

	void afisare() {

		Node<int>* aux = head;

		while (aux != NULL) {

			cout << aux->data << " ";

			aux = aux->next;

		}
	}


};


//todo functie ce returneaza suma primelor 3 elemente din lista

int suma(Lista l) {

	Node<int>* aux = l.head;

	int sum = 0, ct = 0;

	while (aux != NULL && ct < 3) {

		sum += aux->data;

		aux = aux->next;

		ct++;

	}

	return sum;

}


void sol11() {

	Lista l;

	l.add(1);

	l.add(2);

	l.add(3);

	l.add(4);

	l.add(5);

	cout << suma(l);

}