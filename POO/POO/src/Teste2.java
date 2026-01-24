import java.util.Scanner;

public class Teste2 {
	public static void main(String args[]){
		
		Scanner sc = new Scanner(System.in);
		String nome = sc.nextLine();		
		int idade = sc.nextInt();
		Pessoa p = new Pessoa();
		p.nome = nome;
		p.idade = idade;
		System.out.println(p.nome + " " + p.idade);
		
//		Pessoa p1[] = new Pessoa[3];
//		p1[0] = new Pessoa();
//		p1[1] = p1[0];
//		p1[2] = new Pessoa();
//		p1[0].idade = 8;
//		p1[1].idade = 6;
//		
//		for(int i = 0; i < p1.length; i++){
//			
//			System.out.println(p1[i].idade);
//		}
		//hash code ==> Syso(p1) Pessoa@1346474754 código que identifica o objeto
		
		
		
		sc.close();
		
		
		
		
		
	}

}
