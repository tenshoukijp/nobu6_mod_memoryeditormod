#pragma once

#include "ModMode.h"

using namespace System;
using namespace System::Windows::Forms;




ref class MemoryEditorForm : public Form {
public:
	static MemoryEditorForm^ meForm = nullptr; // 自分自身のグローバル変数

	TabControl^ tcME;	// 全体で１つになってるタブコントロール。TabPage型を追加してく


public: 
	MemoryEditorForm() {
		// フォームにかかわるものの初期化等
		this->Text = "MemoryEditorMod";
		this->Width = 800;
		this->Height = 600;

		SetFormIcon();

		SetTabControl();

		this->KeyPreview = true; // 各コントロールのキー入力は全てフォームも受け取る

		this->Shown += gcnew EventHandler(this, &MemoryEditorForm::meForm_Shown);
		this->Resize += gcnew EventHandler(this, &MemoryEditorForm::meForm_Resize);
		this->KeyDown +=  gcnew KeyEventHandler(this, &MemoryEditorForm::meForm_KeyDown);


		meForm_Resize(nullptr, nullptr);
	}

	void SetFormIcon() {
		// このプロジェクトのアセンブリのタイプを取得。
		System::Reflection::Assembly^ prj_assebmly = GetType()->Assembly;
		System::Resources::ResourceManager^ r = gcnew System::Resources::ResourceManager(String::Format("{0}.MemoryEditorMod", prj_assebmly->GetName()->Name), prj_assebmly);


		System::Drawing::Icon^ iconform = (System::Drawing::Icon^)(r->GetObject("MemoryEditorIcon"));
		this->Icon = iconform;
	}

	// タブコントロールの初期化。間に、各データグリッドビューへのデータ流し込み処理が入り込む
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


	// タブを切り替えた時
	void tcME_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
		int iTabIndex = tcME->SelectedIndex;
		TabPage^ tpCur = tcME->TabPages[iTabIndex];

		if ( tpCur->Text == "p年情報" ) {
			dgvYear_DataImport();
		}
		else if ( tpCur->Text == "pターン情報" ) {
			dgvTurn_DataImport();
		}
		else if ( tpCur->Text == "p武将戸籍情報" ) {
			dgvBushouName_DataImport();
		}
		else if ( tpCur->Text == "p武将情報" ) {
			dgvBushou_DataImport();
		}
		else if ( tpCur->Text == "p大名情報" ) {
			dgvDaimyo_DataImport();
		}
		else if ( tpCur->Text == "p大名情報（同盟）" ) {
			dgvDaimyoYuko_DataImport();
		}
		else if ( tpCur->Text == "p軍団情報" ) {
			dgvGundan_DataImport();
		}
		else if ( tpCur->Text == "p城情報" ) {
			dgvCastle_DataImport();
		}
		else if ( tpCur->Text == "p城付加情報" ) {
			dgvCastleAdd_DataImport();
		}
		else if ( tpCur->Text == "p地域情報" ) {
			dgvChiiki_DataImport();
		}
		else if ( tpCur->Text == "p官位情報" ) {
			dgvKanni_DataImport();
		}
		else if ( tpCur->Text == "p家宝情報" ) {
			dgvKahou_DataImport();
		}
		else if ( tpCur->Text == "p相場情報" ) {
			dgvSoba_DataImport();
		}
		else if ( tpCur->Text == "戦場情報（武将）" ) {
			dgvBattleUnit_DataImport();
		}
		else if ( tpCur->Text == "p天気情報" ) {
			dgvWeather_DataImport();
		}
		else if ( tpCur->Text == "p環境設定情報" ) {
			dgvSettings_DataImport();
		}
		else if ( tpCur->Text == "p環境設定拡張情報" ) {
			dgvSettingsEx_DataImport();
		}
		else if ( tpCur->Text == "p音楽情報" ) {
			dgvBGM_DataImport();
		}

		meForm_Resize(sender, e);

	}

private:
	void meForm_Shown(Object^ sender, EventArgs^ e) {
		meForm_Resize(sender, e);
	}

	// ホームサイズを変更した足、タブコントロールのサイズを変更し、さらに各、データグリッドビューの大きさを変更する。
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

	// F5キーが押されたら、該当タブを開いたのと同じ「データ更新」をかます。
	void meForm_KeyDown(Object^ sender, KeyEventArgs^ e) {
		if ( Form::ActiveForm == this && e->KeyCode == ::Keys::F5 ) {
			tcME_SelectedIndexChanged(nullptr, nullptr);
		}
	}

//-------------------------------------------------- p武将戸籍情報編-------------------------------------------------
private: 

	TabPage^ tpBushouName;
	DataGridView^ dgvBushouName;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleBushouName = {
		"【配列用】", 
		"武将番号",
		"Get_名字",
		"Get_名前",
		"顔番号",
		"状態",
		"身分",
		"性別",
		"退却",
		"戦死",
	}; 

	void dgvBushouName_Init() {
		tpBushouName = gcnew TabPage();
		tpBushouName->Text = "p武将戸籍情報";
		tpBushouName->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpBushouName);


		// データグリッド全体のインスタンス 
		dgvBushouName = gcnew DataGridView();
		dgvBushouName->Size = tpBushouName->Size;
		dgvBushouName->ScrollBars = ::ScrollBars::Both;
		dgvBushouName->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleBushouName->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleBushouName[i]; 

			if ( i <= 3 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvBushouName->Columns->Add(dgvtbc); 
		} 

		dgvBushouName_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvBushouName->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvBushouName_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpBushouName->Controls->Add(dgvBushouName);
	} 

private: 
	void dgvBushouName_DataImport() { 
		dgvBushouName->Rows->Clear();

		for ( int i=0; i<最大数::武将情報::配列数; i++) { 
			dgvBushouName->Rows->Add( 
				i,
				i+1,
				gcnew String(Get_名字(i).c_str()), 
				gcnew String(Get_名前(i).c_str()), 
				p武将戸籍情報[i].顔番号,
				p武将戸籍情報[i].状態,
				p武将戸籍情報[i].身分,
				p武将戸籍情報[i].性別,
				p武将戸籍情報[i].退却,
				p武将戸籍情報[i].戦死
			); 
		} 
	} 

	void dgvBushouName_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvBushouName->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、武将番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iBushouID = Convert::ToInt32(dgvBushouName[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvBushouName[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "Get_名字") {
			char szName[32] = "";
			wsprintf(szName, "%s", svalue);
			Set_名字( iBushouID, szName );
		} 
		else if (headerText == "Get_名前") { 
			char szName[32] = "";
			wsprintf(szName, "%s", svalue);
			Set_名前( iBushouID, szName );
		} 
		else if (headerText == "顔番号") { 
			p武将戸籍情報[iBushouID].顔番号 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "状態") { 
			p武将戸籍情報[iBushouID].状態 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "身分") { 
			p武将戸籍情報[iBushouID].身分 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "性別") { 
			p武将戸籍情報[iBushouID].性別 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "退却") { 
			p武将戸籍情報[iBushouID].退却 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "戦死") { 
			p武将戸籍情報[iBushouID].戦死 = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p武将戸籍情報編-------------------------------------------------


//-------------------------------------------------- p武将情報編-------------------------------------------------
private: 

	TabPage^ tpBushou;
	DataGridView^ dgvBushou;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleBushou;

	static cli::array<String^>^ getColTitleBushou() {
		if (iCallDLLMODE == kModeTSMod) {
			cli::array<String^>^ ret = {
				"【配列用】",
				"武将番号",
				"前の武将【武将番号】",
				"次の武将【武将番号】",
				"最大政才",
				"最大戦才",
				"最大智才",
				"政治熟練値",
				"戦闘熟練値",
				"智謀熟練値",
				"魅力",
				"野望",
				"忠誠",
				"勲功",
				"所属血筋",
				"所属大名【大名番号】",
				"所属軍団【軍団番号】",
				"所属居城【城番号】",
				"内応先大名【大名番号】",
				"兵数",
				"訓練",
				"士気",
				"兵態",
				"仕官年数",
				"Get_伴侶武将番号【配列用】",
				"生年",
				"親顔番号",
				"思考",
				"義理",
				"相性",
				"政治適性",
				"戦闘適性",
				"智謀適性",
				"技能一喝",
				"技能暗殺",
				"技能流出",
				"技能煽動",
				"技能流言",
				"技能弁舌",
				"技能焼討",
				"技能挑発",
				"職業",
				"足軽適性",
				"騎馬適性",
				"Get_鉄砲適性",
				"水軍適性",
				"Get_弓適性", // ★ここが加わっている
				"Get_槍適性", // ★ここが加わっている
				"大砲",
				"騎馬鉄砲",
				"鉄甲船",
				"寿命",
				"勇猛",
				"Get_独立",
				"口調",
				"行動済",
				"内応状態",
				"遺恨状態",
				"会見済",
				"Is_プレイヤ担当武将"
			};

			return ret;
		} 
		else {
			cli::array<String^>^ ret = {
				"【配列用】",
				"武将番号",
				"前の武将【武将番号】",
				"次の武将【武将番号】",
				"最大政才",
				"最大戦才",
				"最大智才",
				"政治熟練値",
				"戦闘熟練値",
				"智謀熟練値",
				"魅力",
				"野望",
				"忠誠",
				"勲功",
				"所属血筋",
				"所属大名【大名番号】",
				"所属軍団【軍団番号】",
				"所属居城【城番号】",
				"内応先大名【大名番号】",
				"兵数",
				"訓練",
				"士気",
				"兵態",
				"仕官年数",
				"Get_伴侶武将番号【配列用】",
				"生年",
				"親顔番号",
				"思考",
				"義理",
				"相性",
				"政治適性",
				"戦闘適性",
				"智謀適性",
				"技能一喝",
				"技能暗殺",
				"技能流出",
				"技能煽動",
				"技能流言",
				"技能弁舌",
				"技能焼討",
				"技能挑発",
				"職業",
				"足軽適性",
				"騎馬適性",
				"Get_鉄砲適性",
				"水軍適性",
				"大砲",
				"騎馬鉄砲",
				"鉄甲船",
				"寿命",
				"勇猛",
				"Get_独立",
				"口調",
				"行動済",
				"内応状態",
				"遺恨状態",
				"会見済",
				"Is_プレイヤ担当武将"
			};

			return ret;
		}
	}

	void dgvBushou_Init() {
		// TSModかPluginModかで項目数が異なる
		colTitleBushou = getColTitleBushou();

		tpBushou = gcnew TabPage();
		tpBushou->Text = "p武将情報";
		tpBushou->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpBushou);


		// データグリッド全体のインスタンス 
		dgvBushou = gcnew DataGridView();
		dgvBushou->Size = tpBushou->Size;
		dgvBushou->ScrollBars = ::ScrollBars::Both;
		dgvBushou->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleBushou->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleBushou[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvBushou->Columns->Add(dgvtbc); 
		} 

		dgvBushou_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvBushou->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvBushou_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpBushou->Controls->Add(dgvBushou);
	} 

private: 
	void dgvBushou_DataImport() { 
		dgvBushou->Rows->Clear();

		// TSModかPluginModかで項目数が異なる
		if (iCallDLLMODE == kModeTSMod) {
			// 横列単位で足してゆく、index:0, 姓:1, 名:2, 政治:3 戦闘:4 智謀:5 の順番通り 
			for (int i = 0; i < 最大数::武将情報::配列数; i++) {
				dgvBushou->Rows->Add(
					i,
					i + 1,
					p武将情報[i].前の武将【武将番号】,
					p武将情報[i].次の武将【武将番号】,
					p武将情報[i].最大政才,
					p武将情報[i].最大戦才,
					p武将情報[i].最大智才,
					p武将情報[i].政治熟練値,
					p武将情報[i].戦闘熟練値,
					p武将情報[i].智謀熟練値,
					p武将情報[i].魅力,
					p武将情報[i].野望,
					p武将情報[i].忠誠,
					p武将情報[i].勲功,
					p武将情報[i].所属血筋,
					p武将情報[i].所属大名【大名番号】,
					p武将情報[i].所属軍団【軍団番号】,
					p武将情報[i].所属居城【城番号】,
					p武将情報[i].内応先大名【大名番号】,
					p武将情報[i].兵数,
					p武将情報[i].訓練,
					p武将情報[i].士気,
					p武将情報[i].兵態,
					p武将情報[i].仕官年数,
					Get_伴侶武将番号【配列用】(i),
					p武将情報[i].生年,
					p武将情報[i].親顔番号,
					p武将情報[i].思考,
					p武将情報[i].義理,
					p武将情報[i].相性,
					p武将情報[i].政治適性,
					p武将情報[i].戦闘適性,
					p武将情報[i].智謀適性,
					p武将情報[i].技能一喝,
					p武将情報[i].技能暗殺,
					p武将情報[i].技能流出,
					p武将情報[i].技能煽動,
					p武将情報[i].技能流言,
					p武将情報[i].技能弁舌,
					p武将情報[i].技能焼討,
					p武将情報[i].技能挑発,
					p武将情報[i].職業,
					p武将情報[i].足軽適性,
					p武将情報[i].騎馬適性,
					Get_鉄砲適性(i),
					p武将情報[i].水軍適性,
					Get_弓適性(i),  // ★ここが加わっている
					Get_槍適性(i),  // ★ここが加わっている
					p武将情報[i].大砲,
					p武将情報[i].騎馬鉄砲,
					p武将情報[i].鉄甲船,
					p武将情報[i].寿命,
					p武将情報[i].勇猛,
					Get_独立(i),
					p武将情報[i].口調,
					p武将情報[i].行動済,
					p武将情報[i].内応状態,
					p武将情報[i].遺恨状態,
					p武将情報[i].会見済,
					Is_プレイヤ担当武将(i)
				);
			}
		}
		else {
			// 横列単位で足してゆく、index:0, 姓:1, 名:2, 政治:3 戦闘:4 智謀:5 の順番通り 
			for (int i = 0; i < 最大数::武将情報::配列数; i++) {
				dgvBushou->Rows->Add(
					i,
					i + 1,
					p武将情報[i].前の武将【武将番号】,
					p武将情報[i].次の武将【武将番号】,
					p武将情報[i].最大政才,
					p武将情報[i].最大戦才,
					p武将情報[i].最大智才,
					p武将情報[i].政治熟練値,
					p武将情報[i].戦闘熟練値,
					p武将情報[i].智謀熟練値,
					p武将情報[i].魅力,
					p武将情報[i].野望,
					p武将情報[i].忠誠,
					p武将情報[i].勲功,
					p武将情報[i].所属血筋,
					p武将情報[i].所属大名【大名番号】,
					p武将情報[i].所属軍団【軍団番号】,
					p武将情報[i].所属居城【城番号】,
					p武将情報[i].内応先大名【大名番号】,
					p武将情報[i].兵数,
					p武将情報[i].訓練,
					p武将情報[i].士気,
					p武将情報[i].兵態,
					p武将情報[i].仕官年数,
					Get_伴侶武将番号【配列用】(i),
					p武将情報[i].生年,
					p武将情報[i].親顔番号,
					p武将情報[i].思考,
					p武将情報[i].義理,
					p武将情報[i].相性,
					p武将情報[i].政治適性,
					p武将情報[i].戦闘適性,
					p武将情報[i].智謀適性,
					p武将情報[i].技能一喝,
					p武将情報[i].技能暗殺,
					p武将情報[i].技能流出,
					p武将情報[i].技能煽動,
					p武将情報[i].技能流言,
					p武将情報[i].技能弁舌,
					p武将情報[i].技能焼討,
					p武将情報[i].技能挑発,
					p武将情報[i].職業,
					p武将情報[i].足軽適性,
					p武将情報[i].騎馬適性,
					Get_鉄砲適性(i),
					p武将情報[i].水軍適性,
					p武将情報[i].大砲,
					p武将情報[i].騎馬鉄砲,
					p武将情報[i].鉄甲船,
					p武将情報[i].寿命,
					p武将情報[i].勇猛,
					Get_独立(i),
					p武将情報[i].口調,
					p武将情報[i].行動済,
					p武将情報[i].内応状態,
					p武将情報[i].遺恨状態,
					p武将情報[i].会見済,
					Is_プレイヤ担当武将(i)
				);
			}
		}
	} 

	void dgvBushou_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvBushou->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、武将番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iBushouID = Convert::ToInt32(dgvBushou[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvBushou[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "最大政才") { 
			// 該当のグリッドの値をbyte型(256までの型)にして、p武将情報に代入する。 
			p武将情報[iBushouID].最大政才 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "最大戦才") { 
			p武将情報[iBushouID].最大戦才 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "最大智才") { 
			p武将情報[iBushouID].最大智才 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "政治熟練値") { 
			p武将情報[iBushouID].政治熟練値 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "戦闘熟練値") { 
			p武将情報[iBushouID].戦闘熟練値 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "智謀熟練値") { 
			p武将情報[iBushouID].智謀熟練値 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "魅力") { 
			p武将情報[iBushouID].魅力 = Convert::ToSByte(svalue); 
		} 
		else if (headerText == "野望") { 
			p武将情報[iBushouID].野望 = Convert::ToSByte(svalue); 
		} 
		else if (headerText == "忠誠") { 
			p武将情報[iBushouID].忠誠 = Convert::ToSByte(svalue); 
		} 
		else if (headerText == "勲功") { 
			p武将情報[iBushouID].勲功 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "所属血筋") { 
			p武将情報[iBushouID].所属血筋 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "所属大名【大名番号】") { 
			p武将情報[iBushouID].所属大名【大名番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "所属軍団【軍団番号】") { 
			p武将情報[iBushouID].所属軍団【軍団番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "所属居城【城番号】") { 
			p武将情報[iBushouID].所属居城【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "内応先大名【大名番号】") { 
			p武将情報[iBushouID].内応先大名【大名番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "兵数") { 
			p武将情報[iBushouID].兵数 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "訓練") { 
			p武将情報[iBushouID].訓練 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "士気") { 
			p武将情報[iBushouID].士気 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "兵態") { 
			p武将情報[iBushouID].兵態 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "仕官年数") { 
			p武将情報[iBushouID].仕官年数 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "生年") { 
			p武将情報[iBushouID].生年 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "親顔番号") { 
			p武将情報[iBushouID].親顔番号 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "思考") { 
			p武将情報[iBushouID].思考 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "義理") { 
			p武将情報[iBushouID].義理 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "相性") { 
			p武将情報[iBushouID].相性 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "政治適性") { 
			p武将情報[iBushouID].政治適性 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "戦闘適性") { 
			p武将情報[iBushouID].戦闘適性 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "智謀適性") { 
			p武将情報[iBushouID].智謀適性 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "技能一喝") { 
			p武将情報[iBushouID].技能一喝 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "技能暗殺") { 
			p武将情報[iBushouID].技能暗殺 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "技能流出") { 
			p武将情報[iBushouID].技能流出 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "技能煽動") { 
			p武将情報[iBushouID].技能煽動 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "技能流言") { 
			p武将情報[iBushouID].技能流言 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "技能弁舌") { 
			p武将情報[iBushouID].技能弁舌 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "技能焼討") { 
			p武将情報[iBushouID].技能焼討 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "技能挑発") { 
			p武将情報[iBushouID].技能挑発 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "職業") { 
			p武将情報[iBushouID].職業 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "足軽適性") { 
			p武将情報[iBushouID].足軽適性 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "騎馬適性") { 
			p武将情報[iBushouID].騎馬適性 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "Get_鉄砲適性") { 
			Set_鉄砲適性(iBushouID, Convert::ToByte(svalue) ); 
		} 
		else if (headerText == "水軍適性") {
			p武将情報[iBushouID].水軍適性 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "Get_弓適性") {
			Set_弓適性(iBushouID, Convert::ToByte(svalue));
		}
		else if (headerText == "Get_槍適性") {
			Set_槍適性(iBushouID, Convert::ToByte(svalue));
		}
		else if (headerText == "大砲") { 
			p武将情報[iBushouID].大砲 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "騎馬鉄砲") { 
			p武将情報[iBushouID].騎馬鉄砲 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "鉄甲船") { 
			p武将情報[iBushouID].鉄甲船 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "寿命") { 
			p武将情報[iBushouID].寿命 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "勇猛") { 
			p武将情報[iBushouID].勇猛 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "Get_独立") { 
			Set_独立( iBushouID, Convert::ToByte(svalue) ); 
		} 
		else if (headerText == "口調") { 
			p武将情報[iBushouID].口調 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "行動済") { 
			p武将情報[iBushouID].行動済 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "内応状態") { 
			p武将情報[iBushouID].内応状態 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "遺恨状態") { 
			p武将情報[iBushouID].遺恨状態 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "会見済") { 
			p武将情報[iBushouID].会見済 = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p武将情報編-------------------------------------------------


//-------------------------------------------------- p年情報編-------------------------------------------------
private: 

	TabPage^ tpYear;
	DataGridView^ dgvYear;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleYear = {
		"年", 
		"季節",
		"Get_西暦",
		"Get_和暦",
		"Get_天翔記基準年",
	}; 

	void dgvYear_Init() {
		tpYear = gcnew TabPage();
		tpYear->Text = "p年情報";
		tpYear->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpYear);


		// データグリッド全体のインスタンス 
		dgvYear = gcnew DataGridView();
		dgvYear->Size = tpYear->Size;
		dgvYear->ScrollBars = ::ScrollBars::Both;
		dgvYear->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleYear->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleYear[i]; 

			// グリッドビューに縦列として追加。 
			dgvYear->Columns->Add(dgvtbc); 
		} 

		dgvYear_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvYear->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvYear_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpYear->Controls->Add(dgvYear);
	} 

private: 
	void dgvYear_DataImport() { 
		dgvYear->Rows->Clear();

		和暦型 wa = Get_和暦( Get_西暦() );
		string 歴と年 = wa.元号 + wa.年漢字;

		dgvYear->Rows->Add( 
			p年情報.年,
			p年情報.季節,
			Get_西暦(),
			gcnew String( 歴と年.c_str() ),
			Get_天翔記基準年()
		); 
	} 

	void dgvYear_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvYear->Columns[e->ColumnIndex]->HeaderText;

		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、ターン番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iBushouID = Convert::ToInt32(dgvYear[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvYear[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "年") { 
			p年情報.年 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "季節") { 
			p年情報.季節 = Convert::ToSByte(svalue); 
		} 


	} 


//-------------------------------------------------- p年情報編-------------------------------------------------


//-------------------------------------------------- pターン情報編-------------------------------------------------
private: 

	TabPage^ tpTurn;
	DataGridView^ dgvTurn;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleTurn = {
		"現在のターン【大名番号】", 
		"現在のターン【軍団番号】",
		"現在のターン【城番号】",
	}; 

	void dgvTurn_Init() {
		tpTurn = gcnew TabPage();
		tpTurn->Text = "pターン情報";
		tpTurn->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpTurn);


		// データグリッド全体のインスタンス 
		dgvTurn = gcnew DataGridView();
		dgvTurn->Size = tpTurn->Size;
		dgvTurn->ScrollBars = ::ScrollBars::Both;
		dgvTurn->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleTurn->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleTurn[i]; 

			// グリッドビューに縦列として追加。 
			dgvTurn->Columns->Add(dgvtbc); 
		} 

		dgvTurn_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvTurn->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvTurn_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpTurn->Controls->Add(dgvTurn);
	} 

private: 
	void dgvTurn_DataImport() { 
		dgvTurn->Rows->Clear();

		dgvTurn->Rows->Add( 
			pターン情報.現在のターン【大名番号】,
			pターン情報.現在のターン【軍団番号】,
			pターン情報.現在のターン【城番号】
		); 
	} 

	void dgvTurn_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvTurn->Columns[e->ColumnIndex]->HeaderText;

		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、ターン番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iBushouID = Convert::ToInt32(dgvTurn[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvTurn[e->ColumnIndex, e->RowIndex]->Value->ToString();
	} 


//-------------------------------------------------- pターン情報編-------------------------------------------------


//-------------------------------------------------- p大名情報編-------------------------------------------------
private: 

	TabPage^ tpDaimyo;
	DataGridView^ dgvDaimyo;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleDaimyo = {
		"【配列用】", 
		"大名番号",
		"大名【武将番号】",
		"所属軍団【軍団番号】",
		"所属居城【城番号】",
		"隠居武将【武将番号】",
		"家紋",
		"敵対大名【大名番号】",
		"友好大名【大名番号】",
		"商人",
		"布教済",
		"評定済",
		"Get_大名役職",
		"Get_大名所持城数",
		"Is_プレイヤ担当大名",
	}; 


	void dgvDaimyo_Init() {
		tpDaimyo = gcnew TabPage();
		tpDaimyo->Text = "p大名情報";
		tpDaimyo->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpDaimyo);


		// データグリッド全体のインスタンス 
		dgvDaimyo = gcnew DataGridView();
		dgvDaimyo->Size = tpDaimyo->Size;
		dgvDaimyo->ScrollBars = ::ScrollBars::Both;
		dgvDaimyo->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleDaimyo->Length; i++) {

			
			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleDaimyo[i]; 
			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvDaimyo->Columns->Add(dgvtbc); 

		} 

		dgvDaimyo_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvDaimyo->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvDaimyo_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpDaimyo->Controls->Add(dgvDaimyo);
	} 

private: 
	void dgvDaimyo_DataImport() {

		dgvDaimyo->Rows->Clear();

		for ( int i=0; i<最大数::大名情報::配列数; i++) {

			dgvDaimyo->Rows->Add( 
				i,
				i+1,
				p大名情報[i].大名【武将番号】,
				p大名情報[i].所属軍団【軍団番号】,
				p大名情報[i].所属居城【城番号】,
				p大名情報[i].隠居武将【武将番号】,
				p大名情報[i].家紋,
				p大名情報[i].敵対大名【大名番号】,
				p大名情報[i].友好大名【大名番号】,
				p大名情報[i].商人,
				p大名情報[i].布教済,
				p大名情報[i].評定済,
				Get_大名役職( i ),
				Get_大名所持城数(i),
				Is_プレイヤ担当大名(i)
			); 
		}

	} 

	void dgvDaimyo_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvDaimyo->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、大名番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iDaimyoID = Convert::ToInt32(dgvDaimyo[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvDaimyo[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "大名【武将番号】") { 
			p大名情報[iDaimyoID].大名【武将番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "所属軍団【軍団番号】") { 
			p大名情報[iDaimyoID].所属軍団【軍団番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "所属居城【城番号】") { 
			p大名情報[iDaimyoID].所属居城【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "隠居武将【武将番号】") { 
			p大名情報[iDaimyoID].隠居武将【武将番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "家紋") { 
			p大名情報[iDaimyoID].家紋 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "敵対大名【大名番号】") { 
			p大名情報[iDaimyoID].敵対大名【大名番号】 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "友好大名【大名番号】") { 
			p大名情報[iDaimyoID].友好大名【大名番号】 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "商人") { 
			p大名情報[iDaimyoID].商人 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "布教済") { 
			p大名情報[iDaimyoID].布教済 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "評定済") { 
			p大名情報[iDaimyoID].評定済 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "家紋") { 
			p大名情報[iDaimyoID].家紋 = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p大名情報編-------------------------------------------------


//-------------------------------------------------- p大名情報（同盟）編-------------------------------------------------
private: 

	TabPage^ tpDaimyoYuko;
	DataGridView^ dgvDaimyoYuko;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleDaimyoYuko = {
		"【配列用】", 
		"大名番号",
		"同盟・婚姻・友好",
	}; 

	DataGridViewComboBoxColumn^ dgvDKYtbc;

	void dgvDaimyoYuko_Init() {
		tpDaimyoYuko = gcnew TabPage();
		tpDaimyoYuko->Text = "p大名情報（同盟）";
		tpDaimyoYuko->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpDaimyoYuko);


		// データグリッド全体のインスタンス 
		dgvDaimyoYuko = gcnew DataGridView();
		dgvDaimyoYuko->Size = tpDaimyoYuko->Size;
		dgvDaimyoYuko->ScrollBars = ::ScrollBars::Both;

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleDaimyoYuko->Length; i++) {

			if ( colTitleDaimyoYuko[i] == "同盟・婚姻・友好" ) {
				// コンボボックスのオブジェクト列 
				dgvDKYtbc = gcnew DataGridViewComboBoxColumn(); 

				// タイトル文字列を設定 
				dgvDKYtbc->HeaderText = colTitleDaimyoYuko[i];

				dgvDKYtbc->Width = 270;

				// グリッドビューに縦列として追加。 
				dgvDaimyoYuko->Columns->Add(dgvDKYtbc); 

			} else {
				// 縦列のオブジェクトを作り 
				DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
				// タイトル文字列を設定 
				dgvtbc->HeaderText = colTitleDaimyoYuko[i]; 
				if ( i <= 1 ) {
					dgvtbc->Frozen = true; // 前３つぐらいは固定する。
				}
				// グリッドビューに縦列として追加。 
				dgvDaimyoYuko->Columns->Add(dgvtbc); 
			}

		} 

		dgvDaimyoYuko_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvDaimyoYuko->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvDaimyoYuko_CellValueChanged); 
		dgvDaimyoYuko->DataError += gcnew DataGridViewDataErrorEventHandler(this, &MemoryEditorForm::dgvDaimyoYuko_DataError); 
		dgvDaimyoYuko->CellMouseEnter += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvDaimyoYuko_CellMouseEnter); 

		// データグリッドビューをフォームに乗っける 
		tpDaimyoYuko->Controls->Add(dgvDaimyoYuko);
	} 

	//DataErrorイベントハンドラ
	void dgvDaimyoYuko_DataError(Object^ sender, DataGridViewDataErrorEventArgs^ e) {
		e->Cancel = false;
	}

private: 
	void dgvDaimyoYuko_DataImport() {

		dgvDaimyoYuko->Rows->Clear();

		for ( int i=0; i<最大数::大名情報::配列数; i++) {

			dgvDaimyoYuko->Rows->Add( 
				i,
				i+1
			); 
		}

	} 

	void dgvDaimyoYuko_CellMouseEnter(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		if ( 0 <= e->ColumnIndex && e->ColumnIndex <= 3 &&
			0 <= e->RowIndex && e->RowIndex < 最大数::大名情報::配列数 ) {

			String^ headerText = dgvDaimyoYuko->Columns[e->ColumnIndex]->HeaderText;

			int iDaimyoID = Convert::ToInt32(dgvDaimyoYuko[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

			if ( headerText == "同盟・婚姻・友好" ) {

				BindingSource^ bs = gcnew BindingSource();

				for ( int iTargetDaimyoYukoID=0; iTargetDaimyoYukoID < 最大数::大名情報::配列数; iTargetDaimyoYukoID++ ) {
					String^ y_d_k = String::Format("相手大名番号: {0,2} | 友好: {1,2} | 同盟:{2} | 婚姻:{3}",
												iTargetDaimyoYukoID + 1,
												Get_友好関係(iDaimyoID, iTargetDaimyoYukoID),
												Is_同盟関係(iDaimyoID, iTargetDaimyoYukoID) ? "○" : "×",
												Is_婚姻関係(iDaimyoID, iTargetDaimyoYukoID) ? "○" : "×" );
					bs->Add(y_d_k);

					dgvDKYtbc->DataSource = bs;
				}
			}
		}
	}

	void dgvDaimyoYuko_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvDaimyoYuko->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、大名番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iDaimyoYukoID = Convert::ToInt32(dgvDaimyoYuko[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvDaimyoYuko[e->ColumnIndex, e->RowIndex]->Value->ToString();
	} 


//-------------------------------------------------- p大名情報（同盟）編-------------------------------------------------

//-------------------------------------------------- p軍団情報編-------------------------------------------------
private: 

	TabPage^ tpGundan;
	DataGridView^ dgvGundan;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleGundan = {
		"【配列用】", 
		"軍団番号",
		"前の軍団【軍団番号】",
		"次の軍団【軍団番号】",
		"所属居城【城番号】",
		"所属大名【大名番号】",
		"行動力",
		"金",
		"米",
		"馬",
		"鉄砲",
		"軍団割当番号",
		"Get_軍団兵数",
		"Get_軍団役職",
		"Get_軍師武将番号【配列用】",
		"Get_軍団所持城数",
		"Is_プレイヤ担当軍団",
	}; 

	void dgvGundan_Init() {
		tpGundan = gcnew TabPage();
		tpGundan->Text = "p軍団情報";
		tpGundan->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpGundan);


		// データグリッド全体のインスタンス 
		dgvGundan = gcnew DataGridView();
		dgvGundan->Size = tpGundan->Size;
		dgvGundan->ScrollBars = ::ScrollBars::Both;
		dgvGundan->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleGundan->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleGundan[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvGundan->Columns->Add(dgvtbc); 
		} 

		dgvGundan_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvGundan->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvGundan_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpGundan->Controls->Add(dgvGundan);
	} 

private: 
	void dgvGundan_DataImport() { 

		dgvGundan->Rows->Clear();

		for ( int i=0; i<最大数::軍団情報::配列数; i++) { 
			dgvGundan->Rows->Add( 
				i,
				i+1,
				p軍団情報[i].前の軍団【軍団番号】,
				p軍団情報[i].次の軍団【軍団番号】,
				p軍団情報[i].所属居城【城番号】,
				p軍団情報[i].所属大名【大名番号】,
				p軍団情報[i].行動力,
				p軍団情報[i].金,
				p軍団情報[i].米,
				p軍団情報[i].馬,
				p軍団情報[i].鉄砲,
				p軍団情報[i].軍団割当番号,
				Get_軍団兵数(i),
				Get_軍団役職(i),
				Get_軍師武将番号【配列用】(i),
				Get_軍団所持城数(i),
				Is_プレイヤ担当軍団(i)
				
			); 
		} 
	} 

	void dgvGundan_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvGundan->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、軍団番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iGundanID = Convert::ToInt32(dgvGundan[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvGundan[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "前の軍団【軍団番号】") { 
			p軍団情報[iGundanID].前の軍団【軍団番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "次の軍団【軍団番号】") { 
			p軍団情報[iGundanID].次の軍団【軍団番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "所属居城【城番号】") { 
			p軍団情報[iGundanID].所属居城【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "所属大名【大名番号】") { 
			p軍団情報[iGundanID].所属大名【大名番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "行動力") { 
			p軍団情報[iGundanID].行動力 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "金") { 
			p軍団情報[iGundanID].金 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "米") { 
			p軍団情報[iGundanID].米 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "馬") { 
			p軍団情報[iGundanID].馬 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "鉄砲") { 
			p軍団情報[iGundanID].鉄砲 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "軍団割当番号") { 
			p軍団情報[iGundanID].軍団割当番号 = Convert::ToByte(svalue); 
		} 
	} 
//-------------------------------------------------- p軍団情報編-------------------------------------------------



//-------------------------------------------------- p城情報編-------------------------------------------------
private: 

	TabPage^ tpCastle;
	DataGridView^ dgvCastle;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleCastle = {
		"【配列用】", 
		"城番号",
		"Get_城名",
		"前の城【城番号】",
		"次の城【城番号】",
		"城主【武将番号】",
		"_浪人先頭武将【武将番号】",
		"所属軍団【軍団番号】",
		"城郭",
		"石高",
		"商業",
		"人口",
		"民忠",
		"徴兵可",
		"兵質",
		"本城",
		"鍛冶",
		"馬産地",
		"港",
		"国際港",
		"銀山",
		"金山",
		"一騎煽動",
		"城絵背景",
		"Get_城称",
		"巨城",
		"_名前変更"
	}; 

	void dgvCastle_Init() {
		tpCastle = gcnew TabPage();
		tpCastle->Text = "p城情報";
		tpCastle->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpCastle);


		// データグリッド全体のインスタンス 
		dgvCastle = gcnew DataGridView();
		dgvCastle->Size = tpCastle->Size;
		dgvCastle->ScrollBars = ::ScrollBars::Both;
		dgvCastle->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleCastle->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleCastle[i]; 

			if ( i <= 2 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvCastle->Columns->Add(dgvtbc); 
		} 

		dgvCastle_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvCastle->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvCastle_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpCastle->Controls->Add(dgvCastle);
	} 

private: 
	void dgvCastle_DataImport() { 

		dgvCastle->Rows->Clear();

		for ( int i=0; i<最大数::城情報::配列数; i++) { 
			dgvCastle->Rows->Add( 
				i,
				i+1,
				gcnew String(Get_城名(i).c_str()),

				p城情報[i].前の城【城番号】,
				p城情報[i].次の城【城番号】,
				p城情報[i].城主【武将番号】,
				p城情報[i]._浪人先頭武将【武将番号】,
				p城情報[i].所属軍団【軍団番号】,
				p城情報[i].城郭,
				p城情報[i].石高,
				p城情報[i].商業,
				p城情報[i].人口,
				p城情報[i].民忠,
				p城情報[i].徴兵可,
				p城情報[i].兵質,
				p城情報[i].本城,
				p城情報[i].鍛冶,
				p城情報[i].馬産地,
				p城情報[i].港,
				p城情報[i].国際港,
				p城情報[i].銀山,
				p城情報[i].金山,
				p城情報[i].一騎煽動,
				p城情報[i].城絵背景,
				gcnew String(Get_城称(i).c_str()),
				p城情報[i].巨城,
				p城情報[i]._名前変更
			
			); 
		} 
	} 

	void dgvCastle_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvCastle->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、城番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iCastleID = Convert::ToInt32(dgvCastle[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvCastle[e->ColumnIndex, e->RowIndex]->Value->ToString();



		if (headerText == "Get_城名") { 
			char szName[32] = "";
			wsprintf(szName, "%s", svalue);
			Set_城名( iCastleID, szName );
		} 
		else if (headerText == "前の城【城番号】") { 
			p城情報[iCastleID].前の城【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "次の城【城番号】") { 
			p城情報[iCastleID].次の城【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "城主【武将番号】") { 
			p城情報[iCastleID].城主【武将番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "_浪人先頭武将【武将番号】") { 
			p城情報[iCastleID]._浪人先頭武将【武将番号】 = Convert::ToUInt16(svalue); 
		} 

		else if (headerText == "所属軍団【軍団番号】") { 
			p城情報[iCastleID].所属軍団【軍団番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "城郭") { 
			p城情報[iCastleID].城郭 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "商業") { 
			p城情報[iCastleID].商業 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "人口") { 
			p城情報[iCastleID].人口 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "民忠") { 
			p城情報[iCastleID].民忠 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "徴兵可") { 
			p城情報[iCastleID].徴兵可 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "兵質") { 
			p城情報[iCastleID].兵質 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "本城") { 
			p城情報[iCastleID].本城 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "鍛冶") { 
			p城情報[iCastleID].鍛冶 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "馬産地") { 
			p城情報[iCastleID].馬産地 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "港") { 
			p城情報[iCastleID].港 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "国際港") { 
			p城情報[iCastleID].国際港 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "銀山") { 
			p城情報[iCastleID].銀山 = Convert::ToByte(svalue); 
		} 

		else if (headerText == "金山") { 
			p城情報[iCastleID].金山 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "一騎煽動") { 
			p城情報[iCastleID].一騎煽動 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "城絵背景") { 
			p城情報[iCastleID].城絵背景 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "巨城") { 
			p城情報[iCastleID].巨城 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "_名前変更") { 
			p城情報[iCastleID]._名前変更 = Convert::ToByte(svalue); 
		} 
	} 
//-------------------------------------------------- p城情報編-------------------------------------------------


//-------------------------------------------------- p城付加情報編-------------------------------------------------
private: 

	TabPage^ tpCastleAdd;
	DataGridView^ dgvCastleAdd;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleCastleAdd = {

		"【配列用】", 
		"城番号",
		"所属地域【地域番号】",
		"最大石高÷10",
		"最大商業値",
		"Ｘ位置",
		"Ｙ位置",
		"城グリッド位置.Ｘ",
		"城グリッド位置.Ｙ",
		"Get_都道府県名"
	}; 

	void dgvCastleAdd_Init() {
		tpCastleAdd = gcnew TabPage();
		tpCastleAdd->Text = "p城付加情報";
		tpCastleAdd->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpCastleAdd);


		// データグリッド全体のインスタンス 
		dgvCastleAdd = gcnew DataGridView();
		dgvCastleAdd->Size = tpCastleAdd->Size;
		dgvCastleAdd->ScrollBars = ::ScrollBars::Both;
		dgvCastleAdd->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleCastleAdd->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleCastleAdd[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvCastleAdd->Columns->Add(dgvtbc); 
		} 

		dgvCastleAdd_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvCastleAdd->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvCastleAdd_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpCastleAdd->Controls->Add(dgvCastleAdd);
	} 

private: 
	void dgvCastleAdd_DataImport() { 

		dgvCastleAdd->Rows->Clear();

		for ( int i=0; i<最大数::城情報::配列数; i++) {

			城グリッド位置型 pos = Get_城グリッド位置(i);
			int i都道府県番号 = Get_城都道府県番号(i);

			dgvCastleAdd->Rows->Add( 
				i,
				i+1,

				p城付加情報[i].所属地域【地域番号】,
				p城付加情報[i].最大石高÷10,
				p城付加情報[i].最大商業値,
				p城付加情報[i].Ｘ位置,
				p城付加情報[i].Ｙ位置,
				pos.Ｘ,
				pos.Ｙ,
				gcnew String( Get_都道府県名(i都道府県番号).c_str() )
			); 
		} 
	} 

	void dgvCastleAdd_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvCastleAdd->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、城番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iCastleID = Convert::ToInt32(dgvCastleAdd[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvCastleAdd[e->ColumnIndex, e->RowIndex]->Value->ToString();



		if (headerText == "所属地域【地域番号】") { 
			p城付加情報[iCastleID].所属地域【地域番号】 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "最大石高÷10") { 
			p城付加情報[iCastleID].最大石高÷10 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "最大商業値") { 
			p城付加情報[iCastleID].最大商業値 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "Ｘ位置") { 
			p城付加情報[iCastleID].Ｘ位置 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "Ｙ位置") { 
			p城付加情報[iCastleID].Ｙ位置 = Convert::ToByte(svalue); 
		} 
	} 
//-------------------------------------------------- p城付加情報編-------------------------------------------------


//-------------------------------------------------- p地域情報編-------------------------------------------------
private: 

	TabPage^ tpChiiki;
	DataGridView^ dgvChiiki;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleChiiki = {

		"【配列用】", 
		"地域番号",

		"Get_地域名",
		"地域内の城１",
		"地域内の城２",
		"地域内の城３",
		"地域内の城４",
		"地域内の城５",
		"地域内の城６",
		"地域内の城７",
		"地域内の城８",
	}; 

	void dgvChiiki_Init() {
		tpChiiki = gcnew TabPage();
		tpChiiki->Text = "p地域情報";
		tpChiiki->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpChiiki);


		// データグリッド全体のインスタンス 
		dgvChiiki = gcnew DataGridView();
		dgvChiiki->Size = tpChiiki->Size;
		dgvChiiki->ScrollBars = ::ScrollBars::Both;
		dgvChiiki->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleChiiki->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleChiiki[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvChiiki->Columns->Add(dgvtbc); 
		} 

		dgvChiiki_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvChiiki->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvChiiki_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpChiiki->Controls->Add(dgvChiiki);
	} 

private: 
	void dgvChiiki_DataImport() { 

		dgvChiiki->Rows->Clear();

		for ( int i=0; i<最大数::地域情報::配列数; i++) {

			城グリッド位置型 pos = Get_城グリッド位置(i);
			int i都道府県番号 = Get_城都道府県番号(i);


			dgvChiiki->Rows->Add( 
				i,
				i+1,
				gcnew String( Get_地域名(i).c_str() ),

				p地域情報[i].地域内の城１【城番号】,
				p地域情報[i].地域内の城２【城番号】,
				p地域情報[i].地域内の城３【城番号】,
				p地域情報[i].地域内の城４【城番号】,
				p地域情報[i].地域内の城５【城番号】,
				p地域情報[i].地域内の城６【城番号】,
				p地域情報[i].地域内の城７【城番号】,
				p地域情報[i].地域内の城８【城番号】
			); 
		} 
	} 

	void dgvChiiki_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvChiiki->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、城番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iChiikiID = Convert::ToInt32(dgvChiiki[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvChiiki[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "地域内の城１【城番号】") { 
			p地域情報[iChiikiID].地域内の城１【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "地域内の城２【城番号】") { 
			p地域情報[iChiikiID].地域内の城２【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "地域内の城３【城番号】") { 
			p地域情報[iChiikiID].地域内の城３【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "地域内の城４【城番号】") { 
			p地域情報[iChiikiID].地域内の城４【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "地域内の城５【城番号】") { 
			p地域情報[iChiikiID].地域内の城５【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "地域内の城６【城番号】") { 
			p地域情報[iChiikiID].地域内の城６【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "地域内の城７【城番号】") { 
			p地域情報[iChiikiID].地域内の城７【城番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "地域内の城８【城番号】") { 
			p地域情報[iChiikiID].地域内の城８【城番号】 = Convert::ToUInt16(svalue); 
		} 
	} 
//-------------------------------------------------- p地域情報編-------------------------------------------------


//-------------------------------------------------- p官位情報編-------------------------------------------------
private: 

	TabPage^ tpKanni;
	DataGridView^ dgvKanni;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleKanni = {
		"【配列用】", 
		"官位番号",
		"Get_官位名",
		"位階",
		"所有武将【武将番号】",
		"上昇値",
	}; 

	void dgvKanni_Init() {
		tpKanni = gcnew TabPage();
		tpKanni->Text = "p官位情報";
		tpKanni->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpKanni);


		// データグリッド全体のインスタンス 
		dgvKanni = gcnew DataGridView();
		dgvKanni->Size = tpKanni->Size;
		dgvKanni->ScrollBars = ::ScrollBars::Both;
		dgvKanni->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleKanni->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleKanni[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvKanni->Columns->Add(dgvtbc); 
		} 

		dgvKanni_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvKanni->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvKanni_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpKanni->Controls->Add(dgvKanni);
	} 

private: 
	void dgvKanni_DataImport() {

		dgvKanni->Rows->Clear();

		for ( int i=0; i<最大数::官位情報::配列数; i++) { 
			dgvKanni->Rows->Add( 
				i,
				i+1,
				gcnew String(Get_官位名(i).c_str()),
				p官位情報[i].位階,
				p官位情報[i].所有武将【武将番号】,
				p官位情報[i].上昇値
			); 
		} 
	} 

	void dgvKanni_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvKanni->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、大名番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iKanniID = Convert::ToInt32(dgvKanni[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvKanni[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "Get_官位名") {
			char szKanni[32] = "";
			wsprintf(szKanni, "%s", svalue);
			Set_官位名(iKanniID, szKanni);
		} 
		else if (headerText == "位階") { 
			p官位情報[iKanniID].位階 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "所有武将【武将番号】") { 
			p官位情報[iKanniID].所有武将【武将番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "上昇値") { 
			p官位情報[iKanniID].上昇値 = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p官位情報編-------------------------------------------------


//-------------------------------------------------- p家宝情報編-------------------------------------------------
private: 

	TabPage^ tpKahou;
	DataGridView^ dgvKahou;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleKahou = {
		"【配列用】", 
		"家宝番号",
		"Get_家宝名",
		"家宝分類",
		"家宝画像",
		"所有武将【武将番号】",
		"上昇値",
		"未登場",
		"消失",
	}; 

	void dgvKahou_Init() {
		tpKahou = gcnew TabPage();
		tpKahou->Text = "p家宝情報";
		tpKahou->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpKahou);


		// データグリッド全体のインスタンス 
		dgvKahou = gcnew DataGridView();
		dgvKahou->Size = tpKahou->Size;
		dgvKahou->ScrollBars = ::ScrollBars::Both;
		dgvKahou->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleKahou->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleKahou[i]; 

			if ( i <= 1 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvKahou->Columns->Add(dgvtbc); 
		} 

		dgvKahou_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvKahou->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvKahou_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpKahou->Controls->Add(dgvKahou);
	} 

private: 
	void dgvKahou_DataImport() {

		dgvKahou->Rows->Clear();

		for ( int i=0; i<最大数::家宝情報::配列数; i++) { 
			dgvKahou->Rows->Add( 
				i,
				i+1,
				gcnew String(Get_家宝名(i).c_str()),
				p家宝情報[i].家宝分類,
				p家宝情報[i].家宝画像,
				p家宝情報[i].所有武将【武将番号】,
				p家宝情報[i].上昇値,
				p家宝情報[i].未登場,
				p家宝情報[i].消失
				); 
		} 
	} 

	void dgvKahou_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvKahou->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、大名番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iKahouID = Convert::ToInt32(dgvKahou[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvKahou[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "Get_家宝名") {
			char szKahou[32] = "";
			wsprintf(szKahou, "%s", svalue);
			Set_家宝名(iKahouID, szKahou);
		} 

		else if (headerText == "家宝分類") { 
			p家宝情報[iKahouID].家宝分類 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "家宝画像") { 
			p家宝情報[iKahouID].家宝画像 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "所有武将【武将番号】") { 
			p家宝情報[iKahouID].所有武将【武将番号】 = Convert::ToUInt16(svalue); 
		} 
		else if (headerText == "上昇値") { 
			p家宝情報[iKahouID].上昇値 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "未登場") { 
			p家宝情報[iKahouID].未登場 = Convert::ToByte(svalue); 
		} 
		else if (headerText == "消失") { 
			p家宝情報[iKahouID].消失 = Convert::ToByte(svalue); 
		} 
	} 


//-------------------------------------------------- p家宝情報編-------------------------------------------------


//-------------------------------------------------- p相場情報編-------------------------------------------------
private: 

	TabPage^ tpSoba;
	DataGridView^ dgvSoba;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleSoba = {
		"米相場", 
		"鉄砲相場",
		"馬相場",
		"兵相場",
	}; 


	void dgvSoba_Init() {
		tpSoba = gcnew TabPage();
		tpSoba->Text = "p相場情報";
		tpSoba->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpSoba);


		// データグリッド全体のインスタンス 
		dgvSoba = gcnew DataGridView();
		dgvSoba->Size = tpSoba->Size;
		dgvSoba->ScrollBars = ::ScrollBars::Both;
		dgvSoba->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleSoba->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleSoba[i]; 

			// グリッドビューに縦列として追加。 
			dgvSoba->Columns->Add(dgvtbc); 
		} 

		dgvSoba_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvSoba->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvSoba_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpSoba->Controls->Add(dgvSoba);
	} 

private: 
	void dgvSoba_DataImport() { 

		dgvSoba->Rows->Clear();

		dgvSoba->Rows->Add(
			p相場情報.米相場,
			p相場情報.鉄砲相場,
			p相場情報.馬相場,
			p相場情報.兵相場
		); 
	} 

	void dgvSoba_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvSoba->Columns[e->ColumnIndex]->HeaderText;

		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、相場番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iBushouID = Convert::ToInt32(dgvSoba[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvSoba[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "米相場") { 
			Set_米相場( Convert::ToUInt16(svalue) ); 
		} 
		else if (headerText == "鉄砲相場") { 
			Set_鉄砲相場( Convert::ToUInt16(svalue) ); 
		} 
		else if (headerText == "馬相場") { 
			Set_馬相場( Convert::ToUInt16(svalue) ); 
		} 
		else if (headerText == "兵相場") { 
			Set_兵相場( Convert::ToUInt16(svalue) ); 
		} 
	} 


//-------------------------------------------------- p相場情報編-------------------------------------------------



//-------------------------------------------------- p戦場情報（武将）編-------------------------------------------------
private: 

	TabPage^ tpBattleUnit;
	DataGridView^ dgvBattleUnit;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleBattleUnit = {
		"武将番号",
		"行動団体帰属",
		"ヘックス.Ｘ",
		"ヘックス.Ｙ",
		"移動力残量",
		"武将混乱状態",
		"Is_武将行動済《戦争画面》",
		"p武将戸籍情報[ix].戦死",
		"p武将戸籍情報[ix].退却",
		"出陣中",
		"表示中マップに出陣中",
	}; 

	void dgvBattleUnit_Init() {
		tpBattleUnit = gcnew TabPage();
		tpBattleUnit->Text = "戦場情報（武将）";
		tpBattleUnit->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpBattleUnit);


		// データグリッド全体のインスタンス 
		dgvBattleUnit = gcnew DataGridView();
		dgvBattleUnit->Size = tpBattleUnit->Size;
		dgvBattleUnit->ScrollBars = ::ScrollBars::Both;
		dgvBattleUnit->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleBattleUnit->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleBattleUnit[i]; 

			if ( i == 0 ) {
				dgvtbc->Frozen = true; // 前３つぐらいは固定する。
			}
			// グリッドビューに縦列として追加。 
			dgvBattleUnit->Columns->Add(dgvtbc); 
		} 

		dgvBattleUnit_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvBattleUnit->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvBattleUnit_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpBattleUnit->Controls->Add(dgvBattleUnit);
	} 

private: 
	void dgvBattleUnit_DataImport() {

		dgvBattleUnit->Rows->Clear();

		番号リスト型 武将リスト = Get_武将番号リスト【配列用】();

		for each ( int iBushouID in 武将リスト ) {

			ヘックス位置型 pos = Get_武将の野戦ヘックス位置(iBushouID);

			番号リスト型 出陣中 = Get_出陣中の武将番号リスト【配列用】();
			番号リスト型 現画面 = Get_出陣中の武将番号リスト【配列用】《表示中マップ》();

			int cnt出陣中 = std::count(出陣中.begin(), 出陣中.end(), iBushouID);
			int cnt現画面 = std::count(現画面.begin(), 現画面.end(), iBushouID);

			dgvBattleUnit->Rows->Add(
				iBushouID + 1,
				Get_行動団体帰属(iBushouID),
				pos.Ｘ,
				pos.Ｙ,
				Get_移動残量(iBushouID),
				(int)Get_武将混乱状態(iBushouID),
				(int)Is_武将行動済《戦争画面》(iBushouID),
				p武将戸籍情報[iBushouID].戦死,
				p武将戸籍情報[iBushouID].退却,
				(int)(cnt出陣中>0),
				(int)(cnt現画面>0)
			);

		}
	} 

	void dgvBattleUnit_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvBattleUnit->Columns[e->ColumnIndex]->HeaderText;

		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、大名番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iBattleUnitID = Convert::ToInt32(dgvBattleUnit[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 
		int iBushouID = iBattleUnitID-1;

		String^ svalue = dgvBattleUnit[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "武将混乱状態") {
			if ( 0 <= iBushouID && iBushouID < 最大数::武将情報::配列数) {
				Set_武将混乱状態( iBushouID, Convert::ToUInt16(svalue) ); 
			}
		} 
	} 


//-------------------------------------------------- p戦場情報（武将）編-------------------------------------------------



//-------------------------------------------------- p環境設定情報編-------------------------------------------------
private: 

	TabPage^ tpSettings;
	DataGridView^ dgvSettings;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleSettings = {
		"効果音", 
		"音楽",
		"他国の戦争",
		"ムービー",
		"表示速度",
		"難易度",
	}; 


	void dgvSettings_Init() {
		tpSettings = gcnew TabPage();
		tpSettings->Text = "p環境設定情報";
		tpSettings->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpSettings);


		// データグリッド全体のインスタンス 
		dgvSettings = gcnew DataGridView();
		dgvSettings->Size = tpSettings->Size;
		dgvSettings->ScrollBars = ::ScrollBars::Both;
		dgvSettings->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleSettings->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleSettings[i]; 

			// グリッドビューに縦列として追加。 
			dgvSettings->Columns->Add(dgvtbc); 
		} 

		dgvSettings_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvSettings->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvSettings_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpSettings->Controls->Add(dgvSettings);
	} 

private: 
	void dgvSettings_DataImport() { 

		dgvSettings->Rows->Clear();

		dgvSettings->Rows->Add(
			p環境設定情報.効果音,
			p環境設定情報.音楽,
			p環境設定情報.他国の戦争,
			BOOL(p環境設定情報.ムービー == ムービー::ＯＮ),
			p環境設定情報.表示速度,
			p環境設定情報.難易度
		); 
	} 

	void dgvSettings_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvSettings->Columns[e->ColumnIndex]->HeaderText;

		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、環境情報設定番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iBushouID = Convert::ToInt32(dgvSettings[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvSettings[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "効果音") { 
			p環境設定情報.効果音 = Convert::ToByte(svalue);
		} 
		else if (headerText == "音楽") { 
			p環境設定情報.音楽 = Convert::ToByte(svalue);
		} 
		else if (headerText == "他国の戦争") { 
			p環境設定情報.他国の戦争 = Convert::ToByte(svalue);
		} 
		else if (headerText == "ムービー") { 
			p環境設定情報.ムービー = int(Convert::ToByte(svalue) == ムービー::ＯＮ);
		} 
		else if (headerText == "表示速度") { 
			p環境設定情報.表示速度 = Convert::ToByte(svalue);
		} 
		else if (headerText == "難易度") { 
			p環境設定情報.難易度 = Convert::ToByte(svalue);
		} 
	} 

//-------------------------------------------------- p環境設定情報編-------------------------------------------------


//-------------------------------------------------- p環境設定拡張情報編-------------------------------------------------
private: 

	TabPage^ tpSettingsEx;
	DataGridView^ dgvSettingsEx;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleSettingsEx = {
		"年号表示", 
		"表示位置記憶",
		"表示切替マップ",
		"戦争頻度",
		"計略頻度",
		"死亡頻度",
		"自国の戦争",
		"編集機能",
		"情報表示",
		"武将行動志願",
		"姫武将志願",
	}; 


	void dgvSettingsEx_Init() {
		tpSettingsEx = gcnew TabPage();
		tpSettingsEx->Text = "p環境設定拡張情報";
		tpSettingsEx->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpSettingsEx);


		// データグリッド全体のインスタンス 
		dgvSettingsEx = gcnew DataGridView();
		dgvSettingsEx->Size = tpSettingsEx->Size;
		dgvSettingsEx->ScrollBars = ::ScrollBars::Both;
		dgvSettingsEx->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleSettingsEx->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleSettingsEx[i]; 

			// グリッドビューに縦列として追加。 
			dgvSettingsEx->Columns->Add(dgvtbc); 
		} 

		dgvSettingsEx_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvSettingsEx->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvSettingsEx_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpSettingsEx->Controls->Add(dgvSettingsEx);
	} 

private: 
	void dgvSettingsEx_DataImport() { 

		dgvSettingsEx->Rows->Clear();

		dgvSettingsEx->Rows->Add(
			p環境設定拡張情報.年号表示,
			p環境設定拡張情報.表示位置記憶,
			p環境設定拡張情報.表示切替マップ,
			p環境設定拡張情報.戦争頻度,
			p環境設定拡張情報.計略頻度,
			p環境設定拡張情報.死亡頻度,
			p環境設定拡張情報.自国の戦争,
			p環境設定拡張情報.編集機能,
			p環境設定拡張情報.情報表示,
			p環境設定拡張情報.武将行動志願,
			p環境設定拡張情報.姫武将志願
		); 
	} 

	void dgvSettingsEx_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvSettingsEx->Columns[e->ColumnIndex]->HeaderText;

		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、環境情報設定番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iBushouID = Convert::ToInt32(dgvSettingsEx[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvSettingsEx[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "年号表示") { 
			p環境設定拡張情報.年号表示 = Convert::ToByte(svalue);
		} 
		else if (headerText == "表示位置記憶") { 
			p環境設定拡張情報.表示位置記憶 = Convert::ToByte(svalue);
		} 
		else if (headerText == "表示切替マップ") { 
			p環境設定拡張情報.表示切替マップ = Convert::ToByte(svalue);
		} 
		else if (headerText == "戦争頻度") { 
			p環境設定拡張情報.戦争頻度 = Convert::ToByte(svalue);
		} 
		else if (headerText == "計略頻度") { 
			p環境設定拡張情報.計略頻度 = Convert::ToByte(svalue);
		} 
		else if (headerText == "死亡頻度") { 
			p環境設定拡張情報.死亡頻度 = Convert::ToByte(svalue);
		} 
		else if (headerText == "自国の戦争") { 
			p環境設定拡張情報.自国の戦争 = Convert::ToByte(svalue);
		} 
		else if (headerText == "編集機能") { 
			p環境設定拡張情報.編集機能 = Convert::ToByte(svalue);
		} 
		else if (headerText == "情報表示") { 
			p環境設定拡張情報.情報表示 = Convert::ToByte(svalue);
		} 
		else if (headerText == "武将行動志願") { 
			p環境設定拡張情報.武将行動志願 = Convert::ToByte(svalue);
		} 
		else if (headerText == "姫武将志願") { 
			p環境設定拡張情報.姫武将志願 = Convert::ToByte(svalue);
		} 
	} 

//-------------------------------------------------- p環境設定拡張情報編-------------------------------------------------





//-------------------------------------------------- p天気情報編-------------------------------------------------
private: 

	TabPage^ tpWeather;
	DataGridView^ dgvWeather;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleWeather = {
		"Get_天気",
		""
	}; 

	void dgvWeather_Init() {
		tpWeather = gcnew TabPage();
		tpWeather->Text = "p天気情報";
		tpWeather->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpWeather);


		// データグリッド全体のインスタンス 
		dgvWeather = gcnew DataGridView();
		dgvWeather->Size = tpWeather->Size;
		dgvWeather->ScrollBars = ::ScrollBars::Both;
		dgvWeather->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleWeather->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleWeather[i]; 

			// グリッドビューに縦列として追加。 
			dgvWeather->Columns->Add(dgvtbc); 
		} 

		dgvWeather_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvWeather->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvWeather_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpWeather->Controls->Add(dgvWeather);
	} 

private: 
	void dgvWeather_DataImport() {
		dgvWeather[0, 0]->Value = Get_天気();
	} 

	void dgvWeather_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvWeather->Columns[e->ColumnIndex]->HeaderText;

		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、城番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iCastleID = Convert::ToInt32(dgvWeather[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvWeather[e->ColumnIndex, e->RowIndex]->Value->ToString();
	} 
//-------------------------------------------------- p天気情報編-------------------------------------------------


//-------------------------------------------------- p音楽情報編-------------------------------------------------
private: 

	TabPage^ tpBGM;
	DataGridView^ dgvBGM;  // データグリッドビュー型。 エクセルのように格子状のデータを表示できるため、非常によく利用される。 

	// .NETのString^型を要素とする、.NETの配列array^型。 
	static cli::array<String^>^ colTitleBGM = {
		"Get_再生音楽番号",
		""
	}; 

	void dgvBGM_Init() {
		tpBGM = gcnew TabPage();
		tpBGM->Text = "p音楽情報";
		tpBGM->Size = tcME->ClientSize;
		tcME->TabPages->Add(tpBGM);


		// データグリッド全体のインスタンス 
		dgvBGM = gcnew DataGridView();
		dgvBGM->Size = tpBGM->Size;
		dgvBGM->ScrollBars = ::ScrollBars::Both;
		dgvBGM->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells; // 各カラムの横幅はコンテンツに応じて自動調整 

		// -------------- ここからデータグリッドの「縦列に相当するカラムブジェクト」と、「各カラムのタイトル」の文字列をセッティングする。 

		for (int i=0; i < colTitleBGM->Length; i++) {

			// 縦列のオブジェクトを作り 
			DataGridViewTextBoxColumn^ dgvtbc = gcnew DataGridViewTextBoxColumn(); 
			// タイトル文字列を設定 
			dgvtbc->HeaderText = colTitleBGM[i]; 

			// グリッドビューに縦列として追加。 
			dgvBGM->Columns->Add(dgvtbc); 
		} 

		dgvBGM_DataImport(); 

		// データグリッドのセルを編集した時のイベントハンドラを登録する。 
		dgvBGM->CellValueChanged += gcnew DataGridViewCellEventHandler(this, &MemoryEditorForm::dgvBGM_CellValueChanged); 

		// データグリッドビューをフォームに乗っける 
		tpBGM->Controls->Add(dgvBGM);
	} 

private: 
	void dgvBGM_DataImport() {
		dgvBGM[0, 0]->Value = Get_再生音楽番号();
	} 

	void dgvBGM_CellValueChanged(Object^ sender, DataGridViewCellEventArgs^ e)   { 
		// イベントが発生したオブジェクト(=sender) はデータグリッドビュー型なので、データグリッドビュー型として受け取って… 

		String^ headerText = dgvBGM->Columns[e->ColumnIndex]->HeaderText;



		// 編集したセルの「行」の一番左のカラムである「indexID(=0列目)」に入っている値が、城番号【配列用】である。 
		// ユーザが手で入力したものは全て文字列になってしまう。 
		// 一方プログラムからDgvDataImportでは最初は数値で入れていた。 
		// よって、どのようなデータ型でも良いように、ToStringによってすべて文字列に直した後、Convert::***によって、整数型にする。 
		int iCastleID = Convert::ToInt32(dgvBGM[0, e->RowIndex]->Value->ToString()); // indexIDが一番左だからcolumnは0 

		String^ svalue = dgvBGM[e->ColumnIndex, e->RowIndex]->Value->ToString();

		if (headerText == "Get_再生音楽番号") {
			if ( svalue == "" ) {
				音楽停止();
			} else {
				音楽再生( Convert::ToByte(svalue) ); 
			}
		} 
	} 
//-------------------------------------------------- p音楽情報編-------------------------------------------------


};

