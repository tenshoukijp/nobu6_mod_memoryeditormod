#include <windows.h>
#include <string>

#include "�J�X�^���쓮�֐�.h"

#include "ModMode.h"
#include "Menu.h"

using namespace std;

// �O���[�o���B���j���[�̃n���h���B
static HMENU hMenu;

extern HWND tenshouWND; // �V�ċL�̃E�B���h�E�n���h��


// ���j���[�A�C�e���̒ǉ�
// menuname ���j���[�A�C�e���̕�����B"---"���ƃZ�p���[�^�ƂȂ�B
BOOL AddMenuItem(string menuname, int position, int wID) {

	MENUITEMINFO info;

	// �쐬�������j���[���ڂ�ǉ�����
	ZeroMemory( &info, sizeof(info) );
	info.cbSize = sizeof( info );

	// ID�ԍ��̎w�肪�����ꍇ
	if ( wID == -1 ) {
		info.fMask = MIIM_TYPE;
		// ID�ԍ��̎w�肪����ꍇ
	} else {
		info.fMask = MIIM_TYPE | MIIM_ID;
		info.wID = wID;
	}
	if ( menuname == "---" ) {
		info.fType = MFT_SEPARATOR;
	} else {
		info.fType = MFT_STRING;
	}
	info.dwTypeData =(LPSTR)menuname.c_str();
	BOOL success = InsertMenuItem( hMenu, position, FALSE, &info );
	DrawMenuBar( tenshouWND );

	return success;
}



void AddMemoryEditorMenu() {

	// ------------------------------ ���j���[�n���h���m�ۂƁA���j���[�ǉ�
	hMenu = GetMenu(tenshouWND);
	if ( iCallDLLMODE == kModePluginMod ) {
		AddMenuItem( "�������G�f�B�^", RESOURCE_MENU_ID_SPECIAL_EFFECTS_OF_SCREEN_DRAWING, RESOURCE_MENU_ID_MEMORY_EDITOR_MOD );
	}
}



