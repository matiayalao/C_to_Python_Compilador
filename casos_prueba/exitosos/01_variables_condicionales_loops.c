int global = 1;
float promedio = 2.5;
const int limite = 4;

int contador = 0;

for(int i = 0; i < limite; i++) {
    contador = contador + i;
}

while(contador < 10) {
    contador++;
}

if(contador >= 10) {
    promedio = promedio + contador;
} else {
    promedio = promedio - 1;
}

