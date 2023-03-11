#pragma once
using namespace std;
#include <iostream>
#include <fstream>

//S2, 1c

void algoritm() {

	int n, s, c1, c2;

	cin >> n;

	s = 1;

	c1 = n % 10;

	n = n / 10;

	c2 = n % 10;

	if (c1 == c2) {

		s = 0;

	}
	else {

		if (c1 < c2) {

			s = -1;

		}

	}
	if ((c1 - c2) * s > 0 && n > 9) {

		c1 = n % 10;

		n = n / 10;

		c2 = n % 10;

	}
	do {

		c1 = n % 10;

		n = n / 10;

		c2 = n % 10;

	} while ((c1 - c2) * s > 0 && n > 9);

	cout << s << ' ' << n;

}


//S3, 1:

/*Subprogramul factori are doi parametri, n și m, prin care primește câte un număr natural din intervalul
[1,109]. Subprogramul returnează numărul valorilor prime care apar la aceeași putere atât în
descompunerea în factori primi a lui n, cât și în descompunerea în factori primi a lui m.
Scrieți definiția completă a subprogramului.
Exemplu: dacă n=16500 și m=10780, atunci subprogramul returnează 2 (16500=2235311,
10780=2257211). */


int factori(int n, int m) {

	int putereN = 0, putereM = 0, d = 2, contor = 0;

	do {

		putereN = 0;

		putereM = 0;

		while (n % d == 0) {

			n /= d;

			putereN++;

		}

		while (m % d == 0) {

			m /= d;
			
			putereM++;

		}

		if (putereN == putereM && putereN != 0) {

			contor++;

		}

		d++;

	} while (n > 1 && m > 1);

	return contor;

}


//S3, 2

/*Scrieți un program C/C++ care citește de la tastatură un număr natural, n (n∈[2,20]), și construiește
în memorie un tablou bidimensional cu n linii și n coloane, astfel încât fiecare linie a sa are proprietățile:
• elementul situat pe diagonala secundară are valoarea n;
• începând de la diagonala secundară, spre stânga, elementele formează un șir strict descrescător de
numere consecutive, iar începând de la diagonala secundară, spre dreapta, elementele formează tot
un șir strict descrescător de numere consecutive.
Programul afișează pe ecran tabloul construit, fiecare linie a tabloului pe câte o linie a
ecranului, cu elementele aflate pe aceeași linie separate prin câte un spațiu.*/


void generareMatrice(int a[100][100], int n) {

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (i + j == n - 1) {

				a[i][j] = n;

			}

			if (i + j < n - 1) {

				a[i][j] = i + j + 1;
					
			}

			if (i + j > n - 1) {

				a[i][j] = abs(j - i) + 1;

			}

		}

	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			cout << a[i][j] << ' ';

		}

		cout << endl;
	}

}


//S3, 3

/*Fișierul bac.in conține un șir de cel mult 106 numere întregi din intervalul [-109,109], separate prin
câte un spațiu. Cel puțin un număr din șir este pozitiv.
Se cere să se afișeze pe ecran lungimea maximă a unei secvențe a șirului care fie începe, fie se încheie
cu un număr pozitiv. O secvență este formată din termeni aflați pe poziții consecutive în șir, iar lungimea
secvenței este egală cu numărul de termeni ai acesteia. Proiectați un algoritm eficient din punctul de
vedere al memoriei utilizate și al timpului de executare.
*/


void secventa() {

	ifstream f("bac.in");

	bool flag = 0;

	int x, d = 0, inceput = 0, sfarsit = 0;

	while (f >> x) {

		d++;

		if (x > 0) {

			flag = 1;

			inceput = d;

		}

		if (flag == 9 || sfarsit == 0) {

			sfarsit++;

		}
	}

	if (inceput > d - sfarsit) {

		cout << inceput;

	}
	else {

		cout << sfarsit;

	}

}