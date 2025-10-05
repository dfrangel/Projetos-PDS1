void valida_data (int dia, int mes, int ano, int *end_valida, int *end_bissexto) {
    
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        *end_bissexto = 1;
    }
    else {
        *end_bissexto = 0;
    }
    
    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
            if (dia <= 29) {
                *end_valida = 1;
                return;
    	    }
            else {
                *end_valida = 0;
                return;
            }
        }
        else {
            if (dia <= 28) {
                *end_valida = 1;
                return;
            }
            else {
                *end_valida = 0;
                return;
            }
        }
}

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        if (dia <= 30) {
            *end_valida = 1;
            return;
        }
        else {
            *end_valida = 0;
            return;
        }
    }

    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        if (dia > 31) {
            *end_valida = 0;
            return;
    }
        else {
            *end_valida = 1;
            return;
        }
    }

    if (mes > 12) {
        *end_valida = 0;
        return;
    }


}