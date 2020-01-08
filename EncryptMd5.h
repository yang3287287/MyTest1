// EncryptMd5.h: interface for the CEncryptMd5 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENCRYPTMD5_H__85EC0B44_601D_4B48_9565_6E87D849F8D0__INCLUDED_)
#define AFX_ENCRYPTMD5_H__85EC0B44_601D_4B48_9565_6E87D849F8D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEncryptMd5  
{
public:
	CEncryptMd5();
	virtual ~CEncryptMd5();

	static CString GetMD5(BYTE* pBuf, UINT nLength);
	static CString GetMD5(CString &sInput);
	static CString GetMd5File(CString filename,ULONGLONG&filelen);
protected:
	//RSA MD5 implementation
	void Transform(BYTE Block[64]);
	void Update(BYTE* Input, ULONG nInputLen);
	static void HexStringToBin(char*hexstring,BYTE*value);
	CString Final();
	inline DWORD RotateLeft(DWORD x, int n);
	inline void FF( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);
	inline void GG( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);
	inline void HH( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);
	inline void II( DWORD& A, DWORD B, DWORD C, DWORD D, DWORD X, DWORD S, DWORD T);

	//utility functions
	void DWordToByte(BYTE* Output, DWORD* Input, UINT nLength);
	void ByteToDWord(DWORD* Output, BYTE* Input, UINT nLength);
private:
	BYTE  m_lpszBuffer[64];		//input buffer
	ULONG m_nCount[2];			//number of bits, modulo 2^64 (lsb first)
	ULONG m_lMD5[4];			//MD5 checksum
};

#endif // !defined(AFX_ENCRYPTMD5_H__85EC0B44_601D_4B48_9565_6E87D849F8D0__INCLUDED_)
