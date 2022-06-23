// Battaglia navale ver. 1.cpp

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <ctime>

using namespace std;

void situazione(char m[][25], int elementi, int numero_navi, int navi_colpite, int tiri, bool flag, int riga, int colonna, bool errore);
int main()
{
	char m1[25][25], m2[25][25];
	int i, j, dimensione, numero_navi, navi_colpite, riga, colonna, tiri;
	bool flag, errore;
	
	srand((unsigned) time(NULL));
	
	do
	{
		cout << endl << " Inserire la dimensione del campo di battaglia (max 25) : ";
		cin >> dimensione;
		if (dimensione > 25) cout << endl << " Inserire una dimensione minore..." << endl;
	} while (dimensione > 25);
	
	do
	{
		cout << endl << " Inserire il numero di navi (max " << dimensione*dimensione << ") : ";
		cin >> numero_navi;
		if(numero_navi>dimensione*dimensione) cout << endl << " Diminuire il numero di navi..." << endl;
	} while(numero_navi>dimensione*dimensione);
	
	for (int i=0; i<dimensione; i++)
		for (int j=0; j<dimensione; j++)
				{
					m1[i][j]='0';
					m2[i][j]='.';
				}
	
	//Inserimento della matrice delle navi, con controllo della posizione se è già occupata
	
	for (int k=1; k<=numero_navi; k++)
		{
			flag=false;
			
			do
			{
				i=rand()%dimensione; //Genera l'indice di riga, compreso tra 0 e dimensione-1
				j=rand()%dimensione; //Genera l'indice di colonna, compreso tra 0 e dimensione-1
				if(m1[i][j]=='0')
					{
						m1[i][j]='1';
						flag=true;
					}
					
			} while(!flag);
		}
	
	cout << endl;

//Prima stampa del campo di battaglia, senza indicazioni sui tiri effettuati
	
	system("CLS");	//Comando per cancellare tutto lo schermo.
	
	cout << endl << "  - Situazione del campo di battaglia -";
	
	cout << endl << endl << endl;
		
	cout << setw(4) << "";
	
	for (int i=0; i<dimensione; i++)
		cout << setw(4) << i+1;
	
	cout << endl << endl;
	
	for (int i=0; i<dimensione; i++)
		{
			cout << setw(4) << i+1;
			for (int j=0; j<dimensione; j++)
				cout << setw(4) << m2[i][j];
			
			cout << endl;
		}
		
 	cout << endl;
 	
//Fine della prima stampa del campo di battaglia

	navi_colpite=0;
	tiri=0;
	
	do
	{
		tiri++;
		flag=false;
		errore=false;
		
		cout << endl << "  Inserire l'indice di riga e di colonna (esempio 3 2): ";
		cin >> riga >> colonna;
		if (riga<1 || riga>dimensione || colonna<1 || colonna>dimensione)
			{
				errore=true;
				situazione(m2, dimensione, numero_navi, navi_colpite, tiri, flag, riga, colonna, errore);
			}
		
		if(!errore)
			{
				if(m2[riga-1][colonna-1]=='0' || m2[riga-1][colonna-1]=='X')
					{
						errore=true;
					}
				if(m2[riga-1][colonna-1]=='.' && m1[riga-1][colonna-1]=='1')
					{
						m2[riga-1][colonna-1]='X';
						navi_colpite++;
						flag=true;
					}
				if(m2[riga-1][colonna-1]=='.' && m1[riga-1][colonna-1]=='0')
					{
						m2[riga-1][colonna-1]='0';
					}
				
				situazione(m2, dimensione, numero_navi, navi_colpite, tiri, flag, riga, colonna, errore);
		
			}
	} while (navi_colpite<numero_navi);
	
 	cout << endl << endl << endl;

	system("PAUSE");
	return 0;
}

void situazione(char m[][25], int elementi, int numero_navi, int navi_colpite, int tiri, bool flag, int riga, int colonna, bool errore)
{
	system("CLS");	//Comando per cancellare tutto lo schermo.
	
	cout << endl << "  - Situazione del campo di battaglia -";
	
	cout << endl << endl << endl;
		
	cout << setw(4) << "";
	
	for (int i=0; i<elementi; i++)
		cout << setw(4) << i+1;
	
	cout << endl << endl;
	
	for (int i=0; i<elementi; i++)
		{
			cout << setw(4) << i+1;
			for (int j=0; j<elementi; j++)
				cout << setw(4) << m[i][j];
			
			cout << endl;
		}
		
 	cout << endl;
 	
 	if(flag) cout << endl << "  (" << riga << " , " << colonna << ")   " << "  Nave colpita!" << endl << endl;
					else if (errore) cout << endl << "  (" << riga << " , " << colonna << ")   " << "  Colpo NON valido!" << endl << endl;
						else if (!flag) cout << endl << "  (" << riga << " , " << colonna << ")   " << "  Colpo fallito!" << endl << endl;
		
				cout << "  Navi iniziali : " << numero_navi << "     ";
				cout << "Navi colpite : " << navi_colpite << "     ";
				cout << "Tiri effettuati : " << tiri << "     ";
				cout << "Navi rimanenti : " << numero_navi-navi_colpite << endl;
}

