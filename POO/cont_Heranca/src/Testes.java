public class Testes {
    public static void main(String[] args) {

//        Funcionario f = new Funcionario("01057869776", 26);
//        System.out.println((f.getCpf()));
//        System.out.println(f.getIdade());
//
        Funcionario x = new Funcionario("34335675733", 18);
//        System.out.println(Math.random()); classe static //Math não precisa de import
        x.setIdade(39);
        Funcionario y = new Funcionario("888",20);
        System.out.println(x.getCpf());
//       System.out.println(Funcionario.getCpf()); isso é parte da explicação de pq nn pode usar o static no getter
        System.out.println(y.getCpf());


    }
}