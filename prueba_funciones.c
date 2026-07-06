int sumar(int a, int b) {
    return a + b;
}

void saludar(int x) {
    int y = x;
}

int main() {
    int resultado = sumar(1, 2);
    saludar(5);
    saludar(1, 2, 3);
    int mal = sumar(1);
}
