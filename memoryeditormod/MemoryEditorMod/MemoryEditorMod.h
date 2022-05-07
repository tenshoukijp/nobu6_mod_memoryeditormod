#pragma once

#include "ModMode.h"

using namespace System;
using namespace System::Windows::Forms;




ref class MemoryEditorForm : public Form {
public:
	static MemoryEditorForm^ meForm = nullptr; // �������g�̃O���[�o���ϐ�

	TabControl^ tcME;	// �S�̂łP�ɂȂ��Ă�^�u�R���g���[���BTabPage�^��ǉ����Ă�


public: 
	MemoryEditorForm() {
		// �t�H�[���ɂ��������̂̏�������
		this->Text = "MemoryEditorMod";
		this->Width = 800;
		this->Height = 600;

		SetFormIcon();

		SetTabControl();

		this->KeyPreview = true; // �e�R���g���[���̃L�[���͂͑S�ăt�H�[�����󂯎��

		this->Shown += gcnew EventHandler(this, &MemoryEditorForm::meForm_Shown);
		this->Resize += gcnew EventHandler(this, &MemoryEditorForm::meForm_Resize);
		this->KeyDown +=  gcnew KeyEventHandler(this, &MemoryEditorForm::meForm_KeyDown);


		meForm_Resize(nullptr, nullptr);
	}

	void SetFormIcon() {
		// ���̃v���W�F�N�g�̃A�Z���u���̃^�C�v���擾�B
		System::Reflection::Assembly^ prj_assebmly = GetType()->Assembly;
		System::Resources::ResourceManager^ r = gcnew System::Resources::ResourceManager(String::Format("{0}.MemoryEditorMod", prj_assebmly->GetName()->Name), prj_assebmly);


		System::Drawing::Icon^ iconform = (System::Drawing::Icon^)(r->GetObject("MemoryEditorIcon"));
		this->Icon = iconform;
	}

	// �^�u�R���g���[���̏������B�ԂɁA�e�f�[�^�O���b�h�r���[�ւ̃f�[�^�������ݏ��������荞��
	void SetTabControl() {
		tcME = gcnew TabControl();

		dgvYear_Init();
		dgvTurn_Init();
		dgvBushouName_Init();
		dgvBushou_Init();
		dgvDaimyo_Init();
		dgvDaimyoYuko_Init();
		dgvGundan_Init();
		dgvCastle_Init();
		dgvCastleAdd_Init();
		dgvChiiki_Init();
		dgvKanni_Init();
		dgvKahou_Init();
		dgvSoba_Init();

		dgvBattleUnit_Init();
		dgvWeather_Init();
		dgvSettings_Init();
		dgvSettingsEx_Init();
		dgvBGM_Init();

		tcME->SelectedIndexChanged += gcnew EventHandler(this, &MemoryEditorForm::tcME_SelectedIndexChanged);
		this->Controls->Add(tcME);
	}


	// �^�u��؂�ւ�����
	void tcME_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
		int iTabIndex = tcME->SelectedIndex;
		TabPage^ tpCur = tcME->TabPages[iTabIndex];

		if ( tpCur->Text == "p�N���" ) {
			dgvYear_DataImport();
		}
		else if ( tpCur->Text == "p�^�[�����" ) {
			dgvTurn_DataImport();
		}
		else if ( tpCur->Text == "p�����ːЏ��" ) {
			dgvBushouName_DataImport();
		}
		else if ( tpCur->Text == "p�������" ) {
			dgvBushou_DataImport();
		}
		else if ( tpCur->Text == "p�喼���" ) {
			dgvDaimyo_DataImport();
		}
		else if ( tpCur->Text == "p�喼���i�����j" ) {
			dgvDaimyoYuko_DataImport();
		}
		else if ( tpCur->Text == "p�R�c���" ) {
			dgvGundan_DataImport();
		}
		else if ( tpCur->Text == "p����" ) {
			dgvCastle_DataImport();
		}
		else if ( tpCur->Text == "p��t�����" ) {
			dgvCastleAdd_DataImport();
		}
		else if ( tpCur->Text == "p�n����" ) {
			dgvChiiki_DataImport();
		}
		else if ( tpCur->Text == "p���ʏ��" ) {
			dgvKanni_DataImport();
		}
		else if ( tpCur->Text == "p�ƕ���" ) {
			dgvKahou_DataImport();
		}
		else if ( tpCur->Text == "p������" ) {
			dgvSoba_DataImport();
		}
		else if ( tpCur->Text == "�����i�����j" ) {
			dgvBattleUnit_DataImport();
		}
		else if ( tpCur->Text == "p�V�C���" ) {
			dgvWeather_DataImport();
		}
		else if ( tpCur->Text == "p���ݒ���" ) {
			dgvSettings_DataImport();
		}
		else if ( tpCur->Text == "p���ݒ�g�����" ) {
			dgvSettingsEx_DataImport();
		}
		else if ( tpCur->Text == "p���y���" ) {
			dgvBGM_DataImport();
		}

		meForm_Resize(sender, e);

	}

private:
	void meForm_Shown(Object^ sender, EventArgs^ e) {
		meForm_Resize(sender, e);
	}

	// �z�[���T�C�Y��ύX�������A�^�u�R���g���[���̃T�C�Y��ύX���A����Ɋe�A�f�[�^�O���b�h�r���[�̑傫����ύX����B
	void meForm_Resize(Object^ sender, EventArgs^ e) {
		tcME->Size = this->ClientSize;

		dgvYear->Size = tpYear->ClientSize;
		dgvTurn->Size = tpTurn->ClientSize;
		dgvBushouName->Size = tpBushouName->ClientSize;
		dgvBushou->Size = tpBushou->ClientSize;
		dgvDaimyo->Size = tpDaimyo->ClientSize;
		dgvDaimyoYuko->Size = tpDaimyoYuko->ClientSize;
		dgvGundan->Size = tpGundan->ClientSize;
		dgvCastle->Size = tpCastle->ClientSize;
		dgvCastleAdd->Size = tpCastleAdd->ClientSize;
		dgvChiiki->Size = tpChiiki->ClientSize;
		dgvKanni->Size = tpKanni->ClientSize;
		dgvKahou->Size = tpKahou->ClientSize;
		dgvSoba->Size = tpSoba->ClientSize;
		dgvBattleUnit->Size = tpBattleUnit->ClientSize;
		dgvWeather->Size = tpWeather->ClientSize;
		dgvSettings->Size = tpSettings->ClientSize;
		dgvSettingsEx->Size = tpSettingsEx->ClientSize;
		dgvBGM->Size = tpBGM->ClientSize;

	}

	// F5�L�[�������ꂽ��A�Y���^�u���J�����̂Ɠ����u�f�[�^�X�V�v�����܂��B
	void meForm_KeyDown(Object^ sender, KeyEventArgs^ e) {
		if ( Form::ActiveForm == this && e->KeyCode == ::Keys::F5 ) {
			tcME_SelectedIndexChanged(nullptr, nullptr);
		}
	}

//-------------------------------------------------- p�����ːЏ���-------------------------------------------------
private: 

	TabPage^ tpBushouName;
	DataGridView^ dgvBushouName;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleBushouName = {
		"�y�z��p�z", 
		"�����ԍ�",
		"Get_����",
		"Get_���O",
		"��ԍ�",
		"���",
		"�g��",
		"����",
		"�ދp",
		"�펀",
	}; 

	void dgvBushouName_Init() {
		tpBushouName = gcnew TabPage();
		tpBushouName->Text = "p�����ːЏ��";
		tpBushouName->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpBushouName);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvBushouName = gcnew DataGridView();
		dgvBushouName->Size = tpBushouName->Size;
		dgvBushouName->ScrollBars = ::ScrollBars::Both;
		dgvBushouName->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleBushouName->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleBushouName[i]; 

			if ( i <= 3 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvBushouName->Columns->Add(dgvtbc); 
		} 

		dgvBushouName_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvBushouName->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvBushouName_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpBushouName->Controls->Add(dgvBushouName);
	} 

private: 
	void dgvBushouName_DataImport() { 
		dgvBushouName->Rows->Clear();

		for ( int i=0; i<�ő吔::�������::�z��; i++) { 
			dgvBushouName->Rows->Add( 
				i,
				i+1,
				gcnew String(Get_����(i).c_str()), 
				gcnew String(Get_���O(i).c_str()), 
				p�����ːЏ��[i].��ԍ�,
				p�����ːЏ��[i].���,
				p�����ːЏ��[i].�g��,
				p�����ːЏ��[i].����,
				p�����ːЏ��[i].�ދp,
				p�����ːЏ��[i].�펀
			); 
		} 
	} 

	void dgvBushouName_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvBushouName->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�����ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iBushouID = Convert::ToInt32(dgvBushouName[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvBushouName[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "Get_����") {
			char szName[32] = "";
			wsprintf(szName, "%s", svalue);
			Set_����( iBushouID, szName );
		} 
		else if (headerText == "Get_���O") { 
			char szName[32] = "";
			wsprintf(szName, "%s", svalue);
			Set_���O( iBushouID, szName );
		} 
		else if (headerText == "��ԍ�") { 
			p�����ːЏ��[iBushouID].��ԍ� = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "���") { 
			p�����ːЏ��[iBushouID].��� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�g��") { 
			p�����ːЏ��[iBushouID].�g�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "����") { 
			p�����ːЏ��[iBushouID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�ދp") { 
			p�����ːЏ��[iBushouID].�ދp = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�펀") { 
			p�����ːЏ��[iBushouID].�펀 = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p�����ːЏ���-------------------------------------------------


//-------------------------------------------------- p��������-------------------------------------------------
private: 

	TabPage^ tpBushou;
	DataGridView^ dgvBushou;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleBushou;

	static cli::array<String^>^ getColTitleBushou() {
		if (iCallDLLMODE == kModeTSMod) {
			cli::array<String^>^ ret = {
				"�y�z��p�z",
				"�����ԍ�",
				"�O�̕����y�����ԍ��z",
				"���̕����y�����ԍ��z",
				"�ő吭��",
				"�ő���",
				"�ő�q��",
				"�����n���l",
				"�퓬�n���l",
				"�q�d�n���l",
				"����",
				"��]",
				"����",
				"�M��",
				"��������",
				"�����喼�y�喼�ԍ��z",
				"�����R�c�y�R�c�ԍ��z",
				"��������y��ԍ��z",
				"������喼�y�喼�ԍ��z",
				"����",
				"�P��",
				"�m�C",
				"����",
				"�d���N��",
				"Get_���������ԍ��y�z��p�z",
				"���N",
				"�e��ԍ�",
				"�v�l",
				"�`��",
				"����",
				"�����K��",
				"�퓬�K��",
				"�q�d�K��",
				"�Z�\�ꊅ",
				"�Z�\�ÎE",
				"�Z�\���o",
				"�Z�\����",
				"�Z�\����",
				"�Z�\�ِ�",
				"�Z�\�ē�",
				"�Z�\����",
				"�E��",
				"���y�K��",
				"�R�n�K��",
				"Get_�S�C�K��",
				"���R�K��",
				"Get_�|�K��", // ��������������Ă���
				"Get_���K��", // ��������������Ă���
				"��C",
				"�R�n�S�C",
				"�S�b�D",
				"����",
				"�E��",
				"Get_�Ɨ�",
				"����",
				"�s����",
				"�������",
				"�⍦���",
				"���",
				"Is_�v���C���S������"
			};

			return ret;
		} 
		else {
			cli::array<String^>^ ret = {
				"�y�z��p�z",
				"�����ԍ�",
				"�O�̕����y�����ԍ��z",
				"���̕����y�����ԍ��z",
				"�ő吭��",
				"�ő���",
				"�ő�q��",
				"�����n���l",
				"�퓬�n���l",
				"�q�d�n���l",
				"����",
				"��]",
				"����",
				"�M��",
				"��������",
				"�����喼�y�喼�ԍ��z",
				"�����R�c�y�R�c�ԍ��z",
				"��������y��ԍ��z",
				"������喼�y�喼�ԍ��z",
				"����",
				"�P��",
				"�m�C",
				"����",
				"�d���N��",
				"Get_���������ԍ��y�z��p�z",
				"���N",
				"�e��ԍ�",
				"�v�l",
				"�`��",
				"����",
				"�����K��",
				"�퓬�K��",
				"�q�d�K��",
				"�Z�\�ꊅ",
				"�Z�\�ÎE",
				"�Z�\���o",
				"�Z�\����",
				"�Z�\����",
				"�Z�\�ِ�",
				"�Z�\�ē�",
				"�Z�\����",
				"�E��",
				"���y�K��",
				"�R�n�K��",
				"Get_�S�C�K��",
				"���R�K��",
				"��C",
				"�R�n�S�C",
				"�S�b�D",
				"����",
				"�E��",
				"Get_�Ɨ�",
				"����",
				"�s����",
				"�������",
				"�⍦���",
				"���",
				"Is_�v���C���S������"
			};

			return ret;
		}
	}

	void dgvBushou_Init() {
		// TSMod��PluginMod���ō��ڐ����قȂ�
		colTitleBushou = getColTitleBushou();

		tpBushou = gcnew TabPage();
		tpBushou->Text = "p�������";
		tpBushou->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpBushou);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvBushou = gcnew DataGridView();
		dgvBushou->Size = tpBushou->Size;
		dgvBushou->ScrollBars = ::ScrollBars::Both;
		dgvBushou->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleBushou->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleBushou[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvBushou->Columns->Add(dgvtbc); 
		} 

		dgvBushou_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvBushou->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvBushou_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpBushou->Controls->Add(dgvBushou);
	} 

private: 
	void dgvBushou_DataImport() { 
		dgvBushou->Rows->Clear();

		// TSMod��PluginMod���ō��ڐ����قȂ�
		if (iCallDLLMODE == kModeTSMod) {
			// ����P�ʂő����Ă䂭�Aindex:0, ��:1, ��:2, ����:3 �퓬:4 �q�d:5 �̏��Ԓʂ� 
			for (int i = 0; i < �ő吔::�������::�z��; i++) {
				dgvBushou->Rows->Add(
					i,
					i + 1,
					p�������[i].�O�̕����y�����ԍ��z,
					p�������[i].���̕����y�����ԍ��z,
					p�������[i].�ő吭��,
					p�������[i].�ő���,
					p�������[i].�ő�q��,
					p�������[i].�����n���l,
					p�������[i].�퓬�n���l,
					p�������[i].�q�d�n���l,
					p�������[i].����,
					p�������[i].��],
					p�������[i].����,
					p�������[i].�M��,
					p�������[i].��������,
					p�������[i].�����喼�y�喼�ԍ��z,
					p�������[i].�����R�c�y�R�c�ԍ��z,
					p�������[i].��������y��ԍ��z,
					p�������[i].������喼�y�喼�ԍ��z,
					p�������[i].����,
					p�������[i].�P��,
					p�������[i].�m�C,
					p�������[i].����,
					p�������[i].�d���N��,
					Get_���������ԍ��y�z��p�z(i),
					p�������[i].���N,
					p�������[i].�e��ԍ�,
					p�������[i].�v�l,
					p�������[i].�`��,
					p�������[i].����,
					p�������[i].�����K��,
					p�������[i].�퓬�K��,
					p�������[i].�q�d�K��,
					p�������[i].�Z�\�ꊅ,
					p�������[i].�Z�\�ÎE,
					p�������[i].�Z�\���o,
					p�������[i].�Z�\����,
					p�������[i].�Z�\����,
					p�������[i].�Z�\�ِ�,
					p�������[i].�Z�\�ē�,
					p�������[i].�Z�\����,
					p�������[i].�E��,
					p�������[i].���y�K��,
					p�������[i].�R�n�K��,
					Get_�S�C�K��(i),
					p�������[i].���R�K��,
					Get_�|�K��(i),  // ��������������Ă���
					Get_���K��(i),  // ��������������Ă���
					p�������[i].��C,
					p�������[i].�R�n�S�C,
					p�������[i].�S�b�D,
					p�������[i].����,
					p�������[i].�E��,
					Get_�Ɨ�(i),
					p�������[i].����,
					p�������[i].�s����,
					p�������[i].�������,
					p�������[i].�⍦���,
					p�������[i].���,
					Is_�v���C���S������(i)
				);
			}
		}
		else {
			// ����P�ʂő����Ă䂭�Aindex:0, ��:1, ��:2, ����:3 �퓬:4 �q�d:5 �̏��Ԓʂ� 
			for (int i = 0; i < �ő吔::�������::�z��; i++) {
				dgvBushou->Rows->Add(
					i,
					i + 1,
					p�������[i].�O�̕����y�����ԍ��z,
					p�������[i].���̕����y�����ԍ��z,
					p�������[i].�ő吭��,
					p�������[i].�ő���,
					p�������[i].�ő�q��,
					p�������[i].�����n���l,
					p�������[i].�퓬�n���l,
					p�������[i].�q�d�n���l,
					p�������[i].����,
					p�������[i].��],
					p�������[i].����,
					p�������[i].�M��,
					p�������[i].��������,
					p�������[i].�����喼�y�喼�ԍ��z,
					p�������[i].�����R�c�y�R�c�ԍ��z,
					p�������[i].��������y��ԍ��z,
					p�������[i].������喼�y�喼�ԍ��z,
					p�������[i].����,
					p�������[i].�P��,
					p�������[i].�m�C,
					p�������[i].����,
					p�������[i].�d���N��,
					Get_���������ԍ��y�z��p�z(i),
					p�������[i].���N,
					p�������[i].�e��ԍ�,
					p�������[i].�v�l,
					p�������[i].�`��,
					p�������[i].����,
					p�������[i].�����K��,
					p�������[i].�퓬�K��,
					p�������[i].�q�d�K��,
					p�������[i].�Z�\�ꊅ,
					p�������[i].�Z�\�ÎE,
					p�������[i].�Z�\���o,
					p�������[i].�Z�\����,
					p�������[i].�Z�\����,
					p�������[i].�Z�\�ِ�,
					p�������[i].�Z�\�ē�,
					p�������[i].�Z�\����,
					p�������[i].�E��,
					p�������[i].���y�K��,
					p�������[i].�R�n�K��,
					Get_�S�C�K��(i),
					p�������[i].���R�K��,
					p�������[i].��C,
					p�������[i].�R�n�S�C,
					p�������[i].�S�b�D,
					p�������[i].����,
					p�������[i].�E��,
					Get_�Ɨ�(i),
					p�������[i].����,
					p�������[i].�s����,
					p�������[i].�������,
					p�������[i].�⍦���,
					p�������[i].���,
					Is_�v���C���S������(i)
				);
			}
		}
	} 

	void dgvBushou_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvBushou->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�����ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iBushouID = Convert::ToInt32(dgvBushou[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvBushou[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "�ő吭��") { 
			// �Y���̃O���b�h�̒l��byte�^(256�܂ł̌^)�ɂ��āAp�������ɑ������B 
			p�������[iBushouID].�ő吭�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�ő���") { 
			p�������[iBushouID].�ő��� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�ő�q��") { 
			p�������[iBushouID].�ő�q�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�����n���l") { 
			p�������[iBushouID].�����n���l = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�퓬�n���l") { 
			p�������[iBushouID].�퓬�n���l = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�q�d�n���l") { 
			p�������[iBushouID].�q�d�n���l = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "����") { 
			p�������[iBushouID].���� = Convert::ToSByte(svalue); 
		} 
		else if (headerText == "��]") { 
			p�������[iBushouID].��] = Convert::ToSByte(svalue); 
		} 
		else if (headerText == "����") { 
			p�������[iBushouID].���� = Convert::ToSByte(svalue); 
		} 
		else if (headerText == "�M��") { 
			p�������[iBushouID].�M�� = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "��������") { 
			p�������[iBushouID].�������� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�����喼�y�喼�ԍ��z") { 
			p�������[iBushouID].�����喼�y�喼�ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�����R�c�y�R�c�ԍ��z") { 
			p�������[iBushouID].�����R�c�y�R�c�ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "��������y��ԍ��z") { 
			p�������[iBushouID].��������y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "������喼�y�喼�ԍ��z") { 
			p�������[iBushouID].������喼�y�喼�ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "����") { 
			p�������[iBushouID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�P��") { 
			p�������[iBushouID].�P�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�m�C") { 
			p�������[iBushouID].�m�C = Convert::ToByte(svalue); 
		} 
		else if (headerText == "����") { 
			p�������[iBushouID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�d���N��") { 
			p�������[iBushouID].�d���N�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "���N") { 
			p�������[iBushouID].���N = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�e��ԍ�") { 
			p�������[iBushouID].�e��ԍ� = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�v�l") { 
			p�������[iBushouID].�v�l = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�`��") { 
			p�������[iBushouID].�`�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "����") { 
			p�������[iBushouID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�����K��") { 
			p�������[iBushouID].�����K�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�퓬�K��") { 
			p�������[iBushouID].�퓬�K�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�q�d�K��") { 
			p�������[iBushouID].�q�d�K�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�Z�\�ꊅ") { 
			p�������[iBushouID].�Z�\�ꊅ = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�Z�\�ÎE") { 
			p�������[iBushouID].�Z�\�ÎE = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�Z�\���o") { 
			p�������[iBushouID].�Z�\���o = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�Z�\����") { 
			p�������[iBushouID].�Z�\���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�Z�\����") { 
			p�������[iBushouID].�Z�\���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�Z�\�ِ�") { 
			p�������[iBushouID].�Z�\�ِ� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�Z�\�ē�") { 
			p�������[iBushouID].�Z�\�ē� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�Z�\����") { 
			p�������[iBushouID].�Z�\���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�E��") { 
			p�������[iBushouID].�E�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "���y�K��") { 
			p�������[iBushouID].���y�K�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�R�n�K��") { 
			p�������[iBushouID].�R�n�K�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "Get_�S�C�K��") { 
			Set_�S�C�K��(iBushouID, Convert::ToByte(svalue) ); 
		} 
		else if (headerText == "���R�K��") {
			p�������[iBushouID].���R�K�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "Get_�|�K��") {
			Set_�|�K��(iBushouID, Convert::ToByte(svalue));
		}
		else if (headerText == "Get_���K��") {
			Set_���K��(iBushouID, Convert::ToByte(svalue));
		}
		else if (headerText == "��C") { 
			p�������[iBushouID].��C = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�R�n�S�C") { 
			p�������[iBushouID].�R�n�S�C = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�S�b�D") { 
			p�������[iBushouID].�S�b�D = Convert::ToByte(svalue); 
		} 
		else if (headerText == "����") { 
			p�������[iBushouID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�E��") { 
			p�������[iBushouID].�E�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "Get_�Ɨ�") { 
			Set_�Ɨ�( iBushouID, Convert::ToByte(svalue) ); 
		} 
		else if (headerText == "����") { 
			p�������[iBushouID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�s����") { 
			p�������[iBushouID].�s���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�������") { 
			p�������[iBushouID].������� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�⍦���") { 
			p�������[iBushouID].�⍦��� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "���") { 
			p�������[iBushouID].��� = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p��������-------------------------------------------------


//-------------------------------------------------- p�N����-------------------------------------------------
private: 

	TabPage^ tpYear;
	DataGridView^ dgvYear;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleYear = {
		"�N", 
		"�G��",
		"Get_����",
		"Get_�a��",
		"Get_�V�ċL��N",
	}; 

	void dgvYear_Init() {
		tpYear = gcnew TabPage();
		tpYear->Text = "p�N���";
		tpYear->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpYear);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvYear = gcnew DataGridView();
		dgvYear->Size = tpYear->Size;
		dgvYear->ScrollBars = ::ScrollBars::Both;
		dgvYear->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleYear->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleYear[i]; 

			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvYear->Columns->Add(dgvtbc); 
		} 

		dgvYear_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvYear->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvYear_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpYear->Controls->Add(dgvYear);
	} 

private: 
	void dgvYear_DataImport() { 
		dgvYear->Rows->Clear();

		�a��^ wa = Get_�a��( Get_����() );
		string ���ƔN = wa.���� + wa.�N����;

		dgvYear->Rows->Add( 
			p�N���.�N,
			p�N���.�G��,
			Get_����(),
			gcnew String( ���ƔN.c_str() ),
			Get_�V�ċL��N()
		); 
	} 

	void dgvYear_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvYear->Columns[e->ColumnIndex]->HeaderText;

		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�^�[���ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iBushouID = Convert::ToInt32(dgvYear[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvYear[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "�N") { 
			p�N���.�N = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�G��") { 
			p�N���.�G�� = Convert::ToSByte(svalue); 
		} 


	} 


//-------------------------------------------------- p�N����-------------------------------------------------


//-------------------------------------------------- p�^�[������-------------------------------------------------
private: 

	TabPage^ tpTurn;
	DataGridView^ dgvTurn;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleTurn = {
		"���݂̃^�[���y�喼�ԍ��z", 
		"���݂̃^�[���y�R�c�ԍ��z",
		"���݂̃^�[���y��ԍ��z",
	}; 

	void dgvTurn_Init() {
		tpTurn = gcnew TabPage();
		tpTurn->Text = "p�^�[�����";
		tpTurn->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpTurn);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvTurn = gcnew DataGridView();
		dgvTurn->Size = tpTurn->Size;
		dgvTurn->ScrollBars = ::ScrollBars::Both;
		dgvTurn->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleTurn->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleTurn[i]; 

			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvTurn->Columns->Add(dgvtbc); 
		} 

		dgvTurn_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvTurn->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvTurn_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpTurn->Controls->Add(dgvTurn);
	} 

private: 
	void dgvTurn_DataImport() { 
		dgvTurn->Rows->Clear();

		dgvTurn->Rows->Add( 
			p�^�[�����.���݂̃^�[���y�喼�ԍ��z,
			p�^�[�����.���݂̃^�[���y�R�c�ԍ��z,
			p�^�[�����.���݂̃^�[���y��ԍ��z
		); 
	} 

	void dgvTurn_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvTurn->Columns[e->ColumnIndex]->HeaderText;

		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�^�[���ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iBushouID = Convert::ToInt32(dgvTurn[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvTurn[e->ColumnIndex, e->RowIndex]->Value->ToString();
	} 


//-------------------------------------------------- p�^�[������-------------------------------------------------


//-------------------------------------------------- p�喼����-------------------------------------------------
private: 

	TabPage^ tpDaimyo;
	DataGridView^ dgvDaimyo;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleDaimyo = {
		"�y�z��p�z", 
		"�喼�ԍ�",
		"�喼�y�����ԍ��z",
		"�����R�c�y�R�c�ԍ��z",
		"��������y��ԍ��z",
		"�B�������y�����ԍ��z",
		"�Ɩ�",
		"�G�Α喼�y�喼�ԍ��z",
		"�F�D�喼�y�喼�ԍ��z",
		"���l",
		"�z����",
		"�]���",
		"Get_�喼��E",
		"Get_�喼�����鐔",
		"Is_�v���C���S���喼",
	}; 


	void dgvDaimyo_Init() {
		tpDaimyo = gcnew TabPage();
		tpDaimyo->Text = "p�喼���";
		tpDaimyo->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpDaimyo);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvDaimyo = gcnew DataGridView();
		dgvDaimyo->Size = tpDaimyo->Size;
		dgvDaimyo->ScrollBars = ::ScrollBars::Both;
		dgvDaimyo->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleDaimyo->Length; i++) {

			
			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleDaimyo[i]; 
			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvDaimyo->Columns->Add(dgvtbc); 

		} 

		dgvDaimyo_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvDaimyo->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvDaimyo_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpDaimyo->Controls->Add(dgvDaimyo);
	} 

private: 
	void dgvDaimyo_DataImport() {

		dgvDaimyo->Rows->Clear();

		for ( int i=0; i<�ő吔::�喼���::�z��; i++) {

			dgvDaimyo->Rows->Add( 
				i,
				i+1,
				p�喼���[i].�喼�y�����ԍ��z,
				p�喼���[i].�����R�c�y�R�c�ԍ��z,
				p�喼���[i].��������y��ԍ��z,
				p�喼���[i].�B�������y�����ԍ��z,
				p�喼���[i].�Ɩ�,
				p�喼���[i].�G�Α喼�y�喼�ԍ��z,
				p�喼���[i].�F�D�喼�y�喼�ԍ��z,
				p�喼���[i].���l,
				p�喼���[i].�z����,
				p�喼���[i].�]���,
				Get_�喼��E( i ),
				Get_�喼�����鐔(i),
				Is_�v���C���S���喼(i)
			); 
		}

	} 

	void dgvDaimyo_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvDaimyo->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�喼�ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iDaimyoID = Convert::ToInt32(dgvDaimyo[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvDaimyo[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "�喼�y�����ԍ��z") { 
			p�喼���[iDaimyoID].�喼�y�����ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�����R�c�y�R�c�ԍ��z") { 
			p�喼���[iDaimyoID].�����R�c�y�R�c�ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "��������y��ԍ��z") { 
			p�喼���[iDaimyoID].��������y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�B�������y�����ԍ��z") { 
			p�喼���[iDaimyoID].�B�������y�����ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�Ɩ�") { 
			p�喼���[iDaimyoID].�Ɩ� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�G�Α喼�y�喼�ԍ��z") { 
			p�喼���[iDaimyoID].�G�Α喼�y�喼�ԍ��z = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�F�D�喼�y�喼�ԍ��z") { 
			p�喼���[iDaimyoID].�F�D�喼�y�喼�ԍ��z = Convert::ToByte(svalue); 
		} 
		else if (headerText == "���l") { 
			p�喼���[iDaimyoID].���l = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�z����") { 
			p�喼���[iDaimyoID].�z���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�]���") { 
			p�喼���[iDaimyoID].�]��� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�Ɩ�") { 
			p�喼���[iDaimyoID].�Ɩ� = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p�喼����-------------------------------------------------


//-------------------------------------------------- p�喼���i�����j��-------------------------------------------------
private: 

	TabPage^ tpDaimyoYuko;
	DataGridView^ dgvDaimyoYuko;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleDaimyoYuko = {
		"�y�z��p�z", 
		"�喼�ԍ�",
		"�����E�����E�F�D",
	}; 

	DataGridViewComboBoxColumn^ dgvDKYtbc;

	void dgvDaimyoYuko_Init() {
		tpDaimyoYuko = gcnew TabPage();
		tpDaimyoYuko->Text = "p�喼���i�����j";
		tpDaimyoYuko->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpDaimyoYuko);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvDaimyoYuko = gcnew DataGridView();
		dgvDaimyoYuko->Size = tpDaimyoYuko->Size;
		dgvDaimyoYuko->ScrollBars = ::ScrollBars::Both;

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleDaimyoYuko->Length; i++) {

			if ( colTitleDaimyoYuko[i] == "�����E�����E�F�D" ) {
				// �R���{�{�b�N�X�̃I�u�W�F�N�g�� 
				dgvDKYtbc = gcnew DataGridViewComboBoxColumn(); 

				// �^�C�g���������ݒ� 
				dgvDKYtbc->HeaderText = colTitleDaimyoYuko[i];

				dgvDKYtbc->Width = 270;

				// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
				dgvDaimyoYuko->Columns->Add(dgvDKYtbc); 

			} else {
				// �c��̃I�u�W�F�N�g����� 
				DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
				// �^�C�g���������ݒ� 
				dgvtbc->HeaderText = colTitleDaimyoYuko[i]; 
				if ( i <= 1 ) {
					dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
				}
				// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
				dgvDaimyoYuko->Columns->Add(dgvtbc); 
			}

		} 

		dgvDaimyoYuko_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvDaimyoYuko->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvDaimyoYuko_CellValueChanged); 
		dgvDaimyoYuko->DataError += gcnew DataGridViewDataErrorEventHandler(this, &MemoryEditorForm::dgvDaimyoYuko_DataError); 
		dgvDaimyoYuko->CellMouseEnter += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvDaimyoYuko_CellMouseEnter); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpDaimyoYuko->Controls->Add(dgvDaimyoYuko);
	} 

	//DataError�C�x���g�n���h��
	void dgvDaimyoYuko_DataError(Object^ sender, DataGridViewDataErrorEventArgs^ e) {
		e->Cancel = false;
	}

private: 
	void dgvDaimyoYuko_DataImport() {

		dgvDaimyoYuko->Rows->Clear();

		for ( int i=0; i<�ő吔::�喼���::�z��; i++) {

			dgvDaimyoYuko->Rows->Add( 
				i,
				i+1
			); 
		}

	} 

	void dgvDaimyoYuko_CellMouseEnter(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		if ( 0 <= e->ColumnIndex && e->ColumnIndex <= 3 &&
			0 <= e->RowIndex && e->RowIndex < �ő吔::�喼���::�z�� ) {

			String^ headerText = dgvDaimyoYuko->Columns[e->ColumnIndex]->HeaderText;

			int iDaimyoID = Convert::ToInt32(dgvDaimyoYuko[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

			if ( headerText == "�����E�����E�F�D" ) {

				BindingSource^ bs = gcnew BindingSource();

				for ( int iTargetDaimyoYukoID=0; iTargetDaimyoYukoID < �ő吔::�喼���::�z��; iTargetDaimyoYukoID++ ) {
					String^ y_d_k = String::Format("����喼�ԍ�: {0,2} | �F�D: {1,2} | ����:{2} | ����:{3}",
												iTargetDaimyoYukoID + 1,
												Get_�F�D�֌W(iDaimyoID, iTargetDaimyoYukoID),
												Is_�����֌W(iDaimyoID, iTargetDaimyoYukoID) ? "��" : "�~",
												Is_�����֌W(iDaimyoID, iTargetDaimyoYukoID) ? "��" : "�~" );
					bs->Add(y_d_k);

					dgvDKYtbc->DataSource = bs;
				}
			}
		}
	}

	void dgvDaimyoYuko_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvDaimyoYuko->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�喼�ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iDaimyoYukoID = Convert::ToInt32(dgvDaimyoYuko[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvDaimyoYuko[e->ColumnIndex, e->RowIndex]->Value->ToString();
	} 


//-------------------------------------------------- p�喼���i�����j��-------------------------------------------------

//-------------------------------------------------- p�R�c����-------------------------------------------------
private: 

	TabPage^ tpGundan;
	DataGridView^ dgvGundan;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleGundan = {
		"�y�z��p�z", 
		"�R�c�ԍ�",
		"�O�̌R�c�y�R�c�ԍ��z",
		"���̌R�c�y�R�c�ԍ��z",
		"��������y��ԍ��z",
		"�����喼�y�喼�ԍ��z",
		"�s����",
		"��",
		"��",
		"�n",
		"�S�C",
		"�R�c�����ԍ�",
		"Get_�R�c����",
		"Get_�R�c��E",
		"Get_�R�t�����ԍ��y�z��p�z",
		"Get_�R�c�����鐔",
		"Is_�v���C���S���R�c",
	}; 

	void dgvGundan_Init() {
		tpGundan = gcnew TabPage();
		tpGundan->Text = "p�R�c���";
		tpGundan->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpGundan);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvGundan = gcnew DataGridView();
		dgvGundan->Size = tpGundan->Size;
		dgvGundan->ScrollBars = ::ScrollBars::Both;
		dgvGundan->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleGundan->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleGundan[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvGundan->Columns->Add(dgvtbc); 
		} 

		dgvGundan_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvGundan->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvGundan_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpGundan->Controls->Add(dgvGundan);
	} 

private: 
	void dgvGundan_DataImport() { 

		dgvGundan->Rows->Clear();

		for ( int i=0; i<�ő吔::�R�c���::�z��; i++) { 
			dgvGundan->Rows->Add( 
				i,
				i+1,
				p�R�c���[i].�O�̌R�c�y�R�c�ԍ��z,
				p�R�c���[i].���̌R�c�y�R�c�ԍ��z,
				p�R�c���[i].��������y��ԍ��z,
				p�R�c���[i].�����喼�y�喼�ԍ��z,
				p�R�c���[i].�s����,
				p�R�c���[i].��,
				p�R�c���[i].��,
				p�R�c���[i].�n,
				p�R�c���[i].�S�C,
				p�R�c���[i].�R�c�����ԍ�,
				Get_�R�c����(i),
				Get_�R�c��E(i),
				Get_�R�t�����ԍ��y�z��p�z(i),
				Get_�R�c�����鐔(i),
				Is_�v���C���S���R�c(i)
				
			); 
		} 
	} 

	void dgvGundan_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvGundan->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�R�c�ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iGundanID = Convert::ToInt32(dgvGundan[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvGundan[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "�O�̌R�c�y�R�c�ԍ��z") { 
			p�R�c���[iGundanID].�O�̌R�c�y�R�c�ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "���̌R�c�y�R�c�ԍ��z") { 
			p�R�c���[iGundanID].���̌R�c�y�R�c�ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "��������y��ԍ��z") { 
			p�R�c���[iGundanID].��������y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�����喼�y�喼�ԍ��z") { 
			p�R�c���[iGundanID].�����喼�y�喼�ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�s����") { 
			p�R�c���[iGundanID].�s���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "��") { 
			p�R�c���[iGundanID].�� = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "��") { 
			p�R�c���[iGundanID].�� = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�n") { 
			p�R�c���[iGundanID].�n = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�S�C") { 
			p�R�c���[iGundanID].�S�C = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�R�c�����ԍ�") { 
			p�R�c���[iGundanID].�R�c�����ԍ� = Convert::ToByte(svalue); 
		} 
	} 
//-------------------------------------------------- p�R�c����-------------------------------------------------



//-------------------------------------------------- p�����-------------------------------------------------
private: 

	TabPage^ tpCastle;
	DataGridView^ dgvCastle;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleCastle = {
		"�y�z��p�z", 
		"��ԍ�",
		"Get_�閼",
		"�O�̏�y��ԍ��z",
		"���̏�y��ԍ��z",
		"���y�����ԍ��z",
		"_�Q�l�擪�����y�����ԍ��z",
		"�����R�c�y�R�c�ԍ��z",
		"��s",
		"�΍�",
		"����",
		"�l��",
		"����",
		"������",
		"����",
		"�{��",
		"�b��",
		"�n�Y�n",
		"�`",
		"���ۍ`",
		"��R",
		"���R",
		"��R����",
		"��G�w�i",
		"Get_���",
		"����",
		"_���O�ύX"
	}; 

	void dgvCastle_Init() {
		tpCastle = gcnew TabPage();
		tpCastle->Text = "p����";
		tpCastle->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpCastle);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvCastle = gcnew DataGridView();
		dgvCastle->Size = tpCastle->Size;
		dgvCastle->ScrollBars = ::ScrollBars::Both;
		dgvCastle->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleCastle->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleCastle[i]; 

			if ( i <= 2 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvCastle->Columns->Add(dgvtbc); 
		} 

		dgvCastle_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvCastle->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvCastle_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpCastle->Controls->Add(dgvCastle);
	} 

private: 
	void dgvCastle_DataImport() { 

		dgvCastle->Rows->Clear();

		for ( int i=0; i<�ő吔::����::�z��; i++) { 
			dgvCastle->Rows->Add( 
				i,
				i+1,
				gcnew String(Get_�閼(i).c_str()),

				p����[i].�O�̏�y��ԍ��z,
				p����[i].���̏�y��ԍ��z,
				p����[i].���y�����ԍ��z,
				p����[i]._�Q�l�擪�����y�����ԍ��z,
				p����[i].�����R�c�y�R�c�ԍ��z,
				p����[i].��s,
				p����[i].�΍�,
				p����[i].����,
				p����[i].�l��,
				p����[i].����,
				p����[i].������,
				p����[i].����,
				p����[i].�{��,
				p����[i].�b��,
				p����[i].�n�Y�n,
				p����[i].�`,
				p����[i].���ۍ`,
				p����[i].��R,
				p����[i].���R,
				p����[i].��R����,
				p����[i].��G�w�i,
				gcnew String(Get_���(i).c_str()),
				p����[i].����,
				p����[i]._���O�ύX
			
			); 
		} 
	} 

	void dgvCastle_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvCastle->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A��ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iCastleID = Convert::ToInt32(dgvCastle[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvCastle[e->ColumnIndex, e->RowIndex]->Value->ToString();



		if (headerText == "Get_�閼") { 
			char szName[32] = "";
			wsprintf(szName, "%s", svalue);
			Set_�閼( iCastleID, szName );
		} 
		else if (headerText == "�O�̏�y��ԍ��z") { 
			p����[iCastleID].�O�̏�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "���̏�y��ԍ��z") { 
			p����[iCastleID].���̏�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "���y�����ԍ��z") { 
			p����[iCastleID].���y�����ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "_�Q�l�擪�����y�����ԍ��z") { 
			p����[iCastleID]._�Q�l�擪�����y�����ԍ��z = Convert::ToUInt16(svalue); 
		} 

		else if (headerText == "�����R�c�y�R�c�ԍ��z") { 
			p����[iCastleID].�����R�c�y�R�c�ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "��s") { 
			p����[iCastleID].��s = Convert::ToByte(svalue); 
		} 
		else if (headerText == "����") { 
			p����[iCastleID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�l��") { 
			p����[iCastleID].�l�� = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "����") { 
			p����[iCastleID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "������") { 
			p����[iCastleID].������ = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "����") { 
			p����[iCastleID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�{��") { 
			p����[iCastleID].�{�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�b��") { 
			p����[iCastleID].�b�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�n�Y�n") { 
			p����[iCastleID].�n�Y�n = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�`") { 
			p����[iCastleID].�` = Convert::ToByte(svalue); 
		} 
		else if (headerText == "���ۍ`") { 
			p����[iCastleID].���ۍ` = Convert::ToByte(svalue); 
		} 
		else if (headerText == "��R") { 
			p����[iCastleID].��R = Convert::ToByte(svalue); 
		} 

		else if (headerText == "���R") { 
			p����[iCastleID].���R = Convert::ToByte(svalue); 
		} 
		else if (headerText == "��R����") { 
			p����[iCastleID].��R���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "��G�w�i") { 
			p����[iCastleID].��G�w�i = Convert::ToByte(svalue); 
		} 
		else if (headerText == "����") { 
			p����[iCastleID].���� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "_���O�ύX") { 
			p����[iCastleID]._���O�ύX = Convert::ToByte(svalue); 
		} 
	} 
//-------------------------------------------------- p�����-------------------------------------------------


//-------------------------------------------------- p��t������-------------------------------------------------
private: 

	TabPage^ tpCastleAdd;
	DataGridView^ dgvCastleAdd;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleCastleAdd = {

		"�y�z��p�z", 
		"��ԍ�",
		"�����n��y�n��ԍ��z",
		"�ő�΍���10",
		"�ő古�ƒl",
		"�w�ʒu",
		"�x�ʒu",
		"��O���b�h�ʒu.�w",
		"��O���b�h�ʒu.�x",
		"Get_�s���{����"
	}; 

	void dgvCastleAdd_Init() {
		tpCastleAdd = gcnew TabPage();
		tpCastleAdd->Text = "p��t�����";
		tpCastleAdd->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpCastleAdd);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvCastleAdd = gcnew DataGridView();
		dgvCastleAdd->Size = tpCastleAdd->Size;
		dgvCastleAdd->ScrollBars = ::ScrollBars::Both;
		dgvCastleAdd->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleCastleAdd->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleCastleAdd[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvCastleAdd->Columns->Add(dgvtbc); 
		} 

		dgvCastleAdd_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvCastleAdd->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvCastleAdd_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpCastleAdd->Controls->Add(dgvCastleAdd);
	} 

private: 
	void dgvCastleAdd_DataImport() { 

		dgvCastleAdd->Rows->Clear();

		for ( int i=0; i<�ő吔::����::�z��; i++) {

			��O���b�h�ʒu�^ pos = Get_��O���b�h�ʒu(i);
			int i�s���{���ԍ� = Get_��s���{���ԍ�(i);

			dgvCastleAdd->Rows->Add( 
				i,
				i+1,

				p��t�����[i].�����n��y�n��ԍ��z,
				p��t�����[i].�ő�΍���10,
				p��t�����[i].�ő古�ƒl,
				p��t�����[i].�w�ʒu,
				p��t�����[i].�x�ʒu,
				pos.�w,
				pos.�x,
				gcnew String( Get_�s���{����(i�s���{���ԍ�).c_str() )
			); 
		} 
	} 

	void dgvCastleAdd_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvCastleAdd->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A��ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iCastleID = Convert::ToInt32(dgvCastleAdd[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvCastleAdd[e->ColumnIndex, e->RowIndex]->Value->ToString();



		if (headerText == "�����n��y�n��ԍ��z") { 
			p��t�����[iCastleID].�����n��y�n��ԍ��z = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�ő�΍���10") { 
			p��t�����[iCastleID].�ő�΍���10 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�ő古�ƒl") { 
			p��t�����[iCastleID].�ő古�ƒl = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�w�ʒu") { 
			p��t�����[iCastleID].�w�ʒu = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�x�ʒu") { 
			p��t�����[iCastleID].�x�ʒu = Convert::ToByte(svalue); 
		} 
	} 
//-------------------------------------------------- p��t������-------------------------------------------------


//-------------------------------------------------- p�n�����-------------------------------------------------
private: 

	TabPage^ tpChiiki;
	DataGridView^ dgvChiiki;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleChiiki = {

		"�y�z��p�z", 
		"�n��ԍ�",

		"Get_�n�於",
		"�n����̏�P",
		"�n����̏�Q",
		"�n����̏�R",
		"�n����̏�S",
		"�n����̏�T",
		"�n����̏�U",
		"�n����̏�V",
		"�n����̏�W",
	}; 

	void dgvChiiki_Init() {
		tpChiiki = gcnew TabPage();
		tpChiiki->Text = "p�n����";
		tpChiiki->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpChiiki);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvChiiki = gcnew DataGridView();
		dgvChiiki->Size = tpChiiki->Size;
		dgvChiiki->ScrollBars = ::ScrollBars::Both;
		dgvChiiki->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleChiiki->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleChiiki[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvChiiki->Columns->Add(dgvtbc); 
		} 

		dgvChiiki_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvChiiki->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvChiiki_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpChiiki->Controls->Add(dgvChiiki);
	} 

private: 
	void dgvChiiki_DataImport() { 

		dgvChiiki->Rows->Clear();

		for ( int i=0; i<�ő吔::�n����::�z��; i++) {

			��O���b�h�ʒu�^ pos = Get_��O���b�h�ʒu(i);
			int i�s���{���ԍ� = Get_��s���{���ԍ�(i);


			dgvChiiki->Rows->Add( 
				i,
				i+1,
				gcnew String( Get_�n�於(i).c_str() ),

				p�n����[i].�n����̏�P�y��ԍ��z,
				p�n����[i].�n����̏�Q�y��ԍ��z,
				p�n����[i].�n����̏�R�y��ԍ��z,
				p�n����[i].�n����̏�S�y��ԍ��z,
				p�n����[i].�n����̏�T�y��ԍ��z,
				p�n����[i].�n����̏�U�y��ԍ��z,
				p�n����[i].�n����̏�V�y��ԍ��z,
				p�n����[i].�n����̏�W�y��ԍ��z
			); 
		} 
	} 

	void dgvChiiki_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvChiiki->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A��ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iChiikiID = Convert::ToInt32(dgvChiiki[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvChiiki[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "�n����̏�P�y��ԍ��z") { 
			p�n����[iChiikiID].�n����̏�P�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�n����̏�Q�y��ԍ��z") { 
			p�n����[iChiikiID].�n����̏�Q�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�n����̏�R�y��ԍ��z") { 
			p�n����[iChiikiID].�n����̏�R�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�n����̏�S�y��ԍ��z") { 
			p�n����[iChiikiID].�n����̏�S�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�n����̏�T�y��ԍ��z") { 
			p�n����[iChiikiID].�n����̏�T�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�n����̏�U�y��ԍ��z") { 
			p�n����[iChiikiID].�n����̏�U�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�n����̏�V�y��ԍ��z") { 
			p�n����[iChiikiID].�n����̏�V�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�n����̏�W�y��ԍ��z") { 
			p�n����[iChiikiID].�n����̏�W�y��ԍ��z = Convert::ToUInt16(svalue); 
		} 
	} 
//-------------------------------------------------- p�n�����-------------------------------------------------


//-------------------------------------------------- p���ʏ���-------------------------------------------------
private: 

	TabPage^ tpKanni;
	DataGridView^ dgvKanni;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleKanni = {
		"�y�z��p�z", 
		"���ʔԍ�",
		"Get_���ʖ�",
		"�ʊK",
		"���L�����y�����ԍ��z",
		"�㏸�l",
	}; 

	void dgvKanni_Init() {
		tpKanni = gcnew TabPage();
		tpKanni->Text = "p���ʏ��";
		tpKanni->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpKanni);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvKanni = gcnew DataGridView();
		dgvKanni->Size = tpKanni->Size;
		dgvKanni->ScrollBars = ::ScrollBars::Both;
		dgvKanni->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleKanni->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleKanni[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvKanni->Columns->Add(dgvtbc); 
		} 

		dgvKanni_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvKanni->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvKanni_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpKanni->Controls->Add(dgvKanni);
	} 

private: 
	void dgvKanni_DataImport() {

		dgvKanni->Rows->Clear();

		for ( int i=0; i<�ő吔::���ʏ��::�z��; i++) { 
			dgvKanni->Rows->Add( 
				i,
				i+1,
				gcnew String(Get_���ʖ�(i).c_str()),
				p���ʏ��[i].�ʊK,
				p���ʏ��[i].���L�����y�����ԍ��z,
				p���ʏ��[i].�㏸�l
			); 
		} 
	} 

	void dgvKanni_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvKanni->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�喼�ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iKanniID = Convert::ToInt32(dgvKanni[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvKanni[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "Get_���ʖ�") {
			char szKanni[32] = "";
			wsprintf(szKanni, "%s", svalue);
			Set_���ʖ�(iKanniID, szKanni);
		} 
		else if (headerText == "�ʊK") { 
			p���ʏ��[iKanniID].�ʊK = Convert::ToByte(svalue); 
		} 
		else if (headerText == "���L�����y�����ԍ��z") { 
			p���ʏ��[iKanniID].���L�����y�����ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�㏸�l") { 
			p���ʏ��[iKanniID].�㏸�l = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p���ʏ���-------------------------------------------------


//-------------------------------------------------- p�ƕ����-------------------------------------------------
private: 

	TabPage^ tpKahou;
	DataGridView^ dgvKahou;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleKahou = {
		"�y�z��p�z", 
		"�ƕ�ԍ�",
		"Get_�ƕ�",
		"�ƕ󕪗�",
		"�ƕ�摜",
		"���L�����y�����ԍ��z",
		"�㏸�l",
		"���o��",
		"����",
	}; 

	void dgvKahou_Init() {
		tpKahou = gcnew TabPage();
		tpKahou->Text = "p�ƕ���";
		tpKahou->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpKahou);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvKahou = gcnew DataGridView();
		dgvKahou->Size = tpKahou->Size;
		dgvKahou->ScrollBars = ::ScrollBars::Both;
		dgvKahou->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleKahou->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleKahou[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvKahou->Columns->Add(dgvtbc); 
		} 

		dgvKahou_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvKahou->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvKahou_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpKahou->Controls->Add(dgvKahou);
	} 

private: 
	void dgvKahou_DataImport() {

		dgvKahou->Rows->Clear();

		for ( int i=0; i<�ő吔::�ƕ���::�z��; i++) { 
			dgvKahou->Rows->Add( 
				i,
				i+1,
				gcnew String(Get_�ƕ�(i).c_str()),
				p�ƕ���[i].�ƕ󕪗�,
				p�ƕ���[i].�ƕ�摜,
				p�ƕ���[i].���L�����y�����ԍ��z,
				p�ƕ���[i].�㏸�l,
				p�ƕ���[i].���o��,
				p�ƕ���[i].����
				); 
		} 
	} 

	void dgvKahou_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvKahou->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�喼�ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iKahouID = Convert::ToInt32(dgvKahou[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvKahou[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "Get_�ƕ�") {
			char szKahou[32] = "";
			wsprintf(szKahou, "%s", svalue);
			Set_�ƕ�(iKahouID, szKahou);
		} 

		else if (headerText == "�ƕ󕪗�") { 
			p�ƕ���[iKahouID].�ƕ󕪗� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "�ƕ�摜") { 
			p�ƕ���[iKahouID].�ƕ�摜 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "���L�����y�����ԍ��z") { 
			p�ƕ���[iKahouID].���L�����y�����ԍ��z = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "�㏸�l") { 
			p�ƕ���[iKahouID].�㏸�l = Convert::ToByte(svalue); 
		} 
		else if (headerText == "���o��") { 
			p�ƕ���[iKahouID].���o�� = Convert::ToByte(svalue); 
		} 
		else if (headerText == "����") { 
			p�ƕ���[iKahouID].���� = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p�ƕ����-------------------------------------------------


//-------------------------------------------------- p�������-------------------------------------------------
private: 

	TabPage^ tpSoba;
	DataGridView^ dgvSoba;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleSoba = {
		"�đ���", 
		"�S�C����",
		"�n����",
		"������",
	}; 


	void dgvSoba_Init() {
		tpSoba = gcnew TabPage();
		tpSoba->Text = "p������";
		tpSoba->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpSoba);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvSoba = gcnew DataGridView();
		dgvSoba->Size = tpSoba->Size;
		dgvSoba->ScrollBars = ::ScrollBars::Both;
		dgvSoba->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleSoba->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleSoba[i]; 

			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvSoba->Columns->Add(dgvtbc); 
		} 

		dgvSoba_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvSoba->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvSoba_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpSoba->Controls->Add(dgvSoba);
	} 

private: 
	void dgvSoba_DataImport() { 

		dgvSoba->Rows->Clear();

		dgvSoba->Rows->Add(
			p������.�đ���,
			p������.�S�C����,
			p������.�n����,
			p������.������
		); 
	} 

	void dgvSoba_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvSoba->Columns[e->ColumnIndex]->HeaderText;

		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A����ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iBushouID = Convert::ToInt32(dgvSoba[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvSoba[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "�đ���") { 
			Set_�đ���( Convert::ToUInt16(svalue) ); 
		} 
		else if (headerText == "�S�C����") { 
			Set_�S�C����( Convert::ToUInt16(svalue) ); 
		} 
		else if (headerText == "�n����") { 
			Set_�n����( Convert::ToUInt16(svalue) ); 
		} 
		else if (headerText == "������") { 
			Set_������( Convert::ToUInt16(svalue) ); 
		} 
	} 


//-------------------------------------------------- p�������-------------------------------------------------



//-------------------------------------------------- p�����i�����j��-------------------------------------------------
private: 

	TabPage^ tpBattleUnit;
	DataGridView^ dgvBattleUnit;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleBattleUnit = {
		"�����ԍ�",
		"�s���c�̋A��",
		"�w�b�N�X.�w",
		"�w�b�N�X.�x",
		"�ړ��͎c��",
		"�����������",
		"Is_�����s���ρs�푈��ʁt",
		"p�����ːЏ��[ix].�펀",
		"p�����ːЏ��[ix].�ދp",
		"�o�w��",
		"�\�����}�b�v�ɏo�w��",
	}; 

	void dgvBattleUnit_Init() {
		tpBattleUnit = gcnew TabPage();
		tpBattleUnit->Text = "�����i�����j";
		tpBattleUnit->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpBattleUnit);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvBattleUnit = gcnew DataGridView();
		dgvBattleUnit->Size = tpBattleUnit->Size;
		dgvBattleUnit->ScrollBars = ::ScrollBars::Both;
		dgvBattleUnit->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleBattleUnit->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleBattleUnit[i]; 

			if ( i == 0 ) {
				dgvtbc->Frozen = true; // �O�R���炢�͌Œ肷��B
			}
			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvBattleUnit->Columns->Add(dgvtbc); 
		} 

		dgvBattleUnit_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvBattleUnit->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvBattleUnit_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpBattleUnit->Controls->Add(dgvBattleUnit);
	} 

private: 
	void dgvBattleUnit_DataImport() {

		dgvBattleUnit->Rows->Clear();

		�ԍ����X�g�^ �������X�g = Get_�����ԍ����X�g�y�z��p�z();

		for each ( int iBushouID in �������X�g ) {

			�w�b�N�X�ʒu�^ pos = Get_�����̖��w�b�N�X�ʒu(iBushouID);

			�ԍ����X�g�^ �o�w�� = Get_�o�w���̕����ԍ����X�g�y�z��p�z();
			�ԍ����X�g�^ ����� = Get_�o�w���̕����ԍ����X�g�y�z��p�z�s�\�����}�b�v�t();

			int cnt�o�w�� = std::count(�o�w��.begin(), �o�w��.end(), iBushouID);
			int cnt����� = std::count(�����.begin(), �����.end(), iBushouID);

			dgvBattleUnit->Rows->Add(
				iBushouID + 1,
				Get_�s���c�̋A��(iBushouID),
				pos.�w,
				pos.�x,
				Get_�ړ��c��(iBushouID),
				(int)Get_�����������(iBushouID),
				(int)Is_�����s���ρs�푈��ʁt(iBushouID),
				p�����ːЏ��[iBushouID].�펀,
				p�����ːЏ��[iBushouID].�ދp,
				(int)(cnt�o�w��>0),
				(int)(cnt�����>0)
			);

		}
	} 

	void dgvBattleUnit_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvBattleUnit->Columns[e->ColumnIndex]->HeaderText;

		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�喼�ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iBattleUnitID = Convert::ToInt32(dgvBattleUnit[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 
		int iBushouID = iBattleUnitID-1;

		String^ svalue = dgvBattleUnit[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "�����������") {
			if ( 0 <= iBushouID && iBushouID < �ő吔::�������::�z��) {
				Set_�����������( iBushouID, Convert::ToUInt16(svalue) ); 
			}
		} 
	} 


//-------------------------------------------------- p�����i�����j��-------------------------------------------------



//-------------------------------------------------- p���ݒ����-------------------------------------------------
private: 

	TabPage^ tpSettings;
	DataGridView^ dgvSettings;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleSettings = {
		"���ʉ�", 
		"���y",
		"�����̐푈",
		"���[�r�[",
		"�\�����x",
		"��Փx",
	}; 


	void dgvSettings_Init() {
		tpSettings = gcnew TabPage();
		tpSettings->Text = "p���ݒ���";
		tpSettings->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpSettings);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvSettings = gcnew DataGridView();
		dgvSettings->Size = tpSettings->Size;
		dgvSettings->ScrollBars = ::ScrollBars::Both;
		dgvSettings->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleSettings->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleSettings[i]; 

			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvSettings->Columns->Add(dgvtbc); 
		} 

		dgvSettings_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvSettings->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvSettings_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpSettings->Controls->Add(dgvSettings);
	} 

private: 
	void dgvSettings_DataImport() { 

		dgvSettings->Rows->Clear();

		dgvSettings->Rows->Add(
			p���ݒ���.���ʉ�,
			p���ݒ���.���y,
			p���ݒ���.�����̐푈,
			BOOL(p���ݒ���.���[�r�[ == ���[�r�[::�n�m),
			p���ݒ���.�\�����x,
			p���ݒ���.��Փx
		); 
	} 

	void dgvSettings_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvSettings->Columns[e->ColumnIndex]->HeaderText;

		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�����ݒ�ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iBushouID = Convert::ToInt32(dgvSettings[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvSettings[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "���ʉ�") { 
			p���ݒ���.���ʉ� = Convert::ToByte(svalue);
		} 
		else if (headerText == "���y") { 
			p���ݒ���.���y = Convert::ToByte(svalue);
		} 
		else if (headerText == "�����̐푈") { 
			p���ݒ���.�����̐푈 = Convert::ToByte(svalue);
		} 
		else if (headerText == "���[�r�[") { 
			p���ݒ���.���[�r�[ = int(Convert::ToByte(svalue) == ���[�r�[::�n�m);
		} 
		else if (headerText == "�\�����x") { 
			p���ݒ���.�\�����x = Convert::ToByte(svalue);
		} 
		else if (headerText == "��Փx") { 
			p���ݒ���.��Փx = Convert::ToByte(svalue);
		} 
	} 

//-------------------------------------------------- p���ݒ����-------------------------------------------------


//-------------------------------------------------- p���ݒ�g������-------------------------------------------------
private: 

	TabPage^ tpSettingsEx;
	DataGridView^ dgvSettingsEx;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleSettingsEx = {
		"�N���\��", 
		"�\���ʒu�L��",
		"�\���ؑփ}�b�v",
		"�푈�p�x",
		"�v���p�x",
		"���S�p�x",
		"�����̐푈",
		"�ҏW�@�\",
		"���\��",
		"�����s���u��",
		"�P�����u��",
	}; 


	void dgvSettingsEx_Init() {
		tpSettingsEx = gcnew TabPage();
		tpSettingsEx->Text = "p���ݒ�g�����";
		tpSettingsEx->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpSettingsEx);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvSettingsEx = gcnew DataGridView();
		dgvSettingsEx->Size = tpSettingsEx->Size;
		dgvSettingsEx->ScrollBars = ::ScrollBars::Both;
		dgvSettingsEx->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleSettingsEx->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleSettingsEx[i]; 

			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvSettingsEx->Columns->Add(dgvtbc); 
		} 

		dgvSettingsEx_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvSettingsEx->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvSettingsEx_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpSettingsEx->Controls->Add(dgvSettingsEx);
	} 

private: 
	void dgvSettingsEx_DataImport() { 

		dgvSettingsEx->Rows->Clear();

		dgvSettingsEx->Rows->Add(
			p���ݒ�g�����.�N���\��,
			p���ݒ�g�����.�\���ʒu�L��,
			p���ݒ�g�����.�\���ؑփ}�b�v,
			p���ݒ�g�����.�푈�p�x,
			p���ݒ�g�����.�v���p�x,
			p���ݒ�g�����.���S�p�x,
			p���ݒ�g�����.�����̐푈,
			p���ݒ�g�����.�ҏW�@�\,
			p���ݒ�g�����.���\��,
			p���ݒ�g�����.�����s���u��,
			p���ݒ�g�����.�P�����u��
		); 
	} 

	void dgvSettingsEx_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvSettingsEx->Columns[e->ColumnIndex]->HeaderText;

		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A�����ݒ�ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iBushouID = Convert::ToInt32(dgvSettingsEx[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvSettingsEx[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "�N���\��") { 
			p���ݒ�g�����.�N���\�� = Convert::ToByte(svalue);
		} 
		else if (headerText == "�\���ʒu�L��") { 
			p���ݒ�g�����.�\���ʒu�L�� = Convert::ToByte(svalue);
		} 
		else if (headerText == "�\���ؑփ}�b�v") { 
			p���ݒ�g�����.�\���ؑփ}�b�v = Convert::ToByte(svalue);
		} 
		else if (headerText == "�푈�p�x") { 
			p���ݒ�g�����.�푈�p�x = Convert::ToByte(svalue);
		} 
		else if (headerText == "�v���p�x") { 
			p���ݒ�g�����.�v���p�x = Convert::ToByte(svalue);
		} 
		else if (headerText == "���S�p�x") { 
			p���ݒ�g�����.���S�p�x = Convert::ToByte(svalue);
		} 
		else if (headerText == "�����̐푈") { 
			p���ݒ�g�����.�����̐푈 = Convert::ToByte(svalue);
		} 
		else if (headerText == "�ҏW�@�\") { 
			p���ݒ�g�����.�ҏW�@�\ = Convert::ToByte(svalue);
		} 
		else if (headerText == "���\��") { 
			p���ݒ�g�����.���\�� = Convert::ToByte(svalue);
		} 
		else if (headerText == "�����s���u��") { 
			p���ݒ�g�����.�����s���u�� = Convert::ToByte(svalue);
		} 
		else if (headerText == "�P�����u��") { 
			p���ݒ�g�����.�P�����u�� = Convert::ToByte(svalue);
		} 
	} 

//-------------------------------------------------- p���ݒ�g������-------------------------------------------------





//-------------------------------------------------- p�V�C����-------------------------------------------------
private: 

	TabPage^ tpWeather;
	DataGridView^ dgvWeather;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleWeather = {
		"Get_�V�C",
		""
	}; 

	void dgvWeather_Init() {
		tpWeather = gcnew TabPage();
		tpWeather->Text = "p�V�C���";
		tpWeather->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpWeather);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvWeather = gcnew DataGridView();
		dgvWeather->Size = tpWeather->Size;
		dgvWeather->ScrollBars = ::ScrollBars::Both;
		dgvWeather->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleWeather->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleWeather[i]; 

			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvWeather->Columns->Add(dgvtbc); 
		} 

		dgvWeather_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvWeather->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvWeather_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpWeather->Controls->Add(dgvWeather);
	} 

private: 
	void dgvWeather_DataImport() {
		dgvWeather[0, 0]->Value = Get_�V�C();
	} 

	void dgvWeather_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvWeather->Columns[e->ColumnIndex]->HeaderText;

		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A��ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iCastleID = Convert::ToInt32(dgvWeather[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvWeather[e->ColumnIndex, e->RowIndex]->Value->ToString();
	} 
//-------------------------------------------------- p�V�C����-------------------------------------------------


//-------------------------------------------------- p���y����-------------------------------------------------
private: 

	TabPage^ tpBGM;
	DataGridView^ dgvBGM;  // �f�[�^�O���b�h�r���[�^�B �G�N�Z���̂悤�Ɋi�q��̃f�[�^��\���ł��邽�߁A���ɂ悭���p�����B 

	// .NET��String^�^��v�f�Ƃ���A.NET�̔z��array^�^�B 
	static cli::array<String^>^ colTitleBGM = {
		"Get_�Đ����y�ԍ�",
		""
	}; 

	void dgvBGM_Init() {
		tpBGM = gcnew TabPage();
		tpBGM->Text = "p���y���";
		tpBGM->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpBGM);


		// �f�[�^�O���b�h�S�̂̃C���X�^���X 
		dgvBGM = gcnew DataGridView();
		dgvBGM->Size = tpBGM->Size;
		dgvBGM->ScrollBars = ::ScrollBars::Both;
		dgvBGM->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // �e�J�����̉����̓R���e���c�ɉ����Ď������� 

		// -------------- ��������f�[�^�O���b�h�́u�c��ɑ�������J�����u�W�F�N�g�v�ƁA�u�e�J�����̃^�C�g���v�̕�������Z�b�e�B���O����B 

		for (int i=0; i < colTitleBGM->Length; i++) {

			// �c��̃I�u�W�F�N�g����� 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// �^�C�g���������ݒ� 
			dgvtbc->HeaderText = colTitleBGM[i]; 

			// �O���b�h�r���[�ɏc��Ƃ��Ēǉ��B 
			dgvBGM->Columns->Add(dgvtbc); 
		} 

		dgvBGM_DataImport(); 

		// �f�[�^�O���b�h�̃Z����ҏW�������̃C�x���g�n���h����o�^����B 
		dgvBGM->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvBGM_CellValueChanged); 

		// �f�[�^�O���b�h�r���[���t�H�[���ɏ������ 
		tpBGM->Controls->Add(dgvBGM);
	} 

private: 
	void dgvBGM_DataImport() {
		dgvBGM[0, 0]->Value = Get_�Đ����y�ԍ�();
	} 

	void dgvBGM_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// �C�x���g�����������I�u�W�F�N�g(=sender) �̓f�[�^�O���b�h�r���[�^�Ȃ̂ŁA�f�[�^�O���b�h�r���[�^�Ƃ��Ď󂯎���āc 

		String^ headerText = dgvBGM->Columns[e->ColumnIndex]->HeaderText;



		// �ҏW�����Z���́u�s�v�̈�ԍ��̃J�����ł���uindexID(=0���)�v�ɓ����Ă���l���A��ԍ��y�z��p�z�ł���B 
		// ���[�U����œ��͂������̂͑S�ĕ�����ɂȂ��Ă��܂��B 
		// ����v���O��������DgvDataImport�ł͍ŏ��͐��l�œ���Ă����B 
		// ����āA�ǂ̂悤�ȃf�[�^�^�ł��ǂ��悤�ɁAToString�ɂ���Ă��ׂĕ�����ɒ�������AConvert::***�ɂ���āA�����^�ɂ���B 
		int iCastleID = Convert::ToInt32(dgvBGM[0, e->RowIndex]->Value->ToString()); // indexID����ԍ�������column��0 

		String^ svalue = dgvBGM[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "Get_�Đ����y�ԍ�") {
			if ( svalue == "" ) {
				���y��~();
			} else {
				���y�Đ�( Convert::ToByte(svalue) ); 
			}
		} 
	} 
//-------------------------------------------------- p���y����-------------------------------------------------


};

