// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {
        BinaryTreeOfInteger b = new BinaryTreeOfInteger();
        // b.addRoot(1);
        // b.addLeft(2, 1);
        // b.addRight(3, 1);
        // b.addRight(0, 3);
        // b.addLeft(4, 2);
        // b.addRight(5, 2);
        // b.addRight(6, 5);
        // b.addRight(7, 6);


        b.addRoot('A');
        b.addLeft('B', 'A');
        b.addRight('C', 'A');

        b.addLeft('D', 'B');
        b.addLeft('F', 'C');

        b.addRight('E', 'B');
        b.addRight('G', 'C');

        System.out.println("[3] Caminhamento Central:");
        System.out.println(b.positionsCentral());
    }
}