// Lancio del Dado a 6 Facce - 3.cpp

/*Il programma fornisce qual è il numero di iterazioni mediamente necessarie per ottenere
una frequenza, di tutti i numeri contemporaneamente, che sia inferiore ad un certo errore,
fornito da tastiera, rispetto alla probabilità ideale di 1/6, cioè 16.6666666666 % */

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <cmath>

using namespace std;

const float limite=16.6666666666;	//Valore della probabilità ideale

int main()
{
	int uno=0, due=0, tre=0, quattro=0, cinque=0, sei=0, numLanci=0, lancio;
	float freqUno, freqDue, freqTre, freqQuattro, freqCinque, freqSei, errore;
	bool flag=true;
	
	srand((unsigned) time(NULL));
	
	cout << endl << "Quale errore vuoi rispetto al limite ideale di 16.6666666666 ? : ";
	cin >> errore;
	
	while(flag)
	{
		numLanci++;
		lancio=rand();
		if(lancio>=0 && lancio<=5461) uno++;
		if(lancio>5461 && lancio<=10922) due++;
		if(lancio>10922 && lancio<=16383) tre++;
		if(lancio>16383 && lancio<=21845) quattro++;
		if(lancio>21845 && lancio<=27305) cinque++;
		if(lancio>27305 && lancio<=32767) sei++;
//		cout << endl << "Numero lanci : " << numLanci << " - Estratto il numero : " << lancio << endl;
		freqUno=((float)uno/numLanci)*100;
		freqDue=((float)due/numLanci)*100;
		freqTre=((float)tre/numLanci)*100;
		freqQuattro=((float)quattro/numLanci)*100;
		freqCinque=((float)cinque/numLanci)*100;
		freqSei=((float)sei/numLanci)*100;
/*		cout << endl << "Freq. UNO : " << freqUno << " -- Freq. DUE : " << freqDue
		<< " -- Freq. TRE : " << freqTre << " -- Freq. QUATTRO : " << freqQuattro
		<< " -- Freq. CINQUE : " << freqCinque << " -- Freq. SEI : " << freqSei << endl;*/
		if(abs(freqUno-limite)<=errore && abs(freqDue-limite)<=errore && abs(freqTre-limite)<=errore &&
		abs(freqQuattro-limite)<=errore && abs(freqCinque-limite)<=errore && abs(freqSei-limite)<=errore)
		flag=false;
	}

	cout << endl << "Numero lanci : " << numLanci << endl;
	
	cout << endl << "Freq. UNO : " << freqUno << " -- Freq. DUE : " << freqDue
		<< " -- Freq. TRE : " << freqTre << " -- Freq. QUATTRO : " << freqQuattro
		<< " -- Freq. CINQUE : " << freqCinque << " -- Freq. SEI : " << freqSei << endl;
	
	cout << endl << endl;

	system("PAUSE");
	return 0;
}

