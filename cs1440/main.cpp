#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Station.hpp"
#include "Day.hpp"
#include "Region.hpp"
#include "Stat.hpp"
#include "Analyzer.hpp"

#define MAX_DAYS          365
#define MAX_STATS         100
#define MAX_STATION_COUNT 20


int main(int argc, char* argv[]) {
	if (argc>1) {
		std::cout << "Thanks for entering in some arguments. Here is the information: " << std::endl;
		std::ifstream inputStream(argv[1], std::ios_base::in);

		Region region;
		region.load(inputStream);

		Analyzer analyzer;

		if (argc>2) {
			std::string stationId(argv[2]);
			Station* station = region.findStation(stationId);
			if (station!= nullptr)
				analyzer.analyze(station);
		}
		else {
			region.resetStationIteration();
			Station *station;
			while ((station = region.getNextStation()) != nullptr)
				analyzer.analyze(station);
		}
	}
	else {
		std::cout << "This program was called without any arguments. Please run again with the following attached: Data/*year*-*Mon*-to-*Day*.csv \n For example: Data/2012-Jan-to-Mar.csv" << std::endl;
	}
	return 0;
}
