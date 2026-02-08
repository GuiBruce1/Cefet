public class Conta{
    private String nomeCliente;
    private double saldo;

//    public String getNomeCliente(){
//        return nomeCliente;
//    }
//    public void setNomeCliente(String nomeCliente){
//        this.nomeCliente = nomeCliente;
//    }
//
//    public double getSaldo(){
//        return saldo;
//    }
//    public void setSaldo(double saldo){
//        this.saldo = saldo;
//    }

    public boolean debitar(double valor){
        if(valor <= saldo){
            saldo -= valor;
            System.out.println("Valor debitado: " + valor);
            return true;
        }else{
            System.out.println("Débito de " + valor + " não efetuado");
            return false;
        }
    }
    public void depositar(double valor){
        if(valor < 0) throw new RuntimeException();
        saldo += valor;
    }



}
