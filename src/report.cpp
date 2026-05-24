#include "report.h"
#include "aarudh.h"
#include <istream>
#include <fstream>

void basicR :: d1report() {
	ofstream d1r("C:\\Users\\Gaurav Mali\\Desktop\\Yogafinder\\Report\\1.txt", ios::app);
	if (d1r.is_open()) {
		string trial = "D1 chart also known as the lagna chart. This chart shows the snapshot of the planetary positions at the exact moment of time of birth. As per this, lagna is in " + lagna.d1sign + "(" + to_string(g_signNumbers.at(lagna.d1sign)) + ") {" + to_string(g_signNumbers.at(lagna.d1sign)) + " is rashi number of zodiac sign }, sun is in " + sun.d1sign + "(" + to_string(g_signNumbers.at(sun.d1sign)) + "), moon is in " + moon.d1sign + "(" + to_string(g_signNumbers.at(moon.d1sign)) + "), mars is in " + mars.d1sign + "(" + to_string(g_signNumbers.at(mars.d1sign)) + "), mercury is in " + mercury.d1sign + "(" + to_string(g_signNumbers.at(mercury.d1sign)) + "), Jupiter is in " + jupiter.d1sign + "(" + to_string(g_signNumbers.at(jupiter.d1sign)) + "), venus in " + venus.d1sign + "(" + to_string(g_signNumbers.at(venus.d1sign)) + "), Saturn in " + saturn.d1sign + "(" + to_string(g_signNumbers.at(saturn.d1sign)) + "), rahu in " + rahu.d1sign + "(" + to_string(g_signNumbers.at(rahu.d1sign)) + "), ketu in " + ketu.d1sign + "(" + to_string(g_signNumbers.at(ketu.d1sign)) + ").";

		d1r << trial;
		d1r.close();
	}
}

void basicR::d9report() {
	ofstream d1r("C:\\Users\\Gaurav Mali\\Desktop\\Yogafinder\\Report\\2.txt", ios::app);
	if (d1r.is_open()) {
		string trial = "D9 chart is the 9th division of d1 chart. It means making 9 parts of each sign and by that cyclical division reaching at sign of that planet. As per this, lagna is in " + lagna.d9sign + "(" + to_string(g_signNumbers.at(lagna.d9sign)) + ") {" + to_string(g_signNumbers.at(lagna.d9sign)) + " is rashi number of zodiac sign }, sun is in " + sun.d9sign + "(" + to_string(g_signNumbers.at(sun.d9sign)) + "), moon is in " + moon.d9sign + "(" + to_string(g_signNumbers.at(moon.d9sign)) + "), mars is in " + mars.d9sign + "(" + to_string(g_signNumbers.at(mars.d9sign)) + "), mercury is in " + mercury.d9sign + "(" + to_string(g_signNumbers.at(mercury.d9sign)) + "), Jupiter is in " + jupiter.d9sign + "(" + to_string(g_signNumbers.at(jupiter.d9sign)) + "), venus in " + venus.d9sign + "(" + to_string(g_signNumbers.at(venus.d9sign)) + "), Saturn in " + saturn.d9sign + "(" + to_string(g_signNumbers.at(saturn.d9sign)) + "), rahu in " + rahu.d9sign + "(" + to_string(g_signNumbers.at(rahu.d9sign)) + "), ketu in " + ketu.d9sign + "(" + to_string(g_signNumbers.at(ketu.d9sign)) + ").";

		d1r << trial;
		d1r.close();
	}
}
	