public class Funcionario {
    private String cpf;
    private int idade;

    public Funcionario(String c, int i){
        cpf = c;
        idade = i;
    }

    public String getCpf() {
        return cpf;
    }
    public void setCpf(String cpf) {// n precisaria pq cpf nn vai mudar mesmo
        this.cpf = cpf;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }
    public int getIdade() {
        return idade;
    }
}
