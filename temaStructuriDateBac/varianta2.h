#include "node.h";

#pragma once


/*Se consideră o stivă în care iniţial au fost introduse, în această ordine, elementele cu valorile 
1, 2 şi 3. Se notează cu AD(x) operaţia prin care se adaugă elementul cu valoarea x în 
vârful stivei şi cu EL operaţia prin care se elimină elementul din vârful stivei. Asupra acestei 
stive se execută următoarea secvenţă de operaţii: AD(4);EL;AD(5);EL;AD(6);EL;EL.
a) Care este valoarea elementului din vârful stivei în urma executării acestei secvenţe de 
operaţii? (3p.) 
b) Care este suma valorilor elementelor aflate în stivă în urma executării acestei secvenţe de 
operaţii? */


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

//todo functie ce retuneaza suma elementelor din stiva


int suma(Stiva s) {

	int sum = 0;

	Node<int>* aux = s.top;

	while (aux != NULL) {

		sum += aux->data;

		aux = aux->next;

	}

	return sum;

}


void sol2() {

	Stiva s;

	s.AD(3);

	s.AD(2);

	s.AD(1);

	//s.afisare();

	s.AD(4); 
	
	s.EL(); 
	
	s.AD(5);
	
	s.EL(); 
	
	s.AD(6); 
	
	s.EL(); 
		
	s.EL();

	cout << "a) " << s.top->data << endl;

	cout << "b) " << suma(s) << endl;

}