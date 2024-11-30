int* returnStackVariableAddress() {
    int localVariable = 42;
    return &localVariable;
}

int main() {
    int* faultyPointer = returnStackVariableAddress();
    // Attempting to use the faulty pointer will lead to undefined behavior
    // int value = *faultyPointer; // This may crash or give unexpected results
    return 0;
}