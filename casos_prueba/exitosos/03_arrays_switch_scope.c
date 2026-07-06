int matriz[2][2] = {{1, 2}, {3, 4}};
int valor = matriz[0][1];
int opcion = 2;

switch(opcion) {
    case 1:
        valor = valor + 10;
        break;
    case 2:
        valor = valor + 20;
        break;
    default:
        valor = 0;
}

for(int i = 0; i < 2; i++) {
    int local = valor + i;
    valor = local;
}

