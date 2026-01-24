import java.util.Scanner;

public class Teste3 {
	public static void main(String args[]){
		
		float media = 0;
		
		Pessoa p1[] = new Pessoa[3];
		
		Scanner sc = new Scanner(System.in);
		
		for(int i = 0; i < p1.length; i++){
			p1[i] = new Pessoa();
			
			System.out.println("Nome?");
			p1[i].nome = sc.nextLine(); 
			
			System.out.println("Idade?");
			p1[i].idade = sc.nextInt();
			
			System.out.println(p1[i].nome + " " + p1[i].idade);
			sc.nextLine();
			
			media += p1[i].idade;
		}
		
		System.out.println(media);
		sc.close();
	}

}
