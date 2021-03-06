/*
 * This file is part of the UCB release of Plan 9. It is subject to the license
 * terms in the LICENSE file found in the top-level directory of this
 * distribution and at http://akaros.cs.berkeley.edu/files/Plan9License. No
 * part of the UCB release of Plan 9, including this file, may be copied,
 * modified, propagated, or distributed except according to the terms contained
 * in the LICENSE file.
 */

#include	"l.h"

#define	X	99

Optab	optab[] =
{
	{ ATEXT,	C_LEXT,	C_NONE,	C_LCON, 	 0, 0, 0 },
	{ ATEXT,	C_LEXT,	C_REG,	C_LCON, 	 0, 0, 0 },
	{ ANOP,		C_NONE,	C_NONE,	C_NONE, 	 0, 0, 0 },

	{ AMOVW,	C_REG,	C_NONE,	C_REG,		 1, 4, 0 },

	{ AMOVW,	C_SCON,	C_NONE,	C_REG,		 2, 4, 0 },
	{ AMOVW,	C_SACON,C_NONE,	C_REG,		 2, 4, REGSP },
	{ AMOVW,	C_SECON,C_NONE,	C_REG,		 2, 4, REGSB },

	{ AMOVW,	C_SOREG,C_NONE,	C_REG,		 3, 4, 0 },
	{ AMOVW,	C_ZOREG,C_REG,	C_REG,		 3, 4, 0 },
	{ AMOVW,	C_SAUTO,C_NONE,	C_REG,		 3, 4, REGSP },
	{ AMOVW,	C_SEXT,	C_NONE,	C_REG,		 3, 4, REGSB },
	{ AMOVB,	C_SOREG,C_NONE,	C_REG,		 3, 4, 0 },
	{ AMOVB,	C_ZOREG,C_REG,	C_REG,		 3, 4, 0 },
	{ AMOVB,	C_SAUTO,C_NONE,	C_REG,		 3, 4, REGSP },
	{ AMOVB,	C_SEXT,	C_NONE,	C_REG,		 3, 4, REGSB },
	{ AMOVD,	C_SOREG,C_NONE,	C_REG,		 3, 4, 0 },
	{ AMOVD,	C_ZOREG,C_REG,	C_REG,		 3, 4, 0 },
	{ AMOVD,	C_SAUTO,C_NONE,	C_REG,		 3, 4, REGSP },
	{ AMOVD,	C_SEXT,	C_NONE,	C_REG,		 3, 4, REGSB },

	{ AMOVW,	C_REG,	C_NONE,	C_SOREG,	 4, 4, 0 },
	{ AMOVW,	C_REG,	C_REG,	C_ZOREG,	 4, 4, 0 },
	{ AMOVW,	C_REG,	C_NONE,	C_SAUTO,	 4, 4, REGSP },
	{ AMOVW,	C_REG,	C_NONE,	C_SEXT,		 4, 4, REGSB },
	{ AMOVB,	C_REG,	C_NONE,	C_SOREG,	 4, 4, 0 },
	{ AMOVB,	C_REG,	C_REG,	C_ZOREG,	 4, 4, 0 },
	{ AMOVB,	C_REG,	C_NONE,	C_SAUTO,	 4, 4, REGSP },
	{ AMOVB,	C_REG,	C_NONE,	C_SEXT,		 4, 4, REGSB },
	{ AMOVD,	C_REG,	C_NONE,	C_SOREG,	 4, 4, 0 },
	{ AMOVD,	C_REG,	C_REG,	C_ZOREG,	 4, 4, 0 },
	{ AMOVD,	C_REG,	C_NONE,	C_SAUTO,	 4, 4, REGSP },
	{ AMOVD,	C_REG,	C_NONE,	C_SEXT,		 4, 4, REGSB },

	{ AMOVW,	C_LCON,	C_NONE,	C_REG,		 5, 8, 0 },

	{ AMOVW,	C_ASI,	C_NONE,	C_REG,		 6, 4, 0 },
	{ AMOVW,	C_ASI,	C_REG,	C_REG,		 6, 4, 0 },
	{ AMOVB,	C_ASI,	C_NONE,	C_REG,		 6, 4, 0 },
	{ AMOVB,	C_ASI,	C_REG,	C_REG,		 6, 4, 0 },
	{ AMOVD,	C_ASI,	C_NONE,	C_REG,		 6, 4, 0 },
	{ AMOVD,	C_ASI,	C_REG,	C_REG,		 6, 4, 0 },

	{ AMOVW,	C_REG,	C_NONE,	C_ASI,		 7, 4, 0 },
	{ AMOVW,	C_REG,	C_REG,	C_ASI,		 7, 4, 0 },
	{ AMOVB,	C_REG,	C_NONE,	C_ASI,		 7, 4, 0 },
	{ AMOVB,	C_REG,	C_REG,	C_ASI,		 7, 4, 0 },
	{ AMOVD,	C_REG,	C_NONE,	C_ASI,		 7, 4, 0 },
	{ AMOVD,	C_REG,	C_REG,	C_ASI,		 7, 4, 0 },

	{ AMOVW,	C_REG,	C_NONE,	C_PREG,		 8, 4, 0 },
	{ AMOVW,	C_PREG,	C_NONE,	C_REG,		 8, 4, 0 },

	{ AMOVB,	C_REG,	C_NONE,	C_REG,		 9, 8, 0 },

	{ AMOVW,	C_LACON,C_NONE,	C_REG,		10,12, REGSP },
	{ AMOVW,	C_LECON,C_NONE,	C_REG,		10,12, REGSB },

	{ AMOVW,	C_LOREG,C_NONE,	C_REG,		11,12, 0 },
	{ AMOVW,	C_LAUTO,C_NONE,	C_REG,		11,12, REGSP },
	{ AMOVW,	C_LEXT,	C_NONE,	C_REG,		11,12, REGSB },
	{ AMOVB,	C_LOREG,C_NONE,	C_REG,		11,12, 0 },
	{ AMOVB,	C_LAUTO,C_NONE,	C_REG,		11,12, REGSP },
	{ AMOVB,	C_LEXT,	C_NONE,	C_REG,		11,12, REGSB },
	{ AMOVD,	C_LOREG,C_NONE,	C_REG,		11,12, 0 },
	{ AMOVD,	C_LAUTO,C_NONE,	C_REG,		11,12, REGSP },
	{ AMOVD,	C_LEXT,	C_NONE,	C_REG,		11,12, REGSB },

	{ AMOVW,	C_REG,	C_NONE,	C_LOREG,	12,12, 0 },
	{ AMOVW,	C_REG,	C_NONE,	C_LAUTO,	12,12, REGSP },
	{ AMOVW,	C_REG,	C_NONE,	C_LEXT,		12,12, REGSB },
	{ AMOVB,	C_REG,	C_NONE,	C_LOREG,	12,12, 0 },
	{ AMOVB,	C_REG,	C_NONE,	C_LAUTO,	12,12, REGSP },
	{ AMOVB,	C_REG,	C_NONE,	C_LEXT,		12,12, REGSB },
	{ AMOVD,	C_REG,	C_NONE,	C_LOREG,	12,12, 0 },
	{ AMOVD,	C_REG,	C_NONE,	C_LAUTO,	12,12, REGSP },
	{ AMOVD,	C_REG,	C_NONE,	C_LEXT,		12,12, REGSB },

	{ AMOVW,	C_UCON,	C_NONE,	C_REG,		13, 4, 0 },

	{ AADD,		C_SCON,	C_NONE,	C_REG,		20, 4, 0 },
	{ AADD,		C_SCON,	C_REG,	C_REG,		20, 4, 0 },

	{ AADD,		C_REG,	C_NONE,	C_REG,		21, 4, 0 },
	{ AADD,		C_REG,	C_REG,	C_REG,		21, 4, 0 },

	{ AADD,		C_LCON,	C_NONE,	C_REG,		22,12, 0 },
	{ AADD,		C_LCON,	C_REG,	C_REG,		22,12, 0 },

	{ ACMP,		C_REG,	C_NONE,	C_REG,		23, 4, 0 },
	{ ACMP,		C_REG,	C_NONE,	C_SCON,		24, 4, 0 },
	{ ACMP,		C_SCON,	C_NONE,	C_REG,		25, 8, 0 },

	{ AADD,		C_UCON,	C_NONE,	C_REG,		26, 8, 0 },
	{ AADD,		C_UCON,	C_REG,	C_REG,		26, 8, 0 },

	{ AJMP,		C_NONE,	C_NONE,	C_SOREG,	30, 4, 0 },
	{ AJMPL,	C_NONE,	C_NONE,	C_SOREG,	30, 4, 0 },

	{ AJMP,		C_NONE,	C_NONE,	C_SBRA,		31, 4, 0 },
	{ ABA,		C_NONE,	C_NONE,	C_SBRA,		31, 4, 0 },

	{ AJMPL,	C_NONE,	C_NONE,	C_LBRA,		32, 4, 0 },

	{ ATA,		C_REG,	C_NONE,	C_NONE,		33, 4, 0 },
	{ ARETT,	C_REG,	C_NONE,	C_REG,		34, 8, 0 },

	{ AMOVW,	C_SOREG,C_NONE,	C_FSR,		40, 4, 0 },
	{ AMOVW,	C_SAUTO,C_NONE,	C_FSR,		40, 4, REGSP },
	{ AMOVW,	C_SEXT,	C_NONE,	C_FSR,		40, 4, REGSB },
	{ AMOVW,	C_FSR,	C_NONE,	C_SOREG,	40, 4, 0 },
	{ AMOVW,	C_FSR,	C_NONE,	C_SAUTO,	40, 4, REGSP },
	{ AMOVW,	C_FSR,	C_NONE,	C_SEXT,		40, 4, REGSB },
	{ AMOVD,	C_FQ,	C_NONE,	C_SOREG,	40, 4, 0 },
	{ AMOVD,	C_FQ,	C_NONE,	C_SAUTO,	40, 4, REGSP },
	{ AMOVD,	C_FQ,	C_NONE,	C_SEXT,		40, 4, REGSB },

	{ AFMOVF,	C_SOREG,C_NONE,	C_FREG,		41, 4, 0 },
	{ AFMOVF,	C_SAUTO,C_NONE,	C_FREG,		41, 4, REGSP },
	{ AFMOVF,	C_SEXT,	C_NONE,	C_FREG,		41, 4, REGSB },
	{ AMOVW,	C_SOREG,C_NONE,	C_FREG,		41, 4, 0 },
	{ AMOVW,	C_SAUTO,C_NONE,	C_FREG,		41, 4, REGSP },
	{ AMOVW,	C_SEXT,	C_NONE,	C_FREG,		41, 4, REGSB },
	{ AMOVD,	C_SOREG,C_NONE,	C_FREG,		41, 4, 0 },
	{ AMOVD,	C_SAUTO,C_NONE,	C_FREG,		41, 4, REGSP },
	{ AFMOVD,	C_ESAUTO,C_NONE,C_FREG,		41, 4, REGSP },
	{ AMOVD,	C_SEXT,	C_NONE,	C_FREG,		41, 4, REGSB },
	{ AFMOVD,	C_ESEXT,C_NONE,	C_FREG,		41, 4, REGSB },

	{ AFMOVD,	C_SOREG,C_NONE,	C_FREG,		42, 8, 0 },
	{ AFMOVD,	C_SAUTO,C_NONE,	C_FREG,		42, 8, REGSP },
	{ AFMOVD,	C_SEXT,	C_NONE,	C_FREG,		42, 8, REGSB },

	{ AFMOVF,	C_FREG,	C_NONE,	C_SOREG,	43, 4, 0 },
	{ AFMOVF,	C_FREG,	C_NONE,	C_SAUTO,	43, 4, REGSP },
	{ AFMOVF,	C_FREG,	C_NONE,	C_SEXT,		43, 4, REGSB },
	{ AMOVW,	C_FREG,	C_NONE,	C_SOREG,	43, 4, 0 },
	{ AMOVW,	C_FREG,	C_NONE,	C_SAUTO,	43, 4, REGSP },
	{ AMOVW,	C_FREG,	C_NONE,	C_SEXT,		43, 4, REGSB },
	{ AMOVD,	C_FREG,	C_NONE,	C_SOREG,	43, 4, 0 },
	{ AMOVD,	C_FREG,	C_NONE,	C_SAUTO,	43, 4, REGSP },
	{ AFMOVD,	C_FREG,	C_NONE,	C_ESAUTO,	43, 4, REGSP },
	{ AMOVD,	C_FREG,	C_NONE,	C_SEXT,		43, 4, REGSB },
	{ AFMOVD,	C_FREG,	C_NONE,	C_ESEXT,	43, 4, REGSB },

	{ AFMOVD,	C_FREG,	C_NONE,	C_SOREG,	44, 8, 0 },
	{ AFMOVD,	C_FREG,	C_NONE,	C_SAUTO,	44, 8, REGSP },
	{ AFMOVD,	C_FREG,	C_NONE,	C_SEXT,		44, 8, REGSB },

	{ AFMOVF,	C_LOREG,C_NONE,	C_FREG,		45,12, 0 },
	{ AFMOVF,	C_LAUTO,C_NONE,	C_FREG,		45,12, REGSP },
	{ AFMOVF,	C_LEXT,	C_NONE,	C_FREG,		45,12, REGSB },

	{ AFMOVD,	C_LOREG,C_NONE,	C_FREG,		46,16, 0 },
	{ AFMOVD,	C_LAUTO,C_NONE,	C_FREG,		46,16, REGSP },
	{ AFMOVD,	C_LEXT,	C_NONE,	C_FREG,		46,16, REGSB },

	{ AFMOVF,	C_FREG,	C_NONE,	C_LOREG,	47,12, 0 },
	{ AFMOVF,	C_FREG,	C_NONE,	C_LAUTO,	47,12, REGSP },
	{ AFMOVF,	C_FREG,	C_NONE,	C_LEXT,		47,12, REGSB },

	{ AFMOVD,	C_FREG,	C_NONE,	C_LOREG,	48,16, 0 },
	{ AFMOVD,	C_FREG,	C_NONE,	C_LAUTO,	48,16, REGSP },
	{ AFMOVD,	C_FREG,	C_NONE,	C_LEXT,		48,16, REGSB },

	{ AFMOVD,	C_FREG,	C_NONE,	C_FREG,		49, 8, 0 },
	{ AFCMPD,	C_FREG,	C_NONE,	C_FREG,		50, 4, 0 },

	{ AFABSF,	C_FREG,	C_NONE,	C_FREG,		57, 4, 0 },
	{ AFMOVF,	C_FREG,	C_NONE,	C_FREG,		57, 4, 0 },
	{ AFADDD,	C_FREG,	C_NONE,	C_FREG,		21, 4, 0 },
	{ AFADDD,	C_FREG,	C_REG,	C_FREG,		21, 4, 0 },

	{ AWORD,	C_LCON,	C_NONE,	C_NONE,		51, 4, 0 },

	{ ADIV,		C_REG,	C_NONE,	C_REG,		52,12, 0 },
	{ ADIV,		C_REG,	C_REG,	C_REG,		52,12, 0 },

	{ ADIVL,	C_REG,	C_NONE,	C_REG,		53, 8, 0 },
	{ ADIVL,	C_REG,	C_REG,	C_REG,		53, 8, 0 },

	{ AMOD,		C_REG,	C_NONE,	C_REG,		54,20, 0 },
	{ AMOD,		C_REG,	C_REG,	C_REG,		54,20, 0 },

	{ AMODL,	C_REG,	C_NONE,	C_REG,		55,16, 0 },
	{ AMODL,	C_REG,	C_REG,	C_REG,		55,16, 0 },

	{ ABE,		C_NONE,	C_NONE,	C_SBRA,		56, 4, 0 },

	{ AXXX,		C_NONE,	C_NONE,	C_NONE,		 0, 4, 0 },
};
