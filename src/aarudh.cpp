#include "aarudh.h"
#include <iostream>
#include <fstream>
#include <filesystem>




using namespace std;

std::string aarudh::findArudha(planet p_planet,string sclord,string aqlord) {
	string Sign = "";
	string planetSign = "";
	int signnum=0;
	for (int i = 0;i < 12;i++) {
		if (i == 0) {
			Sign = p_planet.d1sign;
		}
		else {
			int signnum = g_signNumbers[Sign];
			signnum++;
			if (signnum > 12) {
				signnum = signnum % 12;
			}
			Sign = g_NumberSigns[signnum];
		}
		
		auto it = g_d1findBySign.find(Sign);
		if (it != g_d1findBySign.end()) {
			sign* abd = it->second;
			string lord = abd->lord;
			//mars,ketu saturn,rahu
			if (lord != "mars,ketu" && lord != "saturn,rahu") {
				auto itrplanet = g_findByPlanet.find(lord);
				if (itrplanet != g_findByPlanet.end()) {
					planet* pp = itrplanet->second;
					planetSign = pp->d1sign;
				}
			}
			else {
				if (lord == "mars,ketu") {
					lord = sclord;
					auto itrplanet = g_findByPlanet.find(lord);
					if (itrplanet != g_findByPlanet.end()) {
						planet* pp = itrplanet->second;
						planetSign = pp->d1sign;
					}
				}
				else {
					lord = aqlord;
					auto itrplanet = g_findByPlanet.find(lord);
					if (itrplanet != g_findByPlanet.end()) {
						planet* pp = itrplanet->second;
						planetSign = pp->d1sign;
					}
				}
			}
		}
		int hdiff = rashicounter(g_signNumbers[Sign], g_signNumbers[planetSign]);
		int arudhaRashiNum = A_bhavatbhavam(g_signNumbers[planetSign], hdiff);
		string arudha__Sign = g_NumberSigns[arudhaRashiNum];
		sign* arudhaInMap = g_d1findBySign[arudha__Sign];
		string putin = "A" + to_string(i+1);
		arudhaInMap->aarudha.push_back(putin);
		g_D1Arudha[putin] = arudhaInMap;
		
	}
	arudhReport();
	return "";
}
//rashi of al----------------------------------------------



//--------------------------------------------------------

//qualities of planet ----------------
string sunal = "";
string moonal = "";
string marsal = "";
string mercuryal = "";
string jupiteral = "";
string venusal = "";
string saturnal = "";
string rahual = "";
string ketual = "";
//---------------------------

//planet influencing al------
string sunonal = "";
string moononal = "";
string marsonal = "";
string mercuryonal = "";
string jupiteronal = "";
string venusonal = "";
string saturnonal = "";
string rahuonal = "";
string ketuonal = "";
//---------------------------

//arudha with al--------------
string ala2 = "";
string ala3 = "";
string ala4 = "";
string ala5 = "";
string ala6 = "";
string ala7 = "";
string ala8 = "";
string ala9 = "";
string ala10 = "";
string ala11 = "";
string ala12 = "";
//----------------------------




string aarudh::arudhReport() {

	//AL----------------------------------------------------------------
	sign* al = g_D1Arudha["A1"];

	string ALlordYog(sign * al);

	int alSignnum = g_signNumbers[al->name];
	std::filesystem::path current_dir = std::filesystem::current_path().parent_path().parent_path().parent_path();

	std::filesystem::path file_path = current_dir / "Report" / "arudha.txt";

	ofstream ard(file_path,ios::app);
	for (int i = 0;i < 12;i++) {
		int arudhno = i + 1;
		string feedin = "A" + to_string(arudhno) + " is in " + al->name +"\n" + "lord is " + al->lord +  "\n planets in this are ";
		string planetsinit = "";
		for (planet* planet : al->vecPlanet) {
			planetsinit = planetsinit + planet->name;
			planetsinit = planetsinit + ",";
		}
		if (planetsinit == "") {
			planetsinit = "none";
		}
		feedin = feedin + planetsinit + "\n planets aspecting are ";
		planetsinit = "";
		for (planet* planet : al->Grah_aspector) {
			planetsinit = planetsinit + planet->name;
			planetsinit = planetsinit + ",";
		}
		if (planetsinit == "") {
			planetsinit = "none";
		}
		feedin = feedin + planetsinit + "\n planets aspecting by rashi are ";
		planetsinit = "";
		for (planet* planet : al->Rashi_aspector) {
			planetsinit = planetsinit + planet->name;
			planetsinit = planetsinit + ",";
		}
		if (planetsinit == "") {
			planetsinit = "none";
		}
		feedin = feedin + planetsinit;
		if (ard.is_open()) {
			ard << feedin << endl << endl <<endl;
			string inp = "A" + to_string(arudhno);
			al = g_D1Arudha[inp.c_str()];
		}
	}
	

	return "";
}
//string lagnarudh = findArudha(lagna);
int aarudh::rashicounter(int from, int to) {
	int cntr = 1;
	while (true) {
		if (from == to) {
			break;
		}
		cntr++;
		if (cntr == 12) {
			break;
		}
		from++;
		if (from == to) {
			break;
		}
		from = from % 12;
	}
	if (cntr == 4 ) {
		cntr = 1;
	}
	else if (cntr == 1) {
		cntr = 10;
	}
	else if ( cntr == 10) {
		cntr = 7;
	}
	else if (cntr == 7) {
		cntr = 4;
	}
	return cntr;
}
int aarudh::A_bhavatbhavam(int rashifrom,int howmany) {
	int cntr = rashifrom;
	for (int i = 1;i < howmany;i++) {
		cntr++;
		cntr = cntr % 12;
		//i = rashifrom;
	}
	if (cntr == 0) {
		cntr = 12;
	}
	return cntr;
}