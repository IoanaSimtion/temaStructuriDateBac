#include "node2.h";

#pragma once


/*Într-o listă liniară simplu înlănţuită, alocată dinamic, fiecare element reţine în câmpul ref
adresa următorului nod din listă sau NULL în cazul ultimului element al listei, iar în câmpul 
inf un număr întreg. 
1. 
Adresa primului element al 
listei este reţinută în variabila 
prim, iar p este o variabilă de 
acelaşi tip cu prim. Ce va 
afişa pe ecran în urma 
executării secvenţei de 
program alăturate?

p=prim;
while ((p->inf%2==0) && (p!=NULL))
 p=p->ref;
if (p!=NULL)
 cout<<(p->inf); | printf("%d",p->inf);
else
 cout<<"NU"; | printf("NU")
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

};


void funtie(Lista l) {

	Node<int>* p = l.prim;

	while ((p->inf % 2 == 0) && (p != NULL)) {

		p = p->urm;

	}

	if (p != NULL) {

		cout << p->inf << ' ';

	}
	else {

		cout << "NU";

	}
}


void sol15() {

	Lista l;

	l.add(12);

	l.add(2);

	l.add(3);

	l.add(50);

	l.add(21);

	l.add(10);

	funtie(l);

}