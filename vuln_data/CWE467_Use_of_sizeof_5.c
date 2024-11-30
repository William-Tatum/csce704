int main() {
    int *arr = malloc(10 * sizeof(int));
    if (arr == NULL) {
        return 1;
    }
    
    size_t size_of_arr = sizeof(arr);
    printf("Size of array: %zu\n", size_of_arr);

    free(arr);
    return 0;
}