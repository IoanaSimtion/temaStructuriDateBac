#include "node.h";

#pragma once


/*Stiva S şi coada C memorează numere întregi. În ambele se introduc, în ordine, numerele 1, 
2, 3, 4. Se notează cu SÆC operaţia de extragere a unui element din stiva S şi adăugarea 
acestuia în coada C, iar cu CÆS operaţia de eliminare a unui element din coada C şi 
introducerea acestuia în stiva S. 
Care este ultima valoare introdusă în stiva S şi care este ultima valoare care a fost adăugată
în coada C la executarea următoarei secvenţe de operaţii: CÆS; CÆS; SÆC; CÆS; 
SÆC; SÆC; CÆS; */


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


	void pop(int& data) {

		data = top->data;

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


struct Coada {

	Node<int>* top = NULL;

	void push(int data) {

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

	void pop(int& data) {

		Node<int>* aux = top;

		while (aux->next->next != NULL) {

			aux = aux->next;
			
		}

		data = aux->data;

		aux->next = NULL;

	}


	void afisare() {

		Node<int>* aux = top;

		
		while (aux != NULL) {

			cout << aux->data << ' ';

			aux = aux->next;

		}
	}

	//todo functie ce returneaza ultima valoare din coada


	int ultimaValoare() {

		Node<int>* aux = top;

		while (aux->next != NULL) {

			aux = aux->next;

		}

		return aux->data;

	}

};


void operatia1(Stiva& s, Coada& c) {

	int data;

	s.pop(data);

	c.push(data);


}


void operatia2(Stiva& s, Coada& c) {

	int data;

	c.pop(data);

	s.push(data);

}


void sol21() {

	Stiva s;

	Coada c;

	s.push(1);

	c.push(1);

	s.push(2);

	c.push(2);

	s.push(3);

	c.push(3);

	s.push(4);

	c.push(4);

	operatia2(s, c);

	operatia2(s, c);

	operatia1(s, c);

	operatia2(s, c);

	operatia1(s, c);

	operatia1(s, c);

	operatia2(s, c);

	cout << "Ultima valoare intordusa in stiva: " << s.top->data << endl << endl;

	cout << "Ultima valoare adaugata in coada: " << c.ultimaValoare() << endl;



}