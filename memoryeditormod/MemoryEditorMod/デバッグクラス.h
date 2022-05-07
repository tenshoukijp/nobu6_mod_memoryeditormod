#pragma once

/*
 デバッグ出力のためのテンプレート
 ①printf(format, ...)にそっくりな記法

 　　デバッグ出力( "%s", 元メッセージ.c_str() );

 ②cout << ... にそっくりな記法

	 デバッグ出力 << 武将名 << ":" << 元メッセージ << (int)メッセージ関連情報.第１人称【武将番号】 << endl;

 この両方を｢デバッグ出力｣というシングルトン(前提の)インスタンスでサポートするためのクラスや宣言
*/


#include <istream>
#include <ostream>
#include <sstream>
#include <windows.h>
#include <tchar.h>




// ｢C4996」のワーニングの発生するコードがあっても、コンパイル時には出力されなくなる。
#pragma warning(push)
#pragma warning(disable:4996)

// OutputDebugStringへとフォーマット(printf)形式を利用して出力する。
extern char szBufOutputDebugStream[4096];


// VC++ で STLport だと using std::char_traits; みたいなのが必要かも
template <typename Ch_T, typename Tr_T = std::char_traits<Ch_T> >
class basic_dbg_streambuf: public std::basic_stringbuf<Ch_T, Tr_T> {
public:
	basic_dbg_streambuf() {
#ifndef STDX_DSTREAM_BUFFERING
		setbuf(0,0);
#endif
	}

	virtual ~basic_dbg_streambuf() {
		sync();
	}

protected:
	int sync(void) {
		dbg_out(str().c_str());
		pbump(static_cast<int>(pbase() - pptr()));
		return 0;
	}

	void dbg_out(const Ch_T*);
};

template <>
inline void basic_dbg_streambuf<char>::dbg_out(const char *str)	{

	::OutputDebugStringA(str);
}

template <>
inline void basic_dbg_streambuf<wchar_t>::dbg_out(const wchar_t *str) {

	::OutputDebugStringW(str);
}

template <typename Ch_T, typename Tr_T = std::char_traits<Ch_T> >
class basic_dbg_ostream: public std::basic_ostream<Ch_T, Tr_T> {
public:
	basic_dbg_ostream() : std::basic_ostream<Ch_T, Tr_T>(new basic_dbg_streambuf<Ch_T, Tr_T>())	{
	}

	virtual ~basic_dbg_ostream() {
		delete rdbuf();
	}

	// 特別に付け加え。OutputDebugStream(format, ...)のprintf関数表記的な感じを実現するため。
	void operator()( const char *format, ... ) {

		int length = sizeof(szBufOutputDebugStream) -1;


		va_list arg;

		va_start(arg, format);
		_vsnprintf_s(szBufOutputDebugStream, length, _TRUNCATE, format, arg);
		va_end(arg);

		// 最後の文字が改行ではない場合
		if ( szBufOutputDebugStream[strlen(szBufOutputDebugStream)-1] != '\n' ) {
			// 改行を足す。
			strcat( szBufOutputDebugStream, "\n");
		}

		szBufOutputDebugStream[length - 1] = '\0'; // 番兵。最悪の場合は最後の改行をすり潰す。

		// OutputDebugStringの方に出す。
		OutputDebugString( szBufOutputDebugStream );
	}
};





typedef basic_dbg_streambuf<_TCHAR> dbg_streambuf;
typedef basic_dbg_ostream<_TCHAR> デバッグストリーム型;

// 以上「C4996」のワーニングの発生するコードがあっても、コンパイル時には出力されなくなる。
#pragma warning(pop)