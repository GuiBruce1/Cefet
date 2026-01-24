
public class Vetores {
	public static void main(String args[]){ // não faz diferença se botar (String [] args)
		
//		int u[];
//		int []j;
		
//		int []j, f; as duas estão sendo declaradas como arrays de inteiro
//		int m[], n; m é um array de inteiro e n é só um inteiro

		int soma = 0; // variáveis locais não tem valor default
		
		String palavras[] = new String[3];
		palavras[0] = "Casa";
		palavras[1] = "Navio";
		palavras[2] = "Mesa";
		
		for(int k = 0; k < palavras.length; k++){
		
			soma += palavras[k].length();
		}
		
//		int i[] = new int[3];
//		i[0] = 8;
//		i[2] = 4;;
//		
//		System.out.println(i[0]);
//		System.out.println(i[2]);
//		
//		for(int k = 0; k < i.length; k++){
//			
//			soma += i[k];
//		}
//		
		System.out.println(soma);
		
	}
}	
