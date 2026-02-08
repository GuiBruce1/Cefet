import java.util.Scanner;

public class CaixaAutomatico {
    public static void main(String[] args) {
        Conta c1 = new Conta();
        //c1.setSaldo(100);
        c1.depositar(100);

        Scanner sc = new Scanner(System.in);
        System.out.println("Quanto quer sacar?");

        double valorSaque = sc.nextDouble();
        if(c1.debitar(valorSaque)){
            System.out.println("Liberando " + valorSaque + "em dinheiro." );
        }
        System.out.println("Fim");
    }
}