import java.util.ArrayList;

public abstract class Lutadores{
    private String nome;
    private int idade;
    private double peso;
    //private int id;
    public Lutadores(String nome, int idade, double peso){
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
    }

    public void possiveisLutas(Lutadores []lutadores){
        for(int i = 0; i < lutadores.length; i++){
            if(this.getClass() == lutadores[i].getClass() && !(this.nome.equals(lutadores[i].nome))){
                System.out.println(lutadores[i].nome + " está disponível para enfrentá-lo");
            }
        }
    }
//    public String categoriaLutador() {
//        if (this.id == 1) {
//            return "Peso pesado";
//        } else if (this.id == 2) {
//            return "Peso meio pesado";
//        } else if (this.id == 4) {
//            return "Peso pena";
//        } else if (this.id == 3) {
//            return "Peso médio";
//        }
    public String categoriaLutador() {
        if (this instanceof PesoPesado) {
            return "Peso pesado";
        } else if (this instanceof PesoMeioPesado) {
            return "Peso meio pesado";
        } else if (this instanceof PesoPena) {
            return "Peso pena";
        } else if (this instanceof PesoMedio) {
            return "Peso médio";
        }
        return "Categoria desconhecida";
    }

    public Lutadores sorteioLuta(Lutadores []lutadores){
        ArrayList<Lutadores> luta = new ArrayList();
        for(int i = 0; i < lutadores.length; i++){
            if (this.getClass() == lutadores[i].getClass()) {
            luta.add(lutadores[i]);
            }
        }
        int sorteado = (int) (Math.random() * luta.size());
        return luta.get(sorteado);
    }

    public String getNome(){
        return nome;
    }
    public void setNome(String nome){
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }

    public double getPeso() {
        return peso;
    }
    public void setPeso(double peso) {
        this.peso = peso;
    }

    @Override
    public String toString() {
        return nome + "/" + idade + "/" + peso;
    }
}
