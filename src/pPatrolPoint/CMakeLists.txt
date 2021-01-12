#--------------------------------------------------------
# The CMakeLists.txt for:                       pPatrolPoint
# Author(s):                              Jaroslaw Lewandowski
#--------------------------------------------------------

SET(SRC
  PatrolPoint.cpp
  PatrolPoint_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pPatrolPoint ${SRC})

TARGET_LINK_LIBRARIES(pPatrolPoint
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

