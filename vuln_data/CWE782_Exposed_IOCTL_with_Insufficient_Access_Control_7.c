#include <stdio.h>
#include <windows.h>

#define FILE_DEVICE_UNKNOWN 0x00008000
#define IOCTL_PRIVILEGED_FUNCTION CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

HANDLE device;

void OpenDevice() {
    device = CreateFile(TEXT("\\\\.\\ExampleDevice"), GENERIC_READ | GENERIC_WRITE,
                        0, NULL, OPEN_EXISTING, 0, NULL);
}

void UnsafeIoctlCall() {
    DWORD bytesReturned;
    char inputBuffer[256];
    char outputBuffer[256];

    DeviceIoControl(device, IOCTL_PRIVILEGED_FUNCTION, inputBuffer, sizeof(inputBuffer),
                    outputBuffer, sizeof(outputBuffer), &bytesReturned, NULL);
}

int main() {
    OpenDevice();
    UnsafeIoctlCall();
    CloseHandle(device);
    return 0;
}