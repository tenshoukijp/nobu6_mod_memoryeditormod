/*
 * ���������^
 */
#pragma once
#pragma pack(1)

#include <windows.h>


typedef char** �V�i���I�������^��;
typedef char *_�V�i���I�������^[3]; 
#define �V�i���I�������^ static _�V�i���I�������^

typedef char** �V�i���I���j���[�^��;
typedef char *_�V�i���I���j���[�^[6]; 
#define �V�i���I���j���[�^ static _�V�i���I���j���[�^


namespace �֐� {
	// �V�i���I�̃^�C�g�����𓾂�B
	// �V�i���I�ԍ��́A�P�`�U�̎w��̂��ƁB
	string Get_�V�i���I��(int �V�i���I�ԍ�);

	// ���ݑI������Ă���(���邢�̓v���C����)�V�i���I�ԍ��𓾂�B
	// �ǂ̃V�i���I�ɂ������Ȃ��ꍇ�A-1���Ԃ��Ă���B
	int Get_���݂̃V�i���I�ԍ�();
}