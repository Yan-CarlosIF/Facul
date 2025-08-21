package livro_resolvidas.Q1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Type[] types = new Type[2];

        for (int i = 0; i < 2; i++) {
            int code;

            do {
                System.out.printf("Type code for %d° type: ", i + 1);
                code = sc.nextInt();

                if (code < 1 || code > 2) {
                    System.out.println("Invalid type, try again...");
                }
            } while (code < 1 || code > 2);

            System.out.printf("Type percentage for %d° type: ", i + 1);
            types[i] = new Type(code, sc.nextFloat());
        }

        sc.nextLine();
        System.out.print("Type product's description: ");
        String description = sc.nextLine();
        int typeCode;

        do {
            System.out.print("Choose between 1 or 2: ");
            typeCode = sc.nextInt();
        } while (typeCode < 1 || typeCode > 2);

        int index = 0;

        for (int i = 0; i < types.length; i++) {
            if (types[i].getTypeCode() == typeCode) {
                index = i;
                break;
            }
        }

        System.out.print("Type the product price: ");
        Product product = new Product(description, types[index], sc.nextDouble());

        System.out.println("Product final price: " + product.calculateFinalPrice());
    }
}
