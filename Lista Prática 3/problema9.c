void media (float nota1, float nota2, float *end_media, char *end_status) {

    *end_media = (nota1 + nota2) / 2;
    
    if (*end_media >= 7) {
        *end_status = 'A';
        return;
    }
    else if (*end_media >= 4) {
        *end_status = 'E';
        return;
    }
    else {
        *end_status = 'R';
        return;
    }
}