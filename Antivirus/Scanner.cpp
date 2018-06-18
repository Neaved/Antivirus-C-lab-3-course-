#include "stdafx.h"
#include "Scanner.h"


using namespace std;

void Scanner::OpenDirectory(char* sPath, char* signature, size_t signatureLenght ,ofstream &log) {

	WIN32_FIND_DATA findFileData;
	HANDLE hFile;
	char* lpLastChar = sPath + strlen(sPath);

	strcat(sPath, "*");
	hFile = FindFirstFile(sPath, &findFileData);
	*lpLastChar = '\0';

	if (hFile == INVALID_HANDLE_VALUE) {
		cout << "Err HANDLE fail :c szPath = %s\r\n" << endl;
		return;
	}

	do {
		if ((0 == strcmp(findFileData.cFileName, ".")) ||
			(0 == strcmp(findFileData.cFileName, ".."))) {
			continue;
		}
		strcat(sPath, findFileData.cFileName);

		if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			strcat(sPath, "\\");
			OpenDirectory(sPath, signature, signatureLenght, log);
		}
		else {
			//cout << szPath << endl;
			ProcessFoundFile(sPath,signature, signatureLenght, log);
		}
		*lpLastChar = '\0';

	} while (FindNextFile(hFile, &findFileData));

	FindClose(hFile);
}

void Scanner::ProcessFoundFile(char* sPath, char* signature, size_t signatureLenght, ofstream &log) {

	streamoff  sizeFile;
	ifstream strm(sPath, ios::binary);
	strm.seekg(0, std::ios::end);
	sizeFile = strm.tellg();
	strm.seekg(0, std::ios::beg);

	char *charFile = new char[sizeFile];
	strm.read(charFile, sizeFile);

	strm.close();

	char *ptr = charFile;
	//int lenghtCompare = 0;

	for (; ptr - charFile < sizeFile; ptr += strlen(ptr) + 1) {
		//char *find = strstr(ptr, signature);
		if (ptr && (strstr(ptr, signature) >= charFile) && (strstr(ptr, signature) <= charFile+sizeFile)){
			log << '\t' << sPath << '\n';
			break;
		}
	}

	//for (int i = 0; i < sizeFile; i++)
	//{
	//	for (int j = 0; j < signatureLenght; j++)
	//	{
	//		if (charFile[i + j] == signature[j]) {
	//			lenghtCompare++;
	//		}
	//		else
	//			break;
	//	}
	//	if (lenghtCompare == signatureLenght) {
	//		//cout << "Virus: " << szPath << endl;
	//		log << '\t' << sPath << '\n';
	//		break;
	//	}
	//}

	delete[] charFile;
}

void Scanner::toScan(SignatureBase& signatureBase) {

	cout << "Let's start " << endl;
	char currDrive[] = "C:\\Program Files\\";//Users\\Asus\\Downloads\\Trash\\";
	char _path[512];
	DWORD i, dwDiskMask = GetLogicalDrives();

	strcpy(_path, currDrive);

	ofstream log("logVirus.txt");

	for (auto sig : signatureBase.signList) {
		log << "\n----------------------------------------------------\n";
		log << "Signature: " << sig.signatureName << "\n";
		log << "----------------------------------------------------\n\n";
		OpenDirectory(_path, sig.signature.sequence, sig.signature.seqLength , log);
	}
}

Scanner::Scanner() {

}

Scanner::~Scanner(){

}
