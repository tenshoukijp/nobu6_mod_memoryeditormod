#include <cassert>
#include "�Q�[���f�[�^�\��.h"


namespace �֐� {


// ���ʖ����擾����
string Get_���ʖ�( int ���ʔԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	if ( 0 <= ���ʔԍ��y�z��p�z && ���ʔԍ��y�z��p�z < �ő吔::���ʏ��::�z�� ) { 
		return string( p���ʏ��[���ʔԍ��y�z��p�z]._���ʖ� );
	} else {
		�f�o�b�O�o��("���ʔԍ��y�z��p�z�͔͈͊O");
		return string("");
	}
}


// ���ʖ���ݒ肷��
void   Set_���ʖ�( int ���ʔԍ��y�z��p�z, string ���ʖ� ) {

	// �͈̓`�F�b�N
	if ( 0 <= ���ʔԍ��y�z��p�z && ���ʔԍ��y�z��p�z < �ő吔::���ʏ��::�z�� ) { 
		strncpy_s( p���ʏ��[���ʔԍ��y�z��p�z]._���ʖ�, ���ʖ�.c_str(), 12 );
		p���ʏ��[���ʔԍ��y�z��p�z]._���ʖ�[12] = NULL;
	} else {
		�f�o�b�O�o��("���ʔԍ��y�z��p�z�͔͈͊O");
	}
}




}