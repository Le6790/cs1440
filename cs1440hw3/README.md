# This message is brought to you by the number 01010101 01010011 01000001

Employment and wage data courtesy the US Federal Government Bureau of Labor and
Statistics

* https://www.bls.gov/cew/datatoc.htm
* https://data.bls.gov/cew/doc/titles/industry/industry_titles.htm
* https://data.bls.gov/cew/doc/titles/area/area_titles.htm
* https://data.bls.gov/cew/doc/titles/ownership/ownership_titles.htm
* https://data.bls.gov/cew/doc/layouts/csv_annual_layout.htm


## Crunching Numbers

Compute the following statistics on both the 0) national aggregate data as well
as the 1) software publishing industry data:

* Standard Deviation of salaries across all FIPS areas
* Top 10 FIPS areas by annual wages, displayed in human-recognizable Area Titles
* Bottom 10 FIPS areas by annual wages, displayed in human-recognizable Area Titles
* Top 10 FIPS areas by annual average number of establishments, displayed in human-recognizable Area Titles
* Bottom 10 FIPS areas by annual average number of establishments, displayed in human-recognizable Area Titles
* Top 10 FIPS areas by annual average number of employees, displayed in human-recognizable Area Titles
* Bottom 10 FIPS areas by annual average number of employees, displayed in human-recognizable Area Titles
* The median annual salary and its assoiated FIPS Area Title
* The mode of annual salaries, along with the number of areas representing that value
* Number of unique salaries in the dataset


## Sorting things out

It will be easier to compute some of the above statistics if you first sort the
datasets.

Write comparators to use with the qsort() function (#include <cstdlib>) to sort
the datasets on the following keys:

0. Employment
  * area_fips
  * annual_avg_estabs
  * annual_avg_emplvl
  * total_annual_wages

Demonstrate that the arrays are sorted by printing the first and last 5
elements of the arrays.
