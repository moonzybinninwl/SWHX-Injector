# SWHX-Injector
This is a basic way to Inject, it uses LoadLibraryA and loads your DLL into Roblox.
You need a cert on your DLL, otherwise this will **not** work.

You also need this export in your EntryPoint file in your module/DLL, and set it to the callback used in the injector or vise versa.
```cpp
extern "C" __declspec(dllexport) LRESULT CALLBACK ntqueryinformationthread(int code, WPARAM wParam, LPARAM lParam) { return CallNextHookEx(NULL, code, wParam, lParam); }
```
