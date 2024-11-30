int main() {
    int a = 0;
    int b = 5;
    if (a == b) { // Intended: a = b
        // This block will never execute, because the comparison is incorrect
        printf("a is now equal to b\n");
    }
    return 0;
}