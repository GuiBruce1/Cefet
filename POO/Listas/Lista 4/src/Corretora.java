import java.util.Scanner;

public class Corretora{
    private Imovel[] imoveis = new Imovel[5];

//    public Corretora() {
//        imoveis = new Imovel[5];
//    }

    public void cadastrarImoveis() {
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < imoveis.length; i++) {
            System.out.println("\nCadastro do imóvel " + (i + 1));
            System.out.print("Informe o endereço: ");
            String endereco = scanner.nextLine();

            System.out.print("Informe o preço base do imóvel: ");
            double preco = scanner.nextDouble();

            System.out.print("O imóvel é novo ou velho? (N/V): ");
            char tipo = scanner.next().toUpperCase().charAt(0);
            scanner.nextLine(); // Consumir o \n

            if (tipo == 'N') {
                Novo novo = new Novo();
                novo.setEndereco(endereco);
                novo.setPreco(preco);
                imoveis[i] = novo;
            } else if (tipo == 'V') {
                Velho velho = new Velho();
                velho.setEndereco(endereco);
                velho.setPreco(preco);
                imoveis[i] = velho;
            } else {
                System.out.println("Tipo inválido! Cadastro cancelado para este imóvel.");
                i--; // Repetir o cadastro do mesmo imóvel
            }
        }

        scanner.close();
    }

    public double calcularPrecoTotal() {
        double total = 0.0;
//        for (Imovel imovel : imoveis) {
//            total += imovel.getPreco();
//        }
        for (int i = 0; i < imoveis.length; i++) {
            total += imoveis[i].getPreco();
        }
        return total;
    }

//    public void listarImoveis() {
//        System.out.println("\nLista de Imóveis:");
//        for (int i = 0; i < imoveis.length; i++) {
//            Imovel imovel = imoveis[i];
//            System.out.println("Imóvel " + (i + 1) + ":");
//            System.out.println("Endereço: " + imovel.getEndereco());
//            System.out.println("Preço com ajuste: R$ " + imovel.getPreco());
//            System.out.println("----------------------------");
//        }
}


