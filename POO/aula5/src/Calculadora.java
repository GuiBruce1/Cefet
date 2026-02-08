public class Calculadora{
    private String cor;

    public void setCor(String cor) {
        this.cor = cor;
    }
    public String getCor() {
        return cor;
    }

    public static double media(double a, double b){
        return (a+b)/2;
    }
    public static double media(double a, double b, double c){
        return (a+b+c)/3;
    }

}

