// Ricerca Dicotomica.cpp

# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

int main()
{
	int v[100], inizio, fine, medio, ricercato, posizione, temp, k;
	
	bool flag;
	
	srand ((unsigned) time(NULL));
	
	cout << endl;
	
	for (int i=0; i<100; i++)
		{
			v[i]=rand()%300+1;
			cout << v[i] << " ";
		}
	
	flag=true;
	
	k=1;
	
	while (flag)
		{
			flag=false;
			
			for(int j=0; j<100-k; j++)
				{
					if(v[j]>v[j+1])
						{
							temp=v[j];
							v[j]=v[j+1];
							v[j+1]=temp;
							
							flag=true;
						}
				}
			k++;
		}
	
	cout << endl << endl;
	
	for (int i=0; i<100; i++)
		{
			cout << i+1 << "." << v[i] << " ";
		}
	
	cout << endl << endl << endl << "Inserire il valore da ricercare : ";
	cin >> ricercato;	
	
	inizio=0;
	
	fine=99;
	
	flag=false;
	
	while (inizio<=fine && !flag)
		{
			medio=(inizio+fine)/2;
			if (v[medio]==ricercato) { flag=true; posizione=medio+1; }
				else if (v[medio]<ricercato) inizio=medio+1;
					else fine=medio-1;
		}
	
	if (flag) cout << endl << "Il valore " << ricercato << " si trova nella posizione " << posizione;
		else cout << endl << "Il valore " << ricercato << " non e\' presente";

 	cout << endl << endl << endl;

	system("PAUSE");
	return 0;
}

