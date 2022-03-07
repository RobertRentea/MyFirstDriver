// ClientCode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <stdio.h>
#include "..\MyFirstDriver\MyFirstDriver.h"

int Error(const char* message) {
	printf("%s (error=%d)\n", message, GetLastError());
	return 1;
}


int main(int argc, const char* argv[])
{
	printf("start\n");
	HANDLE hDevice = CreateFile(L"\\\\.\\MyFirstDriver", GENERIC_WRITE,
		FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, 0, nullptr);
	if (hDevice == INVALID_HANDLE_VALUE) {
		return Error("Failed to open device");
	}
	int data = 1;

	DWORD returned;
	BOOL success = DeviceIoControl(hDevice,
		IOCTL_FIRST_CODE, // control code
		&data, sizeof(data), // input buffer and length
		nullptr, 0, // output buffer and length
		&returned, nullptr);
	if (success)
		printf("Called the first code!\n");
	else
		Error("Failed!");
	
	CloseHandle(hDevice);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
