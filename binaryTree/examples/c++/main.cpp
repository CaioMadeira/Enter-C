#include <iostream>
using namespace std;

#include "NodoAB.h"
#include "BinaryTreeOfInteger.h"

void imprimeLista(list<int> L, string msg)
{
    list<int>::iterator k;

    cout << msg;
    for (k = L.begin(); k != L.end(); k++ )
    {
        cout << *k << " " << endl;
    }
    cout << "FIM." << endl;
}

int main()
{
    BinaryTreeOfInteger b;
    b.addRoot(1);
    b.addLeft(2, 1);
    b.addRight(3, 1);
    b.addRight(0, 3);
    b.addLeft(4, 2);
    b.addRight(5, 2);
    b.addRight(6, 5);
    b.addRight(7, 6);
    
    list<int> L;
 
    cout << "CAMINHAMENTOS/VARREDURAS:" << endl;
    L = b.positionsPre();
    imprimeLista(L, "Varredura Pre-Fixada:\n");

    L.clear();
    L = b.positionsCentral();
    imprimeLista(L, "Varredura Central:\n");

    L.clear();
    L = b.positionsPos();
    imprimeLista(L, "Varredura Pos-Fixada:\n");

    L.clear();
    L = b.positionsWidth();
    imprimeLista(L, "Varredura em Largura:\n");

    b.removeBranch(2);

    b.addLeft(100, 0);

    cout << "Total de nodos da arvore: " << b.size() << endl;

    cout << "Altura da arvore = " << b.height() << endl;

    cout << "---------------------" << endl;
    b.GeraDOT();
    return 0;
}
