#include <stdio.h>
#include <windows.h>

#define DEVICE_NAME "\\\\.\\ExampleDevice"
#define IOCTL_EXPOSED CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

void invokeUnsafeIOCTL(HANDLE deviceHandle) {
    DWORD bytesReturned;
    char inputBuffer[20] = "test";
    char outputBuffer[20];

    DeviceIoControl(
        deviceHandle,
        IOCTL_EXPOSED,
        inputBuffer,
        sizeof(inputBuffer),
        outputBuffer,
        sizeof(outputBuffer),
        &bytesReturned,
        NULL
    );
}

int main() {
    HANDLE deviceHandle = CreateFile(
        DEVICE_NAME,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (deviceHandle == INVALID_HANDLE_VALUE) {
        printf("Failed to open device\n");
        return 1;
    }

    invokeUnsafeIOCTL(deviceHandle);

    CloseHandle(deviceHandle);
    return 0;
}