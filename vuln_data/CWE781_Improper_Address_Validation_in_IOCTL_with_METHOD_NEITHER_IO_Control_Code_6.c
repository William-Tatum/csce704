#include <windows.h>
#include <winioctl.h>
#include <stdio.h>

#define IOCTL_METHOD_NEITHER CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

VOID UntrustedIoctlHandler(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    PIO_STACK_LOCATION irpSp = IoGetCurrentIrpStackLocation(Irp);
    PVOID inputBuffer = irpSp->Parameters.DeviceIoControl.Type3InputBuffer;
    ULONG inputBufferLength = irpSp->Parameters.DeviceIoControl.InputBufferLength;
    PVOID outputBuffer = Irp->UserBuffer;
    ULONG outputBufferLength = irpSp->Parameters.DeviceIoControl.OutputBufferLength;
    NTSTATUS status = STATUS_SUCCESS;
    
    try {
        if (inputBuffer && inputBufferLength > 0 && inputBuffer < MmUserProbeAddress) {
            ProbeForRead(inputBuffer, inputBufferLength, sizeof(UCHAR));
            ProbeForRead(outputBuffer, outputBufferLength, sizeof(UCHAR));

            UCHAR* inputData = (UCHAR*)inputBuffer;
            UCHAR* outputData = (UCHAR*)outputBuffer;
            for (ULONG i = 0; i < inputBufferLength && i < outputBufferLength; i++) {
                outputData[i] = inputData[i];
            }
        } else {
            status = STATUS_INVALID_USER_BUFFER;
        }
    } except(EXCEPTION_EXECUTE_HANDLER) {
        status = GetExceptionCode();
    }
    
    Irp->IoStatus.Status = status;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
}

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = UntrustedIoctlHandler;
    return STATUS_SUCCESS;
}