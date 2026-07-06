int sumar(int a, float b) {
    return a + b;
}

void imprimir(int x, int y) {
    int z = x + y;
}

int main() {
    int r1 = sumar(1, 2);
    int r2 = sumar(3.14, 5);
    imprimir(1, 2);
    imprimir(1, 3.14);
    imprimir(1, 2, 3);
    int r3 = sumar(1);
}
