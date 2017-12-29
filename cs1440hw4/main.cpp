#include <iostream>

#include "List.hpp"
#include "ListStats.hpp"
#include "Report.hpp"
#include "AllFilesInDirectory.hpp"


int main(void) {
	// Read in all employment lists
	Employment * allLists = AllFilesInDirectory("data");
	print_every_empl(allLists);
	// Append them into one list

	// Compute the statistics

	// Fill out the report
	Report rpt;

	rpt.num_areas      = list_length(allLists);

	rpt.gross_wages    = total_annual_wages(allLists);
	rpt.min_wages      = min_annual_wages(allLists);
	rpt.max_wages      = max_annual_wages(allLists);
	rpt.stdev_wages    = stdev_annual_wages(allLists);
//	rpt.unique_wages   = 6;
//	rpt.distinct_wages = 7;

	rpt.gross_emplvl   = total_annual_emplvl(allLists);
	rpt.max_emplvl     = max_annual_emplvl(allLists);
	rpt.min_emplvl     = min_annual_emplvl(allLists);

	rpt.gross_estabs   = total_annual_estabs(allLists);
	rpt.max_estabs     = max_annual_estabs(allLists);
	rpt.min_estabs     = min_annual_estabs(allLists);

	// Print the report
	std::cout << rpt;
	
//	print_every_empl(build_empl_list("data/01.txt")); 
	std::cout << std::endl;
//	std::cout << "list length of data/01.txt: " << list_length(build_empl_list("data/01.txt")) << std::endl;
//	std::cout << "Appending and displaying data/01.txt and data/02.txt." << std::endl;
//	append_lists(build_empl_list("data/01.txt"),build_empl_list("data/02.txt"));
	std::cout << std::endl;

/*
	std:: cout << total_annual_wages(build_empl_list("data/04.txt")) << std::endl;
	std::cout << min_annual_wages(build_empl_list("data/test.txt")) << std::endl;
	std::cout << max_annual_wages(build_empl_list("data/test.txt")) << std::endl;

	std::cout << stdev_annual_wages(build_empl_list("data/test.txt")) << std::endl;
	
	std::cout << "emplvl tests" << std::endl;
	std::cout << total_annual_emplvl(build_empl_list("data/test.txt")) << std::endl;
	std::cout << min_annual_emplvl(build_empl_list("data/test.txt")) << std::endl;
	std::cout << max_annual_emplvl(build_empl_list("data/test.txt")) << std::endl;
	
	std::cout << "estabs tests" << std::endl;
	std::cout << total_annual_estabs(build_empl_list("data/test.txt")) << std::endl;
	std::cout << min_annual_estabs(build_empl_list("data/test.txt")) << std::endl;
	std::cout << max_annual_estabs(build_empl_list("data/test.txt")) << std::endl;
*/	
	
}
