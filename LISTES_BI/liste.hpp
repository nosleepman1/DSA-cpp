#include <iostream>
using namespace std;

/**
 * Creation d'un template
 * Objectif: mettre dans notre class n'importe quelle type
 */
template<typename T>


class liste
{
private:
    /**
     * inititalisation de la structure node avec le next et le prev 
     * Le prev et le next sont du meme type que la structure
     *  pour qu'ils puissent plustard recuperer d autres noeuds
     * Egalement un constructeurpour eviter les multi initialisations dans les fonctions insert
     */
    struct node
    {
        T data;
        node *prev;
        node *next;
        node(T data) : data(data), next(nullptr), prev(nullptr) {}
    };

    /**
     * Creation de la tete et de la queue  qui sont des pointeurs vers la structure
     */
    node *head;
    node *end;
    
public:
    /**
     * Constructeur de la classe liste donc on initialise une liste vide
     */
    liste() : head(nullptr), end(nullptr) {};
    ~liste(){};

    //--------------------------------------------------------------------------------//

     bool isEmpty() {
        return this->head == nullptr;
    }

    //--------------------------------------------------------------------------------//

   /**
     * length() : Retourne le nombre d'éléments présents dans la liste.
     *
     * ÉTAPES :
     * 1. Si la liste est vide → retourne 0 directement.
     * 2. Sinon :
     *      - On parcourt la liste depuis head.
     *      - On incrémente un compteur à chaque nœud rencontré.
     *      - On retourne la valeur finale du compteur.
     */
    int length(){
        int longueur = 0;

        if (isEmpty()) 
            return 0;

        node *temp = this->head;

        while (temp != nullptr) {
            longueur++;
            temp = temp->next;
        }

        return longueur;
    }


    //--------------------------------------------------------------------------------//


     /**
     * push_front() : Insère un nouvel élément au début de la liste doublement chaînée.
     *
     * ÉTAPES :
     * 1. On crée un nouveau nœud contenant la valeur.
     * 2. Si la liste est vide :
     *      - Le nouveau nœud devient à la fois head et end.
     * 3. Sinon (liste non vide) :
     *      - Le nouveau pointe vers l'ancienne tête (newNode->next = head).
     *      - L'ancienne tête pointe en arrière vers le nouveau (head->prev = newNode).
     *      - On met à jour head pour qu'il devienne le nouveau nœud.
     */

    void push_front(T val){
        node* newNode = new node(val);

        if (isEmpty()){
            this->head = newNode;
            this->end = newNode;
            return;
        }

        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }


    //--------------------------------------------------------------------------------//

    /**
     * push_back() : Insère un nouvel élément à la fin de la liste doublement chaînée.
     *
     * ÉTAPES :
     * 1. On crée un nouveau nœud contenant la valeur.
     * 2. Si la liste est vide :
     *      - Le nouveau nœud devient à la fois head et end.
     * 3. Sinon (liste avec au moins un élément) :
     *      - On relie l'ancien dernier nœud au nouveau (end->next = newNode).
     *      - On indique que le nouveau pointe vers l'ancien dernier (newNode->prev = end).
     *      - On met à jour end pour qu'il devienne le nouveau nœud.
     */
    void push_back(T val){
        node* newNode = new node(val);

        if (isEmpty()){
            this->head = newNode;
            this->end = newNode;
            return;
        }

        this->end->next = newNode;
        newNode->prev = this->end;
        this->end = newNode;
    }


    
    //--------------------------------------------------------------------------------//

    /**
     * pop_front() : Supprime l'élément au début de la liste doublement chaînée.
     *
     * ÉTAPES :
     * 1. Si la liste est vide → rien à supprimer.
     * 2. Si la liste contient un seul élément :
     *      - On réinitialise head et end à nullptr (liste vide).
     * 3. Sinon (plusieurs éléments) :
     *      - On mémorise l'ancien premier nœud.
     *      - On avance head vers le second élément.
     *      - On met head->prev à nullptr car il devient la nouvelle tête.
     *      - On libère l'ancien premier nœud.
     */
    void pop_front(){
        if (isEmpty()){
            return;
        }

        if (this->head == this->end)
        {
            delete this->head;
            this->head = nullptr;
            this->end = nullptr;
            return;
        }

        node *toDelete = this->head;

        this->head = this->head->next;
        this->head->prev = nullptr;

        delete toDelete;
    }


    //--------------------------------------------------------------------------------//

   /**
     * pop_back() : Supprime l'élément en fin de liste doublement chaînée.
     *
     * ÉTAPES :
     * 1. Si la liste est vide → rien à supprimer.
     * 2. Si la liste contient un seul élément :
     *      - On réinitialise head et end à nullptr (liste vide).
     * 3. Sinon (plusieurs éléments) :
     *      - On mémorise l'ancien dernier nœud (toDeletedNode).
     *      - On déplace end vers l'avant-dernier nœud.
     *      - On met end->next à nullptr, car il devient le dernier.
     *      - On libère l'ancien dernier nœud.
     */
    void pop_back(){
        if (isEmpty()){
            return;
        }

        if (this->head == this->end)
        {
            this->head = nullptr;
            this->end = nullptr;
            return;
        }

        node *toDeletedNode = this->end;

        this->end = this->end->prev;
        this->end->next = nullptr;

        delete toDeletedNode;
    }


    /*-----------------------------------------------------------------------------------------*/
    /**
     * Fonction insertAt : insère un élément à une position donnée dans une liste doublement chaînée.
     *
     * ÉTAPES :
     * 1. On crée un nouveau nœud.
     * 2. On vérifie que la position est valide : elle doit être comprise entre 1 et length().
     * 3. Si pos == 1 → insertion au début (push_front).
     * 4. Si pos == length() → insertion en fin (push_back).
     * 5. Sinon → insertion en milieu : on se déplace jusqu’au nœud à l’index (pos - 1).
     *
     * LOGIQUE DE L’INSERTION AU MILIEU :
     * Soit temp le nœud juste avant la position où insérer.
     * On ajuste les pointeurs dans cet ordre :
     *
     *   newNode->next = temp->next;   // 1. Le nouveau pointe vers l'ancien suivant
     *   newNode->prev = temp;         // 2. Le nouveau pointe vers temp
     *
     *   temp->next->prev = newNode;   // 3. L'ancien suivant pointe vers le nouveau (en arrière)
     *   temp->next = newNode;         // 4. temp pointe vers le nouveau (en avant)
     */


    void insertAt(int val, int pos) {

        node *newNode = new node(val);

        if (pos < 1 || pos > length()){
            cout << "\n\nPosition saisie invalide";
            delete newNode;
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

   /**
     * deleteAt(pos) : Supprime l'élément se trouvant à la position pos
     * dans la liste doublement chaînée.
     *
     * ÉTAPES :
     * 1. Vérifier que la position est valide (entre 1 et length()).
     * 2. Cas particuliers :
     *      - pos == 1  → suppression au début (pop_front).
     *      - pos == length() → suppression à la fin (pop_back).
     * 3. Cas général (suppression en milieu) :
     *      - On parcourt la liste jusqu'au nœud à supprimer.
     *      - On relie le précédent au suivant.
     *      - On libère le nœud supprimé.
     *
     * NOTE IMPORTANTE :
     * Toujours delete le nœud supprimé pour éviter les fuites de mémoire.
     */
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

        for (int i = 1; i < pos; i++){
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }



    /*---------------------------------------------------------------------------------------------*/



    /**
     * showList() : Affiche le contenu de la liste doublement chaînée
     * depuis la tête jusqu'à la fin.
     *
     * ÉTAPES :
     * 1. On démarre depuis head.
     * 2. On affiche chaque élément suivi de " -> ".
     * 3. On s'arrête lorsque temp devient nullptr (fin de liste).
     */
    void showList() {
        cout << "Affichage de la liste bidirectionnelle : " << endl;

        node *temp = this->head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }



   /**
     * showReversedList() : Affiche le contenu de la liste doublement chaînée
     * depuis la fin (end) jusqu'au début (head).
     *
     * ÉTAPES :
     * 1. On démarre depuis end.
     * 2. On affiche chaque élément en remontant via prev.
     * 3. On s'arrête lorsque temp devient nullptr.
     */
    void showReversedList() {
        cout << "Affichage de la liste bidirectionnelle à l'envers : ";

        node *temp = this->end;

        while (temp != nullptr)
        {
            cout << temp->data << " <- ";
            temp = temp->prev;
        }

        cout << "NULL" << endl;
    }
};


