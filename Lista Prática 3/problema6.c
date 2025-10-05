void troca (int *end_valor1, int *end_valor2) {
    int holder;

    holder = *end_valor1;
    *end_valor1 = *end_valor2;
    *end_valor2 = holder;

    return;
}