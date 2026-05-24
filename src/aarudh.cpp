#include "aarudh.h"
#include <iostream>
#include <fstream>




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
	return "";
}
//rashi of al----------------------------------------------

string ALlordYog(sign* al) {
	string stral = "";
	stral = stral + "#Your arudh lagna is in " + al->name + ". The lord of " + al->name + " is " + al->lord + "." + "The strength of the lord of arudh lagna is one of the indicator of how is the status or fame in the society.";
	planet* allord = g_findByPlanet[al->lord];
	if (allord->d1dignity == "uccha" && allord->d9dignity != "nicha") {
		stral = stral + "The best place of arudh lagna lord to be in is in its exaltation sign. in your case the lord of arudh lagna is in " + allord->d1sign + ". This is the exaltation sign of " + allord->name + ". The result of arudh lagna lord being powerfull is the person will be famous and the personality will be well accepted by the society. This is not very common. you are definitely some famous in your circle.";
	}
	else if (allord->d1dignity == "uccha" && allord->d9dignity == "nicha") {
		stral = stral + "Arudh lagna lord being in its uccha rashi is very good combination. but being in debilitated rashi in navamsa limits its full potential. The lord is in " + allord->d1sign + " which is its exalted sign but in navamsa it is in" + allord->d9sign + " which is its debilitation sign. This shows much resourcces with image bulding but less support of luck for it. Keeping it real about image will be benifitial.";
	}
	else if (allord->d1dignity == "nicha" && allord->d9dignity == "uccha") {
		stral = stral + "Arudh lagna lord being in nich rashi is not considered good. This is not a good combination, in your case the " + allord->name + "is in " + allord->d1sign + " which is its debilitation sign but in navamsa the it is in " + allord->d9sign + ". Being in exaltation sign in navamsa  cancels the debility of the planet and gives good results. The yoga formed here called nich bhang raj yog. The result of this is, at first people judge you bit less but eventually they get to know and image improves in their mind.";
	}
	else if (allord->d1dignity == "mooltrikon") {
		stral = stral + "Arudh lagna lord being in its mooltrikon rashi is good combination. " + allord->d1sign + " is the mooltrikon rashi of " + allord->name + " This makes the planet quite powerful. The strength of planet shows how well we will be perceived in the society. ";
	}
	else if (allord->d1dignity == "nicha" && allord->motion == "retro") {
		stral = stral + "The lord of arudh lagna being in the debilitated sing is generally not considered good for the image but in your case the lord is debilitated at the same time its retrograde. this shows that at first people misjudge you and lateron they understand the depth of your personality. retorgration makes planet very powerful, this reflects in your personality.";
	}
	else if (allord->d1dignity == "nicha" && allord->d9dignity != "uccha") {
		if (allord->nichbhang != "") {
			stral = stral + "in this chart the arudh lagna lord " + allord->name+ " is in debilitation sign. The lord of arudh lagna being debilitated is not desirable but in your case the mars have nichbhang. this means though the lord is in debilitated sign it will not produce those bad effects. The parameters which cancels the debility are : ";
			stral = stral + allord->nichbhang;
		}
		else {
			stral = stral + "In this case the arudh lagna lord is in debilitation sign. this means the people will misunderstand your abilities. You might be capable enough in the reality but the initial perception about you may be different but eventually reality comes upfront.";
		}
	}
	return stral;
}

string PlanetsInAL(sign* al) {
	string planetInAl = "";
	if (al->vecPlanet.size() > 0) {
		planetInAl = planetInAl + "Your arudh lagna contains ";
		string planet = "";
		for (auto it : al->vecPlanet) {
			planet = planet + it->name;
			planet = planet + ",";
		}
		planetInAl = planetInAl + planet + "planets.";
	}
	auto itplanet = find_if(al->vecPlanet.begin(), al->vecPlanet.end(), [&](const planet* pp) {return pp && pp->name == "sun";});
	if (itplanet != al->vecPlanet.end()) {
		planetInAl = planetInAl + " Sun in the arudh lagna works very well. The karaka of the first house is sun and it self is being in the arudh lagna is blessing.";
		if (sun.d1dignity != "" && sun.d1dignity != "nicha") {
			planetInAl = planetInAl + " In your chart the sun is in its " + sun.d1sign + " rahi. This is quite powerful. The qualities of sun being in arudh lagna are ";
			planetInAl = planetInAl + sun.qualities + ". These quaities are visible in your personality.";
		}
		if (sun.d1dignity == "nicha" && sun.nichbhang == "") {
			planetInAl = planetInAl + " Sun in the arudh lagna is good combination but in your case as the sun is in its debilitated sign 'libra' you have to put more efforts in leting world know about yourself with qualities of sun. The qualities of sun like leadershiop, confidence despite being present in your personality the world will perceive as you lack those. ";
		}
		if (sun.d1dignity == "nicha" && sun.nichbhang != "") {
			planetInAl = planetInAl + " Sun in the arudh lagna is good combination but in your case as the sun is in its debilitation sign 'libra'. planet being debilitated is not desirable but the sun have nich bhang. It means cancelation of debility. the bad effects like being perceived as lacking confidence and leadership qualities will not be there. Initially people may think like that but eventually they come to know. ";
			planetInAl = planetInAl + " The reasons of cancelation of debility: " + sun.nichbhang;
		}
	}

	itplanet = find_if(al->vecPlanet.begin(), al->vecPlanet.end(), [&](const planet* pp) {return pp && pp->name == "moon";});
	if (itplanet != al->vecPlanet.end()) {
		planetInAl = planetInAl + " Moon in arudh lagna is very good combination. image about some one is formed by people by their mind and the planet moon governs the mind. Moon being in the arudh lagna makes person popular in their circle.";
		if (moon.d1dignity != "" && moon.d1dignity != "nicha") {
			planetInAl = planetInAl + " In your chart the moon is in its " + moon.d1sign + " rahi. This is one of the favourite rashi of moon to be in. The qualities of moon being in arudh lagna are ";
			planetInAl = planetInAl + moon.qualities + ". These quaities are visible in your personality.";
		}
		if (moon.d1dignity == "nicha" && moon.nichbhang == "") {
			planetInAl = planetInAl + " Moon in the arudh lagna is good combination but in your case as the moon is in its debilitated sign 'scorpio' you have to put more efforts in leting world know that you care about them and you are not cold hearted. People see as secretive person this may not be the reality but people persive as you lack empathy. You have to put more efforts towards it.";
		}
		if (moon.d1dignity == "nicha" && moon.nichbhang != "") {
			planetInAl = planetInAl + " Moon in the arudh lagna is good combination but in your case as the moon is in its debilitation sign 'scorpio'. planet being debilitated is not desirable but the moon have nich bhang. It means cancelation of debility. the bad effects like being perceived as cold hearted, lacking empathy, not understanding people will not be there. Initially people may think like that but eventually they come to know. ";
			planetInAl = planetInAl + " The reasons of cancelation of debility: " + moon.nichbhang;
		}
	}

	itplanet = find_if(al->vecPlanet.begin(), al->vecPlanet.end(), [&](const planet* pp) {return pp && pp->name == "mars";});

	if (itplanet != al->vecPlanet.end()) {
		planetInAl = planetInAl + " Mars in arudh lagna is pretty high energy combination. The mars is fiery planet, thus its attributes are drawn in the persona. Boldness and commanding nature is visible.";
		if (mars.d1dignity != "" && mars.d1dignity != "nicha") {
			planetInAl = planetInAl + " In your chart the mars is in its " + mars.d1sign + " rahi. This is one of the favourable rashi of mars to be in. The qualities of mars being in arudh lagna are ";
			planetInAl = planetInAl + mars.qualities + ". These quaities are visible in your personality.";
		}
		if (mars.d1dignity == "nicha" && mars.nichbhang == "") {
			planetInAl = planetInAl + " In your chart mars is in its debilitation sign 'cancer'. Cancer rashi is very emotional and mars is fiery and very practical action oriented planet, it do not feel good in this sign. The result of it is you may be judged arrogant or short tempered by others while reality may be different.  ";
		}
		if (mars.d1dignity == "nicha" && mars.nichbhang != "") {
			planetInAl = planetInAl + " Mars in the arudh lagna is good combination but in your case as the mars is in its debilitation sign 'cancer'. planet being debilitated is not desirable but the mars have nich bhang. It means cancelation of debility. the bad effects like being perceived as cold hearted, aggressive, short tempered will not be there. Initially people may think like that but eventually they come to know. ";
			planetInAl = planetInAl + " The reasons of cancelation of debility: " + mars.nichbhang;
		}
	}

	itplanet = find_if(al->vecPlanet.begin(), al->vecPlanet.end(), [&](const planet* pp) {return pp && pp->name == "mercury";});
	if (itplanet != al->vecPlanet.end()) {
		planetInAl = planetInAl + " Mercury is the planet of intelligence, communication and skills. These traits of mercury like being witty and spontaneous answers are visible to the people around you.";
		if (mercury.d1dignity != "" && mercury.d1dignity != "nicha") {
			planetInAl = planetInAl + " In your chart the mercury is in its " + mercury.d1sign + " rahi. Mercury loves to be in this rashi. People see you as smart person, who talks well, business minded. The qualities of mercury being in arudh lagna are ";
			planetInAl = planetInAl + mercury.qualities + ". These quaities are visible in your personality.";
		}
		if (mercury.d1dignity == "nicha" && mercury.nichbhang == "") {
			planetInAl = planetInAl + " In your chart mercury is in its debilitation sign 'pisces'. Mercury do not like to be in pisces sign. The result of this may occur as people get confused while talking, while telling the event they might feel you are exaggerating things. misinformation. people may doubt your promise. ";
		}
		if (mercury.d1dignity == "nicha" && mercury.nichbhang != "") {
			planetInAl = planetInAl + " Mercury in the arudh lagna is good combination but in your case as the mercury is in its debilitation sign 'pisces'. planet being debilitated is not desirable but the mercury have nich bhang. It means cancelation of debility. the bad effects like exaggerating things, misinformations , not following promises, bad communicator etc will not be there. Initially people may think like that but eventually they come to know. ";
			planetInAl = planetInAl + " The reasons of cancelation of debility: " + mercury.nichbhang;
		}
	}


	itplanet = find_if(al->vecPlanet.begin(), al->vecPlanet.end(), [&](const planet* pp) {return pp && pp->name == "jupiter";});
	if (itplanet != al->vecPlanet.end()) {

		planetInAl = planetInAl + " Mercury is the planet of intelligence, communication and skills. These traits of mercury like being witty and spontaneous answers are visible to the people around you.";
		if (jupiter.d1dignity != "" && jupiter.d1dignity != "nicha") {
			planetInAl = planetInAl + " In your chart the mercury is in its " + jupiter.d1sign + " rahi. Mercury loves to be in this rashi. People see you as smart person, who talks well, business minded. The qualities of mercury being in arudh lagna are ";
			planetInAl = planetInAl + jupiter.qualities + ". These quaities are visible in your personality.";
		}
		if (jupiter.d1dignity == "nicha" && jupiter.nichbhang == "") {
			planetInAl = planetInAl + " In your chart mercury is in its debilitation sign 'pisces'. Mercury do not like to be in pisces sign. The result of this may occur as people get confused while talking, while telling the event they might feel you are exaggerating things. misinformation. people may doubt your promise. ";
		}
		if (jupiter.d1dignity == "nicha" && jupiter.nichbhang != "") {
			planetInAl = planetInAl + " Mercury in the arudh lagna is good combination but in your case as the mercury is in its debilitation sign 'pisces'. planet being debilitated is not desirable but the mercury have nich bhang. It means cancelation of debility. the bad effects like exaggerating things, misinformations , not following promises, bad communicator etc will not be there. Initially people may think like that but eventually they come to know. ";
			planetInAl = planetInAl + " The reasons of cancelation of debility: " + jupiter.nichbhang;
		}
	}

	return "";
}
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
	ofstream ard("C:\\Users\\Gaurav Mali\\Desktop\\Yogafinder\\Report\\arudha.txt");
	string AL = "your arudh lagna is in " + al->name + "rashi.";
	string planetsInRashi = "";
	if (al->vecPlanet.size() > 0) {
		for (int i = 0;i < al->vecPlanet.size();i++) {
			if (i != 0) {
				planetsInRashi = planetsInRashi + ",";
			}
			planetsInRashi = al->vecPlanet.at(i)->name;
		}
		AL = AL + "Planets in arudh lagna are " + planetsInRashi;
	}
	if (ard.is_open()) {
		
	}

	//------------------------------------------------------------------

	//eleventh house combinations----------------------------------------
	
	int _11thsign=1;
	for (int i = 1;i < 11;i++) {
		alSignnum++;
		if (alSignnum > 12) {
			alSignnum % 12;
		}
		_11thsign = alSignnum;
	}
	al = g_d1findBySign[g_NumberSigns[_11thsign]];
	
	if (ard.is_open()) {
		ard << "Eleventh house from arudh lagna shows the sources of income. planets present and aspecting the house have key influence on the income. Benifics planets like moon, jupiter, venus shows virtuous means. malefics like saturn, rahu may make perception as income through questionable means. " << endl;
		string containingPlanet = "";
		string grahaAspecting = "";
		for (auto a : al->vecPlanet) {
			containingPlanet = containingPlanet + a->name+",";
		}
		for (auto a : al->Rashi_aspector) {
			grahaAspecting = grahaAspecting + a->name+",";
		}
		string entry = "your eleventh house from aarudha is" + al->name + "." + "the lord of his sign is " + al->lord + "." + "the strength of the lord shows the image of that house. Planets influencing this house are as follows.Planets in the eleventh house from arudha are"+ containingPlanet+"."+"Planets aspecting by grah drushti are"+ grahaAspecting+"."+"These planets will have say on the income.";
		ard << entry;
	}
	//--------------------------------------------------------------------

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