#include "report.h"
#include "aarudh.h"
#include <istream>
#include <fstream>
#include <filesystem>

void basicR :: d1report() {
	std::filesystem::path current_dir = std::filesystem::current_path().parent_path().parent_path().parent_path();

	std::filesystem::path file_path = current_dir / "Report" / "arudha.txt";
	ofstream d1r("file_path", ios::app);
	if (d1r.is_open()) {




		string trial = "D1 chart also known as the lagna chart. This chart shows the snapshot of the planetary positions at the exact moment of time of birth. As per this, lagna is in " + lagna.d1sign + "(" + to_string(g_signNumbers.at(lagna.d1sign)) + ") {" + to_string(g_signNumbers.at(lagna.d1sign)) + " is rashi number of zodiac sign }, sun is in " + sun.d1sign + "(" + to_string(g_signNumbers.at(sun.d1sign)) + "), moon is in " + moon.d1sign + "(" + to_string(g_signNumbers.at(moon.d1sign)) + "), mars is in " + mars.d1sign + "(" + to_string(g_signNumbers.at(mars.d1sign)) + "), mercury is in " + mercury.d1sign + "(" + to_string(g_signNumbers.at(mercury.d1sign)) + "), Jupiter is in " + jupiter.d1sign + "(" + to_string(g_signNumbers.at(jupiter.d1sign)) + "), venus in " + venus.d1sign + "(" + to_string(g_signNumbers.at(venus.d1sign)) + "), Saturn in " + saturn.d1sign + "(" + to_string(g_signNumbers.at(saturn.d1sign)) + "), rahu in " + rahu.d1sign + "(" + to_string(g_signNumbers.at(rahu.d1sign)) + "), ketu in " + ketu.d1sign + "(" + to_string(g_signNumbers.at(ketu.d1sign)) + ").";

		d1r << trial;
		d1r.close();
	}
}


	