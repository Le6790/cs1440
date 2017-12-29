#include "List.hpp"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

typedef Employment* EmployeePtr; //Head Pointer

//Function that will make the linked list
void insertAtHead(EmployeePtr& head, std::string areaFips, unsigned estabs, unsigned emplvl, unsigned long wages){

    Employment* tempPtr = new Employment(areaFips,estabs,emplvl, wages, NULL);
    //tempPtr->area_fips = areaFips;
    //tempPtr->annual_avg_estabs = estabs;
    //tempPtr->annual_avg_emplvl = emplvl;
    //tempPtr->total_annual_wages = wages;
    
    tempPtr->next = head;
    
   head = tempPtr;
    
}
// Make a linked list out of the data in data/xx.txt
Employment* build_empl_list(std::string filename) {
    
    std::fstream in(filename, ios::in);
    std::cout<< "BUILD EMP LIST" <<std::endl;
    std::string areaFips="";
    unsigned estabs=0;
    unsigned emplvl=0;
    unsigned long wages=0;
    
   //TODO: Staticcast to the correct
   std::string estabs1;
   std::string emplvl1;
   std::string wages1;
   
   std::string trash;
   //Throw away the top label portion on the data file
    in >> trash >> trash >> trash >> trash;
    //in >> areaFips >> estabs1 >> emplvl1 >> wages1;
    //    estabs = atof(estabs1.c_str());
    //    emplvl = atof(emplvl1.c_str());
    //    wages = atof(wages1.c_str());
    
    EmployeePtr tempEmp = new Employment(areaFips,estabs,emplvl,wages,NULL); 

    while(in >> areaFips >> estabs1 >> emplvl1 >> wages1)
    {
        estabs = atof(estabs1.c_str());
        emplvl = atof(emplvl1.c_str());
        wages = atof(wages1.c_str());
        insertAtHead(tempEmp,areaFips,estabs,emplvl,wages);
        //tempEmp = new Employment(areaFips,estabs,emplvl,wages,NULL);
        //std::cout <<"IN THE WHILE:"<< areaFips << ", " << estabs << ", " << emplvl << ", " << wages << std::endl;

    }
    //insertAtHead(tempEmp,"",0,0,0)
        //tempEmp->next =NULL;    
    in.close();
    return tempEmp;
}



// Prints everything in the employment object linked list
void print_every_empl(Employment *emp) {
std::cout << "area_fips|annual_avg_estabs|annual_avg_emplvl|total_annual_wages" << std::endl;
while(emp->next != NULL){
    std::cout<< emp->area_fips << "," << emp->annual_avg_estabs << "," << emp->annual_avg_emplvl << "," << emp->total_annual_wages << std::endl;
    emp=emp->next;
}
    
}



// Returns the length of the list
int list_length(Employment *emp) {
    int counter =0;
    while(emp->next !=NULL){
        counter++;
        emp = emp->next;
    }
    return counter;
}



// Appends list2 to list1. (All the things will be in list1)
Employment* append_lists(Employment* list1, Employment* list2) {
    Employment *tempPtr;
    /*
    if (list1 ==NULL){
        return (Employment *)NULL;
    }
    if (list2 == NULL)
    {
        return (Employment *)NULL;
    }
    */
    
    tempPtr=list1;
    while(tempPtr->next!=NULL){
        tempPtr=tempPtr->next;
    }
    tempPtr->next = list2;
    
    //print_every_empl(list1);
    //std::cout << "List Length: " <<list_length(list1)-1 << std::endl;
    
    return list1;
}

