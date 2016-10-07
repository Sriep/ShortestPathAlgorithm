E:\Freelancing\C++\FitnessApp\FitnessApp\dietplan.cpp:72: error: C2440: 

'return': cannot convert from 'std::basic_ostream<char,std::char_traits<char>>' 
to 'std::ofstream &'
fitnessappwrapper.obj:-1: error: LNK2019: unresolved external symbol 
"class std::basic_fstream<char,struct std::char_traits<char> > &
 __cdecl operator>>(class std::basic_fstream<char,struct std::char_traits<char> >
 &,class ExercisePlan &)" (??5@YAAEAV?$basic_fstream@DU?$char_traits@D@std@@@std@@AEAV01@AEAVExercisePlan@@@Z) referenced in function 
 "public: void __cdecl FitnessAppWrapper::loadDailyPlan(class std::basic_fstream<char,struct std::char_traits<char> > &,class ExercisePlan &)" 
 (?loadDailyPlan@FitnessAppWrapper@@QEAAXAEAV?$basic_fstream@DU?$char_traits@D@std@@@std@@AEAVExercisePlan@@@Z)
 
 fitnessappwrapper.obj:-1: error: LNK2019: unresolved external symbol 
 "class std::basic_fstream<char,struct
 std::char_traits<char> > 
 & __cdecl operator>>(class std::basic_fstream<char,struct std::char_traits<char> > &,
 class ExercisePlan &)" (??5@YAAEAV?$basic_fstream@DU?$char_traits@D@std@@@std@@AEAV01@AEAVExercisePlan@@@Z) 
 
 referenced in function 
 "public: void __cdecl 
 FitnessAppWrapper::loadDailyPlan(class std::basic_fstream<char,struct std::char_traits<char> > &,class ExercisePlan &)" 
 (?loadDailyPlan@FitnessAppWrapper@@QEAAXAEAV?$basic_fstream@DU?$char_traits@D@std@@@std@@AEAVExercisePlan@@@Z)