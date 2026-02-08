public class uchiha extends ninja{
    String nivelDoSharingan = "Dois Tomois";

    public void sharinganAtivado(){
        System.out.println("Sharingan ativado");
    }

    @Override
    public void ataqueBase(){
        System.out.println("Sou um ninja e taquei uma kunai do elemento fogo");
    }

    public void ataqueBase(int nivelDeChakra){
        if (nivelDeChakra > 2){
            System.out.println("Susano'o ativado");
        }else if (nivelDeChakra >= 1){
            System.out.println("Eu só consigo ativar o sharingan");
        }else{
            System.out.println("Eu tô sem chakra");
        }
    }
}
