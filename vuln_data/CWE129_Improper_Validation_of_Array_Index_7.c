int getUserInput();
void handleArrayIndex(int index);

int main() {
    int array[10];
    int index = getUserInput();
    if (index >= 0 && index < 10) {
        handleArrayIndex(array[index]);
    } else {
        printf("Invalid array index.\n");
    }
    return 0;
}

int getUserInput() {
    int input;
    printf("Enter an index: ");
    scanf("%d", &input);
    return input;
}

void handleArrayIndex(int value) {
    printf("Array value: %d\n", value);
}