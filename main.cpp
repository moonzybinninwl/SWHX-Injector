#include <iostream>
#include <Windows.h>

int main() {
	SetConsoleTitleA("Injection");
	HWND RobloxWindow = FindWindowA(nullptr, "Roblox");
	if (!RobloxWindow)
	{
		std::cerr << "[!] Roblox not found! Open Roblox and run the Injector again." << std::endl;
		Sleep(2500);
	}
	DWORD RobloxPID, RobloxThreadTID = GetWindowThreadProcessId(RobloxWindow, &RobloxPID);
	std::cerr << "[*] Roblox PID: " << RobloxPID << std::endl;
	std::cerr << "[*] Roblox Thread ID: " << RobloxThreadTID << std::endl;
	Sleep(1000);
	HMODULE DLL = LoadLibraryExA("Module.dll", nullptr, DONT_RESOLVE_DLL_REFERENCES);
	std::cerr << "[*] Loading Module: " << DLL << std::endl;
	HOOKPROC CallBack = reinterpret_cast<HOOKPROC>(GetProcAddress(DLL, "ntqueryinformationthread")); // your DLL export name
	std::cerr << "[*] Loading Callback Hook" << std::endl;
	Sleep(1000);
	HHOOK HookHandle = SetWindowsHookEx(WH_GETMESSAGE, CallBack, DLL, RobloxThreadTID);
	PostThreadMessage(RobloxThreadTID, WM_NULL, NULL, NULL);
	std::cerr << "[+] Succesfully Injected!" << std::endl;
	Sleep(3000);
}
