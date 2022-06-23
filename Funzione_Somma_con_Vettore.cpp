// Funzione Somma con Vettore.cpp

# include <iostream>
# include <cstdlib>

using namespace std;

float somma(float vet[], int elementi, char tipoSomma); //Dichiarazione del prototipo della
														//funzione somma, con indicazione dei
														//parametri FORMALI.

int main()
{
	float vet[30]; //Dichiarazione di un vettore di nome somma avente, al massimo, 30 elementi
	int nValori;
	char tipo;
	
	cout << "Quanti valori vuoi inserire? : ";
	cin >> nValori;
	
	for (int i=0; i<nValori; i++)
		{
			cout << "Inserisci il valore numero " << i+1 << "_" << nValori << " : ";
			cin >> vet[i];
		}
	
	cout << endl << "Somma delle posizioni pari : " << somma(vet, nValori, 'p'); //Richiamo
																		//della funzione
																		//somma con
																		//passaggio dei
																		//parametri ATTUALI.
																				
	cout << endl << "Somma delle posizioni dispari : " << somma(vet, nValori, 'd');
	cout << endl << endl;

	system("PAUSE");
	return 0;
}

float somma(float vet[], int elementi, char tipoSomma)
{
	float risultato=0; //Variabile LOCALE, visibile solo dalla funzione somma.
	
	if (tipoSomma == 'd') //Confronto tra la variabile CHAR tipoSomma e il carattere CHAR d
		for (int i=0; i<elementi; i+=2) //i=i+2 serve per saltare gli elementi di posizione pari
			risultato+=vet[i]; //risultato=risultato+vet[i]
		else
			for (int i=1; i<elementi; i+=2)
				risultato+=vet[i];
				
	return risultato; //Valore, di tipo float, restituito dalla funzione.
}










