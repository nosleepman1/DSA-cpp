#include <iostream>
using namespace std;


//Genericité
template <typename T>

/**
 * Les FILES fonctionnent sous le principe du FIFO
 * Le First In, First Out 
 * Donc comme nous le constatons dans une FILE d'attente, 
 * la premiere personne de la file sera la premiere à quitter aussi
 */

class file
{
    private:
        struct noeud
        {
            T valeur;
            noeud *suivant;
            noeud(T val) : valeur(val), suivant(nullptr) {}
        };

        noeud *tete;
        
    public:
        file() : tete(nullptr) {};
        ~file(){};

        //--------------------------------------------------------------------------------//

     bool isEmpty() {
        return this->tete == nullptr;
    }

    //--------------------------------------------------------------------------------//

    int length(){
        int longueur = 0;

        if(isEmpty()) return 0;

        noeud *temp = this->tete;

        while (temp != nullptr) {
            longueur ++ ;
            temp = temp->suivant;
        }
        return longueur;
    }

    //--------------------------------------------------------------------------------//


     //insertion au debut 
    void enfiler(T val){
        
        noeud* newnoeud = new noeud(val);

        if (isEmpty()){
            this->tete = newnoeud;
            return;
        }

        newnoeud->suivant = this->tete;
        tete = newnoeud;
    }


    //--------------------------------------------------------------------------------//

    void defiler(){
       
        if (isEmpty()){
            return;
        }

        if (this->tete == nullptr)
        {
            this->tete = nullptr;
            return;
        }

        noeud *toDeletednoeud = this->tete;   
        this->tete = this->tete->suivant;                        
        delete toDeletednoeud;  

    }

    void afficherFile() {

        cout << "Affichage de la File d attente" << endl;
        noeud *temp = this->tete;

        while (temp != nullptr)
        {
            cout << temp->valeur << " -> "; 
            temp = temp->suivant;
        }
        
    }

};


