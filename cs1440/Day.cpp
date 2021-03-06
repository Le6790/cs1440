#include "Day.hpp"

Day::Day(std::string date) {
	_date = date;
}
Stat* Day::getStatNext() {
	Stat* stat = nullptr;
	if (_currentStat < _statCount)
		stat = _stats[_currentStat++];
	return stat;
}

void Day::addStat(Stat *stat) {
	if (_statCount<MAX_STATS)
		_stats[_statCount++] = stat;
	else
		std::cerr << "Too many stats for " << getDate() << std::endl;
}

void Day::resetStatIteration() {
	_currentStat = 0;
}
