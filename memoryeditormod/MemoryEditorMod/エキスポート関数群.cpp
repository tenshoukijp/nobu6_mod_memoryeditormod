#include "�J�X�^���쓮�֐�.h"
#include <map>
#include <time.h>
#include "Menu.h"
#include "ModMode.h."

#include "ProcessHandle.h"

using namespace std;

// �V�ċL�̃E�B���h�E�n���h��
HWND tenshouWND=NULL;

// TSMod.dll�̃n���h��
HMODULE hModuleTSMod = NULL;



void WINAPI meOnInitialize(HANDLE hCallDLLHandle) {
	// �E�B���h�E�n���h�����m�ۂ��Ă����B�t�H�A�O�����h�Ȃǂ̏����g�����Ƃ�����B
	tenshouWND = ::GetCurrentWindowHandle();
	if ( !tenshouWND ) { tenshouWND = FindWindow("Tenshouki95", NULL); }

	// TSMod����Ă΂ꂽ���A������Ă΂ꂽ���̔���
	CheckModMode(hCallDLLHandle);

	AddMemoryEditorMenu();

	�J�X�^���쓮�֐�.On_�N����();
}

void WINAPI meOnMainGameStart() {


	�J�X�^���쓮�֐�.On_���C���Q�[���J�n();
}

void WINAPI meOnFinalize() {
	�J�X�^���쓮�֐�.On_�I����();
}


void WINAPI meOnApplicationSelectMenuItem(int �I�����j���[�ԍ�) {
	�J�X�^���쓮�֐�.On_�A�v���P�[�V�������j���[�I����(�I�����j���[�ԍ�);
}
