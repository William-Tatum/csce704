#include <ntddk.h>

#define IOCTL_METHOD_NEITHER CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

NTSTATUS ValidateUserBuffer(PVOID buffer, SIZE_T size) {
    if (buffer == NULL || size == 0)
        return STATUS_INVALID_PARAMETER;
    if (MmIsAddressValid(buffer) && MmIsAddressValid((PVOID)((PUCHAR)buffer + size - 1)))
        return STATUS_SUCCESS;
    return STATUS_ACCESS_VIOLATION;
}

NTSTATUS UnsupportedIoctlHandler(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    UNREFERENCED_PARAMETER(DeviceObject);
    Irp->IoStatus.Status = STATUS_INVALID_DEVICE_REQUEST;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return STATUS_INVALID_DEVICE_REQUEST;
}

NTSTATUS IoControlDispatch(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    PIO_STACK_LOCATION irpSp;
    PVOID inputBuffer, outputBuffer;
    SIZE_T inputBufferLength, outputBufferLength;
    NTSTATUS status = STATUS_SUCCESS;

    irpSp = IoGetCurrentIrpStackLocation(Irp);

    switch (irpSp->Parameters.DeviceIoControl.IoControlCode) {
        case IOCTL_METHOD_NEITHER:
            inputBuffer = irpSp->Parameters.DeviceIoControl.Type3InputBuffer;
            outputBuffer = Irp->UserBuffer;
            inputBufferLength = irpSp->Parameters.DeviceIoControl.InputBufferLength;
            outputBufferLength = irpSp->Parameters.DeviceIoControl.OutputBufferLength;

            status = ValidateUserBuffer(inputBuffer, inputBufferLength);
            if (!NT_SUCCESS(status))
                break;

            status = ValidateUserBuffer(outputBuffer, outputBufferLength);
            if (!NT_SUCCESS(status))
                break;

            // Process the buffers
            memset(outputBuffer, 0, outputBufferLength);
            break;

        default:
            return UnsupportedIoctlHandler(DeviceObject, Irp);
    }

    Irp->IoStatus.Status = status;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return status;
}