// lambda.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include<algorithm> //count_if
#include<functional> //function

using namespace std;

//funkcja orzekająca
bool wiekszeNiz30(int liczba) {
	return liczba > 30;
}

//funkcja zliczająca
int policz(vector<int> kontener, bool (*decydent)(int)) {
	int licznik{ 0 };

	for (auto e : kontener) {
		if (decydent(e)) licznik++;
	}
	return licznik;
};

//funkcja zliczjąca przyjmująca jako argument wyrazenie lambda
int policzNowa(vector<int> kontener, function<bool(int)>decydent) {
	int licznik{ 0 };

	for (auto e : kontener) {
		if (decydent(e)) licznik++;
	}
	return licznik;
};


int main()
{ 
	auto lambda = [](int l) {return l <= 2; };
	int zakres{ 100 };
	function<bool(int)> lambda2 = [&zakres](int l) {
		zakres = 400;
		return l==zakres; };

	vector<int> v{ 1,2,3,4,5,55,66,77,88,99,100,2000 };
	; 
	cout << "Wywolanie za pomoca funkcji orzekajacej: policzono: " << policz(v, wiekszeNiz30) << endl; 

	cout << "Wywolanie za pomoca wyrazenia lambda: policzono: " << policz(v, [](int l) {return l > 30; }) << endl;

	cout << "Wywolanie za pomoca funkcji cont_if i wyrazenia lambda: policzono: " << count_if(v.begin(), v.end(), [](int l) {return l > 30; }) << endl;
	 
	cout << "Wywolanie za pomoca funkcji cont_if i wyrazenia lambda w zmiennej: policzono: " << count_if(v.begin(), v.end(), lambda) << endl;
	
	cout << "Wartosc zmiennej zakres: " << zakres << endl;
	
	cout << "Wywolanie policzNowa z argumentem lambda: policzono:" << policzNowa(v, lambda2) << endl;

	cout << "Wartosc zmiennej zakres: " << zakres << endl;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
