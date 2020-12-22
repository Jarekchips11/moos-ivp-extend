#--------------------------------------------------------
# The CMakeLists.txt for:                       pModifyRoute
# Author(s):                              Jaroslaw Lewandowski
#--------------------------------------------------------

SET(SRC
  ModifyRoute.cpp
  ModifyRoute_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pModifyRoute ${SRC})

TARGET_LINK_LIBRARIES(pModifyRoute
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

