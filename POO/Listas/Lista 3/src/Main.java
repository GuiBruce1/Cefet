public class Main {
    public static void main(String[] args){

        // Criando a data de abertura
        Data dataAbertura = new Data();
        dataAbertura.setDia(12);
        dataAbertura.setMes(5);
        dataAbertura.setAno(2012);

        // Criando a conta bancária
        ContaBancaria conta = new ContaBancaria();
        conta.setDataAbertura(dataAbertura);

        // Exibindo a data de abertura
        System.out.println("Data de abertura: " + conta.getDataAberturaFormatada());

        // Realizando operações
        conta.depositar(5000.0);
        System.out.println("Saldo após depósito: " + conta.getSaldoFormatado());

        conta.sacar(1500.0);
        System.out.println("Saldo após saque: " + conta.getSaldoFormatado());

        // Tentativa de saque inválido
        conta.sacar(4000.0);
        System.out.println("Saldo final: " + conta.getSaldoFormatado());

    }
}