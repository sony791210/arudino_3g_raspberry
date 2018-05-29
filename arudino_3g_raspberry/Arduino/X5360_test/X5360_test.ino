/**************************************************************
  # Program : X5360_test
  # Version : 1.0
  # Author : wchihome
  # Date : 2018/05/15
  # Modify : 
  # 1.Add SIM5360_lib 
***************************************************************/
#include <string.h>
#include <SoftwareSerial.h>

//*-- setup Hardware Serial
unsigned long serialBaudrate = 9600;
unsigned long networkBaudrate = 115200;

//*-- SIM5360 Setting
#define netowrkRxPin  2
#define netowrkTxPin  3
#define netowrkResetPin 4
SoftwareSerial networkSerial( netowrkRxPin, netowrkTxPin );
boolean networkStatus = false;
int networkErrorCount = 0;

//*-- setup Upload Infomation
// input ur ip or ddns 
String uploadServer = "IP" ;
// input ur php file
String uploadPage = "/test.php?aid=" ;
String uploadEndSymbol = "\x1a" ;

#define DEBUG true
