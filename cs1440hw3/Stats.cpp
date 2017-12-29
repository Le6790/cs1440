#include "Stats.hpp"
#include "Loop.hpp"
#include "Sort.hpp"



// total employment level across all FIPS areas in this dataset
long unsigned total_employment_level(Employment *array) {
	unsigned long emp = 0;

	for (int i = 0; array[i].area_fips != "END"; ++i)
		emp += array[i].annual_avg_emplvl;

	return emp;
}

// average employees per FIPS area
float average_employment_level(Employment *array) {
	int n = count_all_empl(array);
	unsigned long emp = total_employment_level(array);

	return static_cast<float>(emp) / static_cast<float>(n);
}


// total wages paid across all FIPS areas in this dataset
long unsigned total_annual_wages(Employment *array) {
	unsigned long wages = 0;

	for (int i = 0; array[i].area_fips != "END"; ++i)
		wages += array[i].total_annual_wages;

	return wages;
}


// average wage per employee represented in this dataset
float mean_annual_wages(Employment *array) {
	unsigned long n = total_employment_level(array);
	unsigned long wages = total_annual_wages(array);

	return static_cast<float>(wages) / static_cast<float>(n);
}


// DONE
unsigned long minimum_annual_wages(Employment *array) {
	int len = count_all_empl(array);
	sort_employment_by_total_annual_wages(array, len);
	return array[0].total_annual_wages;
	
	
}


// DONE
unsigned long maximum_annual_wages(Employment *array) {
	int len = count_all_empl(array);
	sort_employment_by_total_annual_wages(array, len);
	return array[len-1].total_annual_wages;
}



// Recheck later
unsigned long median_annual_wages(Employment *array) {
	double len = static_cast<double>(count_all_empl(array));
	int median = ceil(len/2);
	
	sort_employment_by_total_annual_wages(array,static_cast<int>(len));
	
	return array[median].total_annual_wages;
	
	
	//return 0UL;
}



/* TODO - implement me
unsigned long mode_annual_wages(Employment *array) {
	return 0UL;
}
*/



// TODO - implement me
float stdev_annual_wages(Employment *array) {
	int len = count_all_empl(array);
	
	float sd =0.0; // standard Deviation
	float mean = mean_annual_wages(array);
	
	for (int i =0; i < len; ++i)
	{
		sd += pow(array[i].total_annual_wages - mean, 2);
	}
	return sqrt(sd/len);
	
}

int unique(Employment *array, int len)
{
	int count =1;
	int seen =0;
	
	for (int i =1; i < len; i++)
	{
		if (array[i].total_annual_wages == array[i-1].total_annual_wages)
		{
			seen++;
		}
		else {
			if (seen ==0)
			{
				count++;
			}
			seen = 0;
		}
	}
	return count;
}

// TODO - implement me
unsigned long unique_annual_wages(Employment *array) {
	int len = count_all_empl(array);
	int uniqueWages = unique(array, len);
	return uniqueWages;
}



// TODO - Recheck the sort 
std::string loc_max_wages(Employment *array, Area *fips) {
	int len = count_all_empl(array);
	sort_employment_by_total_annual_wages(array,len);
	for (int i =0; fips[i].area_fips != "END"; i++)
	{
		if (fips[i].area_fips == array[len-1].area_fips)
		{
			return fips[i].area_title;
		}
	}
	return std::string("");
}



// TODO - Recheck the sort
std::string loc_min_wages(Employment *array, Area *fips) {
	int len = count_all_empl(array);
	sort_employment_by_total_annual_wages(array, len);
	for (int i =0; fips[i].area_fips != "END"; i++)
	{
		if (fips[i].area_fips == array[0].area_fips){
			return fips[i].area_title;
		}
	}

 	return std::string("Loc min wages not found.");
 }



//DONE
std::string loc_med_wages(Employment *array, Area *fips) {
	int len = count_all_empl(array);
	int med = (len/2);
	sort_employment_by_total_annual_wages(array, len);
	for (int i =0; fips[i].area_fips != "END"; i++){
		if (fips[i].area_fips == array[med].area_fips){
			return fips[i].area_title;
		}
	}
	
	
	return std::string("Loc med wages not found.");
}



//TODO - implement me
void top_10_fips_areas_by_salary(Employment *array, Area *fips) {
	int len = count_all_empl(array);
	sort_employment_by_total_annual_wages(array,len);
	int counter =1;
	for (int i =len; i >= len-10; i--){
		for (int j =0; fips[j].area_fips != "END"; j++){
			if (fips[j].area_fips == array[i].area_fips)
			{
					std::cout << counter << ". " << fips[j].area_title << "    " <<array[i].total_annual_wages << std::endl;
					counter++;
			}
		}
	}

}



// DONE
void bot_10_fips_areas_by_salary(Employment *array, Area *fips) {

	int len = count_all_empl(array);
	sort_employment_by_total_annual_wages(array,len);
	int counter =1;
	for (int i =0; i < 10; i++){
		for (int j =0; fips[j].area_fips != "END"; j++){
		if (fips[j].area_fips == array[i].area_fips){
			std::cout << counter << ". " << fips[j].area_title << "    " <<array[i].total_annual_wages << std::endl;
			counter++;
			
		}
		}
		
	}
}

