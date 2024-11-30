struct PrivateData {
    int value;
};

struct PrivateData private_data_instance;

struct PrivateData* getPrivateData() {
    return &private_data_instance;
}