public class ninja {
    private String nome;
    private String aldeia;
    private int idade;
    private int nivelDeMissao;

    public int getNivelDeMissao(){
        return nivelDeMissao;
    }
    public void setNivelDeMissao(int nivelDeMissao){
        this.nivelDeMissao = nivelDeMissao;
    }

    public String getAldeia(){
        return aldeia;
    }
    public void setAldeia(String aldeia){
        this.aldeia = aldeia;
    }

    public int getIdade(){
        return idade;
    }
    public void setIdade(int idade){
        this.idade = idade;
    }

    // Getter - criar getter para mostrar para o usuário
    public String getNome(){
        return nome;
    }

    //Setter - Settar o valor da variável
    public void setNome(String nome){
        this.nome = nome;
    }



    public void ataqueBase(){
        System.out.println("Sou um ninja e taquei uma kunai");
    }


}
