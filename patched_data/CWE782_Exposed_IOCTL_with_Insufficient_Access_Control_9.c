#include <stdio.h>
#include <windows.h>

#define DEVICE_NAME "\\\\.\\ExampleDevice"
#define IOCTL_EXPOSED CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

void invokeSafeIOCTL(HANDLE deviceHandle) {
    DWORD bytesReturned;
    char inputBuffer[20] = "test";
    char outputBuffer[20];

    if (!DeviceIoControl(
        deviceHandle,
        IOCTL_EXPOSED,
        inputBuffer,
        sizeof(inputBuffer),
        outputBuffer,
        sizeof(outputBuffer),
        &bytesReturned,
        NULL
    )) {
        printf("DeviceIoControl failed: %lu\n", GetLastError());
    } else {
        printf("DeviceIoControl succeeded\n");
    }
}

int main() {
    HANDLE deviceHandle = CreateFile(
        DEVICE_NAME,
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (deviceHandle == INVALID_HANDLE_VALUE) {
        printf("Failed to open device: %lu\n", GetLastError());
        return 1;
    }

    invokeSafeIOCTL(deviceHandle);

    CloseHandle(deviceHandle);
    return 0;
}