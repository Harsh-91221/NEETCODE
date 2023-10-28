import java.util.*;
class Alpha {
    public static void main(String[] args) {
        int a[] = new int[5];
        Scanner in = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            a[i] = in.nextInt();
        }

        for (int i = 0; i < 5; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
