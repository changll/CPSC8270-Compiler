#!/usr/bin/python

import os, sys
import fnmatch
import subprocess
import filecmp

def testCode( retcode, msg ):
  if retcode > 0:
    print msg
    sys.exit( 1 )

testDir = os.path.join( os.getcwd(), 'cases')
if not os.path.isdir( testDir ):
  print testDir, "isn't a directory"
  sys.exit( 1 )

executable = os.path.join(os.getcwd(), "run")
if not os.path.isfile( executable ):
  retcode = subprocess.call("make",shell=True)
  testCode( retcode, "\tFAILED to make the scanner" )

files = os.listdir( testDir )
for x in files:
  if fnmatch.fnmatch(x, "*.py"):
    testcase = os.path.join(testDir, x)
    retcode = subprocess.call("./run < "+testcase+"> /tmp/out",shell=True)
    if retcode != 0:
      testCode( retcode, "\tFAILED to run test case "+x)
    else:
      output = testcase[:-3]+".out"
      if not os.path.isfile( output ):
        print "test case", x[:-3]+'.out', "doesn't exist"
        sys.exit( 1 )
      if not filecmp.cmp("/tmp/out", output): 
        print "\tTEST CASE FAILED", x
        # with open('/tmp/out', 'r') as file1:
        #   with open(output, 'r') as file2:
        #     for line1 in file1:
        #       for line2 in file2:
        #         if not line1 == line2:
        #           print line1, line2, len(line1), len(line2)
        #         break 
      else :
        print "testcase:", x, "passed"


