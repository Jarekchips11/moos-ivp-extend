/************************************************************/
/*    NAME: Jaroslaw Lewandowski                                              */
/*    ORGN: MIT                                             */
/*    FILE: ModifyRoute.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include <vector>
#include <string>
#include "MBUtils.h"
#include "ModifyRoute.h"

using namespace std;


unsigned int m_wpt_receive = 0;
uint64_t m_num;
bool wpt_added;
string wpt_list;
string new_wpt;
vector <uint64_t> my_list;
//---------------------------------------------------------
// Constructor

ModifyRoute::ModifyRoute()
{
}

//---------------------------------------------------------
// Destructor

ModifyRoute::~ModifyRoute()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool ModifyRoute::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    my_list.clear();
    string key = msg.GetKey();

    if(key == "VIEW_SEGLIST"){
      m_wpt_receive++;
      string comming_list = msg.GetString();
      wpt_list="";
      int idx0 = comming_list.find("pts={");
      int idx1 = comming_list.find("},label=");
      wpt_list = comming_list.substr(5, idx1 - 5 );

    }

    if(key == "WPT_ADD"){
      new_wpt = msg.GetString();
      wpt_list = wpt_list + ": " + new_wpt;
      Notify("WPT_UPDATE", "points="+wpt_list);

    }


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
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool ModifyRoute::OnConnectToServer()
{
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool ModifyRoute::Iterate()
{

  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool ModifyRoute::OnStartUp()
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

void ModifyRoute::RegisterVariables()
{
  Register("VIEW_SEGLIST", 0);
  Register("WPT_ADD",0);
  // Register("FOOBAR", 0);
}

