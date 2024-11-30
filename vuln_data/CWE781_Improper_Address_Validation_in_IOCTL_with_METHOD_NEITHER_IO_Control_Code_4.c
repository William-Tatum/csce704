#include <Windows.h>
#include <winioctl.h>

#define IOCTL_MY_OPERATION CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

NTSTATUS MyIoctlHandler(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    PIO_STACK_LOCATION irpSp;
    PVOID inputBuffer, outputBuffer;
    ULONG_PTR inputBufferLength, outputBufferLength;
    NTSTATUS status = STATUS_SUCCESS;

    irpSp = IoGetCurrentIrpStackLocation(Irp);
    inputBuffer = irpSp->Parameters.DeviceIoControl.Type3InputBuffer;
    outputBuffer = Irp->UserBuffer;
    inputBufferLength = irpSp->Parameters.DeviceIoControl.InputBufferLength;
    outputBufferLength = irpSp->Parameters.DeviceIoControl.OutputBufferLength;

    if (!inputBuffer || inputBufferLength < sizeof(ULONG)) {
        status = STATUS_INVALID_PARAMETER;
        goto End;
    }

    __try {
        ProbeForRead(inputBuffer, inputBufferLength, sizeof(UCHAR));
        ProbeForWrite(outputBuffer, outputBufferLength, sizeof(UCHAR));
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        status = GetExceptionCode();
        goto End;
    }

    // Perform operation with validated addresses here

End:
    Irp->IoStatus.Status = status;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return status;
}