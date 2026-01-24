import java.util.ArrayList;

public class Cliente implements Tributavel{
    private String nome;
    private String cpf;
//    Tributavel []array = new Tributavel[10];
    private ArrayList<Tributavel> array = new ArrayList<>();

    public Cliente(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
        this.array = new ArrayList<>();
    }
    public void adicionaTributavel(Tributavel t) {
        array.add(t);
    }

    public ArrayList<Tributavel> getArray() {
        return array;
    }
    @Override
    public double calculaTributos() {
        return 0;
    }
}
