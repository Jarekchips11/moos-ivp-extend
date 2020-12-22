/************************************************************/
/*    NAME: Mayank Mali                                              */
/*    ORGN: MIT                                             */
/*    FILE: BHV_ZigLeg.h                                      */
/*    DATE:                                                 */
/************************************************************/

#ifndef ZigLeg_HEADER
#define ZigLeg_HEADER

#include <string>
#include "IvPBehavior.h"

class BHV_ZigLeg : public IvPBehavior {
public:
  BHV_ZigLeg(IvPDomain);
  ~BHV_ZigLeg() {};
  
  bool         setParam(std::string, std::string);
  void         onSetParamComplete();
  void         onCompleteState();
  void         onIdleState();
  void         onHelmStart();
  void         postConfigStatus();
  void         onRunToIdleState();
  void         onIdleToRunState();

  double       getBufferTime();
  IvPFunction *buildFunctionWithZAIC(void);

  IvPFunction* onRunState();

protected: // Local Utility functions

  double getTime(void);

protected: // Configuration parameters
  
  std::string m_name;

  double m_zig_duration;
  double m_zig_angle;
  
protected: // State variables

  double m_heading;

  double m_zig_start_time;

  double m_last_pulse_time;

  double m_zig_hitpoint_delay;
  double m_zig_hitpoint_delay_start;

  bool m_zig_wait_started;
};

#define IVP_EXPORT_FUNCTION

extern "C" {
  IVP_EXPORT_FUNCTION IvPBehavior * createBehavior(std::string name, IvPDomain domain) 
  {return new BHV_ZigLeg(domain);}
}
#endif
