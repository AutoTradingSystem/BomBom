//---------------------------------------------------------------------------

#pragma hdrstop

#include "fileMng.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// Local
//---------------------------------------------------------------------------
CLSlog fileMngLog;
//---------------------------------------------------------------------------
// SetLogDir
//---------------------------------------------------------------------------
int SetFileMngLogDir(const char *logDir)
{
	fileMngLog = CLSlog("FileMng", logDir);
}
//---------------------------------------------------------------------------
// removeFile
//---------------------------------------------------------------------------
int CreateDir(const char *path)
{
	TCHAR logMsg[1024];
	_tcscpy(logMsg,"[mkdir]");
	_tcscat(logMsg, path);

	fileMngLog.Write("mkdir...");
	if(CreateDirectory(path, NULL) != 0)
	{
		fileMngLog.Write(logMsg);
		return 1;
	}
	return 0;
}
//---------------------------------------------------------------------------
// SearchDir
//---------------------------------------------------------------------------
int SearchDir(const char *root, const char *targetDir)
{
    WIN32_FIND_DATA FindData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD FType;
	TCHAR CurrPath[MAX_PATH];

	TCHAR logMsg[1024];
	TCHAR DirSpec[MAX_PATH];
	TCHAR rmFileNm[1024];
	_tcscpy(DirSpec, root);
	_tcsncat(DirSpec, _T("\\*"), 3);

	SetCurrentDirectory (root);
	GetCurrentDirectory (MAX_PATH, CurrPath);

	fileMngLog.Write(CurrPath);

	hFind = FindFirstFile(DirSpec, &FindData);
	if(hFind == INVALID_HANDLE_VALUE)
	{
		fileMngLog.Write("[FILE] INVALID_HANDLE_VALUE");
		return -1;
	}
	else
	{
		do
		{
			FType = FileType (&FindData);
			if(FType == TYPE_DIR)
			{

			}
		}while(FindNextFile(hFind, &FindData));
	}
	SetCurrentDirectory (__T(".."));
	FindClose (hFind);

	return 0;
}
//---------------------------------------------------------------------------
// removeFile
//---------------------------------------------------------------------------
int removeFileFromCurDIR(const char *dir)
{
	WIN32_FIND_DATA FindData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD FType;
	TCHAR CurrPath[MAX_PATH];

	TCHAR logMsg[1024];
	TCHAR DirSpec[MAX_PATH];
	TCHAR rmFileNm[1024];
	_tcscpy(DirSpec, dir);
	_tcsncat(DirSpec, _T("\\*"), 3);

	SetCurrentDirectory (dir);
	GetCurrentDirectory (MAX_PATH, CurrPath);

	fileMngLog.Write(CurrPath);

	hFind = FindFirstFile(DirSpec, &FindData);
	if(hFind == INVALID_HANDLE_VALUE)
	{
		fileMngLog.Write("[FILE] INVALID_HANDLE_VALUE");
		return -1;
	}
	else
	{
		do
		{
			FType = FileType (&FindData);
			if(FType == TYPE_FILE)
			{
				//remove file
				remove(FindData.cFileName);
				_tcscpy(logMsg, "[remove file]");
				_tcscat(logMsg, FindData.cFileName);

				fileMngLog.Write(logMsg);
				memset(logMsg, 0x00, 1024);

			}
		}while(FindNextFile(hFind, &FindData));
	}
	SetCurrentDirectory (__T(".."));
	FindClose (hFind);

	return 0;
}
//---------------------------------------------------------------------------
// removeDir
//---------------------------------------------------------------------------
int removeDir(const char *dir)
{
    //non zero is success
	return (RemoveDirectory(dir));
}
//---------------------------------------------------------------------------
// FileType
//---------------------------------------------------------------------------
DWORD FileType (LPWIN32_FIND_DATA pFileData)
{
    /* Return file type from the find data structure.
	Types supported:
		TYPE_FILE:	If this is a file
		TYPE_DIR:	If this is a directory other than . or ..
		TYPE_DOT:	If this is . or .. directory */
    BOOL IsDir;
	DWORD FType;
	FType = TYPE_FILE;
	IsDir = (pFileData->dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
	if (IsDir)
		if (lstrcmp (pFileData->cFileName,  (".")) == 0
				|| lstrcmp (pFileData->cFileName,  ("..")) == 0)
			FType = TYPE_DOT;
		else FType = TYPE_DIR;
	return FType;
}