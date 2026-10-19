#include <iostream>
using namespace std;
#include <queue>
//Notas par BST Codes

//Para casi todos los codigos debe existir un Struct
//este se encarga de representar los espacios de memoria
//de cada nodo, por lo que se crea una variable que guarde 
//el valor del nodo llamada info, luego se utiliza Node* 
//para referirse a esa direccion y alli mismo guardar, 
//para la izquierda y la derecha como: Node* left y Node* right.

struct Node{
    int info;
    Node* left;
    Node* right;

    Node(int value){  //Inicializa el valor del nodo y sus dos hijos como nullptr.
        info = value;
        left = nullptr;
        right = nullptr;
    }
};

//Esto se supone que ya va a estar implementado en el examen
//Pero basicamente es el constructor y la clase BST para que las
//funciones q hamos funcionen.

class BST {
private:
    Node* root;
    Node* findMin(Node* n) const;
    bool remove(Node*& n, int x);

public:
    BST() {
        root = nullptr;
    }

    void preorder(Node* n) const;
    void inorder(Node* n) const;
    void postorder(Node* n) const;

    int depth(Node* n, int x) const;
    int height(Node* n) const;

    bool insert(Node*& n, int x);
    Node* search(Node* n, int x) const;

    void levelOrder(Node* n) const;
    
    void preorder() const {
        preorder(root);
        cout << endl;
    }

    void inorder() const {
        inorder(root);
        cout << endl;
    }

    void postorder() const {
        postorder(root);
        cout << endl;
    }

    int depth(int x) const {
        return depth(root, x);
    }

    int height() const {
        return height(root);
    }

    bool insert(int x) {
        return insert(root, x);
    }

    bool contains(int x) const {
        return search(root, x) != nullptr;
    }

    bool remove(int x) {
        return remove(root, x);
    }
    void levelOrder() const {
        levelOrder(root);
        cout << endl;
    }
};


//Y si un nodo no tiene hijo izq entonces left == nullptr.

//* DIFERENCIA ENTRE Node* n y Node*& n */

//Node* n: significa q la funcion recibe una copia del puntero,
//puede consultar el nodo y modificar sus atributos.
//Este es util en inorder y en search, accede pero no cambia a los demas.

//Node*& n: significa que recibe una referencia al puntero orignal. 
//Si hacemos n = new Node, modificamos directamente el enlace del arbol
// como root, parent->left o parent -> right. 
//Este es util en insert y remove.


//NIVEL 1

//BST es recursivo porque se llama a si misma en varios problemas

void BST::preorder(Node* n) const{
    if (n == nullptr){  
        return;
    }
    cout << n->info<< " ";
    preorder(n->left);
    preorder(n->right);
}

void BST::inorder(Node* n) const{
    if (n == nullptr){  //Esto se usa solo si esta vacio el arbol
        return;
    }
    inorder(n->left); //Primero el left subtree
    cout << n->info << " "; //el root
    inorder(n->right); //el right subtree
}

void BST::postorder(Node* n) const{
    if (n == nullptr){  
        return;
    }
    postorder(n->left);
    postorder(n->right);
    cout << n->info<< " ";
}

//NIVEL 2

int BST::depth(Node *n, int x) const {
    if(n== nullptr){
        return -1;
    }
    if(n->info == x){
        return 0;
    }
    int result;
    if(x < n->info){
        result = depth(n->left,x);
    }
    else{
        result = depth(n->right,x);
    }
    if(result == -1)
        return  -1;
    return result +1;
}

int BST::height(Node *n) const{
    if(n==nullptr)return -1;
    int leftH = height(n->left);
    int rightH = height(n->right);
    return 1 + max(leftH,rightH);

}

//NIVEL 3

//En un BST la regla siempre es que a la izquierda 
//ira el valor menor y a la derecha el mayor y solo se pueden 2 hijos

Node* BST::search(Node* n, int x) const{
    if (n == nullptr){  
        return nullptr;
    }
    if(x < n->info) return search(n->left,x);
    if(x > n->info) return search(n->right,x);
    return n;
    
};

bool BST::insert(Node *&n, int x){
    if(n== nullptr){
        n = new Node(x);
        return true;
    }
    if (x==n->info)
         return false;
    if(x<n->info)
        return insert(n->left,x);
    return insert(n->right,x);

}

//NIVEL 4

//Remove y LevelOrder

bool BST::remove(Node *&n, int x){
    if(n== nullptr){
        return false;
    }
    if(x< n ->info){
        return remove(n->left,x);
    }
    if(x >n->info){
        return remove(n->right,x);
    }
    //dos hijos
    if(n->left != nullptr && n->right != nullptr){
    //copiar sucesor
        n->info = findMin(n->right)->info;
    //ponerlo como root y borrar la antigua
        return remove(n->right,n->info);
    }
    // para hojas o solo un hijo
    Node* old = n;
    if(n->left != nullptr) n=n->left;
    else n = n->right;
    delete old;
    return true;
}

Node* BST::findMin(Node *n) const{
    while (n->left !=nullptr)
    {
        n= n->left;
    }
    return n;
    
}
void BST::levelOrder(Node *n) const{
    if(n == nullptr){
        return;
    }
    queue<Node*> q;
    q.push(n);
    while (!q.empty()){
        Node *current = q.front();
        q.pop();
        cout <<current->info<<" ";
        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr){
            q.push(current->right);
        }
    }
    
}



int main() {

    // Crear un árbol vacío
    BST tree;

    cout << "===== PRUEBAS BST =====" << endl;

    // NIVEL 3: INSERT
    cout << "\n--- INSERT ---" << endl;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Arbol creado correctamente" << endl;

    // NIVEL 1: RECORRIDOS
    cout << "\n--- RECORRIDOS ---" << endl;

    cout << "Preorder: ";
    tree.preorder();

    cout << "Inorder: ";
    tree.inorder();

    cout << "Postorder: ";
    tree.postorder();

    // NIVEL 2: DEPTH Y HEIGHT
    cout << "\n--- DEPTH Y HEIGHT ---" << endl;

    cout << "Height del arbol: "
         << tree.height() << endl;

    cout << "Depth del nodo 40: "
         << tree.depth(40) << endl;

    cout << "Depth del nodo 80: "
         << tree.depth(80) << endl;

    cout << "Depth del nodo 50: "
         << tree.depth(50) << endl;

    // NIVEL 3: SEARCH
    cout << "\n--- SEARCH ---" << endl;

    cout << "Buscar 40: "
         << (tree.contains(40) ? "Encontrado" : "No encontrado")
         << endl;

    cout << "Buscar 100: "
         << (tree.contains(100) ? "Encontrado" : "No encontrado")
         << endl;

    // NIVEL 4: LEVEL ORDER
    cout << "\n--- LEVEL ORDER ---" << endl;

    cout << "Level Order: ";
    tree.levelOrder();

    // NIVEL 4: REMOVE
    cout << "\n--- REMOVE ---" << endl;

    // Caso 1: eliminar una hoja
    cout << "\nEliminar 20 (hoja)" << endl;
    tree.remove(20);
    tree.inorder();

    // Caso 2: eliminar nodo con un hijo
    cout << "\nEliminar 30 (un hijo)" << endl;
    tree.remove(30);
    tree.inorder();

    // Caso 3: eliminar nodo con dos hijos
    cout << "\nEliminar 70 (dos hijos)" << endl;
    tree.remove(70);
    tree.inorder();

    // Caso 4: eliminar la raiz
    cout << "\nEliminar 50 (raiz)" << endl;
    tree.remove(50);
    tree.inorder();

    cout << "\n===== FIN DE PRUEBAS =====" << endl;

    return 0;
}
