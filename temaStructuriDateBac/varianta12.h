#include "node2.h";

#pragma once


/*Într-o listă liniară simplu înlănţuită, alocată dinamic, fiecare element reţine în câmpul inf 
un număr întreg, iar în câmpul urm adresa următorului nod din listă sau NULL în cazul 
ultimului nod al listei. Adresa primului element al listei este reţinută în variabila prim, iar p
este o variabilă de acelaşi tip cu prim. Dacă în listă sunt memorate, în această ordine, 
numerele 1, 2, 3, 4 ca în figura de mai jos, care va fi conţinutul listei în urma executării 
secvenţei de instrucţiuni alăturate? 

p=prim;
prim=p->urm;
p->urm=NULL;
prim->urm->urm->urm=p;
*/


struct Lista {

	Node<int>* prim = NULL;

	void add(int data) {

		if (prim == NULL) {

			prim = new Node<int>();

			prim->inf = data;

			prim->urm = NULL;

		}
		else {

			Node<int>* nou = new Node<int>();

			Node<int>* aux = prim;

			while (aux->urm != NULL) {

				aux = aux->urm;

			}

			aux->urm = nou;

			nou->inf = data;

			nou->urm = NULL;

		}

	}


	void afisare() {

		Node<int>* aux = prim;

		while (aux != NULL) {

			cout << aux->inf << ' ';

			aux = aux->urm;

		}

	}

};


void functie(Lista& l) {

	Node<int>* p = l.prim;

	l.prim = p->urm;

	p->urm = NULL;

	l.prim->urm->urm->urm = p;

}


void sol12() {

	Lista l;

	l.add(1);

	l.add(2);

	l.add(3);

	l.add(4);

	functie(l);

	l.afisare();

}