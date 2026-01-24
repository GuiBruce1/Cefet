public class Main {
    public static void main(String[] args){

        Leao scar = new Leao();
        scar.nome = "Scar";
        scar.cor = "Marrom";
        scar.vivo = true;
        scar.idade = 13;

        Leao simba = new Leao();
        simba.nome = "Simba";
        simba.cor = "Bege";
        simba.vivo = true;
        simba.idade = 3;

        Leao mufasa = new Leao();
        mufasa.idade = 9;
        mufasa.vivo = false;
        mufasa.nome = "Mufasa";
        mufasa.cor = "Dourado";

        System.out.println(scar.nome + " " + scar.idade + " " + scar.cor + " " + scar.vivo);
        System.out.println(simba.nome + " " + simba.idade + " " + simba.cor + " " + simba.vivo);
        System.out.println(mufasa.nome + " " + mufasa.idade + " " + mufasa.cor + " " + mufasa.vivo);

        // Os tipos primitivos são int, float, double, short i, boolean, char, byte, long


    }
}