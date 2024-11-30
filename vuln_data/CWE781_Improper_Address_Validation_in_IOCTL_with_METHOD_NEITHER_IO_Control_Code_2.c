#include <windows.h>

#define IOCTL_EXAMPLE_METHOD_NEITHER CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

NTSTATUS ExampleIoctlHandler(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    PIO_STACK_LOCATION irpSp = IoGetCurrentIrpStackLocation(Irp);
    void* inputBuffer = irpSp->Parameters.DeviceIoControl.Type3InputBuffer;
    ULONG inputBufferLength = irpSp->Parameters.DeviceIoControl.InputBufferLength;
    void* outputBuffer = Irp->UserBuffer;
    ULONG outputBufferLength = irpSp->Parameters.DeviceIoControl.OutputBufferLength;
    ULONG_PTR address_range_start = 0x1000;
    ULONG_PTR address_range_end = 0xFFFF;
    NTSTATUS status = STATUS_INVALID_PARAMETER;

    if ((ULONG_PTR)inputBuffer < address_range_start || (ULONG_PTR)inputBuffer + inputBufferLength > address_range_end) {
        return STATUS_ACCESS_DENIED;
    }
    
    if ((ULONG_PTR)outputBuffer < address_range_start || (ULONG_PTR)outputBuffer + outputBufferLength > address_range_end) {
        return STATUS_ACCESS_DENIED;
    }

    // Example processing
    RtlCopyMemory(outputBuffer, inputBuffer, min(inputBufferLength, outputBufferLength));
    Irp->IoStatus.Information = min(inputBufferLength, outputBufferLength);
    status = STATUS_SUCCESS;
    
    Irp->IoStatus.Status = status;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return status;
}