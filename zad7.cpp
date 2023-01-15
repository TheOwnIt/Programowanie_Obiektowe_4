#include <string>
#include <regex>
#include <iostream>
using namespace std;

class Adres {
    private:
        string ulica;
        string numerDomu;
        string kodPocztowy;
        string miasto;
        regex numerDomuRegex = regex("^[0-9]+[a-zA-Z]?$");
        regex kodPocztowyRegex = regex("^[0-9]{2}-[0-9]{3}$");

    public:
        Adres(string ulica, string numerDomu, string kodPocztowy, string miasto) {
            if (ulica.empty()) throw invalid_argument("Ulica nie mo¿e byc nullem");
            if (!regex_match(numerDomu, numerDomuRegex)) throw invalid_argument("Numer domu musi siê skladac z liczby i ewentualnie litery (np. 8c)");
            if (!regex_match(kodPocztowy, kodPocztowyRegex)) throw invalid_argument("Kod pocztowy musi miec format CC-CCC (C to cyfra)");
            if (miasto.empty()) throw invalid_argument("Miasto nie mo¿e byc nullem");

            this->ulica = ulica;
            this->numerDomu = numerDomu;
            this->kodPocztowy = kodPocztowy;
            this->miasto = miasto;
        }

        string getUlica() { return ulica; }
        void setUlica(string ulica) {
            if (ulica.empty()) throw invalid_argument("Ulica nie mo¿e byc nullem");
            this->ulica = ulica;
        }

        string getNumerDomu() { return numerDomu; }
        void setNumerDomu(string numerDomu) {
            if (!regex_match(numerDomu, numerDomuRegex)) throw invalid_argument("Numer domu musi sie skladac z liczby i ewentualnie litery (np. 8c)");
            this->numerDomu = numerDomu;
        }

        string getKodPocztowy() { return kodPocztowy; }
        void setKodPocztowy(string kodPocztowy) {
            if (!regex_match(kodPocztowy, kodPocztowyRegex)) throw invalid_argument("Kod pocztowy musi miec format CC-CCC (C to cyfra)");
            this->kodPocztowy = kodPocztowy;
        }
 		string getMiasto() { return miasto; }
       void setMiasto(string miasto) {
		if (miasto.empty()) throw invalid_argument("Miasto nie mo¿e byc nullem");
		this->miasto = miasto;
		}
};

int main() {
	try {
	string ulica, numerDomu, kodPocztowy, miasto;
	    cout << "Podaj ulice: ";
    getline(cin, ulica);

    cout << "Podaj numer domu: ";
    getline(cin, numerDomu);

    cout << "Podaj kod pocztowy: ";
    getline(cin, kodPocztowy);

    cout << "Podaj miasto: ";
    getline(cin, miasto);

    Adres adres(ulica, numerDomu, kodPocztowy, miasto);

    cout << "Adres zostal pomyslnie wprowadzony: " << endl;
    cout << "Ulica: " << adres.getUlica() << endl;
    cout << "Numer domu: " << adres.getNumerDomu() << endl;
    cout << "Kod pocztowy: " << adres.getKodPocztowy() << endl;
    cout << "Miasto: " << adres.getMiasto() << endl;
	} catch (const invalid_argument& e) {
    cout << "Blad: " << e.what() << endl;
	}
	system("pause");
	return 0;
}
