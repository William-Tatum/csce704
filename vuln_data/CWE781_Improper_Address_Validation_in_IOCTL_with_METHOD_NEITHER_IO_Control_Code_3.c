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

    __try {
        ProbeForRead(inputBuffer, inputBufferLength, sizeof(CHAR));
        userPointer = ExAllocatePoolWithTag(NonPagedPool, size, 'tag1');
        if (userPointer == NULL) {
            Irp->IoStatus.Status = STATUS_INSUFFICIENT_RESOURCES;
            IoCompleteRequest(Irp, IO_NO_INCREMENT);
            return STATUS_INSUFFICIENT_RESOURCES;
        }

        RtlCopyMemory(userPointer, inputBuffer, size);
        ExFreePool(userPointer);
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        Irp->IoStatus.Status = STATUS_ACCESS_VIOLATION;
        IoCompleteRequest(Irp, IO_NO_INCREMENT);
        return STATUS_ACCESS_VIOLATION;
    }

    Irp->IoStatus.Status = STATUS_SUCCESS;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return STATUS_SUCCESS;
}