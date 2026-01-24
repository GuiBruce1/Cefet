import java.text.DecimalFormat;
import java.text.NumberFormat;

public class ContaBancaria{
    private double saldo = 0;
    private Data dataAbertura;

    public double getSaldo() {
        return saldo;
    }
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public Data getDataAbertura() {
        return dataAbertura;
    }
    public void setDataAbertura(Data dataAbertura) {
        this.dataAbertura = dataAbertura;
    }

    public String getDataAberturaFormatada() {
        if (dataAbertura == null) {
            return "Data não definida";
        }
        return String.format("%02d/%02d/%04d", dataAbertura.getDia(), dataAbertura.getMes(), dataAbertura.getAno());
    }

    public String getSaldoFormatado() {
        NumberFormat formatoMoeda = DecimalFormat.getCurrencyInstance();
        return formatoMoeda.format(saldo).replace("$", "R$");
    }

    public void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        } else {
            System.out.println("Valor de depósito inválido.");
        }
    }

    public void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
        } else {
            System.out.println("Saque inválido. Verifique o saldo disponível.");
        }
    }
}


