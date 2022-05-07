#include <cassert>
#include "ƒQ[ƒ€ƒf[ƒ^\‘¢.h"


namespace ŠÖ” {


// ‘å–¼ID‚©‚ç³‹K‰»‚³‚ê‚½(0`7‚Ö‚ÆU‚è‚È‚¨‚³‚ê‚½)–ğEID‚ğ“¾‚é
int Get_‘å–¼–ğE(int ‘å–¼”Ô†y”z—ñ—pz) {

	// ”ÍˆÍƒ`ƒFƒbƒN
	if ( 0 <= ‘å–¼”Ô†y”z—ñ—pz && ‘å–¼”Ô†y”z—ñ—pz < Å‘å”::•«î•ñ::”z—ñ” ) { 

		switch ( p‘å–¼î•ñ[‘å–¼”Ô†y”z—ñ—pz]._–ğE) {
			case 0x01:
				return –ğE::ªˆÎ‘å«ŒR;
			case 0x02:
				return –ğE::ŠÇ—Ì;
			case 0x04:
				return –ğE::ŠÖ“ŒŠÇ—Ì;
			case 0x08 :
				return –ğE::‰œB’T‘è;
			case 0x10:
				return –ğE::¼‘’T‘è;
			case 0x20:
				return –ğE::‹ãB’T‘è;
			case 0x40:
				return –ğE::‰HB’T‘è;
			default:
				return 0;
		}
	}
	return 0;
}

// ŒR’cID‚©‚ç³‹K‰»‚³‚ê‚½–ğEID‚ğ“¾‚é
int Get_ŒR’c–ğE(int ŒR’c”Ô†y”z—ñ—pz) {

	// ”ÍˆÍƒ`ƒFƒbƒN
	if ( 0 <= ŒR’c”Ô†y”z—ñ—pz && ŒR’c”Ô†y”z—ñ—pz < Å‘å”::ŒR’cî•ñ::”z—ñ” ) { 
		return pŒR’cî•ñ[ŒR’c”Ô†y”z—ñ—pz]._–ğE;
	}
	ƒfƒoƒbƒOo—Í("w’è‚ÌŒR’c”Ô†y”z—ñ—pz‚Í”ÍˆÍŠO");
	return -1;
}



}