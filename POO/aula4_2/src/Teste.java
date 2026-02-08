public class Teste {
    public static void main(String[] args) {
        Gato g = new Gato(/* "Félix, 13*/);
        g.setNome("Apatsu");
        System.out.println(g.getNome());
        g.setIdade(13);
        System.out.println(g.getIdade());

        //g.getNome():String - Animal significa que é do tipo string denotado em animal
        //g.toString():String - Object significa que é do tipo string e é denotado em Object
        System.out.println(g.toString());// imprime o objeto referente concatenado a um @ e ao hash code
        g.miar();

    }
}