#include "�J�X�^���쓮�֐�.h"
#include "MemoryEditorMod.h"
#include "Menu.h"

extern void _�����֐��o�^();

void �J�X�^��::On_�N����() {
	if (iCallDLLMODE == kModeTSMod) {
		_�����֐��o�^();
	}
}

void �J�X�^��::On_���C���Q�[���J�n() {

}

void �J�X�^��::On_�I����() {
	// gcnew ���Ă���΁A(�E�B���h�E�����)�j��
	if ( MemoryEditorForm::meForm ) {
		MemoryEditorForm::meForm->Close();
	}
}

void �J�X�^��::On_�A�v���P�[�V�������j���[�I����(int ���j���[�ԍ�) {
	if ( ���j���[�ԍ� == RESOURCE_MENU_ID_MEMORY_EDITOR_MOD ) {

		// �܂�gcnew �������Ƃ��Ȃ���΁Agcnew
		if ( MemoryEditorForm::meForm == nullptr || MemoryEditorForm::meForm->IsDisposed ) {
			MemoryEditorForm::meForm = gcnew MemoryEditorForm();
			MemoryEditorForm::meForm->Show();
		}
	}
}