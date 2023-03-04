#include "node.h";

#pragma once

#include <fstream>



/*Se consideră o listă liniară simplu înlănţuită alocată dinamic în care fiecare nod memorează
în câmpul info un cuvânt format din cel mult 20 de caractere, doar litere mari ale 
alfabetului englez, iar în câmpul urm, adresa următorului nod al listei sau NULL dacă nu 
există un element următor. 
Scrieţi un program C/C++ care citeşte de la tastatură un număr natural n (n≤100) şi apoi n
cuvinte distincte, fiecare cuvânt fiind format din cel mult 20 de caractere, doar litere mari ale 
alfabetului englez, şi construieşte o listă simplu înlănţuită, cu acele cuvinte citite, care încep 
şi se termină cu aceeaşi literă. Cuvintele se vor memora în listă în ordine inversă citirii lor. */


struct Lista {

	Node<string>* head = NULL;

	void addStart(string data) {

		if (head == NULL) {

			head = new Node<string>();

			head->data = data;

			head->next = NULL;

		}
		else {

			Node<string>* nou = new Node<string>();

			nou->data = data;

			nou->next = head;

			head = nou;

		}


	}


	void afisare() {

		Node<string>* aux = head;

		while (aux != NULL) {

			cout << aux->data << ' ';

			aux = aux->next;

		}

	}


};


//todo functie ce verifica daca un cuv incepe si se termina cu aceeasi litera


bool aceeasiLitera(string cuv) {

	char c = cuv[0];

	if (c == cuv[cuv.length()-1]) {

		return true;

	}

	return false;

}


//todo funtie ce citeste cuvinte si adauga in lista cuv cu o anumita proprietate

void citireAdaugare(Lista& l, string cuv, int n) {

	ifstream f("cuvinte.txt");

	for (int i = 0; i < n; i++) {

		f >> cuv;

		if (aceeasiLitera(cuv)) {

			l.addStart(cuv);

		}

	}

}


void sol31() {

	Lista l;

	string cuv;

	int n;

	cout << "n=";

	cin >> n;

	citireAdaugare(l, cuv, n);

	l.afisare();
	

}