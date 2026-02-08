public class Main {
    public static void main(String[] args) {

//        Animal j[] = new Animal[3];
//        j[0] = new Leao();
//        j[1] = new Urso();
//        j[2] =new Urso();
//        for(int i =0; i < j.length; i++){
//            j[i].correr();
//            if(j[i] instanceof Leao){
//                Leao m = (Leao)j[i];
//                m.rugir();
//            }
//        }
//        j[2] = j[1];
//        System.out.println(j[1].getNome());
//        j[2].setNome("Puff");
//        System.out.println(j[1].getNome()); saída é primeiro Null depois Puff

        Animal y[] = new Animal[1];


        Urso x = new Urso();
        x.setNome("Pooh");
        x.setIdade(10);
        x.correr();
        Leao k = new Leao();
        teste(k);
        teste(x);



    }
    public static void teste(Animal u){
        u.correr();
        if(u instanceof Leao){// pergunta se o objeto u se refere ao Leao, se é uma instancia dele
            Leao y = (Leao)u;// ((Leao) u).rugir(); não é mto bom usar pq esquecemos de um parentesis//casting para que Animal seja Leao
            y.rugir();
        }
    }
//    public static void teste(Urso u){
//        u.correr();
//    }
//    public static void teste(Leao x){
//        x.correr();
//    }
}