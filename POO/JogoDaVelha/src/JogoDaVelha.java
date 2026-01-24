import java.util.Scanner;
public class JogoDaVelha{
    char [][]matriz;
    char Input;
    int contadorDeJogadas = 0;

    public JogoDaVelha(){
        matriz = new char[3][3];
        Input = 'X';
        preencher();
    }
    public void preencher(){
        for(int i = 0; i < 3;i++){
            for(int j = 0; j < 3; j++){
                matriz[i][j] = ' ';
            }
        }
    }
    public void mostrandoMatriz(){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(matriz[i][j]);
                if (j < 2) System.out.print("|");
            }
            System.out.println();
            if (i < 2) System.out.println("-----");
        }
    }
    public boolean Jogada(int linha, int coluna){
        if ((linha >= 0 && linha < 3) && (coluna >= 0 && coluna < 3) && matriz[linha][coluna] == ' '){
            matriz[linha][coluna] = Input;
            Input = (Input == 'X') ? 'O' : 'X';
            contadorDeJogadas++;
            return true;
        }
        return false;
    }
}
