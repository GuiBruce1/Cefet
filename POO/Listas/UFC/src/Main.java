import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){

        Lutadores []lutadores = new Lutadores[10];
        Scanner sc = new Scanner(System.in);

        for(int i = 0; i < lutadores.length; i++){
            System.out.println("Qual o nome do lutador a ser inserido");
            String nome = sc.nextLine();

            System.out.println("Insira a idade do Lutador");
            int idade = sc.nextInt();

            System.out.println("Qual o peso dele?");
            double peso = sc.nextDouble();

            if(peso <= 65){
                lutadores[i] = new PesoPena(nome,idade,peso);
            }else if(peso <= 83.9){
                lutadores[i] = new PesoMedio(nome,idade,peso);
            }else if(peso <= 93){
                lutadores[i] = new PesoMeioPesado(nome,idade,peso);
            }else{
                lutadores[i] = new PesoPesado(nome,idade,peso);
            }
        }
        System.out.print("Escolha um lutador (número de 0 a 9): ");
        int escolhido = sc.nextInt();

        Lutadores lutadorEscolhido = lutadores[escolhido];
        System.out.println("Lutador escolhido: " + lutadorEscolhido);

        System.out.println("Lutadores disponíveis para luta:");
        lutadorEscolhido.possiveisLutas(lutadores);

        Lutadores lutadorSorteado = lutadorEscolhido.sorteioLuta(lutadores);

        if (lutadorSorteado != null) {
            System.out.println("\nLutador sorteado para a luta: " + lutadorSorteado);
        } else {
            System.out.println("\nNenhum lutador disponível para a luta.");
        }

        sc.close();
    }
}