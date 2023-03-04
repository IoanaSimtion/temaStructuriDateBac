#include "node.h";


#pragma once

/*Se consideră o stivă în care iniţial au fost introduse, în această ordine, 
elementele cu valorile 1, 2 şi 3, ca în figura alăturată. Se notează cu 
AD(x) operaţia prin care se adaugă elementul cu valoarea x în vârful 
stivei şi cu EL operaţia prin care se elimină elementul din vârful stivei. 
Reprezentaţi, după modelul alăturat, conţinutul stivei, rezultat în urma 
executării secvenţei de operaţii: AD(4);EL;EL;AD(5);EL. */



struct Stiva {

	Node<int>* top = NULL;


	void AD(int data) {

		if (top == NULL) {

			top = new Node<int>();

			top->data = data;

			top->next = NULL;

		}
		else {

			Node<int>* nou = new Node<int>();

			nou->data = data;

			nou->next = top;

			top = nou;

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


void sol4() {

	Stiva s;

	s.AD(1);

	s.AD(2);

	s.AD(3);

	s.AD(4);

	s.EL();

	s.EL();

	s.AD(5);
	
	s.EL();

	s.afisare();
}