public class Gato {
    private String nome;
    private int idade;

    public Gato(String N, int i){
        nome = N;
        idade = i;
    }
    public String toString(){
        return nome;
    }

    public boolean equals(Object O) {
        if(O instanceof Gato){
            Gato K = (Gato) O;
            boolean b = nome.equals(K.nome);
            return b;
        }
        return false;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
    public int getIdade() {
        return idade;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
}
