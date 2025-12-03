#include <iostream>
using namespace std;

template<typename T>


class liste
{
private:
    struct node
    {
        T data;
        node *prev;
        node *next;
        node(T data) : data(data), next(nullptr), prev(nullptr) {}
    };

    node *head;
    node *end;
    
public:
    liste() : head(nullptr), end(nullptr) {};
    ~liste(){};

    //--------------------------------------------------------------------------------//

     bool isEmpty() {
        return this->head == nullptr;
    }

    //--------------------------------------------------------------------------------//

    //longueur ou taille de la liste
    int length(){
        int longueur = 0;

        if(isEmpty()) return 0;

        //temp recupere la liste pour parcours afin d'éviter la destruction de la liste
        node *temp = this->head;

        while (temp != nullptr) {
            longueur ++ ;
            temp = temp->next;
        }
        return longueur;
    }

    //--------------------------------------------------------------------------------//


     //insertion au debut 
    void push_front(T val){
        //creation d'un nouveau noeud avec le constructeur de la structure node
        node* newNode = new node(val);

        //verification si liste vide "si oui la le nouveau noeud sera notre tete et queue"
        if (isEmpty()){
            this->head = newNode;
            this->end = newNode;
            return;
        }
        /**
         * le nouveau element sera notre nouvelle tete 
         * il va recuperer l'ancienne tete head
         * Maintenant que newnode est notre nouvelle tete et qu on ne le retourne pas
         * 1- le prev de l'anciene tete (head->prev) va reucperer le nouveau maillon
         * l'ancienne variable HEAD va recuperer NEWNODE ainsi l'insertion est faite
         */
        newNode->next = this->head;
        this->head->prev = newNode;
        head = newNode;
    }

    //--------------------------------------------------------------------------------//

    //insertion  à la fin 
    void push_back(T val){
        //creation d'un nouveau noeud avec le constructeur de la structure node
        node* newNode = new node(val);

        //verification si liste vide "si oui la le nouveau noeud sera notre tete et queue"
        if (isEmpty()){
            this->head = newNode;
            this->end = newNode;
            return;
        }
        /**
         * le nouveau element sera notre nouvelle end 
         * le suivant du end qui tendait vers NULL va recuperer le nouveau maillon
         * Une fois la recuperation faite, end doit prendre la valeur du nouveau maillon
         * Ainsi l'insertion a la fin de liste est faite
         */
        this->end->next = newNode;
        newNode->prev = this->end;
        this->end = newNode;
    }


    
    //--------------------------------------------------------------------------------//

    //Suppresion au deut
    void pop_front(){
       

        //verification si liste vide "si oui la le nouveau noeud sera notre tete et queue"
        if (isEmpty()){
            return;
        }
        /**
         * Si la liste ne contientqu'un seul element
         * On repart de zero => la tete et la fin seront reinitialisées<
         */
        if (this->head == this->end)
        {
            this->head = nullptr;
            this->end = nullptr;
        }

        /**
         * le end qu'on avait va d'abord se placer sur l avant dernier element  
         * ce qui veut dire que la fin passe du dernier element à l avant dernier
         * Donc le nouveau suivant du end va se placer sur l'ancien dernier element
         * Du coup ce suivant là (end->next) va pointer vers null
         * Ainsi la suppression a la fin est faite
         */

        this->head = this->head->next;
        this->head->prev = nullptr;
    }

    //--------------------------------------------------------------------------------//

    //Suppresion  à  la fin
    void pop_back(){
       

        //verification si liste vide "si oui la le nouveau noeud sera notre tete et queue"
        if (isEmpty()){
            return;
        }
        /**
         * Si la liste ne contientqu'un seul element
         * On repart de zero => la tete et la fin seront reinitialisées<
         */
        if (this->head == this->end)
        {
            this->head = nullptr;
            this->end = nullptr;
            return;
        }

         /**
         * Plusieurs éléments :
         * 1. On récupère l'ancien dernier élément (celui à supprimer)
         * 2. On déplace end sur l'avant-dernier
         * 3. On coupe le lien end->next
         * 4. On supprime l'ancien dernier élément
         */

        node *toDeletedNode = this->end;      // ← L'ancien dernier nœud

        this->end = this->end->prev;          // end passe à l'avant-dernier
        this->end->next = nullptr;            // l'avant-dernier devient le dernier

        delete toDeletedNode;  

    }

    /*---------------------------------------------------------------------------------------------*/


    void insertAt(int val, int pos) {

        /** */
        node *newNode = new node(val);

        if (pos < 1 || pos > length()){
            cout << "\n\nPosition saisie invalide";
            return;
        }
        if (pos == 1){
            push_front(val);
            return;
        }
        if (pos == length()){
            push_back(val);
            return;
        }

        node *temp = this->head;

        for (size_t i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        
        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    /*---------------------------------------------------------------------------------------------*/

    void deleteAt(int pos){

        if (pos < 1 || pos > length()){
            cout << "\n\nPosition saisie invalide";
            return;
        }
        if (pos == 1){
            pop_front();
            return;
        }
        if (pos == length()){
            pop_back();
            return;
        }

        node *temp = this->head;

        for (size_t i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }


    /*---------------------------------------------------------------------------------------------*/



    void showList() {

        cout << "Affichage de la liste bidirectionnelle" << endl;
        node *temp = this->head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> "; 
            temp = temp->next;
        }
        
    }


    void showReversedList() {
        cout << "\n\nAffichage de la liste bidirectionnelle a  l envers" << endl;
        node *temp = this->end;
        while (temp != nullptr)
        {
            cout << " <- " << temp->data ; 
            temp = temp->prev;
        }
    }





};


