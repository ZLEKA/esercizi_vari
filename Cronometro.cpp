// Cronometro.cpp

# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

int main()
{
	int t, a;
	
	t=0;
	a=time(NULL);
	
	while (t<10)  // bool t=true; while (t)	//Per cronometro infinito.
		{
			if (time(NULL)-a>0)  // if (time(NULL)!=a)
				{
					system("CLS");
					t++;  //t=t+1;
					cout << endl << endl << "  " << t;
					a++;
				}
		}

 	cout << endl << endl << endl;

	system("PAUSE");
	return 0;
}

