#include <cassert>
#include <algorithm>
#include "ƒQ[ƒ€ƒf[ƒ^\‘¢.h"






namespace ŠÖ” {


// ŒR’c‚ÉŠ‘®‚·‚é•º”‚ğ“¾‚é
int Get_ŒR’c•º”(int ŒR’c”Ô†y”z—ñ—pz) {
	int i•º” = 0;
	for ( int i=0; i<Å‘å”::•«î•ñ::”z—ñ”; i++) {
		if ( p•«î•ñ[i].Š‘®ŒR’cyŒR’c”Ô†z-1 == ŒR’c”Ô†y”z—ñ—pz ) {
			if ( p•«ŒËĞî•ñ[i].ó‘Ô <= ó‘Ô::Œ»–ğ ) { // ‘å–¼, ŒR’c’·, Œ»–ğ ‚ÅƒJƒEƒ“ƒg
				i•º” += p•«î•ñ[i].•º”;
			}
		}
	}
	return i•º”;
}

// ‘S‚Ä‚Ì—LŒø‚ÈŒR’cƒŠƒXƒg‚ğ“¾‚é
”Ô†ƒŠƒXƒgŒ^ Get_ŒR’c”Ô†ƒŠƒXƒgy”z—ñ—pz() {
	”Ô†ƒŠƒXƒgŒ^ list;

	// ŠY“–‚Ì‘å–¼‚h‚c‚É‘®‚·‚éŒR’c‚ğƒŠƒXƒg‚É‰Á‚¦‚é
	for ( int iŒR’cID=0; iŒR’cID < Å‘å”::ŒR’cî•ñ::”z—ñ”; iŒR’cID++ ) {
		if ( pŒR’cî•ñ[iŒR’cID].ŒR’c’·y•«”Ô†z !=  0xFFFF ) {
			list.push_back(iŒR’cID);
		}
	}
	
	return list;
}

// “Á’è‚Ì‘å–¼Ÿ€‰º‚ÌŒR’cƒŠƒXƒg‚ğ“¾‚é
”Ô†ƒŠƒXƒgŒ^ Get_‘å–¼Ÿ€‰ºŒR’c”Ô†ƒŠƒXƒgy”z—ñ—pz(int ‘å–¼”Ô†y”z—ñ—pz) {
	”Ô†ƒŠƒXƒgŒ^ list;

	if ( 0 <= ‘å–¼”Ô†y”z—ñ—pz && ‘å–¼”Ô†y”z—ñ—pz < Å‘å”::‘å–¼î•ñ::”z—ñ” ) {

		// ŠY“–‚Ì‘å–¼‚h‚c‚É‘®‚·‚éŒR’c‚ğƒŠƒXƒg‚É‰Á‚¦‚é
		for ( int iŒR’cID=0; iŒR’cID < Å‘å”::ŒR’cî•ñ::”z—ñ”; iŒR’cID++ ) {
			if ( pŒR’cî•ñ[iŒR’cID].Š‘®‘å–¼y‘å–¼”Ô†z-1 ==  ‘å–¼”Ô†y”z—ñ—pz) {
				list.push_back(iŒR’cID);
			}
		}
	}
	
	return list;
}


// ‚Æ‚ ‚é‘å–¼”z‰º‚ÌŒR’c‰º‚É‚ ‚éŒR’cŠ„“–”Ô†‚ÌƒŠƒXƒg‚ğ“¾‚éB
// (”Ô†‚Æ”‚ğ—¼•û‚ğ“¾‚éB¸‡)
”Ô†ƒŠƒXƒgŒ^ Get_ŒR’cŠ„“–”Ô†ƒŠƒXƒg(int ‘å–¼”Ô†y”z—ñ—pz) {

	”Ô†ƒŠƒXƒgŒ^ list;

	if ( 0 <= ‘å–¼”Ô†y”z—ñ—pz && ‘å–¼”Ô†y”z—ñ—pz < Å‘å”::‘å–¼î•ñ::”z—ñ” ) {

		// ŠY“–‚Ì‘å–¼‚h‚c‚É‘®‚·‚éŒR’c‚ğƒŠƒXƒg‚É‰Á‚¦‚é
		for ( int iŒR’cID=0; iŒR’cID < Å‘å”::ŒR’cî•ñ::”z—ñ”; iŒR’cID++ ) {
			if ( pŒR’cî•ñ[iŒR’cID].Š‘®‘å–¼y‘å–¼”Ô†z-1 ==  ‘å–¼”Ô†y”z—ñ—pz) {
				list.push_back(pŒR’cî•ñ[iŒR’cID].ŒR’cŠ„“–”Ô†);
			}
		}
	}
	
	std::sort(list.begin(),list.end());//¸‡ƒ\[ƒg

	return list;
}

// ‚Æ‚ ‚é‘å–¼”z‰º‚ÌŒR’c‰º‚É‚ ‚éŒR’cu–¢vŠ„“–”Ô†‚ÌƒŠƒXƒg‚ğ“¾‚éB
// (”Ô†‚Æ”‚ğ—¼•û‚ğ“¾‚éB¸‡)
”Ô†ƒŠƒXƒgŒ^ Get_ŒR’c–¢Š„“–”Ô†ƒŠƒXƒg(int ‘å–¼”Ô†y”z—ñ—pz) {

	// Š„‚è“–‚Ä‚ç‚ê‚Ä‚é‚à‚Ì‚ÉA‚P‚ğ“ü‚ê‚é
	int Š„“–”Ô†”z—ñ[8] = {0,0,0,0,0,0,0,0};

	if ( 0 <= ‘å–¼”Ô†y”z—ñ—pz && ‘å–¼”Ô†y”z—ñ—pz < Å‘å”::‘å–¼î•ñ::”z—ñ” ) {

		// ŠY“–‚Ì‘å–¼‚h‚c‚É‘®‚·‚éŒR’c‚ğƒŠƒXƒg‚É‰Á‚¦‚é
		for ( int iŒR’cID=0; iŒR’cID < Å‘å”::ŒR’cî•ñ::”z—ñ”; iŒR’cID++ ) {
			if ( pŒR’cî•ñ[iŒR’cID].Š‘®‘å–¼y‘å–¼”Ô†z-1 ==  ‘å–¼”Ô†y”z—ñ—pz) {
				int g =  pŒR’cî•ñ[iŒR’cID].ŒR’cŠ„“–”Ô†;
				if ( 1 <= g && g <= 8 ) {
					// Š„‚è“–‚Ä‚ç‚ê‚Ä‚é‚à‚Ì‚ÉA‚P‚ğ“ü‚ê‚é
					Š„“–”Ô†”z—ñ[g-1] = 1;
				}
			}
		}
	}

	”Ô†ƒŠƒXƒgŒ^ –¢Š„“–ƒŠƒXƒg;
	for ( int ix=0; ix<8; ix++ ) {
		if (Š„“–”Ô†”z—ñ[ix] == 0) {
			–¢Š„“–ƒŠƒXƒg.push_back(ix+1);
		}
	}

	std::sort(–¢Š„“–ƒŠƒXƒg.begin(),–¢Š„“–ƒŠƒXƒg.end());//¸‡ƒ\[ƒg

	return –¢Š„“–ƒŠƒXƒg;
}


bool Set_ŒR’cŠ‘®‘å–¼(int ŒR’c”Ô†y”z—ñ—pz, int VŠ‘®‘å–¼”Ô†y”z—ñ—pz) {

	// V‘å–¼‚ª³“–‚Å‚Í‚È‚¢B
	if ( ! (0 <= VŠ‘®‘å–¼”Ô†y”z—ñ—pz && VŠ‘®‘å–¼”Ô†y”z—ñ—pz < Å‘å”::‘å–¼î•ñ::”z—ñ”) ) {
		return false;
	}

	// ŒR’c‚ª‘S•”–„‚Ü‚Á‚Ä‚¢‚é‚È‚ç‚ÎA
	”Ô†ƒŠƒXƒgŒ^ glist = Get_ŒR’cŠ„“–”Ô†ƒŠƒXƒg(VŠ‘®‘å–¼”Ô†y”z—ñ—pz);
	if ( glist.size() == 8 ) { // ŒR’c‚Í‘S•”–„‚Ü‚Á‚Ä‚¢‚é
		// ‰½‚à‚Å‚«‚È‚¢
		return false;
	}

	int iGundanID = ŒR’c”Ô†y”z—ñ—pz;

	if ( 0 <= iGundanID && iGundanID < Å‘å”::ŒR’cî•ñ::”z—ñ” ) {

		// w’è‚ÌŒR’c‚ªŒ»İŠ‘®‚µ‚Ä‚¢‚é‘å–¼”Ô†‚ğ‹‚ß‚é
		int iDaimyoID = pŒR’cî•ñ[iGundanID].Š‘®‘å–¼y‘å–¼”Ô†z-1;
		// VŠ‘®æ‚Ì‘å–¼‚ªA¡Š‘®‚µ‚Ä‚¢‚é‘å–¼‚Å‚ ‚ê‚ÎA‰½‚à‚·‚é‚±‚Æ‚Í‚È‚¢B
		if ( iDaimyoID == VŠ‘®‘å–¼”Ô†y”z—ñ—pz) {
			return true;
		}

		// ŒR’cŠ„‚è“–‚Ä”Ô†‚ª‚P”Ô‚Í‘å–¼©gB‚±‚ê‚ÍŒÅ’èB‚±‚Ìê‡A‰½‚à‚¹‚¸¸”s‚Æ‚·‚éB
		if ( pŒR’cî•ñ[iGundanID].ŒR’cŠ„“–”Ô† == 1 ) {
			return false;
		}

		// Œ»İAV‘å–¼‚ÉŠ‘®‚µ‚Ä‚¢‚ÄAŸ‚ÌŒR’cyŒR’c”Ô†z‚ª0xFFFF‚É‚È‚Á‚Ä‚¢‚éŒR’c‚ªA‚Ô‚ç‰º‚ª‚é‚×‚«ƒŠƒ“ƒNƒŠƒXƒg‚ÌÅŒã‚¾B
		// ‚Ô‚ç‰º‚ª‚é‚±‚Æ‚ªo—ˆ‚é‚©A–‘O‚Éƒ`ƒFƒbƒN‚µ‚Ä‚¨‚­B
		int iLinkEndGundanID = -1;
		for ( int iGID=0; iGID < Å‘å”::ŒR’cî•ñ::”z—ñ”; iGID++ ) {
			// 
			int iCurDaimyoID = pŒR’cî•ñ[iGID].Š‘®‘å–¼y‘å–¼”Ô†z-1;

			// w’è‚ÌV‘å–¼‚ÉŠ‘®‚µ‚Ä‚¢‚é‚È‚ç‚ÎA
			if ( iCurDaimyoID == VŠ‘®‘å–¼”Ô†y”z—ñ—pz) {
				// Ÿ‚ÌŒR’c‚ª–³‚¢‚Ì‚Å‚ ‚ê‚ÎA‚»‚¢‚Â‚ªÅIŒR’c”Ô†
				if ( pŒR’cî•ñ[iGID].Ÿ‚ÌŒR’cyŒR’c”Ô†z == 0xFFFF ) {
					iLinkEndGundanID = iGID+1;
				}
				
			}

		}

		// ‚»‚ê‚ª”ÍˆÍ‚É“ü‚Á‚Ä‚¢‚È‚¢‚È‚ç‚ÎAV‘å–¼‚ÌŒR’cƒŠƒ“ƒNƒŠƒXƒg‚ÍA‰ü‘¢‚©‰½‚©‚µ‚ç‚È‚¢‚ªî•ñ‚ª‰ó‚ê‚Ä‚¢‚éB
		// ˆ—I—¹
		if ( ! (0 < iLinkEndGundanID && iLinkEndGundanID <= Å‘å”::ŒR’cî•ñ::”z—ñ” ) ) {
			return false;
		}

		/* @©ŒR’c
		      «
		   ›-œ-›-›

		   ‚Æ‚¢‚¤‚Ì‚ğ

		   ›-›-›

		   ‚Æ‚·‚éB
		*/

		int iPrevID =  pŒR’cî•ñ[iGundanID].‘O‚ÌŒR’cyŒR’c”Ô†z;
		int iNextID = pŒR’cî•ñ[iGundanID].Ÿ‚ÌŒR’cyŒR’c”Ô†z;

		// ©•ª‚Ìprev‚Í—LŒø‚ÈŒR’c‚¾B
		if ( 0 < iPrevID && iPrevID <= Å‘å”::ŒR’cî•ñ::”z—ñ” ) {

			// ©•ª‚ªæ“ª‚Å‚Í‚È‚¢ŒR’c‚ÅA
			// ‚P‚Â‘O‚ÌŒR’c‚ÌŸ‚ÌƒŠƒ“ƒNæ‚ª©ŒR’c‚Ìê‡
			if ( iPrevID != 0xFFFF && pŒR’cî•ñ[(iPrevID-1)].Ÿ‚ÌŒR’cyŒR’c”Ô†z == iGundanID+1 ) {
				// ©ŒR’c‚Å‚Í‚È‚­AŸ‚ÌŒR’c‚Ö‚ÆŒq‚¬‚©‚¦‚éB
				pŒR’cî•ñ[(iPrevID-1)].Ÿ‚ÌŒR’cyŒR’c”Ô†z = iNextID;
			}
		}

		// ©•ª‚Ìnext‚Í—LŒø‚ÈŒR’c‚¾B
		if ( 0 < iNextID && iNextID <= Å‘å”::ŒR’cî•ñ::”z—ñ” ) {
			// ‚P‚ÂŒã‚ÌŒR’c‚Ì‘O‚ÌƒŠƒ“ƒNæ‚ª©ŒR’c‚Ìê‡
			if ( iNextID != 0xFFFF && pŒR’cî•ñ[(iNextID-1)].‘O‚ÌŒR’cyŒR’c”Ô†z == iGundanID+1 ) {
				// ©ŒR’c‚Å‚Í‚È‚­A‘O‚ÌŒR’c‚Ö‚ÆŒq‚¬‚©‚¦‚éB
				pŒR’cî•ñ[(iNextID-1)].‘O‚ÌŒR’cyŒR’c”Ô†z = iPrevID;
			}
		}


		/* @
		     
		   ›-›

		   ‚Æ‚¢‚¤‚Ì‚ğ

		   ›-›-œ

		   ‚Æ‚·‚éB
		*/



		pŒR’cî•ñ[iLinkEndGundanID-1].Ÿ‚ÌŒR’cyŒR’c”Ô†z = iGundanID+1; // ƒŠƒ“ƒNƒŠƒXƒg‚ÌÅŒã‚ÌŒR’c‚Ìnext‚ğ©ŒR’c‚É

		pŒR’cî•ñ[iGundanID].‘O‚ÌŒR’cyŒR’c”Ô†z = iLinkEndGundanID; // ©ŒR’c‚Ì‘O‚ÌŒR’c‚ÍAŒR’c‚ÌƒŠƒ“ƒNƒŠƒXƒg‚ÌÅŒã‚ÌŒR’c

		// ©ŒR’c‚ÍAŒR’cƒŠƒXƒg‚Ìˆê”ÔÅŒã‚É‚­‚Á‚Â‚­B©ŒR’c‚Ìnext‚Í‹‚È‚¢
		pŒR’cî•ñ[iGundanID].Ÿ‚ÌŒR’cyŒR’c”Ô†z = 0xFFFF; // 

		// ƒƒ‚ƒŠ‘‚«Š·‚¦
		{
			pŒR’cî•ñ[iGundanID].ŒR’cŠ„“–”Ô† = 8; // ‚à‚¤•s³‚É‚È‚Á‚Ä‚µ‚Ü‚Á‚Ä‚¢‚é‚ª‚à‚Á‚Æ‚à‚‚¢Šm—¦‚ÅƒZ[ƒt‚È‚à‚Ì‚ğæ‚é

			”Ô†ƒŠƒXƒgŒ^ milist = Get_ŒR’c–¢Š„“–”Ô†ƒŠƒXƒg(VŠ‘®‘å–¼”Ô†y”z—ñ—pz);
			if ( milist.size() > 0 ) {
				pŒR’cî•ñ[iGundanID].ŒR’cŠ„“–”Ô† = milist[0]; // ‹ó”Ô†‚ÌÅ‰‚Ì‚à‚Ì‚ğ•ú‚è‚Ş
			}

			pŒR’cî•ñ[iGundanID].Š‘®‘å–¼y‘å–¼”Ô†z = VŠ‘®‘å–¼”Ô†y”z—ñ—pz+1;
		}

		for ( int iBushouID=0; iBushouID < Å‘å”::•«î•ñ::”z—ñ”; iBushouID++) {
			// w’è‚ÌŒR’c‚ÉŠ‘®‚µ‚Ä‚¢‚é•«‚ÍA‘S‚ÄAV‘å–¼‚ÉŠ‘®‚ğ•ÏX‚·‚éB
			if ( p•«î•ñ[iBushouID].Š‘®ŒR’cyŒR’c”Ô†z== iGundanID+1 ) {
				p•«î•ñ[iBushouID].Š‘®‘å–¼y‘å–¼”Ô†z = VŠ‘®‘å–¼”Ô†y”z—ñ—pz+1;
				p•«î•ñ[iBushouID].dŠ¯”N” = 0; // mŠ¯”N”ƒŠƒZƒbƒg
				p•«î•ñ[iBushouID].“à‰æ‘å–¼y‘å–¼”Ô†z = 0xFFFF; // “à‰æƒŠƒZƒbƒg
				p•«î•ñ[iBushouID].“à‰ó‘Ô = 0; // “à‰ó‘Ô‚È‚µ
				p•«î•ñ[iBushouID].ˆâ¦ó‘Ô = 0; // ˆâ¦‚È‚µ
			}
		}


		return true;

	}

	return false;
}

}

/*
 ŒR’c”Ô†‚ğˆø”‚Æ‚µ‚ÄAŒRt‚Ì•«”Ô†‚ğ“¾‚é
*/
int pCallFromFuncGetGunshiBushouID = 0x454BE9; //

int iReturnOfBushouIDGetGunshiBushou = 0xFFFF;
int iSigOfGundanIDGetGunshiBushou = 0xFFFF;

void _FuncGetGunshiBushouIDAsm() {
	__asm {
		// ŒR’c”Ô†‚ªˆø”
		MOV     ESI, iSigOfGundanIDGetGunshiBushou

		// ŒR’c”Ô†‚ğˆø”‚Æ‚µ‚ÄAŒRt”Ô†‚ğ“¾‚é‚½‚ß‚ÌŠÖ”‚ğŒÄ‚Ño‚·
		PUSH    ESI
		CALL    pCallFromFuncGetGunshiBushouID
		ADD     ESP, 4

		MOV iReturnOfBushouIDGetGunshiBushou, EAX // Œ‹‰Ê‚Ì‚¤‚¿AAX‚Ì”Ô†‚ğŒRt•«”Ô†‚Æ‚µ‚Ä•Û‘¶

	}
}

namespace ŠÖ” {
// ŒR’c‚ÌŒRt•«‚ğ“¾‚éBŒRt‚½‚éÒ‚ª‹‚È‚¯‚ê‚Î0xFFFF‚ª•Ô‚Á‚Ä‚­‚éB
int Get_ŒRt•«”Ô†y”z—ñ—pz(int ŒR’c”Ô†y”z—ñ—pz) {

	if ( 0 <= ŒR’c”Ô†y”z—ñ—pz && ŒR’c”Ô†y”z—ñ—pz < Å‘å”::ŒR’cî•ñ::”z—ñ” ) {

		iSigOfGundanIDGetGunshiBushou = ŒR’c”Ô†y”z—ñ—pz+1; // ”z—ñ—p¨ŒR’c‚É•ÏX

		iReturnOfBushouIDGetGunshiBushou = 0xFFFF; // ‚Ü‚¸‚ÍA–ˆ“x‚±‚Ì’l‚ÅƒŠƒZƒbƒgB

		__asm {
			push eax
			push ebx
			push ecx
			push edx
			push esp
			push esi
			push edi
		}

		// TENSHOU.EXE“à‚ÌŠÖ”ŒÄ‚Ño‚µ
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

		iReturnOfBushouIDGetGunshiBushou = iReturnOfBushouIDGetGunshiBushou & 0xFFFF; // EAX‚Ì‚¤‚¿AAX‚Ì•”•ª‚¾‚¯—˜—p‚·‚éB

		// ‚»‚ÌŒR’c‚ÉŒRt‚ª‹‚½‚È‚ç‚Î
		if ( 0 <= iReturnOfBushouIDGetGunshiBushou-1 && iReturnOfBushouIDGetGunshiBushou-1 < Å‘å”::•«î•ñ::”z—ñ” ) {
			return iReturnOfBushouIDGetGunshiBushou-1; // •«”Ô†¨•«”Ô†”z—ñ—p‚É‚µ‚Ä•Ô‚·
		}
	}

	// ‹‚È‚¢ê‡‚â•s³‚Èê‡‚Í‘S•”‚±‚êB
	return 0xFFFF;
}



// ‘ÎÛ‚Ì‘å–¼‚ªƒvƒŒƒCƒ„[’S“–‚Ì‘å–¼‚Å‚ ‚é‚©‚Ç‚¤‚©‚ğ”»’f‚·‚éB
// ‘å–¼”Ô†y”z—ñ—pz‚É‚Í”z—ñã‚Ì”Ô†(attach-1‚Ì”)‚ğ“n‚·‚±‚Æ
bool Is_ƒvƒŒƒCƒ„’S“–‘å–¼( WORD ‘å–¼”Ô†y”z—ñ—pz ) {

	// ‘å–¼ID‚Ì”ÍˆÍ‚Éû‚Ü‚Á‚Ä‚¢‚é‚±‚Æ
	if ( 0 <= ‘å–¼”Ô†y”z—ñ—pz&& ‘å–¼”Ô†y”z—ñ—pz < Å‘å”::‘å–¼î•ñ::”z—ñ” ) {
		// ƒ^[ƒQƒbƒg‚Ì•«‚ÌŒR’cID‚ªƒvƒŒƒCƒ„[‚ÌŒR’c‚Å‚ ‚é‚©‚ğ•Ô‚·
		return Is_ƒvƒŒƒCƒ„’S“–ŒR’c(p‘å–¼î•ñ[‘å–¼”Ô†y”z—ñ—pz].Š‘®ŒR’cyŒR’c”Ô†z-1);
	} else {
		return false;
	}
}



// ‘ÎÛ‚ÌŒR’c‚ªƒvƒŒƒCƒ„[’S“–ŒR’c‚Ì¨—Í‰º‚ÌŒR’c‚Å‚ ‚é‚©‚Ç‚¤‚©‚ğ”»’f‚·‚éB
// iTargetGundanID‚É‚Í”z—ñã‚Ì”Ô†(attach-1‚Ì”)‚ğ“n‚·‚±‚Æ
bool Is_ƒvƒŒƒCƒ„’S“–ŒR’c( WORD ŒR’c”Ô†y”z—ñ—pz ) {

	if (ŒR’c”Ô†y”z—ñ—pz >= Å‘å”::ŒR’cî•ñ::”z—ñ” ) { 
		return false;
	}

	WORD ixyŒR’c”Ô†z = 0;
	for ( int n”Ô–Ú=0; n”Ô–Ú< Å‘å”::ƒvƒŒƒCƒ„’S“–ŒR’cî•ñ::”z—ñ”; n”Ô–Ú++) {
		// ƒvƒŒƒCƒ„[‚ª’S“–‚µ‚Ä‚¢‚éŒR’c‚Ì‚h‚c‚ğŠm•Û
		ixyŒR’c”Ô†z = pƒvƒŒƒCƒ„’S“–ŒR’cî•ñ[n”Ô–Ú].’S“–ŒR’cyŒR’c”Ô†z;

		// 0xFFFF‚È‚ç‚ÎƒvƒŒƒCƒ„[‚Å‚Í‚È‚¢
		if ( ixyŒR’c”Ô†z == 0xFFFF ) {
			continue;
		}

		// ƒvƒŒƒCƒ„[’S“–‚ÌŒR’c‚Ì‘å–¼‚ªAƒ^[ƒQƒbƒg‚Æ‚µ‚Ä‚¢‚é‘ÎÛ‚ÌŒR’c‚Ì‘å–¼‚Æˆê’v‚·‚é‚È‚ç‚ÎA
		// ‚»‚ê‚ÍƒvƒŒƒCƒ„[‚Ì¨—Í‰º‚ÌŒR’c‚Å‚ ‚éB
		// ‚Ç‚¤‚ànb6player8‚Ìgundan‚Ì’l‚ÍA“à•”ŠÇ—‚Ìgundan‚Ì’l‚æ‚è‚à+1‚³‚ê‚Ä‚¢‚é‚æ‚¤‚Å‚ ‚éB
		// ‚æ‚Á‚Ä‚±‚±‚Å‚Í-1‚·‚éB
		if (ixyŒR’c”Ô†z >= 1 && pŒR’cî•ñ[ixyŒR’c”Ô†z-1].Š‘®‘å–¼y‘å–¼”Ô†z == pŒR’cî•ñ[ŒR’c”Ô†y”z—ñ—pz].Š‘®‘å–¼y‘å–¼”Ô†z ) {
			return true;
		}
	}
	
	return false;
}


// ‘ÎÛ‚Ì•«‚ª‚¢‚¸‚ê‚©‚ÌƒvƒŒƒCƒ„[¨—Í‰º‚Ì•«‚Å‚ ‚é
bool Is_ƒvƒŒƒCƒ„’S“–•«( WORD •«”Ô†y”z—ñ—pz ) {

	// •«ID‚Ì”ÍˆÍ‚Éû‚Ü‚Á‚Ä‚¢‚é‚±‚Æ
	if ( 0 <= •«”Ô†y”z—ñ—pz && •«”Ô†y”z—ñ—pz < Å‘å”::•«î•ñ::”z—ñ” ) {

		// ƒ^[ƒQƒbƒg‚Ì•«‚ÌŒR’cID‚ªƒvƒŒƒCƒ„[‚ÌŒR’c‚Å‚ ‚é‚©‚ğ•Ô‚·
		return Is_ƒvƒŒƒCƒ„’S“–ŒR’c(p•«î•ñ[•«”Ô†y”z—ñ—pz].Š‘®ŒR’cyŒR’c”Ô†z-1);

	} else {
		return false;
	}
}


}


