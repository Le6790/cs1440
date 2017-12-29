#include <iostream>
#include <iomanip>

#include "Employment.hpp"
#include "Area.hpp"
#include "Database.hpp"
#include "Loop.hpp"
#include "Stats.hpp"
#include "Sort.hpp"

int main(void) {
	/*
	std::cout << count_all_empl(software_publishing)
		<< " FIPS areas reporting across the software publishing industry" << std::endl;

	std::cout << count_all_empl(all_industries)
		<< " FIPS areas reporting across all industries" << std::endl;

	std::cout << "Total annual wages over all industries in 2016 is $"
		<< total_annual_wages(all_industries) << std::endl
		<< "And the average wage is $"
		<< std::setprecision(12)
		<< mean_annual_wages(all_industries) << std::endl;

	std::cout << "There are " << count_all_areas(fips_areas)
		<< " FIPS area codes in the database" << std::endl;

	std::cout << "10 unsorted FIPS areas:\n";
	for (int i = 0; i < 10; ++i)
		std::cout << fips_areas[i] << std::endl;
	// sort the first 10 fips areas
	sort_area_by_fips_code(fips_areas, 10);
	std::cout << "\n\n10 sorted FIPS areas:\n";
	for (int i = 0; i < 10; ++i)
		std::cout << fips_areas[i] << std::endl;
		
	*/
	std::cout << "loc min wages: " << loc_min_wages(all_industries,fips_areas) << std::endl;;	
	std::cout << "loc max wages: " << loc_max_wages(all_industries, fips_areas) << std::endl;
	std::cout <<"minimum annual wages: " << minimum_annual_wages(all_industries) << std::endl;
	std::cout <<"maximum annual wages: " << maximum_annual_wages(all_industries) << std::endl;
	std::cout <<"total Annual Wages: " << total_annual_wages(all_industries) << std::endl;
	std::cout << "Median Annual Wages: " << median_annual_wages(all_industries) << std::endl;
	std::cout << "standard deviation of annual wages: " << stdev_annual_wages(all_industries) << std::endl;
	std::cout << "Unique annual wages " << unique_annual_wages(all_industries) << std::endl;
	std::cout << "Loc med wages: " << loc_med_wages(all_industries, fips_areas) << std::endl;
	//std::cout << "Top 10 areas by Total Annual Wages: " << << std::endl;
	std::cout << "top_10_fips_areas_by_salary" << std::endl;
	top_10_fips_areas_by_salary(all_industries, fips_areas);
	std::cout << "bot_10_fips_areas_by_salary" << std::endl;
	bot_10_fips_areas_by_salary(all_industries, fips_areas);
}
