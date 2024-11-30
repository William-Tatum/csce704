#include <ntddk.h>

#define IOCTL_EXAMPLE_REQUEST CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

NTSTATUS IrpDeviceControlHandler(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    PIO_STACK_LOCATION stack = IoGetCurrentIrpStackLocation(Irp);
    NTSTATUS status = STATUS_SUCCESS;

    if (stack->Parameters.DeviceIoControl.IoControlCode == IOCTL_EXAMPLE_REQUEST) {
        PVOID inputBuffer = stack->Parameters.DeviceIoControl.Type3InputBuffer;
        ULONG inputBufferLength = stack->Parameters.DeviceIoControl.InputBufferLength;
        PVOID outputBuffer = Irp->UserBuffer;
        ULONG outputBufferLength = stack->Parameters.DeviceIoControl.OutputBufferLength;

        if (inputBuffer && outputBuffer) {
            try {
                ProbeForRead(inputBuffer, inputBufferLength, sizeof(UCHAR));
                ProbeForWrite(outputBuffer, outputBufferLength, sizeof(UCHAR));

                // Example operation that could be performed on validated buffers
                RtlCopyMemory(outputBuffer, inputBuffer, min(inputBufferLength, outputBufferLength));
            }
            except(EXCEPTION_EXECUTE_HANDLER) {
                status = GetExceptionCode();
            }
        } else {
            status = STATUS_INVALID_PARAMETER;
        }
    } else {
        status = STATUS_INVALID_DEVICE_REQUEST;
    }

    Irp->IoStatus.Status = status;
    Irp->IoStatus.Information = (status == STATUS_SUCCESS) ? outputBufferLength : 0;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);

    return status;
}

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = IrpDeviceControlHandler;

    return STATUS_SUCCESS;
}