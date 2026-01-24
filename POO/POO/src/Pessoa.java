
public class Pessoa {
	String nome;
	int idade;
	// se não for inserido um construtor, o java determina um contrutor padrão pela gente
	//a partir do momento que vc cria um construtor, não existe mais o construtor padrão
	
//	public Pessoa(){
//		System.out.println("Criando objeto pessoa");
//	}
	
//	podemos criar contrutores com argumentos 
//	public Pessoa(String n){
//		nome = n;
//	}
//	public Pessoa(String n, int i){
//		nome = n;
//		idade =i
//	}
//	public Pessoa(){
//		
//	}
//	para passar o parâmetro
//	Pessoa p =new Pessoa("João"); Já armezenaria joão na variável nome
//	Pessoa p2 =new Pessoa("Ana", 8); Já armezenaria Ana na variável nome e 8 na variável idade
//	Pessoa p3 =new Pessoa(); as 3 entradas vão ser aceitas desde que tenham os respectivos contrutores
	
	public void correr(){
		System.out.println("Pessoa correndo");
	}

}
