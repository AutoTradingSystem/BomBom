//---------------------------------------------------------------------------

#ifndef fileMngH
#define fileMngH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tchar.h>
//---------------------------------------------------------------------------
#include "CLSlog.h"

//---------------------------------------------------------------------------
// Constant
//---------------------------------------------------------------------------
#define MAX_PATH 256
#define TYPE_FILE 1		/* Used in ls, rm, and lsFP */
#define TYPE_DIR 2
#define TYPE_DOT 3

int SetFileMngLogDir(const char *logDir);
int CreateDir(const char *path);
int SearchDir(const char *root, const char *targetDir);
int removeFileFromCurDIR(const char *dir);
int removeDir(const char *dir);
DWORD FileType (LPWIN32_FIND_DATA pFileData);
//---------------------------------------------------------------------------
#endif
