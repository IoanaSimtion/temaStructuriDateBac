#include "node.h";


#pragma once


/*Se consideră o listă liniară simplu înlănţuită
alocată dinamic, cu cel puţin două
elemente. Fiecare element al listei reţine în 
câmpul urm adresa elementului următor din 
listă sau NULL dacă nu există un element 
următor.
Ştiind că variabila p reţine adresa primului element din listă, care dintre expresiile următoare
poate înlocui punctele de suspensie în secvenţa de instrucţiuni de mai sus astfel încât, în
urma executării acesteia, să fie eliminat ultimul element al listei?

while (...)
 p=p->urm;
delete p->urm; | free (p->urm);
p->urm=NULL;

*/


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


void eliminare(Lista& l) {

	Node<int>* p = l.head;

	while (p->next->next!= NULL) {

		p = p->next;

	}

	delete p->next;

	p->next = NULL;

}


void sol6() {

	Lista l;

	l.add(1);

	l.add(2);

	l.add(3);

	eliminare(l);

	l.afisare();

}