#include "node.h";

#pragma once


/*Într-o listă liniară simplu înlănţuită, alocată
dinamic, cu cel puţin 4 elemente, fiecare element 
reţine în câmpul urm adresa elementului următor 
sau NULL dacă nu există un element următor, iar 
în câmpul info o valoare întreagă. Ştiind că
variabila p reţine adresa primului element din listă, 
înlocuiţi punctele de suspensie cu expresiile 
corespunzătoare, astfel încât secvenţa alăturată
să calculeze în variabila s suma tuturor valorilor 
elementelor listei. 

s=...;
while ( ... )
{
 p=p->urm;
 s=s+p->info;
}
cout<<s; | printf(”%d”,s);
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

	int s = 0;

	while (p->next!=NULL)
	{
		p = p->next;

		s = s + p->data;

	}

	cout << s;

}


void sol8() {

	Lista l;

	l.add(1);

	l.add(2);

	l.add(3);

	l.add(4);

	functie(l);

}