import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean emJogo = true;
        JogoDaVelha jogo = new JogoDaVelha();


        while(emJogo){
            jogo.mostrandoMatriz();
            System.out.println("Você é ->  " + (jogo.Input == 'X' ? 'X' : 'O') + ", faça seu movimento (linha e coluna): ");
            int linha = sc.nextInt(), coluna = sc.nextInt();

            if (jogo.Jogada(linha, coluna) == false) {
                System.out.println("Essa jogada não é válida. Tente novamente!");

            }
            if((jogo.matriz[0][0] == 'X' && jogo.matriz[0][1] == 'X' && jogo.matriz[0][2] == 'X') || (jogo.matriz[1][0] == 'X' && jogo.matriz[1][1] == 'X' && jogo.matriz[1][2] == 'X') || (jogo.matriz[2][0] == 'X' && jogo.matriz[2][1] == 'X' && jogo.matriz[2][2] == 'X') || (jogo.matriz[0][0] == 'X' && jogo.matriz[1][0] == 'X' && jogo.matriz[2][0] == 'X') || (jogo.matriz[0][1] == 'X' && jogo.matriz[1][1] == 'X' && jogo.matriz[2][1] == 'X') ||(jogo.matriz[0][2] == 'X' && jogo.matriz[1][2] == 'X' && jogo.matriz[2][2] == 'X') || (jogo.matriz[0][0] == 'X' && jogo.matriz[1][1] == 'X' && jogo.matriz[2][2] == 'X') || (jogo.matriz[0][2] == 'X' && jogo.matriz[1][1] == 'X' && jogo.matriz[2][0] == 'X')){
                System.out.println("O player X ganhou!");
                break;
            }
            if((jogo.matriz[0][0] == 'O' && jogo.matriz[0][1] == 'x' && jogo.matriz[0][2] == 'O') || (jogo.matriz[1][0] == 'O' && jogo.matriz[1][1] == 'O' && jogo.matriz[1][2] == 'O') || (jogo.matriz[2][0] == 'O' && jogo.matriz[2][1] == 'O' && jogo.matriz[2][2] == 'O') || (jogo.matriz[0][0] == 'O' && jogo.matriz[1][0] == 'O' && jogo.matriz[2][0] == 'O') || (jogo.matriz[0][1] == 'O' && jogo.matriz[1][1] == 'O' && jogo.matriz[2][1] == 'O') ||(jogo.matriz[0][2] == 'O' && jogo.matriz[1][2] == 'O' && jogo.matriz[2][2] == 'O') || (jogo.matriz[0][0] == 'O' && jogo.matriz[1][1] == 'O' && jogo.matriz[2][2] == 'O') || (jogo.matriz[0][2] == 'O' && jogo.matriz[1][1] == 'O' && jogo.matriz[2][0] == 'O')){
                System.out.println("O player O ganhou!");
                break;
            }
            if(jogo.contadorDeJogadas == 9){
                System.out.println("Deu velha!");
                break;
            }
        }
    }
}