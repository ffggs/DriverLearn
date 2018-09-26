#pragma once

#include <fltkernel.h>
#include <wdm.h>

#ifdef __cplusplus
extern "C" {
#endif

	//DRIVER_INITIALIZE DriverEntry;
	NTSTATUS DriverEntry(
		_In_ PDRIVER_OBJECT DriverObject,
		_In_ PUNICODE_STRING RegistryPath
		);

	NTSTATUS DriverTestInstanceSetup(
		_In_ PCFLT_RELATED_OBJECTS FltObjects,
		_In_ FLT_INSTANCE_SETUP_FLAGS Flags,
		_In_ DEVICE_TYPE VolumeDeviceType,
		_In_ FLT_FILESYSTEM_TYPE VolumeFilesystemType
		);

	VOID DriverTestInstanceTeardownStart(
		_In_ PCFLT_RELATED_OBJECTS FltObjects,
		_In_ FLT_INSTANCE_TEARDOWN_FLAGS Flags
		);

	VOID DriverTestInstanceTeardownComplete(
		_In_ PCFLT_RELATED_OBJECTS FltObjects,
		_In_ FLT_INSTANCE_TEARDOWN_FLAGS Flags
		);

	NTSTATUS DriverTestUnload(
		_In_ FLT_FILTER_UNLOAD_FLAGS Flags
		);

	NTSTATUS DriverTestInstanceQueryTeardown(
		_In_ PCFLT_RELATED_OBJECTS FltObjects,
		_In_ FLT_INSTANCE_QUERY_TEARDOWN_FLAGS Flags
		);

	FLT_PREOP_CALLBACK_STATUS DriverTestPreOperation(
		_Inout_ PFLT_CALLBACK_DATA Data,
		_In_ PCFLT_RELATED_OBJECTS FltObjects,
		_Flt_CompletionContext_Outptr_ PVOID *CompletionContext
		);

	VOID DriverTestOperationStatusCallback(
		_In_ PCFLT_RELATED_OBJECTS FltObjects,
		_In_ PFLT_IO_PARAMETER_BLOCK ParameterSnapshot,
		_In_ NTSTATUS OperationStatus,
		_In_ PVOID RequesterContext
		);

	FLT_POSTOP_CALLBACK_STATUS DriverTestPostOperation(
		_Inout_ PFLT_CALLBACK_DATA Data,
		_In_ PCFLT_RELATED_OBJECTS FltObjects,
		_In_opt_ PVOID CompletionContext,
		_In_ FLT_POST_OPERATION_FLAGS Flags
		);

	FLT_PREOP_CALLBACK_STATUS DriverTestPreOperationNoPostOperation(
		_Inout_ PFLT_CALLBACK_DATA Data,
		_In_ PCFLT_RELATED_OBJECTS FltObjects,
		_Flt_CompletionContext_Outptr_ PVOID *CompletionContext
		);

	BOOLEAN DriverTestDoRequestOperationStatus(
		_In_ PFLT_CALLBACK_DATA Data
		);

#ifdef __cplusplus
}
#endif