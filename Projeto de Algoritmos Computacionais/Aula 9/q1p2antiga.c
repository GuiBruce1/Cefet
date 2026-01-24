void preenchePercentualAumentoPorFornecedor(float *v[]){
    float aux[10][2];
    int codigoFornecedor;
    float aumentoPercentual;
    for(int i = 0; i < 10){
        int j = 0;
        scanf("d", &codigoFornecedor);
        scanf("f", &aumentoPercentual);
        
        aux[i][j] = codigoFornecedor;
        aux[i][j+1] = aumentoPercentual;   
    }
    for(int ultimo = 10-1; ultimo >= 0; ultimo--) {
        for(int i=0; i<ultimo; i++) {
            if(aux[i][1]>aux[i+1][1]) {
                int help = aux[i][1];
                aux[i][1] = aux[i][1];
                aux[i+1][1] = help;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        v[i]
    }
}