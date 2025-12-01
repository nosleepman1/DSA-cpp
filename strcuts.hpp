#include <iostream>
using namespace std;

typedef struct {
	string prenom;
	string nom;
	string service;

}employe;



//liste bi
//node
typedef struct nodeBi{
	employe em;
	struct nodeBi *next;
	struct nodeBi *prev;
	nodeBi(employe em) : em(em), next(nullptr), prev(nullptr) {}
}nodeBi;

//list
typedef struct listeBi
{
	nodeBi *firstBi;
	nodeBi *lastBi;
	listeBi() : firstBi(nullptr), lastBi(nullptr) {}
}listeBi;



//liste mono7
typedef struct nodeMono
{
	employe em;
	struct nodeMono *next;
	nodeMono(employe em) : em(em), next(nullptr) {}
}nodeMono;

typedef struct listeMono
{
	nodeMono *firstMono;
	nodeMono *lastMono;
	listeMono() : firstMono(nullptr), lastMono(nullptr) {}
}listeMono;