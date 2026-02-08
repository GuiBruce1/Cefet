public class Main {
    public static void main(String[] args) {

        Conta c = new Conta();
        double valSaque = 100;
        try{
            c.sacar(valSaque);
            System.out.println("Liberando dinheiro");
        }catch(RuntimeException e){
            System.out.println(e);
            e.printStackTrace();
            System.out.println(e.getMessage());
        }

        c.depositar(-8);
    }
}