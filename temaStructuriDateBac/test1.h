#pragma once
using namespace std;
#include <iostream>
#include <fstream>

//S2, 1c

void algoritm() {

	int n, m, c;

	cin >> n;

	m = 10;

	if (n == 0) {

		m = 0;

	}
	else {

		do {

			c = n % 10;

			n = n / 10;

			if (c <= m) {

				m = c;

			}
			else {

				m = -1;

			}

		} while (n != 0);

	}

	cout << m;

}


//S2, 2

/*Utilizând metoda backtracking, sunt generate toate numerele din intervalul [100,999], cu proprietatea
că au cifrele în ordine crescătoare, cifrele aflate pe poziții consecutive sunt de paritate diferită, iar suma
lor este egală cu 14. Scrieți toate numerele generate, în ordinea obținerii lor.*/


//todo functie ce verifica daca a un nr are cifrele in ord cresc

bool cifreOrdCresc(int n) {

	while (n > 9) {

		if (n % 10 < (n / 10) % 10) {

			return false;

		}

		n /= 10;

	}

	return true;

}


//todo functie ce verifica daca cifrele aflate pe poziții consecutive sunt de paritate diferită


bool cifreParitateDif(int n) {

	while (n > 9) {

		if ((n % 10) % 2 == 0 && ((n / 10)) % 10 % 2 == 0) {

			return false;

		}
		
		if ((n % 10) % 2 == 1 && ((n / 10)) % 10 % 2 == 1) {

			return false;

		}

		n /= 10;

	}

	return true;

}


//todo functie ce returneaza suma cifrelor unui nr


int sumaCifr(int n) {

	int s = 0;

	while (n) {

		s += n % 10;

		n /= 10;

	}

	return s;

}


//backtracking


int valid(int n) {

	if (!cifreOrdCresc(n) || !cifreParitateDif(n)) {

		return false;

	}

	return true;

}


void back() {

	for (int i = 100; i <= 999; i++) {

		if (valid(i)) {

			cout << i << ' ';

		}

	}

}


//S3, 1

/*Subprogramul divX are doi parametri, n și x, prin care primește câte un număr natural din intervalul
[2,50]. Subprogramul afișează pe ecran, în ordine descrescătoare, separate prin câte un spațiu,
primele n numere naturale nenule divizibile cu x.
Scrieți definiția completă a subprogramului.
Exemplu: dacă n=4 și x=15 în urma apelului se afișează numerele 60 45 30 15*/


void divX(int n, int x) {

	while (n && n * x >= x) {

		cout << x * n << ' ';

		n--;

	}
}


//S3, 2

/*Scrieți un program C/C++ care citește de la tastatură numărul natural n (n[2,102]) și elementele unui
tablou bidimensional cu n linii și n coloane, numere naturale din intervalul [0,109].
Programul afișează pe ecran, separate prin câte un spațiu, elementele primului pătrat
concentric, parcurs în sens invers al acelor de ceasornic, începând din colțul său stângasus, ca în exemplu. Primul pătrat concentric este format din prima și ultima linie, prima și
ultima coloană a tabloului
Exemplu: pentru n=5 și tabloul alăturat, se afișează pe ecran numerele
1 2 3 4 5 6 7 8 9 0 2 4 6 8 1 3

1 3 1 8 6
2 9 2 7 4
3 5 8 5 2
4 1 6 3 0
5 6 7 8 9

*/


//todo functie ce citeste o matrice


void citireMatrice(int a[100][100], int& n) {

	cin >> n;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			cin >> a[i][j];

		}

	}

}


//todo functie ce afiseaza patratul concentric al matricei

void afisarePatratConcentric(int a[100][100], int n) {

	for (int i = 0; i < n; i++) {

		cout << a[i][0] << ' ';

	}

	for (int j = 1; j < n; j++) {

		cout << a[n - 1][j] << ' ';

	}

	for (int i = n - 2; i >= 0; i--) {

		cout << a[i][n - 1] << ' ';

	}

	for (int j = n - 2; j > 0; j--) {

		cout << a[0][j] << ' ';

	}

}


void sol2() {

	int a[100][100], n;

	citireMatrice(a, n);

	afisarePatratConcentric(a, n);

}


//S3, 3

/*Fișierul bac.in conține cel mult 106 numere naturale din intervalul [0,109], separate prin câte un
spațiu. Se cere să se afișeze pe ecran, în ordine descrescătoare, cele mai mari două numere de două
cifre distincte care NU se află în fișier. Numerele afișate sunt separate printr-un spațiu, iar dacă nu
există două astfel de numere, se afișează pe ecran mesajul nu exista. Proiectați un algoritm eficient
din punctul de vedere al timpului de executare.
Exemplu: dacă fișierul bac.in conține numerele 12 235 123 67 98 6 96 94 123 67 98 100
se afișează pe ecran, în această ordine, numerele 97 95.*/


//todo functie ce citeste un vector


void citireVector(int v[], int& n) {

	ifstream f("vector.txt");

	n = 0;

	while (!f.eof()) {

		f >> v[n];

		n++;

	}

}


//todo functie ce ordoneaza un vector


void sort(int v[], int n) {

	bool flag = 0;

	do {

		flag = 1;

		for (int i = 0; i < n - 1; i++) {

			if (v[i] > v[i + 1]) {

				int aux = v[i];

				v[i] = v[i + 1];

				v[i + 1] = aux;

				flag = 0;

			}

		}

	} while (flag == 0);

}


//todo functie ce verifica daca un nr se afla in sir


bool cautareBinara(int v[], int n, int x) {

	int st = 0, dr = n - 1;

	while (st <= dr) {

		int mij = (st + dr) / 2;

		if (v[mij] == x) {

			return true;

		}
		else {

			if (v[mij] < x) {

				st = mij + 1;

			}
			else {

				dr = mij - 1;

			}

		}

	}

	return false;

}


//todo functie ce afiseaza nr din vector


void afisareNumere(int v[], int n) {

	int afisare = 0;

	for (int i = 99; i > 9 && afisare < 2; i--) {

		if (cautareBinara(v, n, i) == 0) {

			cout << i << ' ';

			afisare++;

		}

	}

	if (afisare < 2) {

		cout << "Nu exista";

	}

}


void sol3() {

	int v[100], n;

	citireVector(v, n);

	afisareNumere(v, n);

}