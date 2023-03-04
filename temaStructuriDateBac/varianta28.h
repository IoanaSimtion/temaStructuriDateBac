#include "node2.h"

#pragma once



/*O listă liniară simplu înlănţuită, alocată dinamic, reţine în 
câmpul nr al fiecărui element câte un număr natural, iar în 
câmpul urm, adresa elementului următor din listă sau NULL
dacă nu există un element următor. Lista memorează, în 
acestă ordine, doar numerele: elementele 1, 2, 3, 4, 5.
Ştiind că variabila prim memorează adresa primului element al 
listei şi că p este o variabilă de acelaşi tip cu prim, care sunt, în 
ordine, numerele memorate în elementele listei după executarea 
secvenţei de program alăturate?

p=prim; x=p->nr;
while(p->urm!=NULL)
 {p->nr = p->urm->nr;
 p=p->urm;
 }
p->nr=x
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



void functie(Lista l) {

	Node<int>* p = l. prim; 
	
	int x = p->inf;

	while (p->urm != NULL)
	{
		p->inf = p->urm->inf;

		p = p->urm;

	}

	p->inf = x;

}



void sol28() {

	Lista l;

	l.add(1);

	l.add(2);

	l.add(3);

	l.add(4);

	l.add(5);

	functie(l);

	l.afisare();

}