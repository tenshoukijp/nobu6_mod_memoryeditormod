#define  _CRT_SECURE_NO_WARNINGS

#include <string>
#include <map>

#include "���b�Z�[�W�֘A���^.h"
#include "�f�o�b�O���^.h"

using namespace std;
using namespace �֐�;


extern HMODULE hModuleTSMod;

typedef int (WINAPI *PFNONIGMATCHALLOC)(char *�Ώە�����, char *���K�\��������, int *���K�\���}�b�`����);
PFNONIGMATCHALLOC p_OnigMatchAlloc = NULL;
typedef int (WINAPI *PFNONIGMATCHFREE)(int *���K�\���}�b�`����);
PFNONIGMATCHFREE p_OnigMatchFree = NULL;

// TSMod�ɂ����Ȃ����K�\���֘A�̂̃|�C���^�̓o�^
void _���K�\���֐��o�^() {
	p_OnigMatchAlloc = (PFNONIGMATCHALLOC)GetProcAddress( hModuleTSMod, "Extern_OnigMatchAlloc" );
	p_OnigMatchFree = (PFNONIGMATCHFREE)GetProcAddress( hModuleTSMod, "Extern_OnigMatchFree" );
}


// ���K�\���}�b�`���O�p�̊֐�

namespace �֐� {

	int Is_������}�b�`(  string �Ώە�����, string ���������� ) {
		return �Ώە�����.find(����������) != string::npos;
	}
} // namespace