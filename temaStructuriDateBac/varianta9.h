#include "node.h";

#pragma once


/*Într-o listă liniară simplu înlănţuită, alocată dinamic, fiecare element reţine în câmpul info
o valoare întreagă, iar în câmpul urm adresa elementului următor din listă sau NULL dacă
nu există un element următor. Variabila p reţine adresa primului element din listă.
Lista conţine, în această ordine, 
pornind de la primul element, 
valorile: 2, 3, 4, 5, 6, 7, 8. Ce se va 
afişa în urma executării secvenţei 
de instrucţiuni alăturată? 

while(p!=NULL && p->urm!=NULL) {
 cout<<p->info; | printf(“%d”,p->info);
 p->urm=p->urm->urm;
 p=p->urm;

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


void functie(Lista l) {

	Node<int>* p = l.head;

	while (p != NULL && p->next != NULL) {

		cout << p->data << ' ';

		p->next = p->next->next;

		p = p->next;

	}

}


void sol9() {

	Lista l;

	l.add(2);

	l.add(3);

	l.add(4);

	l.add(5);

	l.add(6);

	l.add(7);

	l.add(8);

	functie(l);
}