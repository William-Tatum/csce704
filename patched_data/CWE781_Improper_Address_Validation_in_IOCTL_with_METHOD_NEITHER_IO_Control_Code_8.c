#include <ntddk.h>

#define IOCTL_METHOD_NEITHER CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

NTSTATUS SafeProbeUserAddress(PVOID buffer, SIZE_T size) {
    if (buffer == NULL || size == 0)
        return STATUS_INVALID_PARAMETER;
    __try {
        ProbeForRead(buffer, size, sizeof(UCHAR));
        ProbeForWrite(buffer, size, sizeof(UCHAR));
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return STATUS_ACCESS_VIOLATION;
    }
    return STATUS_SUCCESS;
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

            status = SafeProbeUserAddress(inputBuffer, inputBufferLength);
            if (!NT_SUCCESS(status))
                break;

            status = SafeProbeUserAddress(outputBuffer, outputBufferLength);
            if (!NT_SUCCESS(status))
                break;

            // Process the buffers
            __try {
                memset(outputBuffer, 0, outputBufferLength);
            } __except (EXCEPTION_EXECUTE_HANDLER) {
                status = STATUS_ACCESS_VIOLATION;
            }
            break;

        default:
            return UnsupportedIoctlHandler(DeviceObject, Irp);
    }

    Irp->IoStatus.Status = status;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return status;
}