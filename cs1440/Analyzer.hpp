#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Station.hpp"


#include "Day.hpp"
#include "Region.hpp"
#include "Stat.hpp"

class Analyzer {
	public:
		void analyze(Station* station);
};

#endif