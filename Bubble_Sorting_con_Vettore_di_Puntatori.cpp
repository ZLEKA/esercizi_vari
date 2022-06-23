// Bubble Sorting con Vettore di Puntatori.cpp

/* Questo algoritmo definisce un vettore di puntatori che puntano agli elementi di un altro
vettore, Vet, inserito in ingresso. Per ordinare il vettore Vet si scambiano gli indirizzi
nel vettore di puntatori.
Il vettore Vet non verrà modificato.
Il vettore di puntatori verrà inizializzato per contenere gli indirizzi uno-a-uno,
in sequenza, del vettore Vet, poi si scambieranno gli indirizzi nel vettore di puntatori. */

# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

const int dim=10000;

void scambio(int *pVet[], int indice);  //Scambia gli indirizzi delle celle del vettore Vet
									//puntate dal vettore di puntatori.
									//Il passaggio di un vettore di puntatori deve essere
									//dichiarato tale.

int main()
{
	int Vet[dim], elementi, max;
	int *pVet[dim]; //Vettore di puntatori ad interi per il vettore vet.
	bool flag;
	
	srand ((unsigned) time(NULL));
	
	cout << endl << "Quanti elementi vuoi per il vettore? (MAX 10000) : ";
	cin >> elementi;
	
	cout << endl << "Max valore nel vettore? : ";
	cin >> max;
	
	for (int i=0; i<elementi; i++)
		{
			Vet[i]=rand()%(max+1);
		}
	
	//Inizializzazione del vettore di puntatori agli elementi del vettore Vet.
	
	pVet[0]=Vet;	//Il primo puntatore punta al primo elemento di Vet
	//pVet[0]=&Vet[0];	//Modo equivalente di eseguire l'istruzione precedente
	
	for (int i=1; i<elementi; i++) //Inizializzazione del vettore di puntatori
		pVet[i]=pVet[i-1]+1; //Gli elementi del vettore Vet hanno indirizzi sequenziali, si
							//può quindi sfruttare l'aritmetica dei puntatori
		
	/*	//ALtro modo (più veloce) per inizializzare il vettore di puntatori, che NON fa uso
		//dell'aritmetica dei puntatori
		
	for (int i=0; i<elementi; i++) //Inizializzazione del vettore di puntatori
		pVet[i]=&Vet[i];
	*/
	
	//Algoritmo BUBBLE SORTING
	
	flag=true; //Affinchè inizi sempre il primo ciclo While-Do
	
	while(flag)
		{
			flag=false;	//Affinchè, se non ci saranno scambi per un ciclo intero (cioè quando il
						// il vettore sarà ordinato), si esca dal ciclo.
			for(int i=0; i<(elementi-1); i++)
				{
					if (*pVet[i]>*pVet[i+1])
						{
							scambio(pVet, i);	//Richiamo della funzione di scambio.
							flag=true;
						}
				}
		}

	//Il vettore assegnato, Vet, NON è stato modificato.

	cout << endl << endl << "Vettore assegnato : " << endl << endl;
	for(int i=0; i<(elementi-1); i++)
				{
					cout << Vet[i] << " ";
				}
	
	//Gli indirizzi contenuti nel vettore di puntatori saranno ordinati in modo da puntare
	//ai valori di Vet in modo che tali valori siano ordinati. 
	
	cout << endl << endl<< endl << "Vettore ordinato : " << endl << endl;
	for(int i=0; i<(elementi-1); i++)
				{
					cout << *pVet[i] << " ";
				}

	cout << endl << endl << endl;

	system("PAUSE");
	return 0;
}

void scambio(int *pVet[], int indice)	//Il passaggio di un vettore di puntatori deve essere
										//dichiarato come tale.
{
	int *temp;	//Per ospitare un puntatore deve essere definita come puntatore.
	
	temp=pVet[indice];
	pVet[indice]=pVet[indice+1];
	pVet[indice+1]=temp;
}
