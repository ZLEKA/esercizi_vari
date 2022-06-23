// Calcolo area rettangolo.cpp

# include <iostream>
# include <cstdlib>

using namespace std;

float areaRettangolo (float b, float h)  //Variabili passate per valore
{
	//return b*h;
	
	float risultato;
	
	risultato=b*h;
	
	return risultato;
}

float perimetroRettangolo (float b, float h); //Definizione del prototipo della funzione.

int main()
{
	float base, altezza, area;  //Variabili locali visibili SOLO dalla funzione MAIN
	
	cout << endl << "Inserire la base : ";
	cin >> base;
	
	cout << endl << "Inserire l'altezza' : ";
	cin >> altezza;
	
	cout << endl << "Il perimetro del rettangolo vale : " << perimetroRettangolo(base, altezza);

	area=areaRettangolo(base, altezza); //Assegna alla variabile area il valore restituito dalla funzione
	
	cout << endl << "L'area vale : " << area;
	
 	cout << endl << endl << endl;

	system("PAUSE");
	return 0;
}

float perimetroRettangolo (float b, float h)
{
	return 2*(b+h);
}
