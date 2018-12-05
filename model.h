#pragma once
#include <string>
#include <iostream>
#include <QtCore>
#include <QDebug>

#include <highfive/H5Attribute.hpp>
#include <highfive/H5File.hpp>
#include <highfive/H5DataSet.hpp>
#include <highfive/H5DataSpace.hpp>
#include "data.h"
#include "parametrs.h"
#include "result.h"

#include <math.h>
using namespace std;
using namespace HighFive;
class Model : public QObject
{
	Q_OBJECT
public:
	int ROW;
	double MAT;
	double iniPheno;
	double iniLai;
	double iniDMP;
	double iniDMD;
	double iniSW;
	double iniPNB;
	double CumFind;//FindSowingData
	double CDB;

	//SoilWater
	double CLL;
	double ISATSW;
	double ATSW;
	double TTSW;
	double FTSW;
	double WSTORG;
	double ATSW1;
	double TTSW1;
	double FTSW1;
	double WLL1;
	double WAT1;
	double WSAT1;
	double WLL;
	double WATRT;
	double WSAT;
	double EOSMIN;
	double WETWAT;
	double KET;
	double CALB;
	double CTR;
	double CE;
	double CRAIN;
	double CRUNOF;
	double CIRGW;
	double IRGNO;
	double DDMP;
	double LAI;
	double LtDrCntr;
	double SE2C;
	double SE1MX;
	double DSR;
	double SSE1;
	double SSE;

	double IRGW;

	double DRAIN1;
	double DRAIN;
	double GRTD;////
	double CBD;///

	double EWAT;//
	double RUNOF;//
	double s;//
	double SWER;//
//	double RAIN;//
	double ETLAI;//
	double BSGLAI;//
	double TD;//
	double ALBEDO;//
	double EEQ;//
	double PET;//

	double EOS;//
	double SEVP;//
	double DYSE;//

	double semethod;
	double FLUX1;
	double vpdtp;
	double VPTMIN;
	double VPTMAX;
	double VPD;
	double TR;


	double TR1;
	double RT1;
	double WSFN;
	double WSFG;
	double WSFL;
	double WSFD;

	double LtDrCnt;

	//WEATHER
	double TMP;

	double DOY;
	double dtEM;
	double dtR1;
	double dtR3;
	double dtR5;
	double dtR7;
	double  dtR8;
	double  MXLAI;
	double BSGDM;
	double  WTOP;
	double WGRN;
	double  NLF;
	double  NST;
	double  NVEG;
	double  NGRN;
	double  CNUP;

	double bdEM;

	double bdR1;
	double bdR3;

	double bdR5;
	double bdR7;
	double bdR8;

	double  bdBLG;

	double  bdTLM;
	double bdTLP;


	double DAP;
	double tempfun;
	double DTT;

	double SABH;
	double Pi;
	double RDN;
	double ALPHA;
	double SMA3;
	double LANDA;
	double DEC;
	double TALSOC;

	double CEDSOC;
	double SOCRA;
	double DL;
	double pp;
	double ppfun;
	double bd;///bio days;


	double PLAPOW;
	double MSNN;
	double PLA2;
	double PLA1;
//	double  LAI;//LATITUDE 
//	double MXLAI;
//	double WSFL;
//	double  SLNG;////////в data_p

	double GLAI;

	double DLAI;

	double INODE;
	double GLF;

	double TCFRUE;
	double RUE;
	double VPDcr;
	double LAT;
	double DECL;
	double SINLD;
	double COSLD;
	double AOB;
	double AOB2;
	double DAYL;
	double DSINB;
	double DSINBE;
	double SC;
	double DSO;
	double Bnoon;
	double DTR;
	double TC;
	double P;
	double SUNRIS;
	double SUNSET;


	double TSUNST;
	double NIGHTL;
	double TEMP1;
	double TMINA;

	double TMAXB;
	double SINB;
	double BET;
	double SRAD1;
	double BETA;
	double FINT;
	double DDMP1;

	double VPTEMP1;
	double VPD1;


	//LEGUMpLANT
	double NUP;
	double XNLF;
	double XNST;
	double INLF;
	double INST;
	double INGRN;

	double NFC;
	double PDNF;
	double DNF;
	double TRLN;
	double FXLF;


	//dmddistribution
	double WLF;
	double WST;
	double WVEG;
	double TRANSL;
	double SGR;
	double DHI;
	double DHIF;
	double TRLDM;
	double DDMP2;
	double FLF1;
	double GST;
	double HI;
	Data data;
	Parametrs param;
	Result res;

	int Pyear;
	int Pdoy;
	int Yr;
	explicit Model(Parametrs new_param, QObject *parent = 0) : QObject(parent), param(new_param)
	{
		run_h5();
	}
public slots:

	void SoilWater()
	{
		if (iniSW == 0)
		{
			//Parameters and Initials
			ISATSW = param.SOLDEP * param.EXTR * param.MAI;
			ATSW = data.data_p.DEPORT * param.EXTR * param.MAI1;
			TTSW = data.data_p.DEPORT * param.EXTR;
			FTSW = ATSW / TTSW;
			WSTORG = ISATSW - ATSW;

			ATSW1 = param.DEP1 *  param.EXTR * param.MAI1;
			TTSW1 = param.DEP1 *  param.EXTR;
			FTSW1 = ATSW1 / TTSW1;

			WLL1 = param.DEP1 * CLL;
			WAT1 = WLL1 + ATSW1;
			WSAT1 = param.DEP1  * param.SAT;

			WLL = data.data_p.DEPORT * CLL;
			WATRT = WLL + ATSW;
			WSAT = data.data_p.DEPORT *  param.SAT;

			EOSMIN = 1.5;
			WETWAT = 10;
			KET = 0.5;
			CALB = 0.23;

			DYSE = 1;
			CTR = 0;
			CE = 0;
			CRAIN = 0;
			CRUNOF = 0; CIRGW = 0;
			IRGNO = 0;
			DDMP = 0;
			LAI = 0;
			LtDrCntr = 0;

			SE2C = 3.5;
			SE1MX = param.U; 
			DSR = 1;
			SSE1 = param.U;
			SSE = param.U + SE2C;
			iniSW = 1;
		}
		//Irrigation
		if (param.water == 1 && FTSW <= param.IRGLVL)/// && CDB < ???bdTSG?? )
		{
			IRGW = (TTSW - ATSW);
			IRGNO = IRGNO + 1;
		}
		else
			IRGW = 0;

		CIRGW = CIRGW + IRGW;

		// Drainage
		if (ATSW1 <= TTSW1)
			DRAIN1 = 0;
		else if (ATSW1 > TTSW1)
			DRAIN1 = (ATSW1 - TTSW1) * param.DRAINF;

		if (ATSW <= TTSW)
			DRAIN = 0;
		else if (ATSW > TTSW)
			DRAIN = (ATSW - TTSW) * param.DRAINF;
		WSTORG = WSTORG + DRAIN;// -EWAT
		if (WSTORG < 0)
			WSTORG = 0;

		//Water exploitation by root growth
		GRTD = data.data_p.GRTDP;//
		if (CBD < data.data_p.ttBRG)//bdBRG)
			GRTD = 0;
		if (CBD > data.data_p.ttTRG)//bdTRG)
			GRTD = 0;
		if (DDMP = 0)
			GRTD = 0;
		if (data.data_p.DEPORT >= param.SOLDEP)
			GRTD = 0;
		if (data.data_p.DEPORT >= data.data_p.EED)
			GRTD = 0;
		if (WSTORG = 0)
			GRTD = 0;
		data.data_p.DEPORT = data.data_p.DEPORT + GRTD;

		EWAT = GRTD * param.EXTR;
		if (EWAT > WSTORG)
			EWAT = WSTORG;

		
		RUNOF = 0;
		if (param.water = 2 && data.data_h5.rain[ROW] > 0.01)//RAIN ИЗ ТАБЛИЦЫ
		{
			s = 254 * (100 / param.CN2 - 1);//CN
			SWER = 0.15 * ((WSAT1 - WAT1) / (WSAT1 - WLL1));
			if (SWER < 0)
				SWER = 0;
			if ((data.data_h5.rain[ROW] - SWER * s) > 0)
				RUNOF = pow((data.data_h5.rain[ROW] - SWER * s),2 )/ (data.data_h5.rain[ROW] + (1 - SWER) * s);
			else
				RUNOF = 0;
		}

		if ((WAT1 - DRAIN1) > WSAT1)
			RUNOF = RUNOF + (WAT1 - DRAIN1 - WSAT1);

		CRAIN = CRAIN + data.data_h5.rain[ROW];
		CRUNOF = CRUNOF + RUNOF;

		//LAI for soil evaporation
		if (CBD <= data.data_p.ttBSG)//bdBSG)
			ETLAI = LAI;
		else
			ETLAI = BSGLAI;

		// Potential ET
		TD = 0.6 * data.data_h5.tmax[ROW]/*TMAX*/ + 0.4 * data.data_h5.tmin[ROW];
		ALBEDO = CALB * (1 - exp(-KET * ETLAI)) + param.SALB * exp(-KET * ETLAI);
		EEQ = data.data_h5.srad[ROW] * (0.004876 - 0.004374 * ALBEDO) * (TD + 29);
		PET = EEQ * 1.1;
		if (data.data_h5.tmax[ROW] > 34)
			PET = EEQ * ((data.data_h5.tmax[ROW] - 34) * 0.05 + 1.1);
		if (data.data_h5.tmax[ROW] < 5)
			PET = EEQ * 0.01 * exp(0.18 * (data.data_h5.tmax[ROW] + 20));

	   // Soil evaporation
		EOS = PET * exp(-KET * ETLAI);
		if (PET > EOSMIN && EOS < EOSMIN)
			EOS = EOSMIN;

		SEVP = EOS;
		if ((data.data_h5.rain[ROW] + IRGW) > WETWAT)
			DYSE = 1;
		if (DYSE > 1 || FTSW < 0.5 || ATSW1 <= 2)
		{
			SEVP = EOS * (pow((DYSE + 1), 0.5 )- pow(DYSE,0.5));
			DYSE = DYSE + 1;
		}
		//////////////
		if (semethod = 2) 
		{
			if (ATSW1 < 0)
				SEVP = 0;
			else
			{

				if (SSE1 < SE1MX)
				{
					//	'Stage I evaporation
					SEVP = EOS;
					if (SEVP > (SE1MX - SSE1))
						SEVP = SE1MX - SSE1;
					SSE1 = SSE1 + SEVP;
					SSE = SSE + SEVP;
					if (SSE1 >= SE1MX)
					{
							//Transition from Stage I to Stage II
						SEVP = SEVP + SE2C * (pow(DSR, 0.5) - pow((DSR - 1) , 0.5)) * (1 - (SEVP / EOS));
						DSR = DSR + 1 - SEVP / EOS;
					}
				}
				else
				{
					//Stage II evaporation
					SEVP = SE2C * (pow(DSR, 0.5) - pow((DSR - 1),0.5));
					if (SEVP > EOS)
						SEVP = EOS;
					DSR = DSR + 1;
					SSE = SSE + SEVP;
				}

				FLUX1 = data.data_h5.rain[ROW] + IRGW - RUNOF;
				if (FLUX1 >= SSE1)
				{
					SSE = SSE - FLUX1;
					if (SSE < 0)
					{
						SSE = 0;
						SSE1 = 0;
						DSR = 1 + pow((SSE / SE2C), 0.5);
					}
				}
				else
				{
					SSE = SSE - FLUX1;
					SSE1 = SSE1 - FLUX1;
					DSR = 1 + pow((SSE / SE2C), 0.5);
				}
			}
		}
		CE = CE + SEVP;

		//Plant transpiration
		if (vpdtp == 1 || vpdtp == 3)
		{
			VPTMIN = 0.6108 * exp(17.27 * data.data_h5.tmin[ROW]/ (data.data_h5.tmin[ROW] + 237.3));
			VPTMAX = 0.6108 * exp(17.27 * data.data_h5.tmax[ROW] / (data.data_h5.tmax[ROW] + 237.3));
			VPD = param.VPDF * (VPTMAX - VPTMIN);
			TR = DDMP * VPD / data.data_p.TEC;    //    'VPD in kPa, TEC in Pa
		}
		else if (vpdtp = 2 )
		{}

		if (TR < 0)
			TR = 0;
			CTR = CTR + TR;

			if (data.data_p.DEPORT <= param.DEP1)
				TR1 = TR;
		else if (data.data_p.DEPORT > param.DEP1)
		{
				if (FTSW1 > data.data_p.WSSG)
					RT1 = 1;
				else
					RT1 = FTSW1 / data.data_p.WSSG;
				TR1 = TR * RT1;
		}
       //  Updating
			ATSW1 = ATSW1 + data.data_h5.rain[ROW] + IRGW - DRAIN1 - RUNOF - TR1 - SEVP;
			if (ATSW1 < 0)
				ATSW1 = 0;
			FTSW1 = ATSW1 / TTSW1;
			WAT1 = WLL1 + ATSW1;

			ATSW = ATSW + data.data_h5.rain[ROW] + IRGW + EWAT - DRAIN - RUNOF - TR - SEVP;
			if (ATSW < 0)
				ATSW = 0;
			TTSW = data.data_p.DEPORT  * param.EXTR;
			FTSW = ATSW / TTSW;

			WLL = data.data_p.DEPORT  * CLL;
			WATRT = WLL + ATSW;
			WSAT = data.data_p.DEPORT  * param.SAT;

		// Water-stress-factors
			if (FTSW > data.data_p.WSSN)
				WSFN = 1;
			else
				WSFN = FTSW / data.data_p.WSSN;
			if (FTSW > data.data_p.WSSL)
				WSFL = 1;
			else
				WSFL = FTSW / data.data_p.WSSL;
			if (FTSW > data.data_p.WSSG)
				WSFG = 1;
			else
				WSFG = FTSW / data.data_p.WSSG;
			WSFD = (1 - WSFG) * data.data_p.WSSD + 1;

			if (WATRT > (0.95 * WSAT))
			{
				WSFN = 0; 
				WSFG = 0;
				WSFL = 0; 
				WSFD = 0;
			}

		// Crop termination by water stress
			if (CBD > data.data_p.ttDKill/*bdDKill*/ && (CBD < data.data_p.ttTSG/*bdTSG*/))
			{
				//If LAI < 0.05 Then CBD = bdTSG
				//If FTSW < 0.02 And VPD > 2.2 Then CBD = bdTSG
				//If FTSW <= 0 And VPD > 1.8 Then CBD = bdTSG
				if (FTSW <= data.data_p.LtFtsw)
				{
					LtDrCntr = LtDrCntr + 1;
				}
				else
					LtDrCnt = 0;

			}
			if (LtDrCntr >= data.data_p.LtWdDur && CBD < data.data_p.ttTSG/*bdTSG*/)
				CBD = data.data_p.ttTSG;
	}

	void FindSowingData(void)
	{
		for (int i = 0; i < data.data_h5.years.size(); i++)
		{
			if (data.data_h5.years[i] == param.FirstYear && data.data_h5.doy[i] == param.Pdoy )
			{
				ROW = i;
				Pyear = param.FirstYear;
				Pdoy = param.Pdoy;
				Yr = Pyear;
				DOY = Pdoy;
				break;
			}
			//еще какое то условие
		}
		if (param.FixFind == 2)
		{
			cout << "CAME" << endl;
			CumFind = 0;
			for (int row = ROW; row < data.data_h5.years.size(); row++)
			{
				ROW = row;
				CDB = 0;
				SoilWater();
				CumFind = CumFind + 1;
				if (CumFind > param.SearchDur)
					MAT = 1;
				if (MAT == 1)
				{
				    DOY = -1;
					dtEM = 0;
					dtR1 = 0;
					dtR3 = 0;
					dtR5 = 0;
					dtR7 = 0;
					dtR8 = 0;
				    MXLAI = 0;
					BSGLAI = 0;
					BSGDM = 0;
					WTOP = 0;
					WGRN = 0;
					NLF = 0;
					NST = 0;
					NVEG = 0;
					NGRN = 0;
					CNUP = 0;
					param.INSOL = 0;
				}
				if (ATSW1 + WSTORG >= param.SowWat || MAT == 1)
					break;

			}
			Pdoy = data.data_h5.doy[ROW];
		}
	}
	void Weather(void)
	{
	//	cout << "ROW =" <<  ROW << endl;
		ROW += 1;
		TMP = (data.data_h5.tmax[ROW] + data.data_h5.tmin[ROW]) / 2;
	//	cout << "TMP = " << TMP <<  endl;
	}
	
	void Phenology(void)
	{
		if (iniPheno == 0)
		{
			bdEM = data.data_p.ttSWEM;
			bdR1 = bdEM + data.data_p.ttEMR1;
			bdR3 = bdR1 + data.data_p.ttR1R3;
			bdR5 = bdR3 + data.data_p.ttR3R5;
			bdR7 = bdR5 + data.data_p.ttR5R7;
			bdR8 = bdR7 + data.data_p.ttR7R8;
			bdBLG = bdEM;
			bdTLM = bdR1 + data.data_p.ttR1TLM;
			bdTLP = bdR1 + data.data_p.ttR1TLP;
			DAP = 0;
			CDB = 0;
			WSFD = 0;
			iniPheno = 1;
		}
		// Thermal time calculation
		if (TMP <= data.data_p.TBD || TMP >= data.data_p.TCD)
			tempfun = 0;
		else if (TMP > data.data_p.TBD && TMP < data.data_p.TP1D)
			tempfun = (TMP - data.data_p.TBD) / (data.data_p.TP1D - data.data_p.TBD);
		else if (TMP > data.data_p.TP2D && TMP < data.data_p.TCD)
			tempfun = (data.data_p.TCD - TMP) / (data.data_p.TCD - data.data_p.TP2D);
		else if (TMP >= data.data_p.TP1D && TMP <= data.data_p.TP2D)
			tempfun = 1;

		DTT = (data.data_p.TP1D - data.data_p.TBD) * tempfun;
		if (CBD > data.data_p.ttWSD)
			tempfun = tempfun * WSFD;
		if (CBD > data.data_p.ttWSD)
			DTT = DTT * WSFD;

			// Photoperiod function
		SABH = 6;
		Pi = 3.141592654;
		RDN = Pi / 180;
		ALPHA = 90 + SABH;
		SMA3 = 0.9856 * DOY - 3.251;
		LANDA = SMA3 + 1.916 * sin(SMA3 * RDN) + 0.02 * sin(2 * SMA3 * RDN) + 282.565;
		DEC = 0.39779 * sin(LANDA * RDN);
		DEC = atan(DEC / sqrt(1.0 - pow(DEC, 2)));
		DEC = DEC / RDN;
		TALSOC = 1 / cos(LAI * RDN);
		CEDSOC = 1 / cos(DEC * RDN);
		SOCRA = (cos(ALPHA * RDN) * TALSOC * CEDSOC) - (tan(LAI * RDN) * tan(DEC * RDN));
		DL = Pi / 2 - (atan(SOCRA / sqrt(1.0 - pow(SOCRA, 2))));
		DL = DL / RDN;
		pp = 2 / 15 * DL;

		if (data.data_p.ppsen >= 0)
			ppfun = 1 - data.data_p.ppsen * (data.data_p.CPP - pp);
		else if (data.data_p.ppsen < 0)
			ppfun = 1 - (-data.data_p.ppsen) * (pp - data.data_p.CPP);
		if (ppfun > 1)
			ppfun = 1;
		if (ppfun < 0)
			ppfun = 0;

		if (CBD < data.data_p.ttBRP)
			ppfun = 1;
		if (CBD > data.data_p.ttTRP)
			ppfun = 1;

	     //  Biological day
		bd = tempfun * ppfun;
		CBD = CBD + bd;
		DAP = DAP + 1;

		if (CBD < bdEM)
			dtEM = DAP + 1;  // 'Saving days to EMR
		if (CBD < bdR1)
			dtR1 = DAP + 1; // 'Saving days to R1
		if (CBD < bdR3)
			dtR3 = DAP + 1;  // 'Saving days to R3
		if (CBD < bdR5)
			dtR5 = DAP + 1;//  'Saving days to R5
		if (CBD < bdR7)
			dtR7 = DAP + 1; //  'Saving days to R7
		if (CBD < bdR8)
			dtR8 = DAP + 1; // 'Saving days to R8

		// Maturity ?
		if (CBD > bdR8)
			MAT = 1;
	}

	void CropLAIN(void)
	{
		if (iniLai == 0)
		{
			PLAPOW = data.data_p.PLAPOW30 * (-0.002 * param.PDEN + 1.0612);//       'Valid for (10<pden<70)

			MSNN = 1;
			PLA2 = 0;
			PLA1 = 0;
			LAI = 0;
			MXLAI = 0; WSFL = 1;
			data.data_p.SLNG = 2;
			iniLai = 1;
		}
		// Yesterday LAI to intercept PAR today
		if (GLAI > (INLF / data.data_p.SLNG))
			GLAI = (INLF / data.data_p.SLNG);
		LAI = LAI + GLAI - DLAI;
		if (LAI < 0)
			LAI = 0;
		if (LAI > MXLAI)
			MXLAI = LAI;  //'Saving maximum LAI

		// Daily increase and decrease in LAI
		if (CBD <= bdBLG)
			GLAI = 0;
		else if (CBD > bdBLG && CBD <= bdTLM)
		{
			INODE = DTT / data.data_p.phyl;
			MSNN = MSNN + INODE * WSFL;
			PLA2 = (int)data.data_p.PLACON * pow(MSNN,PLAPOW);
			GLAI = ((PLA2 - PLA1) * param.PDEN / 10000);
			PLA1 = PLA2;
		}
		else if (CBD > bdTLM && CBD <= bdTLP)
		{
			GLAI = GLF * data.data_p.SLA;
			BSGLAI = LAI;
		}
		//Saving LAI at BSG
		else if (CBD > bdTLP)
			GLAI = 0;
		DLAI = XNLF / (data.data_p.SLNG - data.data_p.SLNS);
	}
	//dmproduction
	
	void DMProduction(void)
	{
		//'------------------------------- Parameters and Initials
		if (iniDMP == 0)
		{
			//data_p
			   /* TBRUE = ThisWorkbook.Worksheets("Crops").Cells(12, CropColNo)  'Sheet5.[b12]
				TP1RUE = ThisWorkbook.Worksheets("Crops").Cells(13, CropColNo)  'Sheet5.[b13]
				TP2RUE = ThisWorkbook.Worksheets("Crops").Cells(14, CropColNo)  'Sheet5.[b14]
				TCRUE = ThisWorkbook.Worksheets("Crops").Cells(15, CropColNo)  'Sheet5.[b15]
				KPAR = ThisWorkbook.Worksheets("Crops").Cells(16, CropColNo)  'Sheet5.[b16]
				IRUE1 = ThisWorkbook.Worksheets("Crops").Cells(17, CropColNo)  'Sheet5.[b17]
				IRUE2 = ThisWorkbook.Worksheets("Crops").Cells(18, CropColNo)  'Sheet5.[b18]

				TEC = ThisWorkbook.Worksheets("Crops").Cells(36, CropColNo)  'Sheet5.[b36]*/

			WSFG = 1;
			iniDMP = 1;
		}

		//'------------------------------- Adjustment of RUE
		if (TMP <= data.data_p.TBRUE || TMP >= data.data_p.TCRUE)
		{
			TCFRUE = 0;
		}
		else if (TMP > data.data_p.TBRUE && TMP < data.data_p.TP1RUE)
		{
			TCFRUE = (TMP - data.data_p.TBRUE) / (data.data_p.TP1RUE - data.data_p.TBRUE);
		}
		else if (TMP > data.data_p.TP2RUE && TMP < data.data_p.TCRUE)
		{
			TCFRUE = (data.data_p.TCRUE - TMP) / (data.data_p.TCRUE - data.data_p.TP2RUE);
		}
		else if (TMP >= data.data_p.TP1RUE && TMP <= data.data_p.TP2RUE)
		{
			TCFRUE = 1;
		}

		if (CBD <= data.data_p.ttRUE)
			RUE = data.data_p.IRUE1 * TCFRUE * WSFG;
		else if (CBD > data.data_p.ttRUE)
			RUE = data.data_p.IRUE2 * TCFRUE * WSFG;


			//'------------------------------ CODES FOR RESPONSE TO VPD
		vpdtp = data.data_p.vpd_resp;
		VPDcr = data.data_p.vpd_cr;

		if (vpdtp == 2 || vpdtp == 3) {
			//'__________________________ Hourly calcs ___________________________
			Pi = 3.141592654;      RDN = Pi / 180;
			DEC = sin(23.45 * RDN) * cos(2 * Pi * (DOY + 10) / 365);
			DEC = atan(DEC / sqrt(1.0 - pow(DEC, 2))) * -1;
			DECL = DEC * 57.29578;
			SINLD = sin(RDN * LAT) * sin(DEC);
			COSLD = cos(RDN * LAT) * cos(DEC);
			AOB = SINLD / COSLD;
			AOB2 = atan(AOB / sqrt(1 - pow(AOB, 2)));
			DAYL = 12 * (1 + 2 * AOB2 / Pi);
			DSINB = 3600 * (DAYL * SINLD + 24 * COSLD * sqrt(1 - AOB * AOB) / Pi);
			DSINBE = 3600 * (DAYL * (SINLD + 0.4 * (SINLD * SINLD + COSLD * COSLD * 0.5)) + 12 * COSLD * (2 + 3 * 0.4 * SINLD) * sqrt(1 - AOB * AOB) / Pi);
			SC = 1370 * (1 + 0.033 * cos(2 * Pi * DOY / 365));
			DSO = SC * DSINB;
			Bnoon = 90 - (LAT - DECL);
			DTR = data.data_h5.srad[ROW] * 1000000; //   'from MJ m-2 d-1 to J m-2 d-1
			TC = 4;
			P = 1.5;
			SUNRIS = 12 - 0.5 * DAYL;
			SUNSET = 12 + 0.5 * DAYL;

			if (vpdtp == 2)
			{
				VPTMIN = 0.6108 * exp(17.27 * data.data_h5.tmin[ROW] / (237.3 + data.data_h5.tmin[ROW]));
				TR = 0;
			}

			DDMP = 0;

			for (int H = 1; H <= 24; H++)
			{
				if (H > SUNRIS && H < SUNSET)//TMINA?????
				{
					if (H < SUNRIS)
					{
						TSUNST = data.data_h5.tmin[ROW] + (TMAXB - data.data_h5.tmin[ROW]) * sin(Pi * (DAYL / (DAYL + 2 * P)));
						NIGHTL = 24 - DAYL;
						TEMP1 = (data.data_h5.tmin[ROW] - TSUNST * exp(-NIGHTL / TC) + (TSUNST - data.data_h5.tmin[ROW]) * exp(-(H + 24 - SUNSET) / TC)) / (1 - exp(-NIGHTL / TC));
					}
					else if (H < 13.5)
					{
						TEMP1 = data.data_h5.tmin[ROW] + (data.data_h5.tmax[ROW] - data.data_h5.tmin[ROW]) * sin(Pi * (H - SUNRIS) / (DAYL + 2 * P));
					}
					else if (H < SUNSET)
					{
						TEMP1 = TMINA + (data.data_h5.tmax[ROW] - TMINA) * sin(Pi * (H - SUNRIS) / (DAYL + 2 * P));
					}
					else
					{
						TSUNST = TMINA + (data.data_h5.tmax[ROW] - TMINA) * sin(Pi * (DAYL / (DAYL + 2 * P)));
						NIGHTL = 24 - DAYL;
						TEMP1 = (TMINA - TSUNST * exp(-NIGHTL / TC) + (TSUNST - TMINA) * exp(-(H - SUNSET) / TC)) / (1 - exp(-NIGHTL / TC));
					}

					SINB = SINLD + COSLD * cos(2 * Pi * (H + 12) / 24);
					if (SINB < 0)
						SINB = 0;

					BET = atan(SINB / sqrt(1 - pow(SINB, 2)));     //      'BETA IN RADIAN
					BETA = BET * 57.29578;         //       'BETA IN DEGREE
					SRAD1 = DTR * SINB * (1 + 0.4 * SINB) / DSINBE; // 'J m-2 s-1
					SRAD1 = SRAD1 * 3600 / 1000000;      //   'to J m-2 h-1; then MJ m-2 h-1
					if (SRAD1 < 0)
						SRAD1 = 0;

					FINT = 1 - exp(-data.data_p.KPAR * LAI);
					DDMP1 = SRAD1 * 0.48 * FINT * RUE;
				}
				if (vpdtp == 2)
				{
					VPTEMP1 = 0.6108 * exp(17.27 * TEMP1 / (237.3 + TEMP1));
					VPD1 = (VPTEMP1 - VPTMIN) * (param.VPDF / 0.75);//       '(VPDF/0.75) is a correction factor when VPDF is different from 0.75
					TR1 = DDMP1 * VPD1 / data.data_p.TEC;   //'VPD in kPa, TEC in Pa

					if (VPD1 > VPDcr)	//'correction of TR and DBP for VDP>VPDcr
					{
						TR1 = DDMP1 * VPDcr / data.data_p.TEC;
						DDMP1 = TR1 * data.data_p.TEC / VPDcr;
						TR1 = DDMP1 * VPDcr / data.data_p.TEC;
						DDMP1 = TR1 * data.data_p.TEC / VPDcr;
					}
					TR = TR + TR1;

					//       If DAP = 75 Then
					//         Sheet8.Cells(H + 2, 1) = H
				//          Sheet8.Cells(H + 2, 2) = TEMP1
					//          Sheet8.Cells(H + 2, 3) = SRAD1
					//          Sheet8.Cells(H + 2, 4) = VPD1
					//         Sheet8.Cells(H + 2, 5) = DDMP1
					//          Sheet8.Cells(H + 2, 6) = TR1
					//          Sheet8.Cells(H + 2, 7) = TR
					//       End If
				}
				DDMP = DDMP + DDMP1;
			}
		}
		else if (vpdtp == 1)
			{
		//	'_________________________daily______________
		//			'  KPAR = 0.9655 * Exp(-1.6721 * LAI) + 0.3032      'KPAR as a function of LAI
		//			'  KPAR = 0.6082 - 0.0073 * PDEN                    'KPAR as a function of PDEN

					FINT = 1 - exp(-data.data_p.KPAR * LAI);
				DDMP = data.data_h5.srad[ROW] * 0.48 * FINT * RUE;
			}

			if (CBD < data.data_p.ttSWEM/*bdEM */ || CBD > data.data_p.ttTSG)
				DDMP = 0;

	}
	
	void DMDistribution(void)
	{

		//	'------------------------------- Parameters and Initials
		if (iniDMD == 0)
		{
			/*FLF1A = ThisWorkbook.Worksheets("Crops").Cells(20, CropColNo)  'Sheet5.[b20]
				FLF1B = ThisWorkbook.Worksheets("Crops").Cells(21, CropColNo)  'Sheet5.[b21]
				WTOPL = ThisWorkbook.Worksheets("Crops").Cells(22, CropColNo)  'Sheet5.[b22]
				FLF2 = ThisWorkbook.Worksheets("Crops").Cells(23, CropColNo)  'Sheet5.[b23]

				FRTRL = ThisWorkbook.Worksheets("Crops").Cells(25, CropColNo)  'Sheet5.[b25]
				GCF = ThisWorkbook.Worksheets("Crops").Cells(26, CropColNo)  'Sheet5.[b26]
				PDHI = ThisWorkbook.Worksheets("Crops").Cells(27, CropColNo)  'Sheet5.[b27]
				WDHI1 = ThisWorkbook.Worksheets("Crops").Cells(28, CropColNo)  'Sheet5.[b28]
				WDHI2 = ThisWorkbook.Worksheets("Crops").Cells(29, CropColNo)  'Sheet5.[b29]
				WDHI3 = ThisWorkbook.Worksheets("Crops").Cells(30, CropColNo)  'Sheet5.[b30]
				WDHI4 = ThisWorkbook.Worksheets("Crops").Cells(31, CropColNo)  'Sheet5.[B31]

				TRESH = ThisWorkbook.Worksheets("Crops").Cells(83, CropColNo)  'Sheet5.[B83]
				*/
			WLF = 0.5;  
			WST = 0.5; 
			WVEG = WLF + WST;
			WGRN = 0; //повторение - переинициализация
			iniDMD = 1;
		}

		//	'------------------------------- Seed dry matter growth
		if (CBD <= data.data_p.ttBSG) {
			TRANSL = 0;
			SGR = 0;
			BSGDM = WTOP;   //             'Saving WTOP at BSG
			if (BSGDM <= data.data_p.WDHI1 || BSGDM >= data.data_p.WDHI4)
				DHIF = 0;
			else if (BSGDM > data.data_p.WDHI1 && BSGDM < data.data_p.WDHI2)
				DHIF = (BSGDM - data.data_p.WDHI1) / (data.data_p.WDHI2 - data.data_p.WDHI1);
			else if (BSGDM > data.data_p.WDHI3 && BSGDM < data.data_p.WDHI4)
				DHIF = (data.data_p.WDHI4 - BSGDM) / (data.data_p.WDHI4 - data.data_p.WDHI3);
			else if (BSGDM >= data.data_p.WDHI2 && BSGDM <= data.data_p.WDHI3)
				DHIF = 1;

			DHI = data.data_p.PDHI * DHIF;
			TRLDM = BSGDM * data.data_p.FRTRL;
		}
		else if (CBD > data.data_p.ttBSG && CBD <= data.data_p.ttTSG)
		{
			SGR = DHI * (WTOP + DDMP) + DDMP * HI;
			if (LAI = 0 && NST <= (WST * data.data_p.SNCS))
				SGR = 0; // 'There is no N for seed filling
			if (SGR < 0)
				SGR = 0;

			if ((SGR * data.data_p.GCF) > DDMP)
				TRANSL = (SGR * data.data_p.GCF) - DDMP;
			if (TRANSL > TRLDM)
				TRANSL = TRLDM;
			else if ((SGR * data.data_p.GCF) <= DDMP)
				TRANSL = 0;

			TRLDM = TRLDM - TRANSL;
			if (SGR > (DDMP + TRANSL) / data.data_p.GCF)
				SGR = (DDMP + TRANSL) / data.data_p.GCF;
		}
		else if (CBD > data.data_p.ttTSG)
		{
			TRANSL = 0;
			SGR = 0;
		}
			//'------------------------------- DM avail. for Leaf & stem
		DDMP2 = DDMP - SGR * data.data_p.GCF;
		if (DDMP2 < 0)
			DDMP2 = 0;

		//	'------------------------------- Leaf dry matter growth
		if (CBD <= bdBLG || CBD > bdTLP)/// ?????????????????????
			GLF = 0;
		else if (CBD > bdBLG && CBD <= bdTLM)
		{
			if (WTOP < data.data_p.WTOPL)
				FLF1 = data.data_p.FLF1A;
			else
				FLF1 = data.data_p.FLF1B;
			GLF = FLF1 * DDMP2;
		}
		else if (CBD > bdTLM && CBD <= bdTLP)
			GLF = data.data_p.FLF2 * DDMP2;

		//	'------------------------------- Stem dry matter growth
		GST = DDMP2 - GLF;

			//'------------------------------- Organs accumulated mass
		WLF = WLF + GLF;
		WST = WST + GST;
		WGRN = WGRN + SGR;
		WVEG = WVEG + DDMP - (SGR * data.data_p.GCF);
		WTOP = WVEG + WGRN;
		HI = WGRN / WTOP;
	}

	void LegumPlant(void)
	{
		if (iniPNB == 0)
		{
			/*SLNG = ThisWorkbook.Worksheets("Crops").Cells(41, CropColNo)  'Sheet5.[b41]
			SLNS = ThisWorkbook.Worksheets("Crops").Cells(42, CropColNo)  'Sheet5.[b42]
			SNCG = ThisWorkbook.Worksheets("Crops").Cells(43, CropColNo)  'Sheet5.[b43]
			SNCS = ThisWorkbook.Worksheets("Crops").Cells(44, CropColNo)  'Sheet5.[b44]
			GNC = ThisWorkbook.Worksheets("Crops").Cells(45, CropColNo)  'Sheet5.[b45]
			MXNUP = ThisWorkbook.Worksheets("Crops").Cells(46, CropColNo)  'Sheet5.[b46]

			INSOL = ThisWorkbook.Worksheets(1).Cells(xCntr + 45, 25)*/


			NST = WST * data.data_p.SNCG;
			NLF = LAI * data.data_p.SLNG;
			WSFN = 1;
			CNUP = NST + NLF;
			NGRN = 0;
			iniPNB = 1;

		}
		if (CBD <= bdEM || CBD > data.data_p.ttTSG)//не то
		{
			NUP = 0;
			XNLF = 0;
			XNST = 0;
			INLF = 0;
			INST = 0;
			INGRN = 0;
		}
		
		else if (CBD > bdEM && CBD < data.data_p.ttBSG)
		{
			INGRN = 0;
			NUP = (GST * data.data_p.SNCG) + (GLAI * data.data_p.SLNG); // '+ NSTDF    '<---- -
			if (CBD < data.data_p.ttBNF && CNUP > param.INSOL)
				NUP = 0;
			if (NUP > data.data_p.MXNUP) 
				NUP = data.data_p.MXNUP;
		
			NFC = NFC * 3 / 4 + NUP / WVEG * (1 / 4);//   'from Sinclair et al. 2003
			NUP = NUP * WSFN;
			if (NUP < 0)
				NUP = 0;
			// 'If FTSW > 1 Then NUP = 0  'Inactivated
			if (DDMP == 0)
				NUP = 0;

			if (NST <= (WST * data.data_p.SNCS))
			{
				INST = WST * data.data_p.SNCS - NST;
				XNST = 0;
				if (INST >= NUP)
				{
					INLF = 0;  
					XNLF = INST - NUP;
				}
				else if (INST < NUP)
					INLF = GLAI * data.data_p.SLNG;
				if (INLF > (NUP - INST))
					INLF = NUP - INST;
				INST = NUP - INLF;
				XNLF = 0;
			}
			else if (NST > (WST * data.data_p.SNCS))
			{
			
			    INLF = GLAI * data.data_p.SLNG;
				XNLF = 0;
		     }
			if (INLF >= NUP)
			{
				INST = 0;
				XNST = INLF - NUP;
				if (XNST > (NST - WST * data.data_p.SNCS))
					XNST = NST - WST * data.data_p.SNCS;
				INLF = NUP + XNST;
			}
			else if (INLF < NUP)
			{
				INST = NUP - INLF;
				XNST = 0;
			}

		}
		   //'       TRLN = LAI * (SLNG - SLNS) + (NST + INST - WST * SNCS)
		   //'       FXLF = LAI * (SLNG - SLNS) / TRLN

		else if (CBD >= data.data_p.ttBSG && CBD <= data.data_p.ttTSG)
		{
			INGRN = SGR * data.data_p.GNC;
			NUP = INGRN + (GST * data.data_p.SNCG) + (GLAI * data.data_p.SLNG);
			if (NUP > data.data_p.MXNUP)
				NUP = data.data_p.MXNUP;
			PDNF = NFC * WVEG;
			if (PDNF > NUP)
				PDNF = NUP;
			DNF = PDNF * WSFN;
			//   'If FTSW > 1 Then DNF = 0  'Inactivated
			if (DNF < 0)
				DNF = 0;
			if (DDMP <= (SGR * data.data_p.GCF))
				DNF = 0;
			if (DDMP == 0)
				DNF = 0;
			NUP = DNF;
			double NUP2;
			if (NUP > (SGR * data.data_p.GNC))
			{
				//   'N is excess of seed needs
				NUP2 = NUP - SGR * data.data_p.GNC;
				if (NST <= (WST * data.data_p.SNCS))
				{
					INST = WST * data.data_p.SNCS - NST;
					XNST = 0;

					if (INST >= NUP2)
					{
						INLF = 0;
						XNLF = INST - NUP2;
					}
					else if (INST < NUP2)
					{
						INLF = GLAI * data.data_p.SLNG;
						if (INLF > (NUP2 - INST))
						{
							INLF = NUP2 - INST;
							INST = NUP2 - INLF;   XNLF = 0;
						}
					}
				}
				else if (NST > (WST * data.data_p.SNCS))
				{
					INLF = GLAI * data.data_p.SLNG; 
					XNLF = 0;
					if (INLF >= NUP2)
					{
						INST = 0;
						XNST = INLF - NUP2;

						if (XNST > (NST - WST * data.data_p.SNCS))
							XNST = NST - WST * data.data_p.SNCS;
						INLF = NUP2 + XNST;
					}
					else if (INLF < NUP2)
					{
							INST = NUP2 - INLF;
							XNST = 0;
					}
					
				}

				TRLN = LAI * (data.data_p.SLNG - data.data_p.SLNS) + (NST + INST - WST * data.data_p.SNCS);
					FXLF = LAI * (data.data_p.SLNG - data.data_p.SLNS) / TRLN;
			}
			else if (NUP <= (SGR * data.data_p.GNC))
			{
				/// 'Need to transfer N from vegetative tissue
				INLF = 0;
				INST = 0;
				XNLF = (SGR * data.data_p.GNC - NUP) * FXLF;
				XNST = (SGR * data.data_p.GNC - NUP) * (1 - FXLF);
			}

		}
		   NST = NST + INST - XNST;
		   NLF = NLF + INLF - XNLF;
		   NVEG = NLF + NST;
		   NGRN = NGRN + INGRN;
		   CNUP = CNUP + NUP;
  
		   TRLN = LAI * (data.data_p.SLNG - data.data_p.SLNS) + (NST - WST * data.data_p.SNCS);
		   FXLF = LAI * (data.data_p.SLNG - data.data_p.SLNS) / (TRLN + 0.000000000001);
		   if (FXLF > 1)
			   FXLF = 1;
		   if (FXLF < 0 )
			   FXLF = 0;
	}
	void DailyPrintOut(void)
	{
		cout << " YEARS= " << data.data_h5.years[ROW] << endl;
		cout << " DOY= " << data.data_h5.doy[ROW] << endl;
		cout << "DAP= " << DAP<< endl;
		cout << " TMP= " << TMP << endl;
		cout << " DTT= " << DTT << endl;
		cout << "CDB= " << CBD << endl;
		cout << "MSNN= " << MSNN << endl;
		cout << "GLAI= " << GLAI << endl;
		cout << " DLAI= " << DLAI << endl;
		cout << "LAI= " << LAI << endl;
		cout << "TCFRUE= " << TCFRUE << endl;
		cout << "FINT= " << FINT << endl;
		cout << " DDMP= " << DDMP << endl;
		cout << "GLF= " << GLF << endl;
		cout << "GST= " << GST << endl;
		cout << " SGR= " << SGR << endl;
		cout << "WLF= " << WLF << endl;
		cout << "WST= " << WST << endl;
		cout << "WVEG=  " << WVEG << endl;
		cout << " WGRN= " << WGRN << endl;
		cout << "WTOP= " << WTOP << endl;
		cout << "DEPORT= " << data.data_p.DEPORT << endl;
		cout << "RAIN= " << data.data_h5.rain[ROW] << endl;////////////RAIN из таблицы
		cout << "IRGW= " << IRGW << endl;
		cout << "RUNOF= " << RUNOF << endl;
		cout << "PET= " << PET << endl;
		cout << "SEVP= " << SEVP << endl;
		cout << "TR= " << TR << endl;
		cout << "ATSW= " << ATSW << endl;
		cout << " FTSW=  " << FTSW << endl;
		cout << " CRAIN= " << CRAIN << endl;
		cout << " CIRGW= " << CIRGW << endl;
		cout << "IRGNO= " << IRGNO << endl;
		cout << " CRUNOF= " << CRUNOF << endl;
		cout << "CE= " << CE << endl;
		cout << " CTR= " << CTR << endl;
		cout << "WSTORG= " << WSTORG << endl;
		cout << "NUP= " << NUP << endl;
		cout << " NLF= " << NLF << endl;
		cout << "NST= " << NST << endl;
		cout << "NVEG= " << NVEG << endl;
		cout << " NGRN= " << NGRN << endl;
		cout << "CNUP= " << CNUP << endl;
	}
	void SummaryPrintOut()
	{
		cout << dtEM << endl;
		cout << dtR1 << endl;
		cout << dtR3 << endl;
		cout << dtR5 << endl;
		cout << dtR7 << endl;
		cout << dtR8 << endl;
		cout << MSNN << endl;
		cout << MXLAI << endl;
		cout << BSGLAI << endl;
		cout << BSGDM << endl;
		cout << WTOP << endl;
		cout << WGRN << endl;
		cout << WGRN / WTOP * 100 << endl;
		cout << WGRN / data.data_p.TRESH << endl;
		cout << ISATSW << endl;
		cout << CRAIN << endl;
		cout << CIRGW << endl;
		cout << IRGNO << endl;
		cout << ATSW << endl;
		cout << CRUNOF << endl;
		cout << CE << endl;
		cout << CTR << endl;
		cout << WSTORG << endl;
		cout << CE + CTR << endl;
		cout << CE / (CE + CTR + 0.00001) << endl;
		cout << NLF << endl;
		cout << NLF << endl;
		cout << (NLF + NST) << endl;
		cout << NGRN << endl;
		cout << CNUP << endl;
		cout << param.INSOL << endl;
		cout << CIRGW << endl;
		//////*
	//	cout << LATX << endl;
	//	cout << LONGX << endl;
	/*	cout << Pyear << endl;
		cout << Pdoy << endl;
		cout << dtEM << endl;
		cout << dtR1 << endl;
		cout << dtR3 << endl;
		cout << dtR5 << endl;
		cout << dtR7 << endl;
		cout << dtR8 << endl;
		cout << MSNN << endl;
		cout << MXLAI << endl;
		cout << BSGLAI << endl;
		cout << BSGDM << endl;
		cout << WTOP << endl;
		cout << WGRN << endl;
		cout << WGRN / WTOP * 100 << endl;
		cout << WGRN / data.data_p.TRESH << endl;
		cout << ISATSW << endl;
		cout << CRAIN << endl;
		cout << CIRGW << endl;
		cout << IRGNO << endl;
		cout << ATSW << endl;
		cout << CRUNOF << endl;
		cout << CE << endl;
		cout << CTR << endl;
		cout << WSTORG << endl;
		cout << CE + CTR << endl;
		cout << CE / (CE + CTR + 0.00001) << endl;
		cout << NLF << endl;
		cout << NLF << endl;
		cout << (NLF + NST) << endl;
		cout << NGRN << endl;
		cout << CNUP << endl;
		cout << param.INSOL << endl;*/
	}
	void calculation()
	{
		cout << "yno = " << param.yno << endl;
		for (int i = 0; i < param.yno; i++)
		{
			//ManagInputs
		    //INITIALS
			MAT = 0;
			iniPheno = 0;
			iniLai = 0;
			iniDMP = 0;
			iniDMD = 0;
			iniSW = 0;
			iniPNB = 0;
			FindSowingData();
			Pyear = param.FirstYear;
			while (MAT != 1)
			{
			//	ROW += 1;
				Weather();
			    Phenology();
				CropLAIN();
				DMProduction();
				DMDistribution();
				LegumPlant();
				SoilWater();
				DailyPrintOut();
			}
			SummaryPrintOut();
			Pyear += 1;
		//	DailyPrintOut();
		}
	}
	void print_res()
	{
		for (int i = 0; i < res.TMP.size(); i++)
			cout << res.TMP[i] << endl;
	}
	void run_h5()
	{
		data.read_h5(param.file_name);
		data.read_ini();
		cout << "BEGIN CALC" << endl;
		calculation();
		cout << "END CALC" << endl;
	//	print_res();
	}

};
