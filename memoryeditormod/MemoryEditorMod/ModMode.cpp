#include <windows.h>

#include "ModMode.h"


int iCallDLLMODE = 0;

extern HMODULE hModuleTSMod;

void CheckModMode(HANDLE hCallDLLHandle) {
	// ---------------------------- TSMod, PluginMod �ǂ��炪�Ă񂾁H
	// �p�X���󂯎�邽�߂̃o�b�t�@ 
    char szFullDLLName[512] = ""; 
  
    // DLL�n���h��(���ۂɂ̓�������̃A�h���X)�˂���̃t���l�[���𓾂�B 
    GetModuleFileNameA((HMODULE)hCallDLLHandle, szFullDLLName, sizeof(szFullDLLName)-1);

	_strlwr(szFullDLLName);
	if ( strstr(szFullDLLName, "tsmod.dll") ) {
		iCallDLLMODE = kModeTSMod;
		hModuleTSMod = (HMODULE)hCallDLLHandle;
	} else {
		iCallDLLMODE = kModePluginMod;
	}
}
