//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        //objeto 1
        uzumaki naruto = new uzumaki();
        naruto.setNome("Naruto Uzumaki");
        System.out.println("Meu nome é " + naruto.getNome());
        naruto.setIdade(16);
        naruto.setAldeia("Vila da folha");
        naruto.setNivelDeMissao(5);
        naruto.chakraInfinito();
        naruto.temBijuu = true;
        naruto.ataqueBase();

        //objeto 2
        uchiha sasuke = new uchiha();
        sasuke.setNome("Sasuke Uchiha");
        System.out.println("Meu nome é " + sasuke.getNome());
        sasuke.setIdade(16);
        sasuke.setAldeia("Ninja renegado da vila da folha");
        sasuke.setNivelDeMissao(2);
        sasuke.sharinganAtivado();
        sasuke.ataqueBase();
        sasuke.ataqueBase(3);
    }
}