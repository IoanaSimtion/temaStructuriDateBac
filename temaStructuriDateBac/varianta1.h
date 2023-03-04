#include "node.h";

#pragma once

/*Se consideră o coadă în care iniţial au fost introduse, în această ordine, elementele cu
valorile 1 şi 2:
1 2.Se notează cu AD(x) operaţia prin care se adaugă elementul cu
valoarea x în coadă şi cu EL operaţia prin care se elimină un element din coadă.Câte
elemente va conţine coada în urma executării secvenţei de operaţii :
AD(4); EL; EL; AD(5); EL; AD(3) ?*/


struct Coada {

	Node<int>* top = NULL;

	void AD(int data) {

		if (top == NULL) {

			top = new Node<int>();

			top->data = data;

			top->next = NULL;

		}
		else {

			Node<int>* nou = new Node<int>();

			Node<int>* aux = top;

			while (aux->next != NULL) {

				aux = aux->next;

			}

			aux->next = nou;

			nou->data = data;

			nou->next = NULL;

		}

	}

	void EL() {

		top = top->next;

	}

	void afisare() {

		Node<int>* aux = top;

		while (aux != NULL) {

			cout << aux->data << ' ';

			aux = aux->next;

		}

	}


};


//todo funtie ce returneaza nr de elemente dintr o coada

int nrElemente(Coada c) {

	Node<int>* aux = c.top;

	int ct = 0;

	while (aux != NULL) {

		ct++;

		aux = aux->next;

	}

	return ct;

}


void sol1() {

	Coada c;

	c.AD(1);

	c.AD(2);

	//c.afisare();

	c.AD(4);

	c.EL(); 

	c.EL(); 

	c.AD(5); 

	c.EL();

	c.AD(3);

	cout << nrElemente(c);


}