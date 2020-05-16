#ifndef SOURCE2_1_H
#define SOURCE2_1_H
#include <vector>
#include <array>
#include <iostream>
#include<string>

using namespace std;

vector < vector <float> >  str_to_f(vector < vector <string> >  p);


void myswap(float &a, float& b) ;


void bsort(vector < vector <float> > &  sortingelement) ;

float waiting_time(vector < vector <string> >  in, vector < vector <string> >  out) ;


vector < vector <float> >  fcfs(vector < vector <string> >  in) ;



vector < vector <float> >  sjf_non_pre_emitive(vector < vector <string> >  in) ;


vector < vector <float> >  sjf_pre_emitive(vector < vector <string> >  in) ;


vector < vector <float> >  priority_pre_emitive(vector < vector <string> >  in) ;


vector < vector <float> >  priority_non_pre_emitive(vector < vector <string> >  in) ;


vector < vector <float> >  R_R(vector < vector <string> >  in,int tq) ;




#endif // SOURCE2_1_H
