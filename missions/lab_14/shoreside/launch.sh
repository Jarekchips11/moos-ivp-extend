#!/bin/bash -e
SHORESIDE="shoreside"
BRAVO="bravo"

#-------------------------------------------------------
#  Part 1: Check for and handle command-line arguments
#-------------------------------------------------------
TIME_WARP=1
for ARGI; do
    if [ "${ARGI}" = "--help" -o "${ARGI}" = "-h" ] ; then
    printf "%s [SWITCHES] [time_warp]   \n" $0
    printf "  --help, -h         \n" 
    exit 0;
    elif [ "${ARGI//[^0-9]/}" = "$ARGI" -a "$TIME_WARP" = 1 ]; then 
        TIME_WARP=$ARGI
    else 
    printf "Bad Argument: %s \n" $ARGI
    exit 0
    fi
done


#-------------------------------------------------------
#  Part 2: Launch the processes
#-------------------------------------------------------

printf "Launching the %s MOOS Community (WARP=%s) \n" $TIME_WARP
pAntler $SHORESIDE.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &

printf "Launching the %s MOOS Community (WARP=%s) \n" $TIME_WARP
pAntler $BRAVO.moos --MOOSTimeWarp=$TIME_WARP >& /dev/null &

uMAC -t $SHORESIDE.moos $BRAVO.moos

printf "Killing all processes ... \n"
kill %1 
kill %2
mykill
printf "Done killing processes.   \n"

