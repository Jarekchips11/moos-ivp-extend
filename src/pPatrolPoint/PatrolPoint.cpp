/************************************************************/
/*    NAME: Jaroslaw Lewandowski                                              */
/*    ORGN: MIT                                             */
/*    FILE: PatrolPoint.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include <string>
#include <vector>
#include "MBUtils.h"
#include "PatrolPoint.h"
#include "explode.cpp"

using namespace std;
vector <string> m_watch_point_vector;
string m_new_control_point;
  //---------------------------------------------------------
  // Constructor

  PatrolPoint::PatrolPoint()
  {
  }

  //---------------------------------------------------------
  // Destructor

  PatrolPoint::~PatrolPoint()
  {
  }

  //---------------------------------------------------------
  // Procedure: OnNewMail

  bool PatrolPoint::OnNewMail(MOOSMSG_LIST &NewMail)
  {
    MOOSMSG_LIST::iterator p;
     
    for(p=NewMail.begin(); p!=NewMail.end(); p++) {
      CMOOSMsg &msg = *p;
      if (msg.GetKey() == "WPT_STAT") {
        wpt_index=msg.GetString();
        int idx0 = wpt_index.find("behavior-name");
        int idx1 = wpt_index.find("index=");
        int idx2 = wpt_index.find(",hits");        
        if(wpt_index.substr(idx0+14,12) == "waypt_survey"){
          m_current_wpt=atof(wpt_index.substr(idx1+6,idx2-(idx1+6)).c_str());
        }
      } 
/*      if(msg.GetKey() == "VIEW_POINT"){
        m_comming_point = msg.GetString();
        int idx0 = 2;
        int idx1 = m_comming_point.find(",y=");
        m_current_x = m_comming_point.substr(idx0, idx1-2);
        int idx2 = m_comming_point.find(",active=");
        m_current_y = m_comming_point.substr(idx1+3,idx2-8);
      }
*/
      if(msg.GetKey() == "VIEW_SEGLIST"){
        string comming_list = msg.GetString();
        int idx0 = comming_list.find("pts={");
        int idx2 = comming_list.find("},active=");
        int idx1 = comming_list.find("},label=");
        if(comming_list.substr(idx1+8, 20) != "alpha_waypt_rotate" && comming_list.substr(idx1+2, 5)=="label"){
          wpt_list = comming_list.substr(5, idx1 - 5 );
          m_wpt_vector = explode(wpt_list , ':');

        }
      }

      if(msg.GetKey() == "NAV_SPEED"){
        m_curr_speed = msg.GetDouble();
      }

      if(msg.GetKey() == "NAV_HEADING"){
        m_curr_heading = msg.GetDouble();
      }

      if(msg.GetKey() == "WATCH_ADD"){
        m_watch_point_vector.push_back(msg.GetString());
        Notify("VIEW_POINT", msg.GetString());
      }
  #if 0 // Keep these around just for template
      string key   = msg.GetKey();
      string comm  = msg.GetCommunity();
      double dval  = msg.GetDouble();
      string sval  = msg.GetString(); 
      string msrc  = msg.GetSource();
      double mtime = msg.GetTime();
      bool   mdbl  = msg.IsDouble();
      bool   mstr  = msg.IsString();
  #endif
     }
  	
     return(true);
  }

  //---------------------------------------------------------
  // Procedure: OnConnectToServer

  bool PatrolPoint::OnConnectToServer()
  {
     RegisterVariables();
     return(true);
  }

  //---------------------------------------------------------
  // Procedure: Iterate()
  //            happens AppTick times per second

  bool PatrolPoint::Iterate()
  {

    if(m_current_wpt!=m_previous_wpt && m_previous_wpt!=0){
      m_wait_time=0;
      Notify("MODE", "STAY");
      Notify("STATION_UPDATES", "station_pt="+m_wpt_vector[m_previous_wpt]);


      if(m_watch_point_vector.size() > (m_previous_wpt-1)){
        int idx0 = m_watch_point_vector[m_previous_wpt-1].find(",y=");
        int idx1 = m_watch_point_vector[m_previous_wpt-1].find(",label=");
        m_new_control_point = m_watch_point_vector[m_previous_wpt-1].substr(2,idx0-2)+","+m_watch_point_vector[m_previous_wpt-1].substr(idx0+3,idx1-(idx0+3));        
      }
      else {
        int idx0 = m_watch_point_vector[0].find(",y=");
        int idx1 = m_watch_point_vector[0].find(",label=");
        m_new_control_point = m_watch_point_vector[0].substr(2,idx0-2)+","+m_watch_point_vector[0].substr(idx0+3,idx1-(idx0+3));      
      }

      m_state=1;
    }
    if(m_state==1 && m_curr_speed==0){
      Notify("MODE", "WATCHING");
      Notify("ROTATE_UPDATE", "points="+m_new_control_point);
      Notify("ROTATE_UPDATE", "speed=0.1");
      m_state=2;
    }
    if(abs(m_curr_heading-m_previous_heading)>0.1 && m_state==2 && m_counter>50){
      m_previous_heading=m_curr_heading;
      m_counter=0;
    }
    else if(abs(m_curr_heading-m_previous_heading)<0.1 && m_state==2 && m_counter>50){
      Notify("ROTATE_UPDATE", "speed=0.0");
      m_wait_time++;
    }
    m_counter++;
    if(m_wait_time > 1000){
      Notify("MODE", "SURVEYING");
      m_state=0;
    }

    m_previous_wpt = m_current_wpt;

    return(true);
  }

  //---------------------------------------------------------
  // Procedure: OnStartUp()
  //            happens before connection is open

  bool PatrolPoint::OnStartUp()
  {
    list<string> sParams;
    m_MissionReader.EnableVerbatimQuoting(false);
    if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
      list<string>::iterator p;
      for(p=sParams.begin(); p!=sParams.end(); p++) {
        string line  = *p;
        string param = tolower(biteStringX(line, '='));
        string value = line;
        
        if(param == "foo") {
          //handled
        }
        else if(param == "bar") {
          //handled
        }
      }
    }
    
    RegisterVariables();	
    return(true);
  }

  //---------------------------------------------------------
  // Procedure: RegisterVariables

  void PatrolPoint::RegisterVariables()
  {
    Register("NAV_HEADING", 0);
    Register("NAV_SPEED",0);
    Register("VIEW_SEGLIST", 0);
    Register("VIEW_POINT",0);
    Register("WPT_STAT",0);
    Register("WATCH_ADD",0);
    // Register("FOOBAR", 0);
  }

