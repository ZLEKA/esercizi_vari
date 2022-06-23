// Scambio diagonali.cpp

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
	
	for (int i=0; i<righe; i++)
		{
			for (int j=0; j<colonne; j++)
				{
					m[i][j]=rand()%101;
					cout << setw(5) << m[i][j];
				}
			cout << endl;	
		}
		
	for (int i=0; i<righe; i++)
		{
			temp=m[i][i];
			m[i][i]=m[i][colonne-1-i];
			m[i][colonne-1-i]=temp;
		}
	
	cout << endl;
	
	for (int i=0; i<righe; i++)
		{
			for (int j=0; j<colonne; j++)
				cout << setw (5) << m[i][j];
			
			cout << endl;
		}

 	cout << endl << endl << endl;

	system("PAUSE");
	return 0;
}

