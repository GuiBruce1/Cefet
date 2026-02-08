import java.util.*;

public class Principal{
    public static void main(String[] args){

        Map m = new HashMap();
        m.put("331-2", new Aluno("331-2"));
        Aluno k = new Aluno("4123-3");
        k.setP1(8);
        k.setP2(8);
        m.put(k.getMatricula(),k);
        m.put("331-2", new Aluno("4432-1")); // substitui o anterior
        m.put("440", k); // chaves são unicas, mas podem apontar para objetos repetidos
        m.remove("440"); //passamos a chave


//        System.out.println(m);
//        System.out.println((m.get("331-2")));








//        Set y = m.keySet(); // poderia usar colletion no lugar de set, set é  uma collection
//        double soma = 0;
//        Iterator i = y.iterator();
//        while(i.hasNext()){
//            String key = (String) i.next();
//            Aluno f = (Aluno) m.get(key);
//            soma += f.getP1();
//        }
//        Collection c = m.values();   Outra forma de fazer o de cima
//        Iterator it = c.iterator();
//        while(it.hasNext()){
//            Aluno a = (Aluno) it.next();
//            soma += a.getP1();
//        }


    }
}
