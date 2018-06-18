#include "stdafx.h"
#include "Scanner.h"
#include "Signature.h"
#include "SignatureBase.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	SignatureBase signatureBase;

	Scanner scanner;

	scanner.toScan(signatureBase);

    return 0;
}

