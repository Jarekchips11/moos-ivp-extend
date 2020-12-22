/************************************************************/
/*    NAME: Mayank Mali                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_Pulse.cpp                                    */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include <cstdlib>
#include "MBUtils.h"
#include "BuildUtils.h"
#include "BHV_Pulse.h"
#include <sstream>

using namespace std;

//---------------------------------------------------------------
// Constructor

double BHV_Pulse::getTime(void){
  return getBufferCurrTime() - this->m_start_time;
}

BHV_Pulse::BHV_Pulse(IvPDomain domain) :
  IvPBehavior(domain)
{
  // Provide a default behavior name
  IvPBehavior::setParam("name", "defaultname");

  // Declare the behavior decision space
  m_domain = subDomain(m_domain, "course,speed");

  // Add any variables this behavior needs to subscribe for
  addInfoVars("NAV_X, NAV_Y");
  addInfoVars("WPT_INDEX", "NO_WARNING");

  this->m_pulse_range = 0.0;
  this->m_pulse_duration = 0.0;
  this->m_name = "";

  this->m_start_time = getBufferCurrTime();

  this->m_last_wpt_index = 0;
  
}

//---------------------------------------------------------------
// Procedure: setParam()

bool BHV_Pulse::setParam(string param, string val)
{
  // Convert the parameter to lower case for more general matching
  param = tolower(param);

  // Get the numerical value of the param argument for convenience once
  double double_val = atof(val.c_str());
  
  if((param == "foo") && isNumber(val)) {
    // Set local member variables here
    return(true);
  }
  else if (param == "bar") {
    return true;

  }else if(param.compare("name") == 0){
    this->m_name = val;
    return true;
    
  }else if(param.compare("pulse_range") == 0){
    this->m_pulse_range = std::strtod(val.c_str(), nullptr);
    return true;

  }else if(param.compare("pulse_duration") == 0){
    this->m_pulse_duration = std::strtod(val.c_str(), nullptr);
    return true;

  }

  //TODO:: use params from moos configuration in view range pulse

  // If not handled above, then just return false;
  return(false);
}

//---------------------------------------------------------------
// Procedure: onSetParamComplete()
//   Purpose: Invoked once after all parameters have been handled.
//            Good place to ensure all required params have are set.
//            Or any inter-param relationships like a<b.

void BHV_Pulse::onSetParamComplete()
{
}

//---------------------------------------------------------------
// Procedure: onHelmStart()
//   Purpose: Invoked once upon helm start, even if this behavior
//            is a template and not spawned at startup

void BHV_Pulse::onHelmStart()
{
}

//---------------------------------------------------------------
// Procedure: onIdleState()
//   Purpose: Invoked on each helm iteration if conditions not met.

void BHV_Pulse::onIdleState()
{
}

//---------------------------------------------------------------
// Procedure: onCompleteState()

void BHV_Pulse::onCompleteState()
{
}

//---------------------------------------------------------------
// Procedure: postConfigStatus()
//   Purpose: Invoked each time a param is dynamically changed

void BHV_Pulse::postConfigStatus()
{
}

//---------------------------------------------------------------
// Procedure: onIdleToRunState()
//   Purpose: Invoked once upon each transition from idle to run state

void BHV_Pulse::onIdleToRunState()
{
}

//---------------------------------------------------------------
// Procedure: onRunToIdleState()
//   Purpose: Invoked once upon each transition from run to idle state

void BHV_Pulse::onRunToIdleState()
{
}

//---------------------------------------------------------------
// Procedure: onRunState()
//   Purpose: Invoked each iteration when run conditions have been met.

IvPFunction* BHV_Pulse::onRunState()
{
  // Part 1: Build the IvP function
  IvPFunction *ipf = 0;

  bool x_found = false;
  bool y_found = false;
  bool wpt_index_found = false;

  double x = getBufferDoubleVal("NAV_X", x_found);
  double y = getBufferDoubleVal("NAV_Y", y_found);
  int wpt_index = (int)(getBufferDoubleVal("WPT_INDEX", wpt_index_found));

  if((wpt_index_found && x_found) && y_found && (this->m_last_wpt_index != wpt_index)){
    this->m_last_wpt_index = wpt_index;

    std::stringstream msg;
    msg << std::fixed <<"x=" << x << ",y=" << y << ",radius=" << this->m_pulse_range << ",duration=" << this->m_pulse_duration << ",label=" << this->m_name << ",edge_color=yellow,fill_color=yellow,time=" << this->getTime() << ",edge_size=1";
    
    postMessage("VIEW_RANGE_PULSE", msg.str().c_str());
  }

  


  // Part N: Prior to returning the IvP function, apply the priority wt
  // Actual weight applied may be some value different than the configured
  // m_priority_wt, depending on the behavior author's insite.
  if(ipf)
    ipf->setPWT(m_priority_wt);

  return(ipf);
}

