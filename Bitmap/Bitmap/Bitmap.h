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
	void set(int k)
	{
		expand(k);
		M[k >> 3] |= (0x80 >> (0x07 & k));
	}
	void clear(int k)
	{
		expand(k);
		M[k >> 3] &= ~(0x80 >> (0x07 & k));
	}
	bool test(int k)
	{
		expand(k);
			return M[k >> 3] & (0x80 >> (0x07 & k));
	}
private:
	char *M;
	int N;
protected:
	void init(int n) { M = new char[N = (n + 7) >> 3]; memset(M, 0, N); }
	void expand(int k)
	{
		if (k < N << 3)
			return;
		char *old_elem = M;
		int old_N = N;
		init(k << 1);
		memcpy_s(M,N,old_elem,old_N);
		delete []old_elem;
	}
};

