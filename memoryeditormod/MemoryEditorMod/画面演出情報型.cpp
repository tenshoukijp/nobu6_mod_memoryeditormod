#include <cassert>
#include "�Q�[���f�[�^�\��.h"





	//---------------------�t�F�C�h�A�E�g-------------------------
	int _pCallFromFuncFadeOut = 0x4232EE; // ���XTENSHOU.EXE���ɂ�����CALL��

namespace �֐� {
	void �t�F�C�h�A�E�g() {
		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		__asm {
			// �����Ȃ�
			call _pCallFromFuncFadeOut
			// �����Ȃ��Ȃ̂ŃX�^�b�N�̂��ꍞ�݂͖���
		}

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}
	}
}
	//---------------------�t�F�C�h�C��-------------------------
	int _pCallFromFuncFadeIn = 0x4232D4; // ���XTENSHOU.EXE���ɂ�����CALL��
	
namespace �֐� {
	void �t�F�C�h�C��() {
		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		__asm {
			// �����Ȃ�
			call _pCallFromFuncFadeIn
			// �����Ȃ��Ȃ̂ŃX�^�b�N�̂��ꍞ�݂͖���
		}

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}
	}
}






	int _pCallFromFuncMoveCamera = 0x48728F; // ���XTENSHOU.EXE���ɂ�����CALL��

	WORD _iCastleIdInFuncMoveCamera = 1L;

	// ���C����ʂł̃J�����ړ�
	void _FuncMoveCameraAsm() {
		__asm {
			push ecx  // ecx �̒l��ۑ�

			// ����1�`3 2�o�C�g����
			mov ecx, 0x4DC218  // (���g��2710=10000���B�Ȃɂ��K�v�炵��);
			push 1
			push 1
			push dword ptr _iCastleIdInFuncMoveCamera;
			call _pCallFromFuncMoveCamera

			pop ecx  // ecx�̒l�����ւƖ߂�
		}
	}


namespace �֐� {
	// �J�������w��̏�ID�ւƈړ�
	void �J�����ړ�(int ��ԍ��y�z��p�z) {

		// �͈̓`�F�b�N
		assert ( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� );

		if ( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� ) {

			// �֐��p�̂�́A��ԍ����̂��̂Ȃ̂ŁA1��������
			_iCastleIdInFuncMoveCamera = (WORD)��ԍ��y�z��p�z+1;
		
			__asm {
				push eax
				push ebx
				push ecx
				push edx
				push esp
				push esi
				push edi
			}

			// TENSHOU.EXE���̊֐��Ăяo��
			_FuncMoveCameraAsm();

			__asm {
				pop edi
				pop esi
				pop esp
				pop edx
				pop ecx
				pop ebx
				pop eax
			}
		}
	}

}





