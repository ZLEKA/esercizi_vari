// Scambio e inversione diagonali - 2 .cpp

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <iomanip>

using namespace std;

int main()
{
	int m[20][20], righe, colonne, temp;
	
	cout << endl << "Matrice quadrata, inserire la dimensione : ";
	cin >> righe;
	colonne=righe;	//Utilizzata solo per maggior chiarezza ANCHE se non è necessaria
	
	srand((unsigned) time(NULL));
	
	cout << endl;

for (int i=0; i<righe; i++) //Creazione della sola diagonale principale e secondaria (gli altri
							//elementi, fuori dalle diagonali, sono lasciati liberi e non gestiti).
				{
					m[i][i]=rand()%101;
					m[i][colonne-1-i]=rand()%101;
				}

for (int i=0; i<righe; i++)	//Stampa delle sole diagonali.
		{
			for (int j=0; j<colonne; j++)
				{
					if (i==j) cout << setw(5) << m[i][j];
						else if (j==(colonne-1-i)) cout << setw(5) << m[i][j];
							else cout << setw(5) << ".";
				}
			cout << endl;	
		}

//Creazione e stampa dell'intera matrice, anche gli elementi fuori dalle diagonali.
	
/*	
for (int i=0; i<righe; i++)
		{
			for (int j=0; j<colonne; j++)
				{
					m[i][j]=rand()%101;
					cout << setw(5) << m[i][j];
				}
			cout << endl;	
		}
*/

/*Nota Bene: da una semplice analisi della simmetria ottenuta scambiando ed invertendo gli
elementi delle diagonali principale e secondaria si deduce che l'algoritmo è uguale a quello
dello scambio delle diagonali ma scambiando gli elementi per colonna anzichè per riga, quindi
è stato sufficiente scambiare gli indici di riga con quelli di colonna (solo per maggior
chiarezza si utilizza la variabile "righe" anzichè "colonne" in quanto la matrice è quadrata
e tali valori sono coincidenti.*/
		
	for (int i=0; i<righe; i++)
		{
			temp=m[i][i];
			m[i][i]=m[righe-1-i][i];
			m[righe-1-i][i]=temp;
		}
	
	cout << endl << endl;
	
	for (int i=0; i<righe; i++)	//Stampa delle sole diagonali.
		{
			for (int j=0; j<colonne; j++)
				{
					if (i==j) cout << setw(5) << m[i][j];
						else if (j==(colonne-1-i)) cout << setw(5) << m[i][j];
							else cout << setw(5) << ".";
				}
			cout << endl;	
		}
	
/*	for (int i=0; i<righe; i++)
		{
			for (int j=0; j<colonne; j++)
				cout << setw (5) << m[i][j];
			
			cout << endl;
		}
*/

 	cout << endl << endl << endl;

	system("PAUSE");
	return 0;
}

