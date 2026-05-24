
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "houseCounter.h"
#include <cmath>
#include <filesystem>

using namespace std;
 float d1Lagna = 0.0f;
 float d1sun = 0.0f;
 float d1moon = 0.0f;
 float d1mars = 0.0f;
 float d1mercury = 0.0f;
 float d1jupiter = 0.0f;
 float d1venus = 0.0f;
 float d1saturn = 0.0f;
 float d1rahu = 0.0f;
 float d1ketu = 0.0f;
 float d1gulika = 0.0f;
 float d1mandi = 0.0f;

 float d9Lagna = 0.0f;
 float d9sun = 0.0f;
 float d9moon = 0.0f;
 float d9mars = 0.0f;
 float d9mercury = 0.0f;
 float d9jupiter = 0.0f;
 float d9venus = 0.0f;
 float d9saturn = 0.0f;
 float d9rahu = 0.0f;
 float d9ketu = 0.0f;
 float d9gulika = 0.0f;
 float d9mandi = 0.0f;


planet lagna;
planet sun;
planet moon;
planet mars;
planet mercury;
planet jupiter;
planet venus;
planet saturn;
planet rahu;
planet ketu;
planet gulika;
planet mandi;

sign d1aries;
sign d1taurus;
sign d1gemini;
sign d1cancer;
sign d1leo;
sign d1virgo;
sign d1libra;
sign d1scorpio;
sign d1sagittarius;
sign d1capricorn;
sign d1aquarius;
sign d1pisces;

 sign d9aries;
 sign d9taurus;
 sign d9gemini;
 sign d9cancer;
 sign d9leo;
 sign d9virgo;
 sign d9libra;
 sign d9scorpio;
 sign d9sagittarius;
 sign d9capricorn;
 sign d9aquarius;
 sign d9pisces;


 map<string, int> g_signNumbers;
 map<int, string> g_NumberSigns;
 map<string, struct sign*> g_d1findBySign;
 map<string, struct planet*> g_findByPlanet;
 map<string, struct sign*> g_D1Arudha;

void houseCounter:: assignPlanet() {
	ifstream outfile;
	vector<string> fileline;
	string line;
	// 1. Fetch the path of your current running folder
	std::filesystem::path current_dir = std::filesystem::current_path();

	// 2. Append the 'D1' folder and 'd1.txt' file to that path
	std::filesystem::path file_path = current_dir / "D1" / "d1.txt";
	outfile.open(file_path);

	if (outfile.is_open()) {
		for (int i = 0;i<15 && getline(outfile,line);i++) {
			fileline.push_back(line);
		}
		outfile.close();
	}
	else {
		throw("file not there");
	}
	for (int i = 2;i < 15;i++) {
		bool retroFlag = false;
		string planet = fileline[i];
		if (planet.find("(R)") != string::npos) {
			retroFlag = true;
		}
		string word = planet.substr(0, planet.find(" "));
		if (word == "Lagna") {
			d1Lagna = degreeAssigner(planet); //assigns degree to the planet setting aries as 0 degree.
			lagna.name = "lagna";
			lagna.d1degree = d1Lagna;
			signAssigner(&lagna, "d1"); //assigns sign to the planet by taking 
			dignity(&lagna);
		}
		else if(word == "Sun") {
			d1sun = degreeAssigner(planet);
			sun.name = "sun";
			sun.d1degree = d1sun;
			signAssigner(&sun, "d1");
		}
		else if (word == "Moon") {
			d1moon = degreeAssigner(planet);
			moon.name = "moon";
			moon.d1degree = d1moon;
			signAssigner(&moon, "d1");
		}
		else if (word == "Mars") {
			d1mars = degreeAssigner(planet);
			mars.name = "mars";
			mars.d1degree = d1mars;
			if (retroFlag) {
				mars.motion = "retro";
			}
			signAssigner(&mars, "d1");

		}
		else if (word == "Mercury") {
			d1mercury = degreeAssigner(planet);
			mercury.name = "mercury";
			mercury.d1degree = d1mercury;
			if (retroFlag) {
				mercury.motion = "retro";
			}
			signAssigner(&mercury, "d1");
		}
		else if (word == "Jupiter") {
			d1jupiter = degreeAssigner(planet);
			jupiter.name = "jupiter";
			jupiter.d1degree = d1jupiter;
			if (retroFlag) {
				jupiter.motion = "retro";
			}
			signAssigner(&jupiter, "d1");
		}
		else if (word == "Venus") {
			d1venus = degreeAssigner(planet);
			venus.name = "venus";
			venus.d1degree = d1venus;
			if (retroFlag) {
				venus.motion = "retro";
			}
			signAssigner(&venus, "d1");
		}
		else if (word == "Saturn") {
			d1saturn = degreeAssigner(planet);
			saturn.name = "saturn";
			saturn.d1degree = d1saturn;
			if (retroFlag) {
				saturn.motion = "retro";
			}
			signAssigner(&saturn, "d1");
		}
		else if (word == "Rahu") {
			d1rahu = degreeAssigner(planet);
			rahu.name = "rahu";
			rahu.d1degree = d1rahu;
			signAssigner(&rahu, "d1");
		}
		else if (word == "Ketu") {
			d1ketu = degreeAssigner(planet);
			ketu.name = "ketu";
			ketu.d1degree = d1ketu;
			signAssigner(&ketu, "d1");
		}
		else if (word == "Maandi") {
			d1mandi = degreeAssigner(planet);
			mandi.name = "mandi";
			mandi.d1degree = d1mandi;
			signAssigner(&mandi, "d1");
		}
		else if (word == "Gulika") {
			d1gulika = degreeAssigner(planet);
			gulika.name = "gulika";
			gulika.d1degree = d1gulika;
			signAssigner(&gulika, "d1");
		}
	}
	
		g_d1findBySign = {
			{"aries", &d1aries },
		{"taurus",  &d1taurus },
		{"gemini",  &d1gemini},
		{"cancer",  &d1cancer },
		{"leo" , &d1leo},
		{"virgo" , &d1virgo},
		{"libra" , &d1libra},
		{"scorpio" , &d1scorpio},
		{"sagittarius" , &d1sagittarius},
		{"capricorn" , &d1capricorn},
		{"aquarius" , &d1aquarius},
		{"pisces",  &d1pisces} };
	
	//planet
	g_findByPlanet = {
			{"sun",&sun},
			{"moon",&moon},
			{"mars",&mars},
			{"mercury",&mercury},
			{"jupiter",&jupiter},
			{"venus",&venus},
			{"saturn",&saturn},
			{"rahu",&rahu},
			{"ketu",&ketu}
		};

	  g_NumberSigns = {
	{1,"aries"},
	{2,"taurus"},
	{3,"gemini"},
	{4,"canser"},
	{5,"leo"},
	{6,"virgo"},
	{7,"libra"},
	{8,"scorpio"},
	{9,"sagittarius"},
	{10,"capricorn"},
	{11,"aquarius"},
	{12,"pisces"}
	};

	  g_signNumbers = {
	{"aries",1},
	{"taurus",2},
	{"gemini",3},
	{"canser",4},
	{"leo",5},
	{"virgo",6},
	{"libra",7},
	{"scorpio",8},
	{"sagittarius",9},
	{"capricorn",10},
	{"aquarius",11},
	{"pisces",12}
	 };



	{
		  d1aries.name = "aries";
		  d1taurus.name = "taurus";
		  d1gemini.name = "gemini";
		  d1cancer.name = "cancer";
		  d1leo.name = "leo";
		  d1virgo.name = "virgo";
		  d1libra.name = "libra";
		  d1scorpio.name = "scorpio";
		  d1sagittarius.name = "sagittarius";
		  d1capricorn.name = "capricorn";
		  d1aquarius.name = "aquarius";
		  d1pisces.name = "pisces";

		  d9aries.name = "aries";
		  d9taurus.name = "taurus";
		  d9gemini.name = "gemini";
		  d9cancer.name = "cancer";
		  d9leo.name = "leo";
		  d9virgo.name = "virgo";
		  d9libra.name = "libra";
		  d9scorpio.name = "scorpio";
		  d9sagittarius.name = "sagittarius";
		  d9capricorn.name = "capricorn";
		  d9aquarius.name = "aquarius";
		  d9pisces.name = "pisces";

		d1aries.lord = "mars";
		d1taurus.lord = "venus";
		d1gemini.lord = "mercury";
		d1cancer.lord = "moon";
		d1leo.lord = "sun";
		d1virgo.lord = "mercury";
		d1libra.lord = "venus";
		d1scorpio.lord = "mars,ketu";
		d1sagittarius.lord = "jupiter";
		d1capricorn.lord = "saturn";
		d1aquarius.lord = "saturn,rahu";
		d1pisces.lord = "jupiter";

		d9aries.lord = "mars";
		d9taurus.lord = "venus";
		d9gemini.lord = "mercury";
		d9cancer.lord = "moon";
		d9leo.lord = "sun";
		d9virgo.lord = "mercury";
		d9libra.lord = "venus";
		d9scorpio.lord = "mars,ketu";
		d9sagittarius.lord = "jupiter";
		d9capricorn.lord = "saturn";
		d9aquarius.lord = "saturn,rahu";
		d9pisces.lord = "jupiter";
	}
	//assigning rashi aspecting planet--------------------------------------------
	{
		for (planet* pla : d1leo.vecPlanet) {
			d1aries.Rashi_aspector.push_back(pla);
			d1libra.Rashi_aspector.push_back(pla);
			d1capricorn.Rashi_aspector.push_back(pla);
		}
		for (planet* pla : d1scorpio.vecPlanet) {
			d1aries.Rashi_aspector.push_back(pla);
			d1cancer.Rashi_aspector.push_back(pla);
			d1capricorn.Rashi_aspector.push_back(pla);
		}
		for (planet* pla : d1aquarius.vecPlanet) {
			d1aries.Rashi_aspector.push_back(pla);
			d1cancer.Rashi_aspector.push_back(pla);
			d1libra.Rashi_aspector.push_back(pla);
		}
		for (planet* pla : d1taurus.vecPlanet) {
			d1cancer.Rashi_aspector.push_back(pla);
			d1libra.Rashi_aspector.push_back(pla);
			d1capricorn.Rashi_aspector.push_back(pla);
		}

		for (planet* pla : d1aries.vecPlanet) {
			d1leo.Rashi_aspector.push_back(pla);
			d1scorpio.Rashi_aspector.push_back(pla);
			d1aquarius.Rashi_aspector.push_back(pla);
		}
		for (planet* pla : d1cancer.vecPlanet) {
			d1taurus.Rashi_aspector.push_back(pla);
			d1scorpio.Rashi_aspector.push_back(pla);
			d1aquarius.Rashi_aspector.push_back(pla);
		}
		for (planet* pla : d1libra.vecPlanet) {
			d1taurus.Rashi_aspector.push_back(pla);
			d1leo.Rashi_aspector.push_back(pla);
			d1aquarius.Rashi_aspector.push_back(pla);
		}
		for (planet* pla : d1capricorn.vecPlanet) {
			d1taurus.Rashi_aspector.push_back(pla);
			d1leo.Rashi_aspector.push_back(pla);
			d1scorpio.Rashi_aspector.push_back(pla);
		}

		for (planet* pla : d1gemini.vecPlanet) {
			d1virgo.Rashi_aspector.push_back(pla);
			d1sagittarius.Rashi_aspector.push_back(pla);
			d1pisces.Rashi_aspector.push_back(pla);
		}
		for (planet* pla : d1virgo.vecPlanet) {
			d1gemini.Rashi_aspector.push_back(pla);
			d1sagittarius.Rashi_aspector.push_back(pla);
			d1pisces.Rashi_aspector.push_back(pla);
		}
		for (planet* pla : d1sagittarius.vecPlanet) {
			d1virgo.Rashi_aspector.push_back(pla);
			d1gemini.Rashi_aspector.push_back(pla);
			d1pisces.Rashi_aspector.push_back(pla);
		}

	}
	//----------------------------------------------------------------------------
	//assign graha aspect *****************************************
	{
		int signnum = assignPlanetoryAsp(g_signNumbers[sun.d1sign], 7);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&sun);
		signnum = assignPlanetoryAsp(g_signNumbers[moon.d1sign], 7);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&moon);
		signnum = assignPlanetoryAsp(g_signNumbers[mars.d1sign], 4);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&mars);
		signnum = assignPlanetoryAsp(g_signNumbers[mars.d1sign], 7);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&mars);
		signnum = assignPlanetoryAsp(g_signNumbers[mars.d1sign], 8);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&mars);
		signnum = assignPlanetoryAsp(g_signNumbers[mercury.d1sign], 7);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&mercury);
		signnum = assignPlanetoryAsp(g_signNumbers[jupiter.d1sign], 7);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&jupiter);
		signnum = assignPlanetoryAsp(g_signNumbers[jupiter.d1sign], 5);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&jupiter);
		signnum = assignPlanetoryAsp(g_signNumbers[jupiter.d1sign], 9);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&jupiter);
		signnum = assignPlanetoryAsp(g_signNumbers[venus.d1sign], 7);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&venus);
		signnum = assignPlanetoryAsp(g_signNumbers[saturn.d1sign], 7);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&saturn);
		signnum = assignPlanetoryAsp(g_signNumbers[saturn.d1sign], 3);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&saturn);
		signnum = assignPlanetoryAsp(g_signNumbers[saturn.d1sign], 10);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&saturn);
		signnum = assignPlanetoryAsp(g_signNumbers[rahu.d1sign], 9);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&rahu);
		signnum = assignPlanetoryAsp(g_signNumbers[rahu.d1sign], 5);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&rahu);
		signnum = assignPlanetoryAsp(g_signNumbers[rahu.d1sign], 7);
		g_d1findBySign[g_NumberSigns[signnum]]->Grah_aspector.push_back(&rahu);
	}
	//*************************************************************

	fileline.clear();
	outfile.open("..\\D9\\d9.txt");
	if (outfile.is_open()) {
		for (int i = 0;i < 15 && getline(outfile, line);i++) {
			fileline.push_back(line);
		}
	}
	for (int i = 2;i < 15;i++) {
		string planet = fileline[i];
		string word = planet.substr(0, planet.find(" "));
		if (word == "Lagna") {
			 d9Lagna = degreeAssigner(planet);
			 lagna.d9degree = d9Lagna;
			 signAssigner(&lagna, "d9");
		}
		else if (word == "Sun") {
			d9sun = degreeAssigner(planet);
			sun.d9degree = d9sun;
			signAssigner(&sun, "d9");
			dignity(&sun);
		}
		else if (word == "Moon") {
			d9moon = degreeAssigner(planet);
			moon.d9degree = d9moon;
			signAssigner(&moon, "d9");
			dignity(&moon);
		}
		else if (word == "Mars") {
			d9mars = degreeAssigner(planet);
			mars.d9degree = d9mars;
			signAssigner(&mars, "d9");
			dignity(&mars);
		}
		else if (word == "Mercury") {
			d9mercury = degreeAssigner(planet);
			mercury.d9degree = d9mercury;
			signAssigner(&mercury, "d9");
			dignity(&mercury);
		}
		else if (word == "Jupiter") {
			d9jupiter = degreeAssigner(planet);
			jupiter.d9degree = d9jupiter;
			signAssigner(&jupiter, "d9");
			dignity(&jupiter);
		}
		else if (word == "Venus") {
			d9venus = degreeAssigner(planet);
			venus.d9degree = d9venus;
			signAssigner(&venus, "d9");
			dignity(&venus);
		}
		else if (word == "Saturn") {
			d9saturn = degreeAssigner(planet);
			saturn.d9degree = d9saturn;
			signAssigner(&saturn, "d9");
			dignity(&saturn);
		}
		else if (word == "Rahu") {
			d9rahu = degreeAssigner(planet);
			rahu.d9degree = d9rahu;
			signAssigner(&rahu, "d9");
			dignity(&rahu);
		}
		else if (word == "Ketu") {
			d9ketu = degreeAssigner(planet);
			ketu.d9degree = d9ketu;
			signAssigner(&ketu, "d9");
			dignity(&ketu);
		}
		else if (word == "Maandi") {
			d9mandi = degreeAssigner(planet);
		}
		else if (word == "Gulika") {
			d9gulika = degreeAssigner(planet);
		}
	}
	
	ofstream confirmfile("..\\Report\\confirmfile.txt");
	if (confirmfile.is_open()) {
		confirmfile <<"d1lagna :-" << to_string(d1Lagna) << endl;
		confirmfile << "d1sun :-" << to_string(d1sun) << endl;
		confirmfile << "d1moon :-" << to_string(d1moon) << endl;
		confirmfile << "d1mars :-" << to_string(d1mars) << endl;
		confirmfile << "d1mercuey :-" << to_string(d1mercury) << endl;
		confirmfile << "d1jupiter :-" << to_string(d1jupiter) << endl;
		confirmfile << "d1venus :-" << to_string(d1venus) << endl;
		confirmfile << "d1saturn :-" << to_string(d1saturn) << endl;
		confirmfile << "d1rahu :-" << to_string(d1rahu) << endl;
		confirmfile << "d1ketu :-" << to_string(d1ketu) << endl;
		confirmfile << "d1gulika :-" << to_string(d1gulika) << endl;
		confirmfile << "d1mandi :-" << to_string(d1mandi) << endl;
		confirmfile << endl;
		confirmfile << "d9lagna :-" << to_string(d9Lagna) << endl;
		confirmfile << "d9sun :-" << to_string(d9sun) << endl;
		confirmfile << "d9moon :-" << to_string(d9moon) << endl;
		confirmfile << "d9mars :-" << to_string(d9mars) << endl;
		confirmfile << "d9mercuey :-" << to_string(d9mercury) << endl;
		confirmfile << "d9jupiter :-" << to_string(d9jupiter) << endl;
		confirmfile << "d9venus :-" << to_string(d9venus) << endl;
		confirmfile << "d9saturn :-" << to_string(d9saturn) << endl;
		confirmfile << "d9rahu :-" << to_string(d9rahu) << endl;
		confirmfile << "d9ketu :-" << to_string(d9ketu) << endl;
		confirmfile << "d9mandi :-" << to_string(d9mandi) << endl;
		confirmfile << "d9gulika :-" << to_string(d9gulika) << endl;
		confirmfile.close();
	}
}
float houseCounter :: degreeAssigner(string planet) {
	int start = planet.find_first_of("1234567890");
	char chardegree = planet[start];
	string strDegree;
	strDegree += chardegree;
	int num = static_cast<int>(planet[++start]);
	if (num > 47 && num < 58) {
		chardegree = planet[start];
		strDegree += chardegree;
	}
	float degree = stof(strDegree);
	string sign;
	while (sign.length() < 2)
	{
		char try1 = planet[++start];
		if ((isalpha(try1)))
			sign += try1;
	}
	auto in = signsDegree.find(sign);
	float signdegree = 0.0;
	if (in != signsDegree.end())
		signdegree = in->second;

	string minute;
	while (minute.length() < 2)
	{
		char try1 = planet[++start];
		if (isdigit(try1))
			minute += try1;
	}
	float Fminute = stof(minute);
	degree = degree + signdegree + static_cast<float>((Fminute / 0.6) / 100);
	return degree;
}

void houseCounter::signAssigner(planet* x,string division) {

	

	if (division == "d1") {
		float rem = x->d1degree / 30;
		int house = (int)rem;
		switch (house)
		{
		case 0:
			x->d1sign = "aries";
			d1aries.vecPlanet.push_back(x);
			break;
		case 1 :
			x->d1sign = "taurus";
			d1taurus.vecPlanet.push_back(x);
			break;
		case 2:
			x->d1sign = "gemini";
			d1gemini.vecPlanet.push_back(x);
			break;
		case 3:
			x->d1sign = "cancer";
			d1cancer.vecPlanet.push_back(x);
			break;
		case 4:
			x->d1sign = "leo";
			d1leo.vecPlanet.push_back(x);
			break;
		case 5:
			x->d1sign = "virgo";
			d1virgo.vecPlanet.push_back(x);
			break;
		case 6:
			x->d1sign = "libra";
			d1libra.vecPlanet.push_back(x);
			break;
		case 7:
			x->d1sign = "scorpio";
			d1scorpio.vecPlanet.push_back(x);
			break;
		case 8:
			x->d1sign = "sagittarius";
			d1sagittarius.vecPlanet.push_back(x);
			break;
		case 9:
			x->d1sign = "capricorn";
			d1capricorn.vecPlanet.push_back(x);
			break;
		case 10:
			x->d1sign = "aquarius";
			d1aquarius.vecPlanet.push_back(x);
			break;
		case 11:
			x->d1sign = "pisces";
			d1pisces.vecPlanet.push_back(x);
			break;

		default:
			break;
		}
	}

	if (division == "d9") {
		float rem = x->d9degree / 30;
		int house = (int)rem;
		switch (house)
		{
		case 0:
			x->d9sign = "aries";
			d9aries.vecPlanet.push_back(x);
			break;
		case 1:
			x->d9sign = "taurus";
			d9taurus.vecPlanet.push_back(x);
			break;
		case 2:
			x->d9sign = "gemini";
			d9gemini.vecPlanet.push_back(x);
			break;
		case 3:
			x->d9sign = "cancer";
			d9cancer.vecPlanet.push_back(x);
			break;
		case 4:
			x->d9sign = "leo";
			d9leo.vecPlanet.push_back(x);
			break;
		case 5:
			x->d9sign = "virgo";
			d9virgo.vecPlanet.push_back(x);
			break;
		case 6:
			x->d9sign = "libra";
			d9libra.vecPlanet.push_back(x);
			break;
		case 7:
			x->d9sign = "scorpio";
			d9scorpio.vecPlanet.push_back(x);
			break;
		case 8:
			x->d9sign = "sagittarius";
			d9sagittarius.vecPlanet.push_back(x);
			break;
		case 9:
			x->d9sign = "capricorn";
			d9capricorn.vecPlanet.push_back(x);
			break;
		case 10:
			x->d9sign = "aquarius";
			d9aquarius.vecPlanet.push_back(x);
			break;
		case 11:
			x->d9sign = "pisces";
			d9pisces.vecPlanet.push_back(x);
			break;

		default:
			break;
		}
	}

}

houseCounter::gstruct_houseTime houseCounter::houseNumberD1(float fromPlanet, float toPlanet) {
	gstruct_houseTime a;
	a.house = 0;
	a.timetochangeforward = 0.0f;
	a.timetochangebackwrd = 0.0f;
	float house;
	int houseno = 0;

	float diff = toPlanet - fromPlanet;

	if (diff <= 0) {
		diff = 360 + diff;
	}

	diff = diff - 15;
	if (diff < 0) {
		houseno = 1;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;

	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 2;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 3;
		a.timetochangebackwrd = (diff * -1) * 4;
		cout << a.timetochangebackwrd;
		a.timetochangeforward = (30 + diff) * 4;
		cout << a.timetochangeforward;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 4;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 5;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 6;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 7;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 8;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 9;
		a.timetochangebackwrd = (diff * -1) * 4;
		cout << a.timetochangebackwrd;
		a.timetochangeforward = (30 + diff) * 4;
		cout << a.timetochangeforward;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 10;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 11;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;
	}
	diff = diff - 30;
	if (diff < 0) {
		houseno = 12;
		a.timetochangebackwrd = (diff * -1) * 4;
		a.timetochangeforward = (30 + diff) * 4;
		return a;
	}
	diff = diff - 15;
	if (diff < 0) {
		houseno = 1;
		a.timetochangebackwrd = (15-diff) * 4;
		a.timetochangeforward = (15 + diff) * 4;
		return a;
	}


	
	float h = diff / 15;
	h = h - 1;
	int hno = h - 1;
	if (hno <= 0) {
		house = 1;
	}
	else {
		float housediff = h / 2;
		int df = 90;
	}

	//----------------------------------------------------------
	/*while (true) {
		float diffadd = fromPlanet + 15.0;
		float diffminus = fromPlanet - 15.0;
		if (diffadd > 360.0) {
			diffadd = diffadd - 360.0;
		}
		if (diffminus < 0) {
			diffminus = 360 - diffminus;
		}
		if (toPlanet < diffadd == true || toPlanet > fromPlanet == true) {

			break;
		}
	}*/
	//---------------------------------------------------------------------

	/*if (diff < 0) {
		fromPlanet = fromPlanet + 15.00f;
		diff = toPlanet - fromPlanet;
		house = floor(diff/30);
		diff = diff - house;
	}
	else {
		float angle = diff / 15;
		angle = angle - 1;
		angle = angle / 2;
		angle = 12 - angle;
		house = floor(angle)+1;
		a.house = (int)house;
		float fraction = angle - floor(angle);
		a.timetochangeforward = fraction * 120;
		a.timetochangebackwrd = (1 - fraction) * 120;
		cout << a.house <<endl;
		cout << a.timetochangebackwrd << endl;
		cout << a.timetochangeforward << endl;
		/*fromPlanet = fromPlanet - 15.00f;
		diff = fromPlanet - toPlanet;
		house = floor(diff / 30);
		house = 13 - house;
		a.house = house;
		diff = (diff/30) - (house-1);
		a.timetochangeforward = 120 * diff;
		a.timetochangebackwrd = 120 * (1 - diff);
	

	}*/
	return a;


}
int houseCounter::houseNumberD1(float fromPlanet, float toPlanet, int nu) {
	int houseno;
	float diff = toPlanet - fromPlanet;

	if (diff <= 0) {
		diff = 360 + diff;
	}
	diff = diff - 15;
	if (diff < 0) {
		return 1;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 2;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 3;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 4;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 5;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 6;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 7;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 8;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 9;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 10;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 11;
	}
	diff = diff - 30;
	if (diff < 0) {
		return 12;
	}
	diff = diff - 15;
	if (diff < 0) {
		return 1;
	}
}

void houseCounter::dignity(planet* x) {
	if (x->name == "lagna") {
		if (x->d1sign == x->d9sign) {
			x->d1dignity = "vargottam";
		}
	}
	if (x->name == "sun") {
		x->qualities = " Leadership qualities are very prominent, confidence, Respect, public recognition, commanding and authoritative personality. ";
		x->vrutti = "beni";
		if (x->d1sign == "aries") {
			x->d1dignity = "uccha";
		}
		if (x->d1sign == "libra") {
			x->d1dignity = "nicha";
			nichbhang_check(sun);
		}
		if (x->d1sign == "leo") {
			x->d1dignity = "own";
		}
		if (x->d9sign == "aries") {
			x->d9dignity = "uccha";
		}
		if (x->d9sign == "libra") {
			x->d9dignity = "nicha";
		}
		if (x->d9sign == "leo") {
			x->d9dignity = "own";
		}
	}
	if (x->name == "moon") {
		x->qualities = " gentle, caring, moody, noticeable personality, understands others, nurturing and helpful nature.";
		x->vrutti = "beni";
		if (x->d1sign == "taurus") {
			x->d1dignity = "uccha";
		}
		if (x->d1sign == "scorpio") {
			x->d1dignity = "nicha";
			nichbhang_check(moon);
		}
		if (x->d1sign == "cancer") {
			x->d1dignity = "own";
		}
		if (x->d9sign == "taurus") {
			x->d9dignity = "uccha";
		}
		if (x->d9sign == "scorpio") {
			x->d9dignity = "nicha";
		}
		if (x->d9sign == "cancer") {
			x->d9dignity = "own";
		}
	}
	if (x->name == "mars") {
		x->qualities = " strong, bold, assertive, action oriented, commanding nature and discipline.";
		x->vrutti = "meli";
		if (x->d1sign == "capricorn") {
			x->d1dignity = "uccha";
		}
		if (x->d1sign == "cancer") {
			x->d1dignity = "nicha";
			nichbhang_check(mars);
		}
		if (x->d1sign == "aries") {
			x->d1dignity = "mooltrikon";
		}
		if (x->d1sign == "scorpio") {
			x->d1dignity = "own";
		}
		if (x->d9sign == "capricorn") {
			x->d9dignity = "uccha";
		}
		if (x->d9sign == "cancer") {
			x->d9dignity = "nicha";
		}
		if (x->d9sign == "scorpio") {
			x->d9dignity = "own";
		}
		if (x->d9sign == "aries") {
			x->d9dignity = "mooltrikon";
		}
	}
	if (x->name == "mercury") {
		x->qualities = " Intelligent, good communicator, witty, knower of many things, good writting ability, spontaneous answering..";
		x->vrutti = "beni";
		if (x->d1sign == "virgo") {
			x->d1dignity = "uccha";
		}
		if (x->d1sign == "gemini") {
			x->d1dignity = "own";
		}
		if (x->d1sign == "pisces") {
			x->d1dignity = "nicha";
			nichbhang_check(mercury);
		}
		if (x->d9sign == "virgo") {
			x->d9dignity = "uccha";
		}
		if (x->d9sign == "pisces") {
			x->d9dignity = "nicha";
		}
		if (x->d9sign == "gemini") {
			x->d9dignity = "own";
		}
	}
	if (x->name == "jupiter") {
		x->vrutti = "beni";
		if (x->d1sign == "cancer") {
			x->d1dignity = "uccha";
		}
		if (x->d1sign == "capricorn") {
			x->d1dignity = "nicha";
			nichbhang_check(jupiter);
		}
		if (x->d1sign == "sagittarius") {
			x->d1dignity = "mooltrikon";
		}
		if (x->d1sign == "pisces") {
			x->d1dignity = "own";
		}
		if (x->d9sign == "cancer") {
			x->d9dignity = "uccha";
		}
		if (x->d9sign == "capricorn") {
			x->d9dignity = "nicha";
		}
		if (x->d9sign == "sagittarius") {
			x->d9dignity = "mooltrikon";
		}
		if (x->d9sign == "pisces") {
			x->d9dignity = "own";
		}
	}
	if (x->name == "venus") {
		x->vrutti = "beni";
		if (x->d1sign == "pisces") {
			x->d1dignity = "uccha";
		}
		if (x->d1sign == "virgo") {
			x->d1dignity = "nicha";
			nichbhang_check(venus);
		}
		if (x->d1sign == "taurus") {
			x->d1dignity = "own";
		}
		if (x->d1sign == "libra") {
			x->d1dignity = "mooltrikon";
		}
		if (x->d9sign == "pisces") {
			x->d9dignity = "uccha";
		}
		if (x->d9sign == "virgo") {
			x->d9dignity = "nicha";
		}
		if (x->d9sign == "taurus") {
			x->d9dignity = "own";
		}
		if (x->d9sign == "libra") {
			x->d9dignity = "mooltrikon";
		}
	}
	if (x->name == "saturn") {
		x->vrutti = "meli";
		if (x->d1sign == "libra") {
			x->d1dignity = "uccha";
		}
		if (x->d1sign == "aries") {
			x->d1dignity = "nicha";
			nichbhang_check(saturn);
		}
		if (x->d1sign == "capricorn") {
			x->d1dignity = "own";
		}
		if (x->d1sign == "aquarius") {
			x->d1dignity = "mooltrikon";
		}
		if (x->d9sign == "libra") {
			x->d9dignity = "uccha";
		}
		if (x->d9sign == "aries") {
			x->d9dignity = "nicha";
		}
		if (x->d9sign == "capricorn") {
			x->d9dignity = "own";
		}
		if (x->d9sign == "aquarius") {
			x->d9dignity = "mooltrikon";
		}
	}
	if (x->name == "rahu") {
		x->vrutti = "meli";
		if (x->d1sign == "taurus" || x->d1sign == "gemini") {
			x->d1dignity = "uccha";
		}
		else if (x->d1sign == "sagittarius" || x->d1sign == "scorpio") {
			x->d1dignity = "nicha";
			nichbhang_check(rahu);
		}
		if (x->d9sign == "taurus" || x->d9sign == "gemini") {
			x->d1dignity = "uccha";
		}
		else if (x->d9sign == "sagittarius" || x->d9sign == "scorpio") {
			x->d1dignity = "nicha";
			nichbhang_check(rahu);
		}
		if (x->d1sign == "aquarius") {
			x->d1dignity = "own";
		}
		if (x->d9sign == "aquarius") {
			x->d9dignity = "own";
		}
		if (x->d1sign == "virgo") {
			x->d1dignity = "mooltrikon";
		}
		if (x->d9sign == "virgo") {
			x->d9dignity = "mooltrikon";
		}
	}
	if (x->name == "ketu") {
		x->vrutti = "meli";
		if (x->d1sign == "taurus" || x->d1sign == "gemini") {
			x->d1dignity = "nicha";
			nichbhang_check(ketu);
		}
		else if (x->d1sign == "sagittarius" || x->d1sign == "scorpio") {
			x->d1dignity = "uccha";
		}
		if (x->d9sign == "taurus" || x->d9sign == "gemini") {
			x->d1dignity = "nicha";
		}
		else if (x->d9sign == "sagittarius" || x->d9sign == "scorpio") {
			x->d1dignity = "uccha";
		}
		if (x->d1sign == "pisces") {
			x->d1dignity = "mooltrikon";
		}
		if (x->d9sign == "pisces") {
			x->d9dignity = "mooltrikon";
		}
	}
}
int houseCounter::assignPlanetoryAsp(int signnum, int pos) {
	for (int i = 1;i < pos;i++) {
		signnum++;
		if (signnum > 12) {
			signnum = signnum % 12;
		}
	}
	return signnum;
}

void houseCounter::nichbhang_check(planet p) {
	if (p.name == "sun" && p.d1sign == "libra") {
		int house = houseNumberD1(lagna.d1degree, mars.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			sun.nichbhang = sun.nichbhang + "Lord of exaltion sign (mars) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, mars.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			sun.nichbhang = sun.nichbhang + "Lord of exaltion sign (mars) is in quadrant from moon.||";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, venus.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			sun.nichbhang = sun.nichbhang + "Lord of dispositor (venus) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, venus.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			sun.nichbhang = sun.nichbhang + "Lord of dispositor (venus) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(sun.d1degree, saturn.d1degree, 0);
		if (house == 1) {
			sun.nichbhang = sun.nichbhang + "Planet(sun) conjoined the exalted planet(saturn)|";
		}
		if (sun.d9dignity == "uccha") {
			sun.nichbhang = sun.nichbhang + "planet exalted in navamsa chart.|";
		}
	}
	if (p.name == "moon" && p.d1sign == "scorpio") {
		int house = houseNumberD1(lagna.d1degree, venus.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			moon.nichbhang = moon.nichbhang + "Lord of exaltion sign (venus) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, venus.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			moon.nichbhang = moon.nichbhang + "Lord of exaltion sign (venus) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, ketu.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			moon.nichbhang = moon.nichbhang + " Lord of dispositor (ketu) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, ketu.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			moon.nichbhang = moon.nichbhang + " Lord of dispositor (ketu) is in quadrant from moon|";
		}

		house = houseNumberD1(lagna.d1degree, mars.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			moon.nichbhang = moon.nichbhang + "Lord of dispositor (mars) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, mars.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			moon.nichbhang = moon.nichbhang + "Lord of dispositor (moon) is in quadrant from moon|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, ketu.d1degree, 0);
		if (house == 1) {
			moon.nichbhang = moon.nichbhang + " Planet(moon) conjoined the exalted planet(ketu)|";
		}
		if (moon.d9dignity == "uccha") {
			moon.nichbhang = moon.nichbhang + "planet exalted in navamsa chart.|";
		}
	}

	if (p.name == "mars" && p.d1sign == "cancer") {
		int house = houseNumberD1(lagna.d1degree, saturn.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			mars.nichbhang = mars.nichbhang + "Lord of exaltion sign (saturm) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, saturn.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			mars.nichbhang = mars.nichbhang + "Lord of exaltion sign (saturn) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, moon.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			mars.nichbhang = mars.nichbhang + " Lord of dispositor (moon) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(mars.d1degree, jupiter.d1degree, 0);
		if (house == 1) {
			mars.nichbhang = mars.nichbhang + " Planet(mars) conjoined the exalted planet(jupiter)|";
		}
		if (mars.d9dignity == "uccha") {
			mars.nichbhang = mars.nichbhang + " planet exalted in navamsa chart.|";
		}
	}
	if (p.name == "mercury" && p.d1sign == "pisces") {
		int house = houseNumberD1(lagna.d1degree, mercury.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			mercury.nichbhang = mercury.nichbhang + " Lord of exaltion sign (mercury) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, mercury.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			mercury.nichbhang = mercury.nichbhang + " Lord of exaltion sign (mercury) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, jupiter.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			mercury.nichbhang = mercury.nichbhang + "Lord of dispositor (jupiter) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, jupiter.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			mercury.nichbhang = mercury.nichbhang + " Lord of dispositor (jupiter) is in quadrant from moon|";
		}
		if (mercury.d9dignity == "uccha") {
			mercury.nichbhang = mercury.nichbhang + " planet exalted in navamsa chart.|";
		}
	}
	if (p.name == "jupiter" && p.d1sign == "capricorn") {
		int house = houseNumberD1(lagna.d1degree, moon.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			jupiter.nichbhang = jupiter.nichbhang + " Lord of exaltion sign (moon) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, saturn.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			jupiter.nichbhang = jupiter.nichbhang + " Lord of dispositor (saturn) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, saturn.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			jupiter.nichbhang = jupiter.nichbhang + " Lord of dispositor (saturn) is in quadrant from moon|";
		}
		house = 0;
		house = houseNumberD1(jupiter.d1degree, mars.d1degree, 0);
		if (house == 1) {
			jupiter.nichbhang = jupiter.nichbhang + " Planet(jupiter) conjoined the exalted planet(moon)|";
		}
		if (jupiter.d9dignity == "uccha") {
			jupiter.nichbhang = jupiter.nichbhang + " planet exalted in navamsa chart.|";
		}
	}
	if (p.name == "venus" && p.d1sign == "virgo") {
		int house = houseNumberD1(lagna.d1degree, jupiter.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			venus.nichbhang = venus.nichbhang + " Lord of exaltion sign (jupiter) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, jupiter.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			venus.nichbhang = venus.nichbhang + " Lord of exaltion sign (jupiter) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, mercury.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			venus.nichbhang = venus.nichbhang + " Lord of dispositor (mercury) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, mercury.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			venus.nichbhang = venus.nichbhang + " Lord of dispositor (mercury) is in quadrant from moon|";
		}
		house = 0;
		house = houseNumberD1(venus.d1degree, mercury.d1degree, 0);
		if (house == 1) {
			venus.nichbhang = venus.nichbhang + " Planet(venus) conjoined the exalted planet(mercury)|";
		}
		if (venus.d9dignity == "uccha") {
			venus.nichbhang = venus.nichbhang + "planet exalted in navamsa chart.|";
		}
	}
	if (p.name == "saturn" && p.d1sign == "aries") {
		int house = houseNumberD1(lagna.d1degree, venus.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			saturn.nichbhang = saturn.nichbhang + " Lord of exaltion sign (venus) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, venus.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			saturn.nichbhang = saturn.nichbhang + " Lord of exaltion sign (venus) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, mars.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			saturn.nichbhang = saturn.nichbhang + " Lord of dispositor (mars) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, mars.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			saturn.nichbhang = saturn.nichbhang + "Lord of dispositor (mars) is in quadrant from moon|";
		}
		house = 0;
		house = houseNumberD1(saturn.d1degree, sun.d1degree, 0);
		if (house == 1) {
			saturn.nichbhang = saturn.nichbhang + " Planet(saturn) conjoined the exalted planet(sun)|";
		}
		if (saturn.d9dignity == "uccha") {
			saturn.nichbhang = saturn.nichbhang + " planet exalted in navamsa chart.|";
		}
	}
	if (p.name == "rahu" && p.d1sign == "sagittarius") {
		int house = houseNumberD1(lagna.d1degree, mercury.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			rahu.nichbhang = rahu.nichbhang + " Lord of exaltion sign (mercury) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, mercury.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			rahu.nichbhang = rahu.nichbhang + " Lord of exaltion sign (mercury) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, venus.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			rahu.nichbhang = rahu.nichbhang + " Lord of exaltion sign (venus) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, venus.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			rahu.nichbhang = rahu.nichbhang + " Lord of exaltion sign (venus) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, jupiter.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			rahu.nichbhang = rahu.nichbhang + " Lord of dispositor (jupiter) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, jupiter.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			rahu.nichbhang = rahu.nichbhang + " Lord of dispositor (jupiter) is in quadrant from moon|";
		}
		if (rahu.d9dignity == "uccha") {
			rahu.nichbhang = rahu.nichbhang + " planet exalted in navamsa chart.|";
		}
	}

	if (p.name == "ketu" && p.d1sign == "gemini") {
		int house = houseNumberD1(lagna.d1degree, mars.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			ketu.nichbhang = ketu.nichbhang + " Lord of exaltion sign (mars) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, mars.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			ketu.nichbhang = ketu.nichbhang + " Lord of exaltion sign (mars) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, jupiter.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			ketu.nichbhang = ketu.nichbhang + " Lord of exaltion sign (jupiter) is in quadrant from ascendent.|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, jupiter.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			ketu.nichbhang = ketu.nichbhang + " Lord of exaltion sign (jupiter) is in quadrant from moon.|";
		}
		house = 0;
		house = houseNumberD1(lagna.d1degree, mercury.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			ketu.nichbhang = ketu.nichbhang + " Lord of dispositor (mercury) is in quadrant from ascendent|";
		}
		house = 0;
		house = houseNumberD1(moon.d1degree, mercury.d1degree, 0);
		if (house == 1 || house == 4 || house == 7 || house == 10) {
			ketu.nichbhang = ketu.nichbhang + " Lord of dispositor (mercury) is in quadrant from moon|";
		}
		if (ketu.d9dignity == "uccha") {
			ketu.nichbhang = ketu.nichbhang + " planet exalted in navamsa chart.|";
		}
	}

}