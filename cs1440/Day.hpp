#ifndef DAY_HPP
#define DAY_HPP
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Stat.hpp"

#define MAX_DAYS          365
#define MAX_STATS         100
#define MAX_STATION_COUNT 20


class Day {
	private:
		std::string         _date;
		Stat*               _stats[MAX_STATS];
		int                 _statCount = 0;
		int                 _currentStat = -1;

	public:
		Day(std::string date);
		void addStat(Stat *stat);
		void resetStatIteration();
		Stat* getStatNext();
		std::string getDate() { return _date; }
};
#endif 