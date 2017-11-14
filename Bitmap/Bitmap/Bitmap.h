#pragma once
#include <cstring>
#include <cstdio>

class Bitmap
{
public:
	Bitmap(int n=8) { init(n); }
	~Bitmap() { delete[]M; M = nullptr; }
	Bitmap(char *file, int n = 8)
	{
		init(n);
		FILE* fp = fopen(file, "r");
		fread(M, sizeof(char), N, fp);
		fclose(fp);
	}
private:
	char *M;
	int N;
protected:
	void init(int n) { M = new char[N = (n + 7) >> 3]; memset(M, 0, N); }
};

