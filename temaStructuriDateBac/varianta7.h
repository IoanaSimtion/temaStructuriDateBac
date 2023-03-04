#include "node.h";

#pragma once


/*O listă liniară simplu înlănţuită cu 
cel puţin două elemente, alocată
dinamic, reţine în câmpul info al 
fiecărui element câte un număr 
natural de maximum 4 cifre, iar în 
câmpul urm adresa elementului 
următor din listă sau NULL dacă nu 
există un element următor. 

Dacă variabila p reţine adresa primului element al listei atunci, în urma executării secvenţei
de program de mai sus se afişează întotdeauna: (4p.)
a. cea mai mică dintre valorile memorate de
elementele din listă
b. cea mai mare dintre valorile memorate de
elementele din listă
c. valoarea memorată de penultimul
element din listă
d. valoarea memorată de primul element din
listă

while (p->urm!=NULL)
{ if (p->urm->info<p->info)
 p->urm->info=p->info;
 p=p->urm;
}
 cout<<p->info;
 | printf(“%d“,p->info);
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

	while (p->next != NULL)
	{
		if (p->next->data < p->data)
			p->next->data = p->data;
		p = p->next;
	}
	cout << p->data;
}


void sol7() {

	Lista l;

	l.add(1);

	l.add(5);

	l.add(7);

	l.add(4);

	functie(l);

}