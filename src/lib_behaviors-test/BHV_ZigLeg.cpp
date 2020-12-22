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
#include "BHV_ZigLeg.h"
#include "ZAIC_PEAK.h"
#include <sstream>
#include <string>

using namespace std;

//---------------------------------------------------------------
// Constructor

double BHV_ZigLeg::getBufferTime(void){
  return getBufferCurrTime();
}

BHV_ZigLeg::BHV_ZigLeg(IvPDomain domain) : IvPBehavior(domain)
{
  // Provide a default behavior name
  IvPBehavior::setParam("name", "defaultname");

  // Declare the behavior decision space
  m_domain = subDomain(m_domain, "course,speed");

  // Add any variables this behavior needs to subscribe for
  addInfoVars("DESIRED_HEADING, VIEW_RANGE_PULSE", "NO_WARNING");//, NO_WARNING");

  this->m_zig_duration = 0.0;
  this->m_zig_angle = 0.0;
  this->m_name = "";

  this->m_zig_hitpoint_delay = 0.0;
  this->m_zig_hitpoint_delay_start = 0.0;

  
  this->m_last_pulse_time = 0.0;

  this->m_zig_wait_started = false;
  
}

//---------------------------------------------------------------
// Procedure: setParam()

bool BHV_ZigLeg::setParam(string param, string val)
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
    
  }else if(param.compare("zig_duration") == 0){
    this->m_zig_duration = double_val;
    return true;

  }else if(param.compare("zig_angle") == 0){
    this->m_zig_angle = double_val;
    return true;

  }else if(param.compare("zig_hitpoint_delay") == 0){
    this->m_zig_hitpoint_delay = double_val;
    return true;
  }

  //TODO:: use params from moos configuration in view range ZigLeg

  // If not handled above, then just return false;
  return(false);
}

//---------------------------------------------------------------
// Procedure: onSetParamComplete()
//   Purpose: Invoked once after all parameters have been handled.
//            Good place to ensure all required params have are set.
//            Or any inter-param relationships like a<b.

void BHV_ZigLeg::onSetParamComplete()
{
}

//---------------------------------------------------------------
// Procedure: onHelmStart()
//   Purpose: Invoked once upon helm start, even if this behavior
//            is a template and not spawned at startup

void BHV_ZigLeg::onHelmStart()
{
}

//---------------------------------------------------------------
// Procedure: onIdleState()
//   Purpose: Invoked on each helm iteration if conditions not met.

void BHV_ZigLeg::onIdleState()
{
}

//---------------------------------------------------------------
// Procedure: onCompleteState()

void BHV_ZigLeg::onCompleteState()
{
}

//---------------------------------------------------------------
// Procedure: postConfigStatus()
//   Purpose: Invoked each time a param is dynamically changed

void BHV_ZigLeg::postConfigStatus()
{
}

//---------------------------------------------------------------
// Procedure: onIdleToRunState()
//   Purpose: Invoked once upon each transition from idle to run state

void BHV_ZigLeg::onIdleToRunState()
{
}

//---------------------------------------------------------------
// Procedure: onRunToIdleState()
//   Purpose: Invoked once upon each transition from run to idle state

void BHV_ZigLeg::onRunToIdleState()
{
}

//---------------------------------------------------------------
// Procedure: onRunState()
//   Purpose: Invoked each iteration when run conditions have been met.

IvPFunction* BHV_ZigLeg::onRunState()
{
  // Part 1: Build the IvP function
  IvPFunction *ipf = 0;

  double pulse_time;
  
  bool heading_found = false;
  bool view_range_pulse_found = false;
  
  double heading = getBufferDoubleVal("DESIRED_HEADING", heading_found);
  std::string view_range_pulse = getBufferStringVal("VIEW_RANGE_PULSE", view_range_pulse_found);

  if(view_range_pulse_found){

    int idx0 = view_range_pulse.find("time=");
    int idx1 = view_range_pulse.find(",edge_size=");

    pulse_time = atof(view_range_pulse.substr(idx0 + 5, idx1 - (idx0 + 5)).c_str());

    if(this->m_last_pulse_time != pulse_time){//if this is a new report, then reset the timer

      this->m_last_pulse_time = pulse_time;

      this->m_zig_hitpoint_delay_start = this->getBufferTime();

      this->m_zig_wait_started = true;

      if(heading_found){
        this->m_heading = heading;
      }

    }
  }

  if(this->m_zig_wait_started && (this->getBufferTime() - this->m_zig_hitpoint_delay_start > this->m_zig_hitpoint_delay)){

      this->m_zig_wait_started = false;

      this->m_zig_start_time = this->getBufferTime();

  }
  



  // Part N: Prior to returning the IvP function, apply the priority wt
  // Actual weight applied may be some value different than the configured
  // m_priority_wt, depending on the behavior author's insite.

  ipf = this->buildFunctionWithZAIC();//uncomment

  if(ipf)

    ipf->setPWT(m_priority_wt);

  return(ipf);
}

IvPFunction *BHV_ZigLeg::buildFunctionWithZAIC(void){
  // Step 1 - Create the IvPDomain, the function's domain
  //IvPDomain domain;
  //domain.addVar("heading", 0, 360, 361);

  // Step 2 - Create the ZAIC_PEAK with the domain and variable name
  ZAIC_PEAK  zaic_peak(this->m_domain, "course");


  // Step 3 - Configure the ZAIC_LEQ parameters
  if(this->getBufferTime() - (this->m_zig_start_time) < this->m_zig_duration){
  
    zaic_peak.setSummit( ((int)(this->m_heading + this->m_zig_angle)) % 360); 

  }else{

   return 0;//we don't want to return an ivp_function
  
  }

  zaic_peak.setMinMaxUtil(20, 120);
  zaic_peak.setBaseWidth(60);


  // Step 4 - Extract the IvP function
  IvPFunction *ivp_function = 0;
  
  ivp_function = zaic_peak.extractIvPFunction();

  return ivp_function; 

}