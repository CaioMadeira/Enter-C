
import java.util.NoSuchElementException;

/**
 * Classe de arvore binaria de numeros inteiros.
 */

public class BinaryTreeOfInteger {

    // classe privada interna que cria o Nodo
    private static final class Node {

        public Node father;
        public Node left; // nodo da esquerda (diferencial da generica)
        public Node right; // nodo da direita (diferencial da generica)
        private char element;

        public Node(char element) {
            father = null;
            left = null;
            right = null;
            this.element = element;
        }
    }

    // Atributos da classe da Arvore
    private int count; //contagem do número de nodos
    private Node root; //referência para o nodo raiz

    // Metodos
    public BinaryTreeOfInteger() {
        count = 0;
        root = null;
    }

    /**
     * Remove todos os elementos da arvore.
     */
    public void clear() {
        count = 0;
        root = null;
    }

    /**
     * Verifica se a arvore esta vazia ou nao.
     *
     * @return true se arvore vazia e false caso contrario.
     */
    public boolean isEmpty() {
        return (root == null);
    }

    /**
     * Retorna o total de elementos da arvore.
     *
     * @return total de elementos
     */
    public int size() {
        return count;
    }

    /**
     * Retorna o elemento armazenado na raiz da arvore.
     *
     * @throws EmptyTreeException se arvore vazia.
     * @return elemento da raiz.
     */
    public char getRoot() {
        if (isEmpty()) {
            throw new EmptyTreeException();
        }
        return root.element;
    }
    // Metodo privado que procura por element a partir de target
    // e retorna a referencia para o nodo no qual element esta
    // armazenado. Retorna null se nao encontrar element.
    private Node searchNodeRef(char element, Node target) {
        if (target == null)
            return null;
        // Visita a "raiz"
        if (element == target.element)
            return target; // se achou element na "raiz"

        // Visita subarvore da esquerda
        Node aux = searchNodeRef(element, target.left);

        // Se nao encontrou, visita a subarvore da direita
        if (aux == null)
            aux = searchNodeRef(element, target.right);

        return aux;
    }

    /**
     * Verifica se element esta ou nao armazenado na arvore.
     *
     * @param element
     * @return true se element estiver na arvore, false caso contrario.
     */
    public boolean contains(char element) {
        Node nAux = searchNodeRef(element, root);
        return (nAux != null);
    }

    /**
     * Retorna quem e o elemento pai do elemento passado por parametro.
     *
     * @param element
     * @return pai de element
     */
    public char getParent(char element) {
        Node n = this.searchNodeRef(element, root);
        if (n == null) {
            return '\0';
        } else if (n.father==null) {
            return '\0';
        }else {
            return n.father.element;
        }
    }

    /**
     * Altera o elemento da raiz da arvore.
     *
     * @param element a ser colocado na raiz da arvore.
     */
    public void setRoot(char element) {
        if (root != null){
            root.element = element;
        }
    }

    /**
     * Insere o elemento como raiz da arvore, se a arvore estiver vazia.
     * @param element a ser inserido.
     * @return true se for feita a insercao, e false caso a arvore nao estiver
     * vazia e a insercao não for feita.
     */
    public boolean addRoot(char element) {
        if (root != null) // se a arvore nao estiver vazia
            return false;
        root = new Node(element);
        count++;
        return true;
    }

    /**
     * Insere element a esquerda de elemFather. Se nao encontrar father,
     * ou se father ja tiver um filho a esquerda, element nao e´
     * inserido.
     *
     * @param element a ser inserido
     * @param elemFather pai do elemento a ser inserido
     * @return true se foi feita a inserção, e false caso contrario.
     */
    public boolean addLeft(char element, char elemFather) {
        // Primeiro procura por elemFather
        Node aux = searchNodeRef(elemFather,root);

        // Se nao encontrou elemFather
        if (aux == null)
            return false;
        // Se elemFather ja tem filho a esquerda
        if (aux.left != null)
            return false;

        // Senao, insere element
        Node n = new Node(element); // primeiro cria o nodo
        n.father = aux; // faz o novo nodo apontar para o pai
        aux.left = n;// faz o pai apontar para o filho
        count++; // atualiza count
        return true;
    }

    /**
     * Insere element a direita de elemFather. Se nao encontrar father,
     * ou se father ja tiver um filho a direita, element nao e´
     * inserido.
     *
     * @param element a ser inserido
     * @param elemFather pai do elemento a ser inserido
     * @return true se foi feita a inserção, e false caso contrario.
     */
    public boolean addRight(char element, char elemFather) {
        // Primeiro procura por elemFather
        Node aux = searchNodeRef(elemFather,root);

        // Se nao encontrou elemFather
        if (aux == null)
            return false;
        // Se elemFather ja tem filho a direita
        if (aux.right != null)
            return false;

        // Senao, insere element
        Node n = new Node(element); // primeiro cria o nodo
        n.father = aux; // faz o novo nodo apontar para o pai
        aux.right = n;// faz o pai apontar para o filho
        count++; // atualiza count
        return true;
    }

    // Conta o numero de nodos a partir de "n"
    private int countNodes(Node n) {
        if (n==null)
            return 0;
        return 1 + countNodes(n.left) + countNodes(n.right);
    }

// ---------------------------------------------------------------------
    /**
     * Retorna uma lista com todos os elementos da arvore na ordem do
     * caminhamento pre-fixado.
     *
     * @return lista com todos os elementos da arvore.
     */
    public LinkedListOfInteger positionsPre() {
        LinkedListOfInteger lista = new LinkedListOfInteger();
        positionsPreAux(root, lista);
        return lista;
    }

    private void positionsPreAux(Node n, LinkedListOfInteger lista) {
        if (n != null) {
            lista.add(n.element); // visita raiz
            positionsPreAux(n.left,lista); // percorre subarvore da esq
            positionsPreAux(n.right,lista); // percorre subarvore da dir
        }
    }

    /*
     *  positionsCentral() - Recursivo e com método auxiliar
     *  
     */
    public LinkedListOfInteger positionsCentral() {
        LinkedListOfInteger lista = new LinkedListOfInteger();
        positionsCentralAux(root, lista);
        return lista;
    }

    public void positionsCentralAux(Node n, LinkedListOfInteger lista)
    {
        if (n != null)
        {
            positionsCentralAux(n.left, lista); // percorre a subarvore da esquerda
            lista.add(n.element); // visita a raiz
            positionsCentralAux(n.right, lista); // percorre a subarvore da direita
        }
    }
    /* 
     *  positionsCentral() - Iterativo e sem metodo auxiliar
     *  
     */

    public LinkedListOfInteger positionsCentral(Node n)
    {
        LinkedListOfInteger lista = new LinkedListOfInteger();
        Node p;
        for(p = n; p != root; p = p.left)
        {
            lista.add(n.element);
        }

        return lista;
    }
}
