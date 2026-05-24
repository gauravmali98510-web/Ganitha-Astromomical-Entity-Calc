#pragma once	
#include <vector>
#include <string>
#include <map>
using namespace std;
struct planet {
	string name;
	float d1degree;
	float d9degree;
	string d1sign;
	string d9sign;
	string graharudhsign;
	string d1dignity;  //uccha,nicha,mooltrikon,own
	string d9dignity;
	string vrutti;
	string motion;
	string nichbhang;
	string qualities;
	planet() {
		name = "";
		d1degree = 0;
		d9degree = 0;
		d1sign = "";
		d9sign = "";
		graharudhsign = "";
		d1dignity = "";
		d9dignity = "";
		motion = "";
		nichbhang = ""; //1)yes_retro, 2)yes_exaltLord_from_lagna, 3)yes_exaltLord_from_moon, 
						//4)yes_despo_lagna, 5)yes_despo_moon, 6)yes_navamsa, 7)yes_conj_exalted.
		qualities = "";
	}
};

#define Ar 0.00
#define Ta 30.00
#define Ge 60.00
#define Cn 90.00
#define Le 120.00
#define Vi 150.00
#define Li 180.00
#define Sc 210.00
#define Sg 240.00
#define Cp 270.00
#define Aq 300.00
#define Pi 330.00

const map<string, float> signsDegree = {
	{"Ar", 0.00},
	{"Ta", 30.00},
	{"Ge", 60.00},
	{"Cn", 90.00},
	{"Le", 120.00},
	{"Vi", 150.00},
	{"Li", 180.00},
	{"Sc", 210.00},
	{"Sg", 240.00},
	{"Cp", 270.00},
	{"Aq", 300.00},
	{"Pi", 330.00}
};



struct sign{
	string name;
	string lord;
	vector <planet*> vecPlanet;
	vector <string> aarudha;
	vector<planet*> Rashi_aspector;
	vector<planet*> Grah_aspector;
	sign() {
		name = "";
		lord = "";
	}
};

extern float d1Lagna;
extern float d1sun;
extern float d1moon;
extern float d1mars;
extern float d1mercury;
extern float d1jupiter;
extern float d1venus;
extern float d1saturn;
extern float d1rahu;
extern float d1ketu;
extern float d1gulika;
extern float d1mandi;


extern float d9Lagna;
extern float d9sun;
extern float d9moon;
extern float d9mars;
extern float d9mercury;
extern float d9jupiter;
extern float d9venus;
extern float d9saturn;
extern float d9rahu;
extern float d9ketu;
extern float d9gulika;
extern float d9mandi;

extern planet lagna;
extern planet sun;
extern planet moon;
extern planet mars;
extern planet mercury;
extern planet jupiter;
extern planet venus;
extern planet saturn;
extern planet rahu;
extern planet ketu;

extern sign d1aries;
extern sign d1taurus;
extern sign d1gemini;
extern sign d1cancer;
extern sign d1leo;
extern sign d1virgo;
extern sign d1libra;
extern sign d1scorpio;
extern sign d1sagittarius;
extern sign d1capricorn;
extern sign d1aquarius;
extern sign d1pisces;

extern sign d9aries;
extern sign d9taurus;
extern sign d9gemini;
extern sign d9cancer;
extern sign d9leo;
extern sign d9virgo;
extern sign d9libra;
extern sign d9scorpio;
extern sign d9sagittarius;
extern sign d9capricorn;
extern sign d9aquarius;
extern sign d9pisces;


extern map<string, int> g_signNumbers;
extern map<int, string> g_NumberSigns;
extern map<string, struct sign*> g_d1findBySign;
//extern map<string, struct sign*> g_d9findBySign;
extern map<string, struct planet*> g_findByPlanet;
extern map<string, struct sign*> g_D1Arudha;

class houseCounter {

public:

	struct gstruct_houseTime {
		int house;
		float timetochangeforward;
		float timetochangebackwrd;
	};

	void assignPlanet();

	gstruct_houseTime houseNumberD1(float fromPlanet, float toPlanet);
	int houseNumberD1(float fromPlanet, float toPlanet, int nu);


	float timeDiflection();

	float degreeAssigner(string planet);
	void signAssigner(planet* x,string division);
	void dignity(planet* x);
	int assignPlanetoryAsp(int num,int pos);
	void nichbhang_check(planet p);
};