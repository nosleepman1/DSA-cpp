#include "liste.hpp"
#include "structs.hpp"



int choixService(){
	int choix;

	cout<< "\n1. Informatique" << endl;
	cout<< "2. R. Humaine" << endl;
	cout<< "3. Maintenance" << endl;
	cout<< "\n Choix:  " ;
	cin >> choix;

	return choix -1;
}

employe newEmploye() {
	employe em;

	system("cls");
	cin.ignore();

	cout << "\nPrenom :  ";
	getline(cin, em.prenom);

	cout << "\nNom :  ";
	getline(cin, em.nom);

	string service[3] = {"Informatique", "RH", "Maintenance"};
	cout << "\n ";
	int choice = choixService();
	em.service = service[choice];
	return em;
}


int choixMenu(){
	system("cls");
	int choix;
	cout << "MENU GESTION EMPLOYES" << endl;
	cout << "1. Creer des employers" << endl;
	cout << "2. Afficher des employers" << endl;
	cout << "3. Ajouter en debut" << endl;
	cout << "4. Ajouter en fin" << endl;
	cout << "5. Ajouter a une position" << endl;
	cout << "6. Transfert" << endl;
	cout << "7. Supprimer en debut" << endl;
	cout << "8. Supprimer en fin" << endl;
	cout << "9. Supprimer à une position" << endl;
	cout << "10. Quitter" << endl;

	cout << "\n\nVotre choix :  ";
	cin >> choix;
	return choix;
}





bool isEmptyBi(listeBi *li){
	return li->firstBi == nullptr;
}

void pushFrontBi(listeBi *&li, employe em){
	nodeBi *newNode = new nodeBi(em);

	if (isEmptyBi(li))
	{
		li->firstBi = newNode;
		li->lastBi = newNode;
		return;
	}
	newNode->next = li->firstBi;
	li->firstBi->prev = newNode;
	li->firstBi = newNode;
}

void pushBackBi(listeBi *&li, employe em){
	nodeBi *newNode = new nodeBi(em);

	if (isEmptyBi(li))
	{
		li->firstBi = newNode;
		li->lastBi = newNode;
		return;
	}
	
	li->lastBi->next = newNode;
	newNode->prev = li->lastBi;
	li->lastBi = newNode;
}

void popFrontBi(listeBi *&liBi) {

	if (isEmptyBi(liBi))
	{
		cout << "\n\nLa liste est deja vide" << endl;
		return;
	}

	nodeBi *temp = liBi->firstBi;

	if (liBi->firstBi == liBi->lastBi){
		liBi->firstBi = nullptr;
		liBi->lastBi = nullptr;
		return;
	}

	liBi->firstBi = liBi->firstBi->next;
	liBi->firstBi->prev = nullptr;
	delete temp;
}

void popBackBi(listeBi *&liBi) {
	if (isEmptyBi(liBi))
	{
		cout << "\n\nLa liste est deja vide" << endl;
		return;
	}

	nodeBi *temp = liBi->lastBi;
	if (liBi->firstBi == liBi->lastBi){
		liBi->firstBi = nullptr;
		liBi->lastBi = nullptr;
		return;
	}
	liBi->lastBi = liBi->lastBi->prev;
	liBi->lastBi->next = nullptr;
	delete temp;
}




//mono

bool isEmptyMono(listeMono *&li){
	return li->firstMono == nullptr;
}

void pushFrontMono(listeMono *&li, employe em) {
	nodeMono *newNode = new nodeMono(em);

	if (isEmptyMono(li))
	{
		li->firstMono = newNode;
		li->lastMono = newNode;
		return;
	}

	newNode->next = li->firstMono;
	li->firstMono = newNode;	
}

void pushBackMono(listeMono *&li, employe em) {
	nodeMono *newNode = new nodeMono(em);

	if (isEmptyMono(li))
	{
		li->firstMono = newNode;
		li->lastMono = newNode;
		return;
	}

	li->lastMono->next = newNode;
}







void addEmploy(listeBi *&li){
	char n;
	do
	{
		employe em = newEmploye();
		pushBackBi(li, em);
		
		cout << "Voulez vous continuer :  ";
		cin >> n;

	} while(n=='o' || n=='O');
}

void showEmploye(employe em){
	cout << "|-" << em.prenom << " " << em.nom << " "  << em.service << endl;
}


void showemployes(listeMono* liMono, listeBi* liBi) {
	system("cls");
	cout << "\n\nAffichage de la liste Mono" << endl;
	cout << "--------------------------------------------------" << endl;
	if (isEmptyMono(liMono)){
	cout << "La liste est vide aucun transfert n a ete efectue" << endl;
	}else {
		nodeMono *temp = liMono->firstMono;
		while (temp != nullptr){
			showEmploye(temp->em);
			temp = temp->next;
		}
	}
	cout << "--------------------------------------------------" << endl;


	cout << "\n\nAffichage de la liste Bi" << endl;
	cout << "--------------------------------------------------" << endl;

	if (isEmptyBi(liBi))
	{
		cout << "La liste est vide" << endl;
	}else {
		nodeBi *temp1 = liBi->firstBi;
		while (temp1 != nullptr){
			showEmploye(temp1->em);
			temp1 = temp1->next;
		}
	}
	cout << "--------------------------------------------------" << endl;
}


void transfert(listeMono *&liMono, listeBi *liBi) {
	nodeBi *temp = liBi->firstBi;

	while (temp != nullptr)
	{
		if (temp->em.service == "Maintenance")
		{
			pushBackMono(liMono, temp->em);
		}
		temp = temp->next;
	}
}

void insertAtPos(listeBi *&liBi, employe em, int pos) {

	nodeBi *temp = liBi->firstBi;
	nodeBi* newNode = new nodeBi(em);

	for (size_t i = 1; i < pos -1 ; i++)
	{
		if (temp == nullptr)
		{
			delete newNode;
			return;
		}
		temp = temp->next;
	}
	newNode->next = temp->next;
	newNode->prev = temp->prev;
}

int lengthList(listeBi *li){

	nodeBi *temp = li->firstBi;
	int length = 0;
	while (temp->next != nullptr)
	{
		length++;
		temp = temp->next;
	}
	return length;
}