
#include <string>
using namespace std;

template<typename T>



class liste
{
private:
    struct node
    {
        T data;
        struct node *next;
        node(T val) : data(val), next(nullptr) {}
    };
    
    node *head;
    node *end;

public:
    //constructeur de notre classe qui initialise la tete et la fin à nullptr(NULL)
    liste() : head(nullptr), end(nullptr) {}
    ~liste(){};

    //--------------------------------------------------------------------------------//

    //verifier si la liste est vide
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
         * l'ancienne variable HEAD va recuperer NEWNODE ainsi l'insertion est faite
         */
        newNode->next = this->head;
        head = newNode;
    }

    //--------------------------------------------------------------------------------//

    //insertion à la fin
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
         * Là vu que nous avions un pointeur vers le dernier element l'insertion a la fin sera simple
         * le suivant (next) du end qui etait à null va recuperer le nouveau noeud 
         * et vu que end pointait vers la derniere valeur ava,t insertion,
         *  on doit l'actualiser afin qu'elle prenne la valeur de newNode
         */
        this->end->next = newNode;
        end = newNode;
    }

    //--------------------------------------------------------------------------------//

    //les suppressions au debut et a la fin
    void pop_front(){
        //deletedNode va plustard contenir le noeud a supprimer et on libere sa memoire
        node *deletedNode = this->head;

        //Si liste vide on fait rien a part supprimer la variable deletedNode
        if(isEmpty()){
            delete deletedNode;
            return;
        } 
        //Si la tete a un seul element on retourne une liste vide
        if (this->head->next == nullptr){
            this->head = nullptr;
            this->end = nullptr;
            delete deletedNode;
            return;  
        }

        /**
         * Sinon (aucun des deux cas) 
         * la tete va pointer vers l'element suivant qui sera notre nouvelle tete
         * le deletedNode va contenir l'ancienne tete et on libre sa memoire
         * */
        this->head = this->head->next;
        delete deletedNode;     
    }

    //--------------------------------------------------------------------------------//

    void pop_back(){
        /**
         * deletedNode va plustard contenir le noeud a supprimer et on libere sa memoire
         * Si liste vide on fait rien a part supprimer la variable deletedNode
         */
  

        if(isEmpty()){
            return;
        } 
        //Si la tete a un seul element on retourne une liste vide
        if (this->head == this->end){
            this->head = nullptr;
            this->end = nullptr;

            return;  
        }
        /**
         * Notre variable temp recupere la tete pour eviter la destruction lors du parcours
         * Parcourir 
         */
         node *temp = this->head;
<<<<<<< HEAD
         node *temp1 = this->head;
        
         while (temp != )
         {
            /* code */
         }
         

         temp->next = nullptr;
         end = temp;
         delete temp;
=======
        /**
         * parcourirjusqu'ace que le suivant de temp pointe vers la derniere valeur
         * 
         */
         while (temp->next != this->end){
            temp = temp->next;
        }
        node *deletedNode = this->end;
        temp->next = nullptr;
        this->end = temp;
        delete deletedNode;
>>>>>>> 4c733e140d85ae2e3e0583e95fd6a5bfce933b98
    }

    //--------------------------------------------------------------------------------//
    
    //fonction afichage
    void showList(){
        node *temp = this->head;

        cout << "\n\nAffichage de la liste monodirectionelle \n";
        cout << "\n------------------------------------------ \n";
        while (temp != nullptr){
            cout << temp->data <<" -> ";
            temp = temp->next;
        }
        cout << "\n------------------------------------------ \n";

    }
};

