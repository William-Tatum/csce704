#include <ntddk.h>

#define IOCTL_METHOD_NEITHER CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

NTSTATUS UnsupportedIoctlHandler(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    PIO_STACK_LOCATION ioStackLocation = IoGetCurrentIrpStackLocation(Irp);
    PVOID inputBuffer;
    PVOID outputBuffer;
    ULONG inputBufferLength = ioStackLocation->Parameters.DeviceIoControl.InputBufferLength;
    ULONG outputBufferLength = ioStackLocation->Parameters.DeviceIoControl.OutputBufferLength;
    NTSTATUS status = STATUS_SUCCESS;

    if (Irp->MdlAddress) {
        inputBuffer = MmGetSystemAddressForMdlSafe(Irp->MdlAddress, NormalPagePriority);
        outputBuffer = MmGetSystemAddressForMdlSafe(Irp->MdlAddress, NormalPagePriority);
    } else {
        inputBuffer = ioStackLocation->Parameters.DeviceIoControl.Type3InputBuffer;
        outputBuffer = Irp->UserBuffer;
    }

    if ((inputBuffer && MmIsAddressValid(inputBuffer)) && (outputBuffer && MmIsAddressValid(outputBuffer))) {
        __try {
            RtlCopyMemory(outputBuffer, inputBuffer, min(inputBufferLength, outputBufferLength));
        } __except (EXCEPTION_EXECUTE_HANDLER) {
            status = GetExceptionCode();
        }
    } else {
        status = STATUS_INVALID_ADDRESS;
    }

    Irp->IoStatus.Status = status;
    Irp->IoStatus.Information = NT_SUCCESS(status) ? min(inputBufferLength, outputBufferLength) : 0;
    IoCompleteRequest(Irp, IO_NO_INCREMENT);
    return status;
}

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = UnsupportedIoctlHandler;

    return STATUS_SUCCESS;
}