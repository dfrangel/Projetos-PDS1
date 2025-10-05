int inverte (int n) {
    int i = 1, soma = 0, digito;

    for (i = 1; n > 0; i++) {
        
        digito = n - (10 * (n / 10));
        
        soma = (10 * soma) + digito;

        n = (n / 10);
    }
    return soma;
}