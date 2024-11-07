#ifndef _NodoAB
#define _NodoAB

class NodoAB{
  public:
    int element;
    NodoAB *father;
    NodoAB *left;
    NodoAB *right;

    NodoAB(int elem); // construtor

    void print();
};
#endif
