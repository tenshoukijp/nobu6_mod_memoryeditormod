
// ���ʂ̂R�c�x�N�g���^�B
#pragma once
#pragma pack(1)

#include "�⏕���C�u����.h"


// ���ʂ̂R�c�ʒu�^�B
struct �R�c�ʒu�^ {
	�R�c�ʒu�^(double �w�ʒu, double �x�ʒu, double �y�ʒu) : �w(�w�ʒu),�x(�x�ʒu),�y(�y�ʒu) {}
	�R�c�ʒu�^() : �w(0),�x(0),�y(0) {}
	double �w;
	double �x;
	double �y;
	�R�c�ʒu�^& operator=(const �R�c�ʒu�^& v);
    //��r���Z�q
	bool operator==(const �R�c�ʒu�^& v) const;
	bool operator!=(const �R�c�ʒu�^& v) const;
};


class �R�c�x�N�g���^ {
public:
	//�����o�ϐ�
	double �w;
	double �x;
	double �y;
	//�R���X�g���N�^
	�R�c�x�N�g���^();
	�R�c�x�N�g���^(double �w����,double �x����,double �y����);
	�R�c�x�N�g���^(�R�c�ʒu�^ pos);
	//������Z�q
	�R�c�x�N�g���^& �R�c�x�N�g���^::operator=(const �R�c�x�N�g���^& v);
	//�P�����Z�q
	�R�c�x�N�g���^& operator+=(const �R�c�x�N�g���^& v);
	�R�c�x�N�g���^& operator-=(const �R�c�x�N�g���^& v);
	�R�c�x�N�g���^& operator*=(double k);
	�R�c�x�N�g���^& operator/=(double k);
	�R�c�x�N�g���^ operator+()const;
	�R�c�x�N�g���^ operator-()const;
	//�Y�������Z�q
	double& operator[](int i);
    //��r���Z�q
	bool operator==(const �R�c�x�N�g���^& v ) const;
	bool operator!=(const �R�c�x�N�g���^& v ) const;
	//�׃N�g���̒���
	double ����()const;
	//���K��
	void ���K��();
};

//�x�N�g�����Z
//�R�c�x�N�g���^+�R�c�x�N�g���^
�R�c�x�N�g���^ operator+(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v);
//�R�c�x�N�g���^-�R�c�x�N�g���^
�R�c�x�N�g���^ operator-(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v);
//double*�R�c�x�N�g���^
�R�c�x�N�g���^ operator*(double k,const �R�c�x�N�g���^& v);
//�R�c�x�N�g���^*double
�R�c�x�N�g���^ operator*(const �R�c�x�N�g���^& v,double k);
//�R�c�x�N�g���^/double
�R�c�x�N�g���^ operator/(const �R�c�x�N�g���^& v,double k);
//���� �R�c�x�N�g���^*�R�c�x�N�g���^
double operator*(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v);
//�O�� �R�c�x�N�g���^%�R�c�x�N�g���^
�R�c�x�N�g���^ operator%(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v);
//�Q�̃x�N�g���̂Ȃ��p�x
double �p�x(const �R�c�x�N�g���^& u,const �R�c�x�N�g���^& v);
//�o��
// �Q�_�ԍ��W�̍�
�R�c�x�N�g���^ operator-(�R�c�ʒu�^ &p1, �R�c�ʒu�^ &p2);
