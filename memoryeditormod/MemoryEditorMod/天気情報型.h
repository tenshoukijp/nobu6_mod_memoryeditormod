/*
 * �V�C��^
 */
#pragma once
#pragma pack(1)

#include <windows.h>


struct �V�C���^ {
	byte _�V�C;				// Get_�V�C�œ��邱��
};

// �V�C���𓾂�s������t 0:���� 1:�܂� 2:�J 3:��
namespace �V�C {
	enum { ����=0, �܂�=1, �J=2, ��=3 };
};


namespace �֐� {
	// �V�C���𓾂�s������t 0:���� 1:�܂� 2:�J 3:��
	byte Get_�V�C();

	// ���̃^�[���̓V�C��\�񂷂�B�f�t�H���g�ł͂Q�^�[���p������B
	void Set_�V�C�\��(int i�V�C, int �p���^�[��=2);
}