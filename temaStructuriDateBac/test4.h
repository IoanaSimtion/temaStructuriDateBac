#pragma once
using namespace std;
#include <iostream>
#include <fstream>


//S2, 2

/*Variabila c memorează date despre o ciocolată: denumirea, gramajul și data expirării. Știind că
expresiile C/C++ de mai jos au ca valori numere naturale reprezentând gramajul, respectiv data (ziua,
luna și anul) expirării produsului, scrieți definiția unei structuri cu eticheta ciocolata, care permite
memorarea datelor precizate pentru o ciocolată, și declarați corespunzător variabila c.*/


struct Data {

	string zi, luna, an;

};

struct Ciocolata {

	int gramaj;

	Data data;

};


//S3, 1

/*Un joc online cu n jetoane poate fi jucat de un grup de k (k≥2) jucători, numai dacă toate cele n jetoane
pot fi distribuite în mod egal celor k jucători.
Subprogramul joc are un singur parametru, n, prin care primește un număr natural (n[2,104]),
reprezentând numărul de jetoane ale unui joc de tipul precizat. Subprogramul returnează numărul
valorilor distincte pe care le poate avea k pentru acest joc.
Scrieți definiția completă a subprogramului.
Exemplu: dacă n=12, atunci subprogramul returnează numărul 5 (cele 12 jetoane se pot distribui în
mod egal pentru o grupă de 2 jucători, de 3 jucători, de 4 jucători, de 6 jucători sau de 12 jucători).*/


int joc(int n) {

	int ct = 0;

	for (int k = 2; k <= n; k++) {

		if (n % k == 0) {

			ct++;

		}
	}

	return ct;

}


//S2, 2

/*Scrieţi un program C/C++ care citeşte de la tastatură numere naturale din intervalul [2,102]: m, n şi
elementele unui tablou bidimensional cu m linii şi n coloane. Programul afișează pe ecran, pentru fiecare
linie a sa, cea mai mare dintre valorile strict mai mici decât 21 memorate în aceasta, sau mesajul
nu exista, dacă nu există nicio astfel de valoare pe linia respectivă. Numerele, respectiv mesajele,
sunt afișate pe linii separate ale ecranului, în ordinea liniilor corespunzătoare din tablou.
Exemplu: pentru m=3, n=5 și tabloul alăturat se afişează pe ecran
16
nu exista
9

6 16 21 4 90
92 26 36 95 80
5 2 9 7 3

*/


void citireMatrice(int a[100][100], int& m, int& n) {

	ifstream f("matr.txt");

	f >> m >> n;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			f >> a[i][j];

		}

	}

}


void afisareLiniiMax(int a[100][100], int m, int n) {

	for (int i = 0; i < m; i++) {

		int max = 0;

		for (int j = 0; j < n; j++) {

			if (a[i][j]<21 && a[i][j]>max) {

				max = a[i][j];

			}

		}

		if (max > 0) {

			cout << max << endl;

		}
		else {

			cout << "nu exista" << endl;

		}

	}

}