#include <cassert>
#include "�Q�[���f�[�^�\��.h"


namespace �֐� {



// �ƕ󖼂��擾����
string Get_�ƕ�( int �ƕ�ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if( 0 <= �ƕ�ԍ��y�z��p�z && �ƕ�ԍ��y�z��p�z < �ő吔::�ƕ���::�z�� ) { 

		return string( p�ƕ���[�ƕ�ԍ��y�z��p�z]._�ƕ� );
	} else {
		�f�o�b�O�o��("�w��̉ƕ�ԍ��y�z��p�z�͔͈͊O");
		return string( "" );
	}
}


// �ƕ󖼂�ݒ肷��
void   Set_�ƕ�( int �ƕ�ԍ��y�z��p�z, string �ƕ� ) {

	// �͈̓`�F�b�N
	if( 0 <= �ƕ�ԍ��y�z��p�z && �ƕ�ԍ��y�z��p�z < �ő吔::�ƕ���::�z�� ) { 

		strncpy_s( p�ƕ���[�ƕ�ԍ��y�z��p�z]._�ƕ�, �ƕ�.c_str(), 12 );
		p�ƕ���[�ƕ�ԍ��y�z��p�z]._�ƕ�[12] = NULL;
	} else {
		�f�o�b�O�o��("�w��̉ƕ�ԍ��y�z��p�z�͔͈͊O");
	}
}




}