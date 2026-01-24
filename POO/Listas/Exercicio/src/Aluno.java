public class Aluno {
    private String nome;
    private double nota1;
    private double nota2;

    public void media(){
        double media;
        media = (this.nota1 + this.nota2)/2;
        System.out.println("A média de " + this.nome + " é " + media);
    }
    public void resultado(){
        double media;
        media = (this.nota1 + this.nota2)/2;
        if(media >= 6){
            System.out.println(this.nome + " está aprovado!");
        }else if(media < 4){
            System.out.println(this.nome + " está reprovado!");
        }else{
            System.out.println(this.nome + " está em recuperação!");

        }
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getNota1() {
        return nota1;
    }
    public void setNota1(double nota1) {
        if(nota1 < 0){
            this.nota1 = 0;
        }else if(nota1 >10){
            this.nota1 = 10;
        }else{
            this.nota1 = nota1;
        }

    }

    public double getNota2() {
        return nota2;
    }
    public void setNota2(double nota2) {
        if(nota2 < 0){
            this.nota2 = 0;
        }else if(nota2 >10){
            this.nota2 = 10;
        }else{
            this.nota2 = nota2;
        }
    }

}
