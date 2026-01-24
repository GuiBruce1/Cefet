public class ContaCorrente extends Conta implements Tributavel{
    @Override
    public double calculaTributos() {
        return (getSaldo()*0.99);
    }
}
