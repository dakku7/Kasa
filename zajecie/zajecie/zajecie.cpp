#include<iostream>
#include <fstream>

using namespace std;


class kasa {
private:
	bool zamkniety;
	double cala_ilosc;
	int b10, b20, b50, b100, b200;
	int gr1, gr2, gr5, gr10, gr20, gr50;
	int m5, m10, m25;

public:
	kasa() {
		zamkniety = true;
		cala_ilosc = 0;
		b10 = b20 = b50 = b100 = b200 = 0;
		gr1 = gr2 = gr5 = gr10 = gr20 = gr50 = 0;
		m5 = m10 = m25 = 0;

		wczytajZPliku(); // Wczytuje dane z pliku przy tworzeniu obiektu
	}

	bool sprawdzeniaUspawiedWyjec(int& a, int& ile_chesz) {
		if (a >= ile_chesz) {
			cout << "Nie masz wystarczajacej ilosci!\n";
			return true;
		}
	}

	void calailosc() {
		cala_ilosc = (b10 * 10) + (b20 * 20) + (b50 * 50) + (b100 * 100) + (b200 * 200) + (m5 * 1) + (m10 * 2) + (m25 * 5) + (gr1 * 0.01) + (gr2 * 0.02) + (gr5 * 0.05) + (gr10 * 0.1) + (gr20 * 0.2) + (gr50 * 0.5);
		cout << "Cala kasa wynosi: " << cala_ilosc << "zl\n" << endl;
	}

	void zapiszPlik() {
		ofstream plik("data.txt"); // Tworzy plik o nazwie data.txt
		if (!plik) {
			cout << "Nie udalo sie otworzyc pliku!" << endl;
			return;
		}
		// Zapisuje dane do pliku

		plik << b10 << " " << b20 << " " << b50 << " " << b100 << " " << b200 << endl;
		plik << gr1 << " " << gr2 << " " << gr5 << " " << gr10 << " " << gr20 << " " << gr50 << endl;
		plik << m5 << " " << m10 << " " << m25 << endl;

		plik.close();

	}


	void wczytajZPliku() {
		ifstream plik("data.txt"); // Otwiera plik do odczytu
		if (!plik) {
			cout << "Nie można otworzyć pliku do odczytu! Ustawienia domyślne.\n";
			return;
		}
		// Wczytuje dane z pliku

		plik >> b10 >> b20 >> b50 >> b100 >> b200;
		plik >> gr1 >> gr2 >> gr5 >> gr10 >> gr20 >> gr50;
		plik >> m5 >> m10 >> m25;

		plik.close();
	}

	void otworz() {
		if (!zamkniety) return;
		zamkniety = false;
		cout << "\Kasa zostala otwarta!\n";
	}

	void zamknij() {
		if (zamkniety) {
			cout << "Kasa jest juz zamknieta!\n";
			return;
		}
		else {
			zamkniety = true;
			cout << "\Kasa zostala zamknieta!\n";
		}
	}

	void sprawdzenieUjemnosci(int& a) {
		if (a < 0) {
			cout << "Nie można dodać ujemnej ilosci!\n";
			return;
		}
	}

	bool sprwadzenieZamnkiecia() {
		if (zamkniety) {
			cout << "Kasa jest zamknieta!\n";
			return true;
		}
	}

	void wyswietl() {
		calailosc();

		if (sprwadzenieZamnkiecia()) {
			return;
		}

		cout << "\tStan kasy\n";
		cout << "Banknoty:\n";
		cout << "10zl: " << b10 << "\n20zl: " << b20 << "\n50zl: " << b50 << "\n100zl: " << b100 << "\n200zl: " << b200 << "\n";
		cout << "Monety:\n";
		cout << "1zl: " << m5 << "\n2zl: " << m10 << "\n5zl: " << m25 << "\n";
		cout << "Grosze:\n";
		cout << "1gr: " << gr1 << "\n2gr: " << gr2 << "\n5gr: " << gr5 << "\n10gr: " << gr10 << "\n20gr: " << gr20 << "\n50gr: " << gr50;
		cout << endl;
	}

	void dodaj() {

		if (sprwadzenieZamnkiecia()) {
			return;
		}


		cout << "[1] Dodaj banknoty\n[2] Dodaj monety zl\n[3] Dodaj monety gr\n";

		int wybor;
		cout << "Wybierz opcje: "; cin >> wybor;

		switch (wybor) {
		case 1:
			cout << "\tPodaj nominal banknotu\n[1] 10 \n[2] 20 \n[3] 50 \n[4] 100 \n[5] 200 \n ";
			int nom;
			cin >> nom;
			cout << "Ile masz banknotow tego nominalu? ";
			int il_chesz;
			cin >> il_chesz;

			sprawdzenieUjemnosci(il_chesz);

			switch (nom) {
			case 1: b10 += il_chesz;
				break;
			case 2: b20 += il_chesz;
				break;
			case 3: b50 += il_chesz;
				break;
			case 4: b100 += il_chesz;
				break;
			case 5: b200 += il_chesz;
				break;
			default: cout << "Nieznany nominal!\n";
				return;
			}
			break;

		case 2:
			cout << "\tPodaj nominal monety zlotowki\n[1] 1 \n[2] 2 \n[3] 5 \n";
			int zl_nom;
			cin >> zl_nom; int il_chesz2;

			cout << "Ile masz monet tego nominalu? ";
			cin >> il_chesz2;

			sprawdzenieUjemnosci(il_chesz2);

			switch (zl_nom) {
			case 1: m5 += il_chesz2;
				break;
			case 2: m10 += il_chesz2;
				break;
			case 3: m25 += il_chesz2;
				break;
			default: cout << "Nieznany nominal!\n";
				return;
			}
			break;

		case 3:
			cout << "\tPodaj nominal monety groszowej\n[1] 1 \n[2] 2 \n[3] 5 \n[4] 10 \n[5] 20 \n[6] 50 \n";
			int gr_nom;
			cin >> gr_nom;

			cout << "Ile masz monet tego nominalu?: ";
			int il_chesz3;
			cin >> il_chesz3;

			sprawdzenieUjemnosci(il_chesz3);

			switch (gr_nom) {
			case 1: gr1 += il_chesz3;
				break;
			case 2: gr2 += il_chesz3;
				break;
			case 3: gr5 += il_chesz3;
				break;
			case 4: gr10 += il_chesz3;
				break;
			case 5: gr20 += il_chesz3;
				break;
			case 6: gr50 += il_chesz3;
				break;
			default: cout << "Nieznany nominal!\n"; return;
			}
			break;

		default:
			cout << "Blad!\n";
		}
		wyswietl();

		zapiszPlik(); // Zapisuje dane do pliku po dodaniu
	}

	void wyjac() {
		if (sprwadzenieZamnkiecia()) {
			return;
		}
		cout << "[1] Wyjmij banknoty\n[2] Wyjmij monety zl\n[3] Wyjmij monety gr\n";
		int wybor;
		cout << "Wybierz opcje: "; cin >> wybor;



		switch (wybor) {
		case 1:
			cout << "\tPodaj nominal banknotu\n[1] 10 \n[2] 20 \n[3] 50 \n[4] 100 \n[5] 200 \n ";
			int nom;
			cin >> nom;
			cout << "Ile chcesz banknotow tego nominalu? ";
			int il_chesz;
			cin >> il_chesz;

			sprawdzenieUjemnosci(il_chesz);

			switch (nom) {
			case 1:
				if (!sprawdzeniaUspawiedWyjec(b10, il_chesz)) {
					return;
				}
				b10 -= il_chesz;
				break;

			case 2:
				if (!sprawdzeniaUspawiedWyjec(b20, il_chesz)) {
					return;
				}
				b20 -= il_chesz;
				break;
			case 3:
				if (!sprawdzeniaUspawiedWyjec(b50, il_chesz)) {
					return;
				}
				b50 -= il_chesz;
				break;
			case 4:
				if (!sprawdzeniaUspawiedWyjec(b100, il_chesz)) {
					return;
				}
				b100 -= il_chesz;
				break;
			case 5:
				if (!sprawdzeniaUspawiedWyjec(b200, il_chesz)) {
					return;
				}
				b200 -= il_chesz;
				break;
			default: cout << "Nieznany nominal!\n";
				return;
			}
			break;

		case 2:
			cout << "\tPodaj nominal monety zlotowki\n[1] 1 \n[2] 2 \n[3] 5 \n";
			int zl_nom;
			cin >> zl_nom; int il_chesz2;

			cout << "Ile masz monet tego nominalu? ";
			cin >> il_chesz2;

			sprawdzenieUjemnosci(il_chesz2);


			switch (zl_nom) {
			case 1:
				if (!sprawdzeniaUspawiedWyjec(m5, il_chesz2)) {
					return;
				}
				m5 -= il_chesz2;
				break;
			case 2:
				if (!sprawdzeniaUspawiedWyjec(m10, il_chesz2)) {
					return;
				}
				m10 -= il_chesz2;
				break;
			case 3:
				if (!sprawdzeniaUspawiedWyjec(m25, il_chesz2)) {
					return;
				}
				m25 -= il_chesz2;
				break;
			default: cout << "Nieznany nominal!\n";
				return;
			}
			break;

		case 3:
			cout << "\tPodaj nominal monety groszowej\n[1] 1 \n[2] 2 \n[3] 5 \n[4] 10 \n[5] 20 \n[6] 50 \n";
			int gr_nom;
			cin >> gr_nom; int il_chesz3;
			cout << "Ile masz monet tego nominalu?: ";
			cin >> il_chesz3;

			sprawdzenieUjemnosci(il_chesz3);

			switch (gr_nom) {
			case 1:
				if (!sprawdzeniaUspawiedWyjec(gr1, il_chesz3)) {
					return;
				}
				gr1 -= il_chesz3;
				break;
			case 2:
				if (!sprawdzeniaUspawiedWyjec(gr2, il_chesz3)) {
					return;
				}
				gr2 -= il_chesz3;

				break;
			case 3:
				if (!sprawdzeniaUspawiedWyjec(gr5, il_chesz3)) {
					return;
				}
				gr5 -= il_chesz3;
				break;
			case 4:
				if (!sprawdzeniaUspawiedWyjec(gr10, il_chesz3)) {
					return;
				}
				gr10 -= il_chesz3;
				break;
			case 5:
				if (!sprawdzeniaUspawiedWyjec(gr20, il_chesz3)) {
					return;
				}
				gr20 -= il_chesz3;
				break;
			case 6:
				if (!sprawdzeniaUspawiedWyjec(gr50, il_chesz3)) {
					return;
				}
				gr50 -= il_chesz3;
				break;
			} break;
		}

		wyswietl();
		zapiszPlik(); // Zapisuje dane do pliku po wyjęciu
	}
};


int main() {
	int choice;
	kasa b;
	cout << "\tTo jest kasa" << endl;
	do {
		cout << endl;
		cout << "1. Otworz\n2. Zamknij\n3. Dodaj\n4. Wyjmij\n5. Stan kasy\n6. Wyjdz\n";
		cout << "Twoja opcja: "; cin >> choice;

		switch (choice) {
		case 1:
			b.otworz();
			break;

		case 2:
			b.zamknij();
			break;
		case 3:
			b.dodaj();
			break;
		case 4:
			b.wyjac();
			break;
		case 5:
			b.calailosc();
			break;
		case 6:
			cout << "Do widzenia!\n";
			break;
		default:
			cout << "Nieznana opcja!\n";
			break;
		}

	} while (choice != 6);
	return 0;
}