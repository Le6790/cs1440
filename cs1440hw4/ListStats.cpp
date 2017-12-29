#include "ListStats.hpp"
#include "List.hpp"
#include <cmath>

// TODO: implement this function
unsigned long total_annual_wages(Employment *emp) {
    unsigned long wages=0;
    while (emp->next != NULL){
        wages += emp->total_annual_wages;
        emp = emp->next;
    }
    return wages;
    
}



// TODO: implement this function
unsigned long min_annual_wages(Employment *emp) {
    Employment * empPtr = emp;
    unsigned long min =empPtr->total_annual_wages;
    while(empPtr->next !=NULL){
        if (empPtr->total_annual_wages < min){
            min = empPtr->total_annual_wages;
        }
        empPtr = empPtr->next;
    }
    
    return min;
}



// TODO: implement this function
unsigned long max_annual_wages(Employment *emp) {
     Employment * empPtr = emp;
    unsigned long max =empPtr->total_annual_wages;
    while(empPtr->next !=NULL){
        if (empPtr->total_annual_wages > max){
            max = empPtr->total_annual_wages;
        }
        empPtr = empPtr->next;
    }
    
    return max;
}



// TODO: implement this function
float stdev_annual_wages(Employment *emp) {
    unsigned long wages = total_annual_wages(emp);
    int n = list_length(emp);
    float mean = static_cast<float>(wages)/ static_cast<float>(n);
    float sos = 0.0;
    Employment * empPtr = emp;
      while(empPtr->next !=NULL){
        float diff = empPtr->total_annual_wages - mean;
        sos +=diff*diff;
        empPtr = empPtr->next;
    }
    return std::sqrt(sos/n);
    
}



// TODO: implement this function
unsigned total_annual_emplvl(Employment *emp) {
    unsigned long emplvl=0;
    while (emp->next != NULL){
        emplvl += emp->annual_avg_emplvl;
        emp = emp->next;
    }
    return emplvl;
    
}



// TODO: implement this function
unsigned max_annual_emplvl(Employment *emp) {
     Employment * empPtr = emp;
    unsigned long max =empPtr->annual_avg_emplvl;
    while(empPtr->next !=NULL){
        if (empPtr->annual_avg_emplvl > max){
            max = empPtr->annual_avg_emplvl;
        }
        empPtr = empPtr->next;
    }
    
    return max;
}



// TODO: implement this function
unsigned min_annual_emplvl(Employment *emp) {
    Employment * empPtr = emp;
    unsigned long min =empPtr->annual_avg_emplvl;
    while(empPtr->next !=NULL){
        if (empPtr->annual_avg_emplvl < min){
            min = empPtr->annual_avg_emplvl;
        }
        empPtr = empPtr->next;
    }
    
    return min;
}



// TODO: implement this function
unsigned total_annual_estabs(Employment *emp) {
     unsigned long emplvl=0;
    while (emp->next != NULL){
        emplvl += emp->annual_avg_estabs;
        emp = emp->next;
    }
    return emplvl;
    
}



// TODO: implement this function
unsigned max_annual_estabs(Employment *emp) {
        Employment * empPtr = emp;
    unsigned long max =empPtr->annual_avg_estabs;
    while(empPtr->next !=NULL){
        if (empPtr->annual_avg_estabs > max){
            max = empPtr->annual_avg_estabs;
        }
        empPtr = empPtr->next;
    }
    
    return max;
}



// TODO: implement this function
unsigned min_annual_estabs(Employment *emp) {
    Employment * empPtr = emp;
    unsigned long min =empPtr->annual_avg_estabs;
    while(empPtr->next !=NULL){
        if (empPtr->annual_avg_estabs < min){
            min = empPtr->annual_avg_estabs;
        }
        empPtr = empPtr->next;
    }
    
    return min;
}

