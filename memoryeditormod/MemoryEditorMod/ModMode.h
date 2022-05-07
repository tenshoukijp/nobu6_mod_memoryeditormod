#pragma once

#include <windows.h>

enum { kModeTSMod = 1, kModePluginMod = 2 };

extern int iCallDLLMODE;

void CheckModMode(HANDLE hCallDLLHandle);
