/*
 * ���o���Ȃǂɂ�����A���́E�q�́E��R�ҁv��ID
 */
#pragma once
#pragma pack(1)

#include <windows.h>
#include <string>
#include <vector>
#include <map>

using namespace std;


typedef vector<string> �����񃊃X�g�^;

// --------------------------------------���b�Z�[�W�֘A���
struct ���b�Z�[�W�֘A���^ {
	WORD ��P�l�́y�����ԍ��z;	// ������ID(�ʏ핐��ID)
	WORD ��Q�l�́y�����ԍ��z;	// �����ID(�ʏ핐��ID�B�C�x���g��⏤�l���531,�_�����532�ƂȂ�)
	WORD ��R�l�́y�����ԍ��z;	// ��R�҂�ID(�ʏ�1stPerson��2ndPerson�̉�b�̒��ŏo�Ă���l��ID);

	// -----------�ȉ��\���B�����̊g���ɑ΂���݊����m�ۂ̂��߁B
	DWORD _undef1;
	DWORD _undef2;
	DWORD _undef3;
	DWORD _undef4;
	DWORD _undef5;
};





// --------------------------------------�����񔻒�̂��߂̐��K�\���֐�

namespace �֐� {

	// �Ώە�����ɁA���������񂪊܂܂�Ă��邩�ǂ����̔���
	int Is_������}�b�`( string �Ώە�����, string ����������);


}