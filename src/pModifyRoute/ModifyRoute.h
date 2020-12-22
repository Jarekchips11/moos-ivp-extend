/************************************************************/
/*    NAME: Jaroslaw Lewandowski                                              */
/*    ORGN: MIT                                             */
/*    FILE: ModifyRoute.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef ModifyRoute_HEADER
#define ModifyRoute_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class ModifyRoute : public CMOOSApp
{
 public:
   ModifyRoute();
   ~ModifyRoute();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected:
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
};

#endif 
