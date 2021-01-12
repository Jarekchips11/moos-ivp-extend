/************************************************************/
/*    NAME: Jaroslaw Lewandowski                                              */
/*    ORGN: MIT                                             */
/*    FILE: PatrolPoint.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef PatrolPoint_HEADER
#define PatrolPoint_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
using namespace std;

class PatrolPoint : public CMOOSApp
{
 public:
   PatrolPoint();
   ~PatrolPoint();

 protected: // Standard MOOSApp functions to overload  
   	bool OnNewMail(MOOSMSG_LIST &NewMail);
   	bool Iterate();
  	bool OnConnectToServer();
  	bool OnStartUp();
 protected:
   void RegisterVariables();


 private: // Configuration variables
	double m_current_wpt = 0;
	double m_previous_wpt = 0;
	std:: string m_current_x = "" ;
 	std::string m_previous_x = "" ;
  	std::string m_current_y = "";
 	std::string m_previous_y = "";
  	std::string m_comming_point;
  	std::string m_wpt_update = "";
  	int m_wait_time = 0;
	vector <string> m_wpt_vector;
	string wpt_list;
	double m_curr_speed;
	int m_state=0;
	int m_curr_heading;
	int m_previous_heading=0;
	int m_counter=0;
	string wpt_index;
 private: // State variables
};

#endif 
