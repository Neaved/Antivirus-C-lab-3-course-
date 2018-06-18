#pragma once

#include "stdafx.h"
#include "SignatureBase.h"
#include "SequenceOfData.h"

using namespace std;

class Scanner {
public:
	Scanner();
	~Scanner();

	void toScan(SignatureBase& signatureBase);

private:
	void OpenDirectory( char* sPath, char* signature, size_t signatureLenght, ofstream &log);
	void ProcessFoundFile( char* sPath, char* signature, size_t signatureLenght, ofstream &log);
};