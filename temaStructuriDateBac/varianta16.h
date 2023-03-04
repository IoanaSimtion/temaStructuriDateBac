#include "node2.h";

#pragma once


/*Într-o listă liniară simplu înlanţuită, alocată dinamic, fiecare element conţine în câmpul nr un 
număr real, iar în câmpul urm adresa elementului următor sau NULL dacă nu există un 
element următor. Lista are cel puţin două elemente, iar variabila x memorează adresa 
primului element din listă. Cu ce pot fi completate punctele de suspensie din secvenţa 
următoare, astfel încât, în urma executării, să afişeze cuvântul ADEVARAT dacă media 
aritmetică dintre valorile câmpului nr ale primelor două elemente din listă este mai mică sau 
cel puţin egală cu 4.75, respectiv cuvântul FALS în caz contrar?*/



struct Lista {

	Node<float>* x = NULL;

	void add(float data) {

		if (x == NULL) {

			x = new Node<float>();

			x->inf = data;

			x->urm = NULL;

		}
		else {

			Node<float>* nou = new Node<float>();

			Node<float>* aux = x;

			while (aux->urm != NULL) {

				aux = aux->urm;

			}

			aux->urm = nou;

			nou->inf = data;

			nou->urm = NULL;

		}

	}

};

//todo functie ce verifica dacă media aritmetică dintre valorile câmpului nr ale primelor 
//două elemente din listă este mai mică saucel puţin egală cu 4.75


void functie(Lista l) {

	if ((l.x->inf + l.x->urm->inf) / 2 <= 4.75) {

		cout << "ADEVARAT";

	}
	else {

		cout << "FALS";

	}

}



void sol16() {

	Lista l;

	l.add(2.4);

	l.add(3.213);

	l.add(32);

	l.add(15.98);

	functie(l);

}