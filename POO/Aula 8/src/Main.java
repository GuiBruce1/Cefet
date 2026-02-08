import java.util.ArrayList;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;

public class Main {
    public static void main(String[] args) {

//        ArrayList x = new ArrayList();
        Collection x = new HashSet();
        x.add("casa");
        x.add("mesa");
        System.out.println(x.add("casa"));
        x.add("toalha");

        System.out.println(x);
//        x.indexOf("Mesa"); // retorna o index do objeto no array list // se nenhum objeto é encontrado é retornado -1
//        x.contains("Mesa");
        double soma = 0;
        Iterator it = x.iterator(); // toda coleção tem acesso a um iterator
        while(it.hasNext()){
            Object obj = it.next();
            String k = (String) obj;
            soma += k.length();
        }
        System.out.println(soma/x.size());
    }
}
