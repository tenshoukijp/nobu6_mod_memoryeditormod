
// ���ʂ̂Q�c�x�N�g���^�B
#pragma once

#include <string>
#include "�⏕���C�u����.h"

using namespace std;



// ���ʂ̂Q�c�ʒu�^�B
struct �Q�c�ʒu�^ {
	�Q�c�ʒu�^(double �w�ʒu, double �x�ʒu) : �w(�w�ʒu),�x(�x�ʒu) {}
	�Q�c�ʒu�^() : �w(0),�x(0) {}
	double �w;
	double �x;

	�Q�c�ʒu�^& operator=(const �Q�c�ʒu�^& v);
    //��r���Z�q
	bool operator==(const �Q�c�ʒu�^& v) const;
	bool operator!=(const �Q�c�ʒu�^& v) const;

};


class �Q�c�x�N�g���^ {
public:
	//�����o�ϐ�
	double �w;
	double �x;
	//�R���X�g���N�^
	�Q�c�x�N�g���^();
	�Q�c�x�N�g���^(double �w����,double �x����);
	�Q�c�x�N�g���^(�Q�c�ʒu�^ pos);
	//������Z�q
	�Q�c�x�N�g���^& �Q�c�x�N�g���^::operator=(const �Q�c�x�N�g���^& v);
	//�P�����Z�q
	�Q�c�x�N�g���^& operator+=(const �Q�c�x�N�g���^& v);
	�Q�c�x�N�g���^& operator-=(const �Q�c�x�N�g���^& v);
	�Q�c�x�N�g���^& operator*=(double k);
	�Q�c�x�N�g���^& operator/=(double k);
	�Q�c�x�N�g���^ operator+()const;
	�Q�c�x�N�g���^ operator-()const;
	//�Y�������Z�q
	double& operator[](int i);
    //��r���Z�q
	bool operator==(const �Q�c�x�N�g���^& v ) const;
	bool operator!=(const �Q�c�x�N�g���^& v ) const;
	//�׃N�g���̒���
	double ����()const;
	//���K��
	void ���K��();
};

//�x�N�g�����Z
//�Q�c�x�N�g���^+�Q�c�x�N�g���^
�Q�c�x�N�g���^ operator+(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v);
//�Q�c�x�N�g���^-�Q�c�x�N�g���^
�Q�c�x�N�g���^ operator-(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v);
//double*�Q�c�x�N�g���^
�Q�c�x�N�g���^ operator*(double k,const �Q�c�x�N�g���^& v);
//�Q�c�x�N�g���^*double
�Q�c�x�N�g���^ operator*(const �Q�c�x�N�g���^& v,double k);
//�Q�c�x�N�g���^/double
�Q�c�x�N�g���^ operator/(const �Q�c�x�N�g���^& v,double k);
//���� �Q�c�x�N�g���^*�Q�c�x�N�g���^
double operator*(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v);
//�O�� �Q�c�x�N�g���^%�Q�c�x�N�g���^
double operator%(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v);
//�Q�̃x�N�g���̂Ȃ��p�x
double �p�x(const �Q�c�x�N�g���^& u,const �Q�c�x�N�g���^& v);

// �Q�_�ԍ��W�̍�
�Q�c�x�N�g���^ operator-(�Q�c�ʒu�^ &p1, �Q�c�ʒu�^ &p2);

// �x�N�g���𕶎��񉻂��邪�A������k�n�i�W���ʁj�ŕ����񉻁B
string Get_�W���ʕ�����(�Q�c�x�N�g���^ v);

// �x�N�g���𕶎��񉻂��邪�A������k�n�i�S���ʁj�ŕ����񉻁B
string Get_�S���ʕ�����(�Q�c�x�N�g���^ v);
