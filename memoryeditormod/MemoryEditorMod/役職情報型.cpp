#include <cassert>
#include "�Q�[���f�[�^�\��.h"


namespace �֐� {


// �喼ID���琳�K�����ꂽ(0�`7�ւƐU��Ȃ����ꂽ)��EID�𓾂�
int Get_�喼��E(int �喼�ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �喼�ԍ��y�z��p�z && �喼�ԍ��y�z��p�z < �ő吔::�������::�z�� ) { 

		switch ( p�喼���[�喼�ԍ��y�z��p�z]._��E) {
			case 0x01:
				return ��E::���Α叫�R;
			case 0x02:
				return ��E::�Ǘ�;
			case 0x04:
				return ��E::�֓��Ǘ�;
			case 0x08 :
				return ��E::���B�T��;
			case 0x10:
				return ��E::�����T��;
			case 0x20:
				return ��E::��B�T��;
			case 0x40:
				return ��E::�H�B�T��;
			default:
				return 0;
		}
	}
	return 0;
}

// �R�cID���琳�K�����ꂽ��EID�𓾂�
int Get_�R�c��E(int �R�c�ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= �R�c�ԍ��y�z��p�z && �R�c�ԍ��y�z��p�z < �ő吔::�R�c���::�z�� ) { 
		return p�R�c���[�R�c�ԍ��y�z��p�z]._��E;
	}
	�f�o�b�O�o��("�w��̌R�c�ԍ��y�z��p�z�͔͈͊O");
	return -1;
}



}