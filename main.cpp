#include <iostream>
#include <string>
#include "liste.hpp"
#include <cstdlib>




int main()
{

	//init lists
	listeMono *liMono = new listeMono();
	listeBi *liBi = new listeBi();
	employe em;


	int choix;
	do
	{
		choix = choixMenu();

		switch (choix)
		{
		case 1:
			addEmploy(liBi);
			break;
		case 2:
			showemployes(liMono, liBi);
			system("pause");
			break;
		case 3:
			em = newEmploye();
			pushFrontBi(liBi, em);
			break;
		case 4:
			em = newEmploye();
			pushBackBi(liBi, em);
			break;
		case 5:
			system("cls");
			cout << "Menu ajout a une position";
			system("pause");
		 	break;
		case 6:
			system("cls");
			transfert(liMono,liBi);
			cout << "transfert effectue avec succes" << endl;
			system("pause");
			break;

		case 7:
			system("cls");
			popFrontBi(liBi);
			cout << "suppression effectuee avec succes" << endl;
			system("pause");
			break;

		case 8:
			system("cls");
			popBackBi(liBi);
			cout << "suppression effectuee avec succes" << endl;
			system("pause");
			break;

		case 9:
			system("cls");
			//popBackBi(liBi);
			cout << "Menu suppression a une position... bientot" << endl;
			system("pause");
			break;

		case 10:
			system("cls");
			cout << "A bientot...." << endl;
			system("pause");
			break;
		default:
			break;
		}
	} while (choix != 10);


	return 0;
}