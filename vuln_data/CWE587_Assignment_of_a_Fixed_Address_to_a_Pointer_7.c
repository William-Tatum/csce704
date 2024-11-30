int main() {
    int *ptr;
    int variable = 0;
    ptr = &variable;
    *ptr = 10;
    printf("%d\n", *ptr);
    return 0;
}