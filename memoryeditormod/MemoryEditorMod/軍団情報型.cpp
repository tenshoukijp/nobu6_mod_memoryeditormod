#include <cassert>
#include <algorithm>
#include "�Q�[���f�[�^�\��.h"






namespace �֐� {


// �R�c�ɏ������镺���𓾂�
int Get_�R�c����(int �R�c�ԍ��y�z��p�z) {
	int i���� = 0;
	for ( int i=0; i<�ő吔::�������::�z��; i++) {
		if ( p�������[i].�����R�c�y�R�c�ԍ��z-1 == �R�c�ԍ��y�z��p�z ) {
			if ( p�����ːЏ��[i].��� <= ���::���� ) { // �喼, �R�c��, ���� �ŃJ�E���g
				i���� += p�������[i].����;
			}
		}
	}
	return i����;
}

// �S�Ă̗L���ȌR�c���X�g�𓾂�
�ԍ����X�g�^ Get_�R�c�ԍ����X�g�y�z��p�z() {
	�ԍ����X�g�^ list;

	// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
	for ( int i�R�cID=0; i�R�cID < �ő吔::�R�c���::�z��; i�R�cID++ ) {
		if ( p�R�c���[i�R�cID].�R�c���y�����ԍ��z !=  0xFFFF ) {
			list.push_back(i�R�cID);
		}
	}
	
	return list;
}

// ����̑喼�����̌R�c���X�g�𓾂�
�ԍ����X�g�^ Get_�喼�����R�c�ԍ����X�g�y�z��p�z(int �喼�ԍ��y�z��p�z) {
	�ԍ����X�g�^ list;

	if ( 0 <= �喼�ԍ��y�z��p�z && �喼�ԍ��y�z��p�z < �ő吔::�喼���::�z�� ) {

		// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
		for ( int i�R�cID=0; i�R�cID < �ő吔::�R�c���::�z��; i�R�cID++ ) {
			if ( p�R�c���[i�R�cID].�����喼�y�喼�ԍ��z-1 ==  �喼�ԍ��y�z��p�z) {
				list.push_back(i�R�cID);
			}
		}
	}
	
	return list;
}


// �Ƃ���喼�z���̌R�c���ɂ���R�c�����ԍ��̃��X�g�𓾂�B
// (�ԍ��Ɛ��𗼕��𓾂�B����)
�ԍ����X�g�^ Get_�R�c�����ԍ����X�g(int �喼�ԍ��y�z��p�z) {

	�ԍ����X�g�^ list;

	if ( 0 <= �喼�ԍ��y�z��p�z && �喼�ԍ��y�z��p�z < �ő吔::�喼���::�z�� ) {

		// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
		for ( int i�R�cID=0; i�R�cID < �ő吔::�R�c���::�z��; i�R�cID++ ) {
			if ( p�R�c���[i�R�cID].�����喼�y�喼�ԍ��z-1 ==  �喼�ԍ��y�z��p�z) {
				list.push_back(p�R�c���[i�R�cID].�R�c�����ԍ�);
			}
		}
	}
	
	std::sort(list.begin(),list.end());//�����\�[�g

	return list;
}

// �Ƃ���喼�z���̌R�c���ɂ���R�c�u���v�����ԍ��̃��X�g�𓾂�B
// (�ԍ��Ɛ��𗼕��𓾂�B����)
�ԍ����X�g�^ Get_�R�c�������ԍ����X�g(int �喼�ԍ��y�z��p�z) {

	// ���蓖�Ă��Ă���̂ɁA�P������
	int �����ԍ��z��[8] = {0,0,0,0,0,0,0,0};

	if ( 0 <= �喼�ԍ��y�z��p�z && �喼�ԍ��y�z��p�z < �ő吔::�喼���::�z�� ) {

		// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
		for ( int i�R�cID=0; i�R�cID < �ő吔::�R�c���::�z��; i�R�cID++ ) {
			if ( p�R�c���[i�R�cID].�����喼�y�喼�ԍ��z-1 ==  �喼�ԍ��y�z��p�z) {
				int g =  p�R�c���[i�R�cID].�R�c�����ԍ�;
				if ( 1 <= g && g <= 8 ) {
					// ���蓖�Ă��Ă���̂ɁA�P������
					�����ԍ��z��[g-1] = 1;
				}
			}
		}
	}

	�ԍ����X�g�^ ���������X�g;
	for ( int ix=0; ix<8; ix++ ) {
		if (�����ԍ��z��[ix] == 0) {
			���������X�g.push_back(ix+1);
		}
	}

	std::sort(���������X�g.begin(),���������X�g.end());//�����\�[�g

	return ���������X�g;
}


bool Set_�R�c�����喼(int �R�c�ԍ��y�z��p�z, int �V�����喼�ԍ��y�z��p�z) {

	// �V�喼�������ł͂Ȃ��B
	if ( ! (0 <= �V�����喼�ԍ��y�z��p�z && �V�����喼�ԍ��y�z��p�z < �ő吔::�喼���::�z��) ) {
		return false;
	}

	// �R�c���S�����܂��Ă���Ȃ�΁A
	�ԍ����X�g�^ glist = Get_�R�c�����ԍ����X�g(�V�����喼�ԍ��y�z��p�z);
	if ( glist.size() == 8 ) { // �R�c�͑S�����܂��Ă���
		// �����ł��Ȃ�
		return false;
	}

	int iGundanID = �R�c�ԍ��y�z��p�z;

	if ( 0 <= iGundanID && iGundanID < �ő吔::�R�c���::�z�� ) {

		// �w��̌R�c�����ݏ������Ă���喼�ԍ������߂�
		int iDaimyoID = p�R�c���[iGundanID].�����喼�y�喼�ԍ��z-1;
		// �V������̑喼���A���������Ă���喼�ł���΁A�������邱�Ƃ͂Ȃ��B
		if ( iDaimyoID == �V�����喼�ԍ��y�z��p�z) {
			return true;
		}

		// �R�c���蓖�Ĕԍ����P�Ԃ͑喼���g�B����͌Œ�B���̏ꍇ�A�����������s�Ƃ���B
		if ( p�R�c���[iGundanID].�R�c�����ԍ� == 1 ) {
			return false;
		}

		// ���݁A�V�喼�ɏ������Ă��āA���̌R�c�y�R�c�ԍ��z��0xFFFF�ɂȂ��Ă���R�c���A�Ԃ牺����ׂ������N���X�g�̍Ōゾ�B
		// �Ԃ牺���邱�Ƃ��o���邩�A���O�Ƀ`�F�b�N���Ă����B
		int iLinkEndGundanID = -1;
		for ( int iGID=0; iGID < �ő吔::�R�c���::�z��; iGID++ ) {
			// 
			int iCurDaimyoID = p�R�c���[iGID].�����喼�y�喼�ԍ��z-1;

			// �w��̐V�喼�ɏ������Ă���Ȃ�΁A
			if ( iCurDaimyoID == �V�����喼�ԍ��y�z��p�z) {
				// ���̌R�c�������̂ł���΁A�������ŏI�R�c�ԍ�
				if ( p�R�c���[iGID].���̌R�c�y�R�c�ԍ��z == 0xFFFF ) {
					iLinkEndGundanID = iGID+1;
				}
				
			}

		}

		// ���ꂪ�͈͂ɓ����Ă��Ȃ��Ȃ�΁A�V�喼�̌R�c�����N���X�g�́A��������������Ȃ�����񂪉��Ă���B
		// �����I��
		if ( ! (0 < iLinkEndGundanID && iLinkEndGundanID <= �ő吔::�R�c���::�z�� ) ) {
			return false;
		}

		/* �@���R�c
		      ��
		   ��-��-��-��

		   �Ƃ����̂�

		   ��-��-��

		   �Ƃ���B
		*/

		int iPrevID =  p�R�c���[iGundanID].�O�̌R�c�y�R�c�ԍ��z;
		int iNextID = p�R�c���[iGundanID].���̌R�c�y�R�c�ԍ��z;

		// ������prev�͗L���ȌR�c���B
		if ( 0 < iPrevID && iPrevID <= �ő吔::�R�c���::�z�� ) {

			// �������擪�ł͂Ȃ��R�c�ŁA
			// �P�O�̌R�c�̎��̃����N�悪���R�c�̏ꍇ
			if ( iPrevID != 0xFFFF && p�R�c���[(iPrevID-1)].���̌R�c�y�R�c�ԍ��z == iGundanID+1 ) {
				// ���R�c�ł͂Ȃ��A���̌R�c�ւƌq��������B
				p�R�c���[(iPrevID-1)].���̌R�c�y�R�c�ԍ��z = iNextID;
			}
		}

		// ������next�͗L���ȌR�c���B
		if ( 0 < iNextID && iNextID <= �ő吔::�R�c���::�z�� ) {
			// �P��̌R�c�̑O�̃����N�悪���R�c�̏ꍇ
			if ( iNextID != 0xFFFF && p�R�c���[(iNextID-1)].�O�̌R�c�y�R�c�ԍ��z == iGundanID+1 ) {
				// ���R�c�ł͂Ȃ��A�O�̌R�c�ւƌq��������B
				p�R�c���[(iNextID-1)].�O�̌R�c�y�R�c�ԍ��z = iPrevID;
			}
		}


		/* �@
		     
		   ��-��

		   �Ƃ����̂�

		   ��-��-��

		   �Ƃ���B
		*/



		p�R�c���[iLinkEndGundanID-1].���̌R�c�y�R�c�ԍ��z = iGundanID+1; // �����N���X�g�̍Ō�̌R�c��next�����R�c��

		p�R�c���[iGundanID].�O�̌R�c�y�R�c�ԍ��z = iLinkEndGundanID; // ���R�c�̑O�̌R�c�́A�R�c�̃����N���X�g�̍Ō�̌R�c

		// ���R�c�́A�R�c���X�g�̈�ԍŌ�ɂ������B���R�c��next�͋��Ȃ�
		p�R�c���[iGundanID].���̌R�c�y�R�c�ԍ��z = 0xFFFF; // 

		// ��������������
		{
			p�R�c���[iGundanID].�R�c�����ԍ� = 8; // �����s���ɂȂ��Ă��܂��Ă��邪�����Ƃ������m���ŃZ�[�t�Ȃ��̂����

			�ԍ����X�g�^ milist = Get_�R�c�������ԍ����X�g(�V�����喼�ԍ��y�z��p�z);
			if ( milist.size() > 0 ) {
				p�R�c���[iGundanID].�R�c�����ԍ� = milist[0]; // ��ԍ��̍ŏ��̂��̂���荞��
			}

			p�R�c���[iGundanID].�����喼�y�喼�ԍ��z = �V�����喼�ԍ��y�z��p�z+1;
		}

		for ( int iBushouID=0; iBushouID < �ő吔::�������::�z��; iBushouID++) {
			// �w��̌R�c�ɏ������Ă��镐���́A�S�āA�V�喼�ɏ�����ύX����B
			if ( p�������[iBushouID].�����R�c�y�R�c�ԍ��z== iGundanID+1 ) {
				p�������[iBushouID].�����喼�y�喼�ԍ��z = �V�����喼�ԍ��y�z��p�z+1;
				p�������[iBushouID].�d���N�� = 0; // �m���N�����Z�b�g
				p�������[iBushouID].������喼�y�喼�ԍ��z = 0xFFFF; // �����惊�Z�b�g
				p�������[iBushouID].������� = 0; // ������ԂȂ�
				p�������[iBushouID].�⍦��� = 0; // �⍦�Ȃ�
			}
		}


		return true;

	}

	return false;
}

}

/*
 �R�c�ԍ��������Ƃ��āA�R�t�̕����ԍ��𓾂�
*/
int pCallFromFuncGetGunshiBushouID = 0x454BE9; //

int iReturnOfBushouIDGetGunshiBushou = 0xFFFF;
int iSigOfGundanIDGetGunshiBushou = 0xFFFF;

void _FuncGetGunshiBushouIDAsm() {
	__asm {
		// �R�c�ԍ�������
		MOV     ESI, iSigOfGundanIDGetGunshiBushou

		// �R�c�ԍ��������Ƃ��āA�R�t�ԍ��𓾂邽�߂̊֐����Ăяo��
		PUSH    ESI
		CALL    pCallFromFuncGetGunshiBushouID
		ADD     ESP, 4

		MOV iReturnOfBushouIDGetGunshiBushou, EAX // ���ʂ̂����AAX�̔ԍ����R�t�����ԍ��Ƃ��ĕۑ�

	}
}

namespace �֐� {
// �R�c�̌R�t�����𓾂�B�R�t����҂����Ȃ����0xFFFF���Ԃ��Ă���B
int Get_�R�t�����ԍ��y�z��p�z(int �R�c�ԍ��y�z��p�z) {

	if ( 0 <= �R�c�ԍ��y�z��p�z && �R�c�ԍ��y�z��p�z < �ő吔::�R�c���::�z�� ) {

		iSigOfGundanIDGetGunshiBushou = �R�c�ԍ��y�z��p�z+1; // �z��p���R�c�ɕύX

		iReturnOfBushouIDGetGunshiBushou = 0xFFFF; // �܂��́A���x���̒l�Ń��Z�b�g�B

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
		_FuncGetGunshiBushouIDAsm();

		__asm {
			pop edi
			pop esi
			pop esp
			pop edx
			pop ecx
			pop ebx
			pop eax
		}

		iReturnOfBushouIDGetGunshiBushou = iReturnOfBushouIDGetGunshiBushou & 0xFFFF; // EAX�̂����AAX�̕����������p����B

		// ���̌R�c�ɌR�t�������Ȃ��
		if ( 0 <= iReturnOfBushouIDGetGunshiBushou-1 && iReturnOfBushouIDGetGunshiBushou-1 < �ő吔::�������::�z�� ) {
			return iReturnOfBushouIDGetGunshiBushou-1; // �����ԍ��������ԍ��z��p�ɂ��ĕԂ�
		}
	}

	// ���Ȃ��ꍇ��s���ȏꍇ�͑S������B
	return 0xFFFF;
}



// �Ώۂ̑喼���v���C���[�S���̑喼�ł��邩�ǂ����𔻒f����B
// �喼�ԍ��y�z��p�z�ɂ͔z���̔ԍ�(attach-1�̐�)��n������
bool Is_�v���C���S���喼( WORD �喼�ԍ��y�z��p�z ) {

	// �喼ID�͈̔͂Ɏ��܂��Ă��邱��
	if ( 0 <= �喼�ԍ��y�z��p�z&& �喼�ԍ��y�z��p�z < �ő吔::�喼���::�z�� ) {
		// �^�[�Q�b�g�̕����̌R�cID���v���C���[�̌R�c�ł��邩��Ԃ�
		return Is_�v���C���S���R�c(p�喼���[�喼�ԍ��y�z��p�z].�����R�c�y�R�c�ԍ��z-1);
	} else {
		return false;
	}
}



// �Ώۂ̌R�c���v���C���[�S���R�c�̐��͉��̌R�c�ł��邩�ǂ����𔻒f����B
// iTargetGundanID�ɂ͔z���̔ԍ�(attach-1�̐�)��n������
bool Is_�v���C���S���R�c( WORD �R�c�ԍ��y�z��p�z ) {

	if (�R�c�ԍ��y�z��p�z >= �ő吔::�R�c���::�z�� ) { 
		return false;
	}

	WORD ix�y�R�c�ԍ��z = 0;
	for ( int n�Ԗ�=0; n�Ԗ�< �ő吔::�v���C���S���R�c���::�z��; n�Ԗ�++) {
		// �v���C���[���S�����Ă���R�c�̂h�c���m��
		ix�y�R�c�ԍ��z = p�v���C���S���R�c���[n�Ԗ�].�S���R�c�y�R�c�ԍ��z;

		// 0xFFFF�Ȃ�΃v���C���[�ł͂Ȃ�
		if ( ix�y�R�c�ԍ��z == 0xFFFF ) {
			continue;
		}

		// �v���C���[�S���̌R�c�̑喼���A�^�[�Q�b�g�Ƃ��Ă���Ώۂ̌R�c�̑喼�ƈ�v����Ȃ�΁A
		// ����̓v���C���[�̐��͉��̌R�c�ł���B
		// �ǂ���nb6player8��gundan�̒l�́A�����Ǘ���gundan�̒l����+1����Ă���悤�ł���B
		// ����Ă����ł�-1����B
		if (ix�y�R�c�ԍ��z >= 1 && p�R�c���[ix�y�R�c�ԍ��z-1].�����喼�y�喼�ԍ��z == p�R�c���[�R�c�ԍ��y�z��p�z].�����喼�y�喼�ԍ��z ) {
			return true;
		}
	}
	
	return false;
}


// �Ώۂ̕����������ꂩ�̃v���C���[���͉��̕����ł���
bool Is_�v���C���S������( WORD �����ԍ��y�z��p�z ) {

	// ����ID�͈̔͂Ɏ��܂��Ă��邱��
	if ( 0 <= �����ԍ��y�z��p�z && �����ԍ��y�z��p�z < �ő吔::�������::�z�� ) {

		// �^�[�Q�b�g�̕����̌R�cID���v���C���[�̌R�c�ł��邩��Ԃ�
		return Is_�v���C���S���R�c(p�������[�����ԍ��y�z��p�z].�����R�c�y�R�c�ԍ��z-1);

	} else {
		return false;
	}
}


}


