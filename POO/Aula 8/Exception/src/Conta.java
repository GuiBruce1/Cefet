public class Conta{
    private double saldo;
    
    public void sacar(double x)/*throws SemDinheiroException, isso joga a responsabilidade de quem está chamando fazer o try catch, já que é uma exceção checked*/{
        if(saldo < x) {
          throw new RuntimeException();
//            throw new SemDinheiroException();

        }else{
            saldo -= x;
        }
    }
    public void depositar(double x){
        if(x < 0){
            throw new RuntimeException("Valor menor que 0: " + x);
        }else{
            saldo += x;
        }
    }
}
