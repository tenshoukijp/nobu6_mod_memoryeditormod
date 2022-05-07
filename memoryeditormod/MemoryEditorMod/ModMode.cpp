#include <windows.h>

#include "ModMode.h"


int iCallDLLMODE = 0;

extern HMODULE hModuleTSMod;

void CheckModMode(HANDLE hCallDLLHandle) {
	// ---------------------------- TSMod, PluginMod どちらが呼んだ？
	// パスを受け取るためのバッファ 
    char szFullDLLName[512] = ""; 
  
    // DLLハンドル(実際にはメモリ上のアドレス)⇒そやつのフルネームを得る。 
    GetModuleFileNameA((HMODULE)hCallDLLHandle, szFullDLLName, sizeof(szFullDLLName)-1);

	_strlwr(szFullDLLName);
	if ( strstr(szFullDLLName, "tsmod.dll") ) {
		iCallDLLMODE = kModeTSMod;
		hModuleTSMod = (HMODULE)hCallDLLHandle;
	} else {
		iCallDLLMODE = kModePluginMod;
	}
}
