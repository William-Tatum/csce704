#include <stdio.h>
#include <windows.h>

#define IOCTL_CODE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)

HANDLE device_handle;

BOOL IsProcessAdmin() {
    BOOL isAdmin = FALSE;
    PSID adminGroup = NULL;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;
    if (AllocateAndInitializeSid(&ntAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &adminGroup)) {
        CheckTokenMembership(NULL, adminGroup, &isAdmin);
        FreeSid(adminGroup);
    }
    return isAdmin;
}

BOOL SecureIoctlCall() {
    if (!IsProcessAdmin()) {
        printf("Access denied. Administrator privileges are required.\n");
        return FALSE;
    }

    DWORD bytesReturned;
    char inBuffer[100] = {0};
    char outBuffer[100] = {0};

    BOOL result = DeviceIoControl(device_handle, IOCTL_CODE, inBuffer, sizeof(inBuffer), outBuffer, sizeof(outBuffer), &bytesReturned, NULL);
    if (!result) {
        printf("IOCTL call failed.\n");
        return FALSE;
    }

    printf("IOCTL call succeeded.\n");
    return TRUE;
}

int main() {
    device_handle = CreateFile("\\\\.\\ExampleDevice", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (device_handle == INVALID_HANDLE_VALUE) {
        printf("Failed to open device.\n");
        return 1;
    }

    SecureIoctlCall();

    CloseHandle(device_handle);
    return 0;
}