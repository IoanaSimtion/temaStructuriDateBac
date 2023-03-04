#include "node2.h";

#pragma once


/*O listă liniară simplu înlănţuită, alocată dinamic, 
memorează în câmpul ref al fiecărui nod adresa 
următorului nod din listă sau NULL în cazul în care nu 
există un nod următor. Lista conţine cel puţin 5 noduri, 
adresa primului nod este memorată în variabila p, iar 
variabilele a şi b sunt de acelaşi tip cu p. Adresa cărui nod 
va fi memorată în variabila b, după executarea secvenţei 
alăturate de program?
a=p;
while (a->ref != NULL)
{ b=a;
 a=a->ref;
}
*/


struct Lista {

	Node<int>* p = NULL;

	void add(int data) {

		if (p == NULL) {

			p = new Node<int>();

			p->inf = data;

			p->urm = NULL;

		}
		else {

			Node<int>* nou = new Node<int>();

			Node<int>* aux = p;

			while (aux->urm != NULL) {

				aux = aux->urm;

			}

			aux->urm = nou;

			nou->inf = data;

			nou->urm = NULL;

		}

	}



};


void functie(Lista l) {

	Node<int>* a = l.p;

	Node<int>* b = 0;

	while (a->urm != NULL)
	{
		b = a;

		a = a->urm;

	}

	cout << b->inf;

}


void sol13() {

	Lista l;

	l.add(1);

	l.add(4);

	l.add(4);

	l.add(13);

	l.add(78);

	functie(l);

}