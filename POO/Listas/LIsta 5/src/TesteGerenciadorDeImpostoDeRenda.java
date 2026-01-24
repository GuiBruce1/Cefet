public class TesteGerenciadorDeImpostoDeRenda{
    public static void main(String[] args){
        // Criando cliente
        Cliente cliente = new Cliente("João", "123.456.789-00");

        // Criando bens tributáveis
        ContaCorrente cc1 = new ContaCorrente();
        cc1.deposita(1000);
        ContaCorrente cc2 = new ContaCorrente();
        cc2.deposita(2000);
        SeguroDeVida seguro = new SeguroDeVida();

        // Adicionando bens ao cliente
        cliente.adicionaTributavel(cc1);
        cliente.adicionaTributavel(cc2);
        cliente.adicionaTributavel(seguro);

        // Criando gerenciador e adicionando tributos
        GerenciadorDeImpostoDeRenda gerenciador = new GerenciadorDeImpostoDeRenda();
        for (Tributavel t : cliente.getArray()) {
            gerenciador.adiciona(t);
        }

        // Exibindo total de tributos
        System.out.println("Total de tributos a serem pagos: R$" + gerenciador.getTotal());
    }
}