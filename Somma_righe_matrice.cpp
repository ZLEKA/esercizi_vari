// Titolo.cpp

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <ctime>

using namespace std;

int main()
{
	int M[10][10];
	
	int somma_righe_pari=0, somma_righe_dispari=0, dimensione;
	
	cout << endl << "Inserire la dimensione della matrice quadrata (max 10x10) : ";
	cin >> dimensione;
	
	srand((unsigned) time(NULL));
	
	for (int i=0; i<dimensione; i++)
		for (int j=0; j<dimensione; j++)
			M[i][j]=rand()%11;
	
	cout << endl << endl;
			
	for (int i=0; i<dimensione; i++)
		{
			for (int j=0; j<dimensione; j++)
			
				cout << setw(4) << M[i][j];
			
			cout << endl;
		}
	
	cout << endl;
	
	for (int i=0; i<dimensione; i++)
		for (int j=0; j<dimensione; j++)
			{
				if ((i+1)%2!=0) somma_righe_dispari=somma_righe_dispari+M[i][j];
					else somma_righe_pari=somma_righe_pari+M[i][j];
			}
	
	cout << endl << "Somma righe dispari : " << somma_righe_dispari;
	
	cout << endl;
	
	cout << endl << "Somma righe pari : " << somma_righe_pari;
	
 	cout << endl << endl << endl;

	system("PAUSE");
	return 0;
}

