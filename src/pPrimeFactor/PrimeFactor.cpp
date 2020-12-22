/************************************************************/
/*    NAME: Lewandowski                                              */
/*    ORGN: MIT                                             */
/*    FILE: PrimeFactor.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include <vector>
#include <string>
#include "MBUtils.h"
#include "PrimeFactor.h"

using namespace std;
unsigned int m_prime_num = 0;
unsigned int m_prime_receive = 0;
unsigned int m_prime_calculated = 0;
uint64_t m_num;
vector <uint64_t> my_list;
//---------------------------------------------------------
// Constructor

PrimeFactor::PrimeFactor()
{
}

//---------------------------------------------------------
// Destructor

PrimeFactor::~PrimeFactor()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool PrimeFactor::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
  
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    my_list.clear();
    string key = msg.GetKey();

    if(key == "NUM_VALUE"){
      m_prime_receive++;
      m_num = msg.GetDouble();
      my_list.push_back(m_num);

    }
  m_prime_calculated++;
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
	
   return (true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool PrimeFactor::OnConnectToServer()
{
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool PrimeFactor::Iterate()
{

  string mojstring=" ";
  ostringstream oss;

  if(!my_list.empty())
  {
    copy(my_list.begin(), my_list.end(),
        ostream_iterator<uint64_t>(oss));
  }
  mojstring = "Orig="+oss.str()+", received="+to_string(m_prime_receive)+", calculated="+to_string(m_prime_calculated);

  Notify("NUM_RESULT", mojstring);

  /*
  list<string>:: iterator iter;
  for(iter=my_list.begin(); iter!=my_list.end(); iter++){
    string ss = *iter;
   
    if(ss % 2 == 0) str = to_string(ss)+", parzyste";
    else str = to_string(ss)+", nieparzyste"; 
    
    Notify("NUM_RESULT", ss);
    iter = my_list.erase(iter);


    }*/

  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool PrimeFactor::OnStartUp()
{
  list <string> sParams;
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

void PrimeFactor::RegisterVariables()
{
  Register("NUM_VALUE", 0);
  // Register("FOOBAR", 0);
}

