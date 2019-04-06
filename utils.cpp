#include "utils.h"


GLchar *LoadFileContent(const char *path, int &fileSize)
{
	GLchar *fileContent = nullptr;
	fileSize = 0;
	FILE *pFile = fopen(path,"rb");
	if (pFile)
	{
		fseek(pFile, 0, SEEK_END);
		int nLen = ftell(pFile);
		if (nLen > 0)
		{
			rewind(pFile);
			fileContent = new GLchar[nLen + 1];
			fread(fileContent, sizeof(GLchar), nLen, pFile);
			fileContent[nLen] = '\0';
			fileSize = nLen;
		}
		fclose(pFile);
	}

	return fileContent;
}