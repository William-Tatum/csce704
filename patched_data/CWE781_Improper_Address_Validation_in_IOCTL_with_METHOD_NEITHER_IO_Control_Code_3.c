#include <ntddk.h>

NTSTATUS ExampleIoctlHandler(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    PIO_STACK_LOCATION ioStackLocation = IoGetCurrentIrpStackLocation(Irp);
    VOID* inputBuffer = ioStackLocation->Parameters.DeviceIoControl.Type3InputBuffer;
    ULONG inputBufferLength = ioStackLocation->Parameters.DeviceIoControl.InputBufferLength;

    VOID* userPointer;
    SIZE_T size = inputBufferLength;

    if (inputBuffer == NULL) {
        Irp->IoStatus.Status = STATUS_INVALID_PARAMETER;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_INVALID_PARAMETER;
    }

    // Check for integer overflow
    if (size > SIZE_MAX / sizeof(CHAR)) {
        Irp->IoStatus.Status = STATUS_INVALID_PARAMETER;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_INVALID_PARAMETER;
    }

    __try {
        ProbeForRead(inputBuffer, inputBufferLength, sizeof(CHAR));
        
        userPointer = ExAllocatePoolWithTag(NonPagedPool, size, 'tag1');
        if (userPointer == NULL) {
            Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
            IoCompleteRequest(Irp, IO_NO_INCREMENT);
            return STATUS_INSUFFICIENT_RESOURCES;
        }

        // Initialize memory to avoid potential information leaks
        RtlZeroMemory(userPointer, size);

        RtlCopyMemory(userPointer, inputBuffer, size);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        if (userPointer != NULL) {
            ExFreePool(userPointer);
        }
        Irp->IoStatus.Status = STATUS_ACCESS_VIOLATION;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_ACCESS_VIOLATION;
    }

    ExFreePool(userPointer);

    Irp->IoStatus.Status = STATUS_SUCCESS;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}