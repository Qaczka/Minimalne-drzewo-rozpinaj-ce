#include <iostream>
#include <list>
#include <algorithm> // potrzebne do przeszukiwania listy dla danej wartosci

using namespace std;

struct K{
	int waga;
	int bok1;
	int bok2;
};

bool compare(const K& a, const K& b)//musialem napisac do porownywania po wadze do sortowania
{
	return (a.waga < b.waga);//chce wiedziec czy pierwszy jest mniejszy od drugiego i iteruje n razy i potem n czyli O(n*n)
}


int main() {
	list<int> las_L = { 1,2,4,3,5,6 };

	list<K> zbior_K;
	list<K> wynik;
	list<K> wynik_drugiego;


	int algorytm;
	cout << "Ktory algorytm chcesz wlaczyc? (Kruskala, Prima, Boruvki){1,2,3}" << endl;
	cin >> algorytm;



		K boki12;
		boki12.waga = 1;
		boki12.bok1 = 1;
		boki12.bok2 = 2;
		zbior_K.push_back(boki12);

		K boki13;
		boki13.waga = 2;
		boki13.bok1 = 1;
		boki13.bok2 = 3;
		zbior_K.push_back(boki13);


		K boki14;
		boki14.waga = 2;
		boki14.bok1 = 1;
		boki14.bok2 = 4;
		zbior_K.push_back(boki14);


		K boki34;
		boki34.waga = 3;
		boki34.bok1 = 3;
		boki34.bok2 = 4;
		zbior_K.push_back(boki34);


		K boki45;
		boki45.waga = 3;
		boki45.bok1 = 4;
		boki45.bok2 = 5;
		zbior_K.push_back(boki45);


		K boki24;
		boki24.waga = 4;
		boki24.bok1 = 2;
		boki24.bok2 = 4;
		zbior_K.push_back(boki24);


		K boki25;
		boki25.waga = 5;
		boki25.bok1 = 2;
		boki25.bok2 = 5;
		zbior_K.push_back(boki25);

		zbior_K.sort(compare);
		cout << "Zawartoœæ listy K: " << endl;
		for (list<K>::iterator iter1 = zbior_K.begin(); iter1 != zbior_K.end(); iter1++)
			cout << iter1->waga << " " << iter1->bok1 << " " << iter1->bok2 << endl;


		las_L.sort();//greater<int>() daloby od najwiekszej - list sort stl

		cout << "Zawartoœæ listy: ";
		for (list<int>::iterator iter = las_L.begin(); iter != las_L.end(); iter++)
			cout << *iter << ' ';
		cout << endl;

		if (algorytm == 1)
		{

		K tymczasowy;
		bool contains;
		bool contains2;
		bool czy_dodal;

		while (zbior_K.empty() != true)
		{
			czy_dodal = false;
			tymczasowy = *zbior_K.begin();
			contains = (find(las_L.begin(), las_L.end(), tymczasowy.bok1) != las_L.end());
			if (contains == true)
			{
				wynik.push_front(tymczasowy);
				czy_dodal = true;
				las_L.remove(tymczasowy.bok1);
			}
			contains2 = (find(las_L.begin(), las_L.end(), tymczasowy.bok2) != las_L.end());
			if (contains2 == true)
			{
				las_L.remove(tymczasowy.bok2);
				if (czy_dodal == false)
				{
					wynik.push_front(tymczasowy);
				}
			}
			zbior_K.pop_front();
		}

		cout << "Boki koncowe: " << endl;
		int suma = 0;
		for (list<K>::iterator iter1 = wynik.begin(); iter1 != wynik.end(); iter1++)
		{
			cout << iter1->bok1 << " " << iter1->bok2 << endl;
			suma += iter1->waga;
		}
		cout << "Suma wag to: " << suma << endl;
	}

	if (algorytm == 2)
	{
		int bok_zaczynajacy;
		cout << "Prosze wpisz bok zaczynajacy: " << endl;
		cin >> bok_zaczynajacy;
		//las_L.remove(bok_zaczynajacy);

		bool contains;
		bool contains2;
		int tymczasowy;
		K tymczasowy_struct;
		bool nic_nie_znaleziono;
		bool koniec = false;
		int pozycja = 0;

		while (koniec == false)
		{
			nic_nie_znaleziono = true;
			for (list<K>::iterator iter1 = zbior_K.begin(); iter1 != zbior_K.end(); iter1++)
			{
				tymczasowy = iter1->bok2;
				contains = (find(las_L.begin(), las_L.end(), tymczasowy) != las_L.end());
				tymczasowy = iter1->bok1;
				contains2 = (find(las_L.begin(), las_L.end(), tymczasowy) != las_L.end());

				if ((iter1->bok1 == bok_zaczynajacy && contains == true) || (iter1->bok2 == bok_zaczynajacy&&contains2 == true))//sprawdzam czy jednym z elementow jest poszukiwana liczba i czy ta druga nie byla juz uzywana
				{
					wynik.push_front(*iter1);//wartosc iteratora powinno caly struct (i jest)
					nic_nie_znaleziono = false;
				}
			}

			if (nic_nie_znaleziono == true)
			{
				koniec = true;
			}

			las_L.remove(bok_zaczynajacy);

			wynik.sort(compare);

			cout << "Posortowane wyniki: " << endl;
			for (list<K>::iterator iter1 = wynik.begin(); iter1 != wynik.end(); iter1++)
				cout << iter1->waga << " " << iter1->bok1 << " " << iter1->bok2 << endl;

			for (list<K>::iterator iter1 = wynik.begin(); iter1 != wynik.end(); iter1++)
			{
				//tymczasowy_struct = *wynik.begin();
				tymczasowy_struct = *iter1;
				contains = (find(las_L.begin(), las_L.end(), tymczasowy_struct.bok1) != las_L.end());
				contains2 = (find(las_L.begin(), las_L.end(), tymczasowy_struct.bok2) != las_L.end());
				pozycja++;

				if (contains == true)
				{
					bok_zaczynajacy = tymczasowy_struct.bok1;
					wynik.erase(iter1);
					break;
				}
				else if (contains2 == true)
				{
					bok_zaczynajacy = tymczasowy_struct.bok2;
					wynik.erase(iter1);
					break;
				}
			}
			wynik_drugiego.push_front(tymczasowy_struct);
		//	wynik.remove(*(&tymczasowy_struct));

		}
		//las_L.remove(bok_zaczynajacy);

		cout << "Boki koncowe: " << endl;
		int suma = 0;
		for (list<K>::iterator iter1 = wynik_drugiego.begin(); iter1 != wynik_drugiego.end(); iter1++)
		{
			cout << iter1->bok1 << " " << iter1->bok2 << endl;
			suma += iter1->waga;
		}
		cout << "Suma wag to: " << suma << endl;

	}
	system("PAUSE");
	return 0;
}