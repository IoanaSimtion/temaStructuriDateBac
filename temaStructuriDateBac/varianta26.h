#include "node.h";

#pragma once

#include <fstream>


/*Într-o stivă care memorează numere, o valoare x poate fi adăugată
numai dacă în vârful stivei se află un element cu o valoare strict mai mare 
decât x; în caz contrar sunt eliminate toate elementele care nu 
îndeplinesc această condiţie şi apoi se adaugă valoarea x. 
Exemplu: pentru stiva din fig.1, adăugarea elementului 11 este 
precedată de eliminarea elementelor ce conţin valorile 2 şi 10. După
adăugare, stiva va avea conţinutul din fig.2. 
Dacă stiva este iniţial vidă, care este numărul elementelor aflate în această stivă după
adăugarea, respectând condiţiile de mai sus, în ordine, a numerelor 20,5,16,9,3,7,5,4,8 ?*/


struct Stiva {

	Node<int>* top = NULL;


	void push(int data) {

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
	

	void pop() {

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


//todo functie ce adauga elemente pe stiva

void addStiva(Stiva& s) {

	int x;

	ifstream f("numere.txt");

	while (!f.eof()) {

		f >> x;

		if (s.top == NULL) {

			s.push(x);

		}
		else {

			//cout << x << ' ';

			if (x < s.top->data) {

				s.push(x);

			}
			else {

				while (x >= s.top->data) {

					s.pop();

				}

				s.push(x);

			}

		}

	}

}


void sol26() {

	Stiva s;

	addStiva(s);

	s.afisare();

}